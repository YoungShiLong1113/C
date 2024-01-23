#include<stdio.h>
#include<string.h>

char str[5];
int main()
{
    printf("putin a num");
    scanf("%s", &str);

    //位数
    printf("有%d位\n", strlen(str));

    //每一位

    printf("高位到地位分别为\n");
    for (int i = strlen(str); i > 1 ; i--)
    {
        printf("%d\n ", str[i]);
    }

}