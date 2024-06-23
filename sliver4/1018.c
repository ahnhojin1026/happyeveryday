#include<stdio.h>
#include<stdlib.h>

int getsum(int** diff, int i, int j){
    int sum=0;
    for(int a=0;a<8;a++){
        for(int b=0;b<8;b++){
            sum += diff[i+a][j+b];
        }
    }
    return sum;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    char **chess = (char **) malloc(sizeof(char *)*n);
    int **diff1 = (int **) malloc(sizeof(int *)*n);//BWBWBW...
    int **diff2 = (int **) malloc(sizeof(int *)*n);//WBWBWB...
    for(int i=0;i<n;i++){
        chess[i] = (char *) malloc(sizeof(char)*m);
        diff1[i] = (int *) malloc(sizeof(int)*m);
        diff2[i] = (int *) malloc(sizeof(int)*m);
        scanf("%s",chess[i]);
        for(int j=0;j<m;j++){
            switch (chess[i][j])
            {
            //다르면 1 같으면 0
            case 'B':
                if((i+j)%2){
                    diff1[i][j] = 1;
                    diff2[i][j] = 0;
                }
                else{
                    diff1[i][j] = 0;
                    diff2[i][j] = 1;
                }
                /* code */
                break;
            case 'W':
                if((i+j)%2){
                    diff1[i][j] = 0;
                    diff2[i][j] = 1;
                }
                else{
                    diff1[i][j] = 1;
                    diff2[i][j] = 0;
                }
                break;
            default:
                break;
            }
        }

    }
    // printf("%d %d",n,m);
    int sol = 0x7fffffff;
    for(int i=0;i<=n-8;i++){
        for(int j=0; j<=m-8;j++){
            int tmp = getsum(diff1,i,j);
            if(sol>tmp){
                sol = tmp;
            }
            tmp = getsum(diff2,i,j);
            if(sol>tmp){
                sol = tmp;
            }
        }
    }
    printf("%d",sol);
    /*
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%c",chess[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d",diff1[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d",diff2[i][j]);
        }
        printf("\n");
    }
    */
    return 0;
}