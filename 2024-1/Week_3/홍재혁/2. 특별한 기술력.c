#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;
int compare(const void* a, const void* b);
int main(void)
{

    scanf("%d", &N);

    long long* arr = (long long*)malloc(sizeof(long long) * N);

    long long left = 1000000000 + 7;

    for (int i = 0; i < N; i++)
    {
        scanf("%lld ", &arr[i]);
    }
    qsort(arr, N, sizeof(long long), compare);

    

    if (N == 1)
    {
        printf("%lld", arr[0] % left);
        exit(0);
    }
    else if (N == 2)
    {
        arr[1] += arr[0] % left;
        arr[0] += arr[1] % left;
        printf("%lld", arr[0] % left);
        exit(0);
    }
    else if (N == 3)
    {
        arr[1] += arr[0] % left;
        arr[2] += arr[0] % left;

        arr[0] += arr[1] % left;
        arr[2] += arr[1] % left;
        
        arr[0] += arr[2] % left;
        printf("%lld", arr[0] % left);
        exit(0);

    }


    for (int i = 1; i < N; i++)
    {
        arr[i] += arr[0] % left;
        arr[0] += arr[i] % left;
    }
    printf("%lld", arr[0] % left);

    free(arr);


    return 0;
}
int compare(const void* a, const void* b)
{
    if (*(int*)a > *(int*)b)
        return -1;
    else if (*(int*)a < *(int*)b)
        return 1;
    else
        return 0;
}