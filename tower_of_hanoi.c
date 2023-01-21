#include<stdio.h>
int ackerman(int ,int);
int main()
{
    int m,n;
    printf("Enter values of M and N\n");
    scanf("%d%d",&m,&n);
    printf("The answer is %d\n",ackerman(m,n));
    return 0;
}
int ackerman(int m,int n)
{
    if(m==0)
        return n+1;
    else if(m!=0&&n==0)
        return ackerman(m-1,m);
    else
        return ackerman(m-1,(ackerman(m,n-1)));
}
