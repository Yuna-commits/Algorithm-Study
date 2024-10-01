#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int isprime(int num);
int get1(int n);
int get2(int n);
int get3(int n);
int get4(int n);
int get5(int n);
int get6(int n);
int get7(int n);
int get8(int n);
int main(void)
{
    int N;
    scanf("%d", &N);

    
    if (N == 1)
        get1(N);
    else if (N == 2)
        get2(N);
    else if (N == 3)
        get3(N);
    else if (N == 4)
        get4(N);
    else if (N == 5)
        get5(N);
    else if (N == 6)
        get6(N);
    else if (N == 7)
        get7(N);
    else if (N == 8)
        get8(N);

    




    return 0;
}
//소수면 1 아니면 0 return
int isprime(int num)
{
    if (num <= 1)
    {
        return 0;
    }

    for (int j = 2; j <= sqrt(num); j++)
    {
        if (num % j == 0)
        {
            return 0;
        }
    }
    return 1;
}
int get1(int n)
{
    int num1 = 1;
    int num2 = 1;
    for (int i = 0; i < n; i++)
    {
        num1 *= 10;
    }
    for (int i = 0; i < n - 1; i++)
    {
        num2 *= 10;
    }

    for (int i = num2; i < num1; i++)
    {
        if (i == 1 || i == 4 || i == 8 || i == 9)
            continue;
        else
        {
            if (isprime(i))
            {
                printf("%d\n", i);
            }
        }
    }
}
int get2(int n)
{
    int num1 = 1;
    int num2 = 1;
    for (int i = 0; i < n; i++)
    {
        num1 *= 10;
    }
    for (int i = 0; i < n - 1; i++)
    {
        num2 *= 10;
    }

    for (int i = num2; i < num1; i++)
    {
        if ((i / 10) == 1 || (i / 10) == 4 || (i / 10) == 8 || (i / 10) == 9)
            continue;
        else
        {
            if (isprime(((i / 1000) * 100) + (((i % 1000) / 100) * 10) + ((i % 100) / 10)) && isprime(i))
            {
                printf("%d\n", i);
            }
        }
    }
}
int get3(int n)
{
    int num1 = 1;
    int num2 = 1;
    for (int i = 0; i < n; i++)
    {
        num1 *= 10;
    }
    for (int i = 0; i < n - 1; i++)
    {
        num2 *= 10;
    }

    for (int i = num2; i < num1; i++)
    {
        if ((i / 100) == 1 || (i / 100) == 4 || (i / 100) == 8 || (i / 100) == 9)
            continue;
        else
        {
            if (isprime(((i / 1000) * 10) + (i % 1000) / 100) && isprime(((i / 1000) * 100) + (((i % 1000) / 100) * 10) + ((i % 100) / 10)) && isprime(i))
            {
                printf("%d\n", i);
            }
        }
    }
}
int get4(int n)
{
    int num1 = 1;
    int num2 = 1;
    for (int i = 0; i < n; i++)
    {
        num1 *= 10;
    }
    for (int i = 0; i < n-1; i++)
    {
        num2 *= 10;
    }

    for (int i = num2; i < num1; i++)
    {
        if ((i / 1000) == 1 || (i / 1000) == 4 || (i / 1000) == 8 || (i / 1000) == 9)
            continue;
        else
        {
            if (isprime(i / 1000) && isprime(((i / 1000) * 10) + (i % 1000) / 100) && isprime(((i / 1000) * 100) + (((i % 1000) / 100) * 10) + ((i % 100) / 10)) && isprime(i))
            {
                printf("%d\n",i);
            }
        }
    }
}
int get5(int n)
{
    int num1 = 1;
    int num2 = 1;
    for (int i = 0; i < n; i++)
    {
        num1 *= 10;
    }
    for (int i = 0; i < n - 1; i++)
    {
        num2 *= 10;
    }

    for (int i = num2; i < num1; i++)
    {
        if ((i / 10000) == 1 || (i / 10000) == 4 || (i / 10000) == 8 || (i / 10000) == 9)
            continue;
        else
        {
            if (isprime(i/10000)&&isprime(i / 1000) && isprime(((i / 1000) * 10) + (i % 1000) / 100) && isprime(((i / 1000) * 100) + (((i % 1000) / 100) * 10) + ((i % 100) / 10)) && isprime(i))
            {
                printf("%d\n", i);
            }
        }
    }
}
int get6(int n)
{
    int num1 = 1;
    int num2 = 1;
    for (int i = 0; i < n; i++)
    {
        num1 *= 10;
    }
    for (int i = 0; i < n - 1; i++)
    {
        num2 *= 10;
    }

    for (int i = num2; i < num1; i++)
    {
        if ((i / 100000) == 1 || (i / 100000) == 4 || (i / 100000) == 8 || (i / 100000) == 9)
            continue;
        else
        {
            if (isprime(i / 100000)&&isprime(i / 10000) && isprime(i / 1000) && isprime(((i / 1000) * 10) + (i % 1000) / 100) && isprime(((i / 1000) * 100) + (((i % 1000) / 100) * 10) + ((i % 100) / 10)) && isprime(i))
            {
                printf("%d\n", i);
            }
        }
    }
}
int get7(int n)
{
    int num1 = 1;
    int num2 = 1;
    for (int i = 0; i < n; i++)
    {
        num1 *= 10;
    }
    for (int i = 0; i < n - 1; i++)
    {
        num2 *= 10;
    }

    for (int i = num2; i < num1; i++)
    {
        if ((i / 1000000) == 1 || (i / 1000000) == 4 || (i / 1000000) == 8 || (i / 1000000) == 9)
            continue;
        else
        {
            if (isprime(i/ 1000000)&&isprime(i / 100000) && isprime(i / 10000) && isprime(i / 1000) && isprime(((i / 1000) * 10) + (i % 1000) / 100) && isprime(((i / 1000) * 100) + (((i % 1000) / 100) * 10) + ((i % 100) / 10)) && isprime(i))
            {
                printf("%d\n", i);
            }
        }
    }
}
int get8(int n)
{
    int num1 = 1;
    int num2 = 1;
    for (int i = 0; i < n; i++)
    {
        num1 *= 10;
    }
    for (int i = 0; i < n - 1; i++)
    {
        num2 *= 10;
    }

    for (int i = num2; i < num1; i++)
    {
        if ((i / 10000000) == 1 || (i / 10000000) == 4 || (i / 10000000) == 8 || (i / 10000000) == 9)
            continue;
        else
        {
            if (isprime(i / 10000000)&&isprime(i / 1000000) && isprime(i / 100000) && isprime(i / 10000) && isprime(i / 1000) && isprime(((i / 1000) * 10) + (i % 1000) / 100) && isprime(((i / 1000) * 100) + (((i % 1000) / 100) * 10) + ((i % 100) / 10)) && isprime(i))
            {
                printf("%d\n", i);
            }
        }
    }
}