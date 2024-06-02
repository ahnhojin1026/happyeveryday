#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    int MAX_STRING_LEN = 50;
    int n;
    scanf("%d",&n);
    char** arr = (char **) malloc(sizeof(char*)*n);
    char*** size_sort = (char ***) malloc(sizeof(char*));
    int size_len[50] = {0};
    for(int i=0;i<50;i++){
        size_sort[i] = (char **) malloc(sizeof(char*));
    }
    //first get the inputs by length
    for (int i = 0; i<n;i++){
        arr[i] = (char*) malloc(MAX_STRING_LEN * sizeof(char));
        scanf("%s", arr[i]);
        int len = strlen(arr[i]);
        size_sort[len] = (char**)realloc(size_sort[len], sizeof(char*)*(size_len[len]+1));
        size_sort[len][size_len[len]] = arr[i];
        size_len[len]++;
    }
    for(int i=0;i<50;i++){
        //sort by each size
        for(int j=0;j<size_len[i];j++){
            char* min = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
            int min_index;
            for(int k=j;k<size_len[i];k++){
                if(strcmp(size_sort[i][k],min)<0){
                    min = size_sort[i][k];
                    min_index = k;
                }
            }
            char *tmp = size_sort[i][j];
            size_sort[i][j] = min;
            size_sort[i][min_index] = tmp;
        }
    }
    for (int i = 0; i < 50; i++) {
        if (size_len[i] > 0) {
            printf("%s\n", size_sort[i][0]);
            for (int j = 1; j < size_len[i]; j++) {
                if (strcmp(size_sort[i][j], size_sort[i][j - 1]) != 0) {
                    printf("%s\n", size_sort[i][j]);
                }
            }
        }
    }
    for (int i = 0; i<n;i++){
        free(arr[i]);
    }
    free(arr);
    for(int i=0;i<50;i++){
        free(size_sort[i]);
    }
    free(size_sort);
    return 0;
}
