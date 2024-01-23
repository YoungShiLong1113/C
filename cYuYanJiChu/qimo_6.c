// 水仙花数：水仙花数是指一个 3 位数，它的每个数位上的数字的 3次幂之和等于它本身。例如：1^3 + 5^3+ 3^3 = 153。
#include<stdio.h>

int main()
{
    int temp;
    int i,j,k;
    //输入一个三位数
    scanf("%d", &temp);


    //如何获得各个位
    //介块系精华
    i = temp / 100;
    j = (temp-100*i)/10;
    k = temp % 10;


    // printf("%d %d %d", i, j, k);
    if(temp==i*i*i+j*j*j+k*k*k)
    {
        printf("%d是水仙花数", temp);
    }
    else
    {
        printf("%d非水仙花数", temp);
    }
}