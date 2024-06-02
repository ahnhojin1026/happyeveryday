#include<stdio.h>

int main() {
    int init = 0;
    int cnt = 0;
    int next = -1;
    scanf("%d", &init);
    while (init != next) {
        if(cnt == 0){
            next = init;
        }
        next = 10*(next%10)+(next/10+next%10)%10;
        cnt++;
    }
    printf("%d",cnt);
    return 0;
}