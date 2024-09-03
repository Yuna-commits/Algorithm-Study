#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#define min(a,b)(a<b?a:b)
int Xs, Ys;
int Xe, Ye, dx, dy;
double get_distance(int x1, int y1) {
                double tmp = pow((x1 - Xs), 2) + pow((y1 - Ys), 2);
                return sqrt(tmp);
}
void fix_dxdy() {//dx,dy를 가장 작게 만들어 매순간(1초마다 X) 이동하는 위치 구하기
                int small = min(dx, dy);
                if (small == 0) {//둘 중 하나가 0이면 다른 하나를 1로 만듬
                                if (dx == 0) dy = 1;
                                else dx = 1;
                                return;
                }
                //최대공약수를 구해서 나누기
                while (small) {
                                if (dx % small == 0 && dy % small == 0) break;
                                else small--;
                }
                if (small > 1) { dx /= small; dy /= small; }
}
int main()
{
                scanf("%d%d", &Xs, &Ys);
                scanf("%d%d%d%d", &Xe, &Ye, &dx, &dy);
                //열차는 계속 정류장에 가까워졌다가 어느 순간 멀어짐
                //현재 정류장까지의 거리<=다음 정류장까지의 거리일 때가 가장 근접한 경우
                fix_dxdy();
                while (1) {
                                if (get_distance(Xe, Ye) < get_distance(Xe + dx, Ye + dy)) break;
                                else {
                                                Xe += dx;
                                                Ye += dy;
                                }
                }
                printf("%d %d", Xe, Ye);
}
