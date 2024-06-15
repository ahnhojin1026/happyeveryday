#include <stdio.h>
#include <stdlib.h>

char around(int ** bomb, int i, int j,int n){
    int tmp=0;
    if(i !=0){
        tmp += bomb[i-1][j];
        if(j !=0){
            tmp += bomb[i-1][j-1];
        }
        if(j != n-1){
            tmp += bomb[i-1][j+1];
        }
    }
    if(i != n-1){
        tmp += bomb[i+1][j];
        if(j !=0){
            tmp += bomb[i+1][j-1];
        }
        if(j != n-1){
            tmp += bomb[i+1][j+1];
        }
    }
    if(j !=0){
        tmp += bomb[i][j-1];
    }
    if(j != n-1){
        tmp += bomb[i][j+1];
    }
    if(tmp<10){
        return tmp + '0';
    }
    else{
        return 'M';
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int** bomb = (int **) malloc (sizeof(int *) * n);
    for(int i=0;i<n;i++){
        bomb[i] = (int *) malloc (sizeof(int) * n);
    }
    char** map = (char **) malloc (sizeof(char *) * n);
    for(int i=0;i<n;i++){
        map[i] = (char *) malloc (sizeof(char) * n);
    }

    for(int i=0;i<n;i++){
        char buf[n+1];
        scanf("%s", buf);
        for(int j=0;j<n;j++){
            if(buf[j] == '.'){
                bomb[i][j] = 0;
            }
            else{
                bomb[i][j] = buf[j]-48;
            }
        }
    }
    //draw the bomb map
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(bomb[i][j] != 0){
                map[i][j] = '*';
            }
            else{
                map[i][j] = around(bomb,i,j,n);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%c",map[i][j]);
        }
        printf("\n");
    }
    
     for(int i=0;i<n;i++){
        free(bomb[i]);
        free(map[i]);
    }
    free(bomb);
    free(map);

    return 0;
}