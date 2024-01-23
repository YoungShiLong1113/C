//输入一行字符，统计空格，数字，英文，其他
#include<stdio.h>
int main()
{
    char a;
    int num=0;
    int spa=0;
    int eng=0;
    int oth=0;

    while((a=getchar())!='\n')
    {
        if(a>'0'&&a<'9')
        {
            num++;
        }else if((a>'a'&&a<'z')||(a>'A'&&a<'Z'))
        {
            eng++;
        }else if(a==' ')
        {
            spa++;
        }else{
            oth++;
        }
    }
    printf("spa:%d,eng:%d,num:%d,oth:%d", spa, eng, num, oth);
}