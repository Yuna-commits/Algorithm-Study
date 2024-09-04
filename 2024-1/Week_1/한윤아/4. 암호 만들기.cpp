#include<stdio.h>
#define MAX_SIZE 15
#define swap(a,b) {char t=a; a=b; b=t;}
char code[MAX_SIZE], tmp[MAX_SIZE];
int L, C;
int is_satis() {//모음, 자음 조건 만족 확인
                int vo = 0, con = 0;
                for (int i = 0; i < L; i++) {
                                switch (tmp[i]) {
                                case 'a': case 'e': case 'i': case 'o': case 'u': vo++; break;
                                default: con++; break;
                                }
                }
                if (vo >= 1 && con >= 2) return 1;
                else return 0;
}
void dfs(int cnt, int idx) {
                if (cnt == L && is_satis()) {
                                for (int i = 0; i < L; i++) printf("%c", tmp[i]);
                                printf("\n");
                                return;
                }
                for (int i = idx; i <= C; i++) {
                                tmp[cnt] = code[i];
                                dfs(cnt + 1, i + 1);
                }
}
int main()
{
                scanf("%d%d", &L, &C);
                for (int i = 1; i <= C; i++) scanf(" %c", &code[i]);
                for (int i = 1; i < C; i++) {
                                for (int j = i + 1; j <= C; j++) {
                                                if (code[i] > code[j]) swap(code[i], code[j]);
                                }
                }
                dfs(0, 1);
}
