#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int gcd(int a, int b);
int dist(int a, int b, int c, int d);
int main(void)
{
    int xs, ys;
    scanf("%d %d", &xs, &ys);
    int xe, ye, dx, dy;
    scanf("%d %d %d %d", &xe, &ye, &dx, &dy);

    int m = gcd(dx, dy); //2 
    dx /= m; //1
    dy /= m; //2

    //최초 거리 저장
    int minv = dist(xs, ys, xe, ye); //10
    int ansX = xe;  //2
    int ansY = ye;  //1

    while (1)
    {
        xe += dx;   //3
        ye += dy;   //3
        //최초 거리가 이동한 좌표의 거리보다 큰 경우
        if (minv > dist(xs, ys, xe, ye)) // 5
        {
            //거리 변경
            minv = dist(xs, ys, xe, ye); //5
            ansX = xe; //3
            ansY = ye; //3
        }
        //minv가 이동한 좌표의 거리보다 작다면 break
        else {
            break;
        }
    }
    //정답 출력
    printf("%d %d", ansX, ansY);


    return 0;
}
//최대공약수
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
//거리
int dist(int a, int b, int c, int d)
{
    return ((a - c) * (a - c) + (b - d) * (b - d));
}
