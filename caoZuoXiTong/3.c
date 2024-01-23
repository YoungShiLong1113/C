//这段代码实现了一个简单的文件系统模拟。以下是对代码功能的分析和注释：


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//包含了所需的头文件。


typedef struct {
    int diskCapacity;
    int numFreeBlocks;
    int blockSize;
} DiskInfo;

//定义了一个结构体 DiskInfo ，用于存储磁盘的信息，包括磁盘容量、空闲块数和块大小。


typedef struct {
    char fileName[100];
    int fileSize;
    int* blockList;
} FileInfo;

//定义了一个结构体 FileInfo ，用于存储文件的信息，包括文件名、文件大小和文件块列表。


typedef struct Node {
    int blockIndex;
    struct Node* next;
} Node;

//定义了一个结构体 Node ，用于表示链表节点，包含一个块索引和指向下一个节点的指针。


typedef struct {
    int groupSize;
    int numGroups; // 新增组数成员变量
    Node** groups;
} FreeBlockList;

//定义了一个结构体 FreeBlockList ，用于存储空闲块的链表，包括每组的大小和每组的链表头指针。


void printDiskInfo(DiskInfo diskInfo, FreeBlockList freeBlockList) {
    int numGroups = diskInfo.diskCapacity / diskInfo.blockSize;
    printf("当前超级块及每组空白块信息：\n");
    for (int i = 0; i < numGroups; i++) {
        printf("组别 %d: ", i);
        Node* currentNode = freeBlockList.groups[i];
        while (currentNode != NULL) {
            printf("(%d, %d) ", i, currentNode->blockIndex);
            currentNode = currentNode->next;
        }
        printf("\n");
    }
    printf("\n");
}

//打印磁盘信息和空闲块链表的函数。遍历每一组的链表，打印每个节点的块索引。



void initFreeBlockList(DiskInfo diskInfo, FreeBlockList* freeBlockList) {
    int numGroups = diskInfo.diskCapacity / diskInfo.blockSize;
    freeBlockList->groupSize = diskInfo.blockSize;
    freeBlockList->numGroups = numGroups; // 存储组数
    freeBlockList->groups = (Node**)malloc(numGroups * sizeof(Node*));
    for (int i = 0; i < numGroups; i++) {
        freeBlockList->groups[i] = NULL;
    }
    for (int i = 0; i < numGroups; i++) {
        for (int j = 0; j < diskInfo.blockSize; j++) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->blockIndex = j;
            newNode->next = freeBlockList->groups[i];
            freeBlockList->groups[i] = newNode;
        }
    }
}

void destroyFreeBlockList(FreeBlockList* freeBlockList) {
    int numGroups = freeBlockList->numGroups; // 使用存储的组数
    for (int i = 0; i < numGroups; i++) {
        Node* currentNode = freeBlockList->groups[i];
        while (currentNode != NULL) {
            Node* temp = currentNode;
            currentNode = currentNode->next;
            free(temp);
        }
    }
    free(freeBlockList->groups);
}

//销毁空闲块链表的函数。释放每个节点的内存，并释放链表头指针数组的内存。


int allocateBlocks(DiskInfo* diskInfo, FreeBlockList* freeBlockList, int numBlocks) {
    int allocatedBlocks = 0;
    int numGroups = diskInfo->diskCapacity / diskInfo->blockSize;
    int groupIndex = 0;
    int blockIndex = 0;
    while (allocatedBlocks < numBlocks) {
        if (freeBlockList->groups[groupIndex] == NULL) {
            groupIndex++;
            blockIndex = 0;
            continue;
        }
        Node* currentNode = freeBlockList->groups[groupIndex];
        if (blockIndex > 0) {
            for (int i = 0; i < blockIndex; i++) {
                currentNode = currentNode->next;
            }
        }
        if (currentNode != NULL) {
            int blockNumber = groupIndex * diskInfo->blockSize + currentNode->blockIndex;
            printf("分配磁盘块：%d\n", blockNumber);
            currentNode->blockIndex = -1; // mark as allocated
            allocatedBlocks++;
            diskInfo->numFreeBlocks--;
            blockIndex++;
        } else {
            groupIndex++;
            blockIndex = 0;
        }
    }
    return allocatedBlocks;
}

