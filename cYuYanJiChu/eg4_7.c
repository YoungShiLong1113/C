//用switch语句处理命令
#include<stdio.h>

int func1()
{
    printf("func1");
}

int func2()
{
    printf("func2");
}

int main()
{
    
    char ch;
    printf("putin\n");
    scanf("%c", &ch);

    switch(ch)
    {
        case 'a':
        case 'A':
            func1();
            break;
        case 'b':
        case 'B':
            func2();
            break;
    }

    return 0;
}