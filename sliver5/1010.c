#include <stdio.h>
#include <stdlib.h>

long long ncr (int n,int r){
    if(n-r<r){
        r = n-r;
    }
    long long dp[r + 1];
    for (int i = 0; i <= r; i++) {
        dp[i] = 0;
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = r; j > 0; j--) {
            dp[j] = dp[j] + dp[j - 1];
        }
    }
    return dp[r];
}

int main() {
    int number_of_testcase;
    scanf("%d", &number_of_testcase);
    int* result = (int *) malloc(sizeof(int) * number_of_testcase);
    for(int i=0;i<number_of_testcase;i++){
        int N;
        int M;
        scanf("%d %d", &N, &M);
        result[i] = ncr(M,N);
    }
    for(int i=0;i<number_of_testcase;i++){
        printf("%d\n",result[i]);
    }
    free(result);

    return 0;
}