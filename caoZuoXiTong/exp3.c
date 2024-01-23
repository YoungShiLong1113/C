#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 50

int m = 2, p = 4, q = 8; // 磁盘参数

// 查找位示图中的空闲块
void findFreeBlocks(int *bitmap, int size, int blockCount, int *index, int *offset)
{
    int num = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < sizeof(int) * 8; j++)
        {
            if (!(bitmap[i] >> j & 1))
            {
                (*index) = i;
                (*offset) = j;
                num = num + 1;
                if (num == blockCount)
                    return;
            }
        }
    }
}

// 为文件分配块
void allocateBlocks(int *bitmap, int size, char *filename, int blockCount)
{
    int index, offset;
    findFreeBlocks(bitmap, size, blockCount, &index, &offset);

    if (index == -1 || offset == -1)
    {
        printf("错误：没有足够的空间分配文件。\n");
        return;
    }

    // 更新位示图
    bitmap[index] = bitmap[index] | (1 << offset);

    // 计算相对块号
    int relativeBlock = index * sizeof(int) * 8 + offset;

    // 计算柱面、磁道和块
    int cylinders = relativeBlock / (m * p);
    int tracks = (relativeBlock % (m * p)) / q;
    int block = relativeBlock % q;

    // 打印分配信息
    printf("文件 %s 分配 %d 块：\n", filename, blockCount);
    printf("位示图位置：[%d][%d]\n", index, offset);
    printf("磁盘地址：C%d H%d R%d\n", cylinders, tracks, block);
}

// 释放文件的块
void releaseBlocks(int *bitmap, int size, char *filename)
{
    // TODO: 根据文件的信息实现释放逻辑
}

int main()
{
    int size = (m * p * q) / (sizeof(int) * 8);
    int *bitmap = (int *)malloc(size * sizeof(int));

    // 随机初始化位示图（用于测试）
    for (int i = 0; i < size; i++)
    {
        bitmap[i] = rand();
    }

    // 打印初始位示图
    printf("初始位示图：\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = sizeof(int) * 8 - 1; j >= 0; j--)
        {
            printf("%d ", (bitmap[i] >> j) & 1);
        }
        printf("\n");
    }

    // 文件分配逻辑
    char filename[MAX_FILENAME_LENGTH];
    int blockCount;
    int continueInput = 1;

    while (continueInput)
    {
        printf("输入文件名和要分配的块数，输入0结束（例如：F1 5）：");
        scanf("%s %d", filename, &blockCount);

        if (blockCount == 0)
        {
            continueInput = 0;
        }
        else
        {
            // 执行文件分配
            allocateBlocks(bitmap, size, filename, blockCount);

            // 打印更新后的位示图
            printf("更新后的位示图：\n");
            for (int i = 0; i < size; i++)
            {
                for (int j = sizeof(int) * 8 - 1; j >= 0; j--)
                {
                    printf("%d ", (bitmap[i] >> j) & 1);
                }
                printf("\n");
            }
        }
    }

    free(bitmap); // 释放分配的内存
    return 0;
}
