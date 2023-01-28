#include <stdio.h>
#include <stdlib.h>
int prime(int);
int main()
{
    int n,f=0;
    printf("Enter The Number: \n");
    scanf("%d", &n);
    if(n<2)
    {
        printf("smallest prime number is 2!");
    }
    else if(n==2)
    {
        printf("Yes! %d is a prime number\n(fun fact: Its infact the smallest prime number)",n);
    }
    else
    {
        f=prime(n);
        if(f!=0)
    {
        printf("Yes! %d is a prime number\n",n);
    }
        else
    {
        printf("No! %d is not a prime number\n",n);
    }
    }
    return 0;
}
int prime(int n)
{
    int static d=2,flag=1;
    if(d==n)
    {
        return 0;
    }
    else
    {
    if(n%d==0)
    {
        flag=0;
        d++;
    }
    else
    {
        d++;
        prime(n);
    }
    return flag;
}
}