//分配磁盘块的函数。根据需要分配的块数，遍历空闲块链表，找到可用的块并分配给文件。同时更新磁盘信息和空闲块链表。


void freeBlocks(DiskInfo* diskInfo, FreeBlockList* freeBlockList, int* blockList, int numBlocks) {
    int numGroups = diskInfo->diskCapacity / diskInfo->blockSize;
    for (int i = 0; i < numBlocks; i++) {
        int groupIndex = blockList[i] / diskInfo->blockSize;
        int blockIndex = blockList[i] % diskInfo->blockSize;
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->blockIndex = blockIndex;
        newNode->next = freeBlockList->groups[groupIndex];
        freeBlockList->groups[groupIndex] = newNode;
        printf("释放磁盘块：%d\n", blockList[i]);
        diskInfo->numFreeBlocks++;
    }
}

//释放磁盘块的函数。根据给定的块列表，将每个块添加到空闲块链表中。同时更新磁盘信息和空闲块链表。


int main() {
    DiskInfo diskInfo;

    // 接受输入参数：磁盘容量、空闲物理块数、块大小
    printf("请输入磁盘容量：");
    scanf("%d", &diskInfo.diskCapacity);
    printf("请输入空闲物理块数：");
    scanf("%d", &diskInfo.numFreeBlocks);
    printf("请输入块大小：");
    scanf("%d", &diskInfo.blockSize);

    // 计算所需的组数
    int numGroups = diskInfo.diskCapacity / diskInfo.blockSize;

    // 检查组数是否小于2
    if (numGroups < 2) {
        printf("错误：组数至少为2。\n");
        return 0;
    }

    FreeBlockList freeBlockList;
    initFreeBlockList(diskInfo, &freeBlockList);

    printf("初始空闲块链：\n");
    printDiskInfo(diskInfo, freeBlockList);

    char op[10];
    char fileName[100];
    int fileSize = 0;
    int allocatedBlocks = 0;
    int freedBlocks = 0;

    while (1) {
        printf("请输入操作（touch/rm 文件名 文件大小）：");
        scanf("%s %s %d", op, fileName, &fileSize);

        if (strcmp(op, "touch") == 0) {
            if (diskInfo.numFreeBlocks < fileSize) {
                printf("已无可用空闲空间！\n");
            } else {
                int* blockList = (int*)malloc(fileSize * sizeof(int));
                allocatedBlocks += allocateBlocks(&diskInfo, &freeBlockList, fileSize);
                for (int i = 0; i < fileSize; i++) {
                    blockList[i] = allocatedBlocks - fileSize + i;
                }
                printf("当前所有文件占用物理块信息：\n");
                printf("文件名：%s 文件大小：%d\n", fileName, fileSize);
                printf("分配物理块总数：%d\n", allocatedBlocks);
                printf("读磁盘次数：%d\n", fileSize);
                printf("文件块列表：");
                for (int i = 0; i < fileSize; i++) {
                    printf("%d ", blockList[i]);
                }
                printf("\n\n");
                free(blockList);
            }
        }
        else if (strcmp(op, "rm") == 0) {
            int* blockList = (int*)malloc(fileSize * sizeof(int));
            for (int i = 0; i < fileSize; i++) {
                printf("请输入文件块编号：");
                scanf("%d", &blockList[i]);
            }
            freeBlocks(&diskInfo, &freeBlockList, blockList, fileSize);
            freedBlocks += fileSize;
            printf("当前所有文件占用物理块信息：\n");
            printf("文件名：%s 文件大小：%d\n", fileName, fileSize);
            printf("释放物理块总数：%d\n", freedBlocks);
            printf("读磁盘次数：%d\n", fileSize);
            printf("\n");
            free(blockList);
        }
        else if (strcmp(op, "exit") == 0) {
            break;
        }
        else {
            printf("错误：无效的操作。\n");
            continue;
        }

        printDiskInfo(diskInfo, freeBlockList);
    }

    destroyFreeBlockList(&freeBlockList);

    return 0;
}

//主函数。首先接受用户输入的磁盘信息，然后初始化空闲块链表。进入循环，根据用户输入的操作进行相应的处理，包括分配磁盘块和释放磁盘块。循环直到用户输入"exit"为止。最后销毁
