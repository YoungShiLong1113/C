#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义结构体Order，表示每个操作的信息
typedef struct
{
    char *operate; // 操作符（加、减、乘、存、取、移位）
    int o_page;    // 页号
    int address;   // 地址
} Order;

// 定义结构体Page，表示每个页面的信息
typedef struct
{
    int p_page;      // 页面号
    int flag;        // 标志位（表示页面是否在内存中）
    int frame;       // 帧号（物理内存中的位置）
    int change_flag; // 修改标志位
    int place;       // 页面在磁盘中的位置
    int counter;     // 计数器（用于记录页面最近未使用的情况）
} Page;

// 计算页面的绝对地址
int address(Page p, int x)
{
    return p.frame * 1024 + x;
}

// 在页表中查找操作对应的页号的位置
int findPageIndex(int *pageTable, int size, int page)
{
    for (int i = 0; i < size; i++)
    {
        if (pageTable[i] == page)
        {
            return i;
        }
    }
    return -1;
}

// 更新页表
void updatePageTable(int *pageTable, int size, int outPage, int inPage)
{
    for (int i = 0; i < size - 1; i++)
    {
        pageTable[i] = pageTable[i + 1];
    }
    pageTable[size - 1] = inPage;
}

// 打印缺页信息
void printPageFaultInfo(int realPage)
{
    printf("*%d\n", realPage);
}

// 打印页面替换信息
void printPageReplacementInfo(int outPage, int realPage, Page *pages)
{
    printf("OUT：%d\n", outPage);
    printf("//已被修改过，需调出后重写磁盘，该页在磁盘中的位置为：%d\n", pages[outPage].place);
    printf("IN：%d\n", realPage);
}

// 打印绝对地址信息
void printAbsoluteAddressInfo(Order order, Page page)
{
    printf("绝对地址： %d\n", address(page, order.address));
}

int main()
{
    enum OPERATE
    {
        PLUS,
        MINUS,
        MULTIPLY,
        STORE,
        RETRIEVE,
        SHIFT
    };

    Order order[] = {
        {"+", 0, 70},
        {"-", 1, 50},
        {"×", 2, 15},
        {"存", 3, 21},
        {"取", 0, 56},
        {"-", 6, 40},
        {"移位", 4, 53},
        {"+", 5, 23},
        {"存", 1, 37},
        {"取", 2, 78},
        {"+", 4, 01},
        {"存", 6, 84}};

    Page page[] = {
        {0, 1, 5, 0, 011, 0},
        {1, 1, 8, 0, 012, 0},
        {2, 1, 9, 0, 013, 0},
        {3, 1, 1, 0, 021, 0},
        {4, 0, 0, 0, 022, 0},
        {5, 0, 0, 0, 023, 0},
        {6, 0, 0, 0, 121, 0}};

    int p1[4] = {0, 1, 2, 3}; // 页表，表示内存中的页面顺序
    int p1_size = 4;

    int order_size = sizeof(order) / sizeof(order[0]); // 计算操作数组的大小
    int page_size = sizeof(page) / sizeof(page[0]);    // 计算页面数组的大小

    int real_page, out_page, temp_page;
    double num = 0; // 缺页次数

    // 遍历操作数组
    for (int i = 0; i < order_size; i++)
    {
        printf("操作  %s\n", order[i].operate);
        printf("页号 %d\n", order[i].o_page);

        real_page = order[i].o_page;
        int index = findPageIndex(p1, p1_size, real_page);

        if (index != -1)
        {
            temp_page = p1[index];

            // 如果操作是存储，则将页面的修改标志位置为1
            if (strcmp(order[i].operate, "存") == 0)
            {
                page[real_page].change_flag = 1;
            }

            printAbsoluteAddressInfo(order[i], page[real_page]);
        }
        else
        {
            printPageFaultInfo(real_page);
            num++;

            out_page = p1[0]; // 最早进入内存的页面

            // 如果需要被换出的页面已被修改过，则打印相应信息
            if (page[out_page].change_flag == 1)
            {
                printPageReplacementInfo(out_page, real_page, page);
            }
            else
            {
                printf("IN：%d\n", real_page);
            }

            // 将最早进入内存的页面替换为当前页面，并更新页面信息
            p1[0] = real_page;
            page[real_page].flag = 1;
            page[out_page].flag = 0;
            page[real_page].change_flag = 0;
            page[real_page].frame = page[out_page].frame;

            updatePageTable(p1, p1_size, out_page, real_page);
        }

        printf("~~~~~~~~~~~~~~~~~~~~~~\n");
    }

    return 0;
}