#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define min(a,b) (a<b?a:b)
int main() {
        char str[1001]; scanf("%s", str);
        int a_cnt = 0, ans = strlen(str);
        for (int i = 0; i < strlen(str); i++) {
                if (str[i] == 'a') a_cnt++;
        }
        for (int i = 0; i < strlen(str); i++) {
                int change_cnt = 0;
                for (int j = i, a = a_cnt; j < i + strlen(str); j++, a--) {
                        if (a == 0) break;
                        if (str[j % strlen(str)] == 'b')change_cnt++;
                }
                ans = min(ans, change_cnt);
        }
        printf("%d\n", ans);
}