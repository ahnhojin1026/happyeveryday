#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int partition (char** arr, int* arr_n, int p, int r){
    int low, high;
    int pivot = arr_n[p];

    low = p+1;
    high = r;

    while(low <= high){
        while(low <= r && arr_n[low] <= pivot) low++; // pivot 보다 작은 값이 나올때마다 이동
        while(high >= p + 1 && arr_n[high] > pivot) high--; // pivot 보다 큰 값이 나올때마다 이동
 
        if (low <= high){ // low와 high 가 중단된 지점이 서로 위치가 역전된 지점이 아니라면
            char* temp = arr[low];    // low 와 high 의 값 변경
            arr[low] = arr[high];
            arr[high] = temp;
            int temp_n = arr_n[low];    // low 와 high 의 값 변경
            arr_n[low] = arr_n[high];
            arr_n[high] = temp_n;
        }
    }
    // 피벗과 high 위치 교환
    int temp_n = arr_n[p];
    arr_n[p] = arr_n[high];
    arr_n[high] = temp_n;
    char* temp = arr[p];
    arr[p] = arr[high];
    arr[high] = temp;

    return high; // 피벗 위치 반환
}
int partition1 (char** arr, int* arr_n, int p, int r){
    int low, high;
    char* pivot = arr[p];

    low = p+1;
    high = r;

    while(low <= high){
        while(low <= r && strcmp(arr[low],pivot)<=0) low++; // pivot 보다 작은 값이 나올때마다 이동
        while(high >= p + 1 && strcmp(arr[high],pivot)>0) high--; // pivot 보다 큰 값이 나올때마다 이동
 
        if (low <= high){ // low와 high 가 중단된 지점이 서로 위치가 역전된 지점이 아니라면
            char* temp = arr[low];    // low 와 high 의 값 변경
            arr[low] = arr[high];
            arr[high] = temp;
            int temp_n = arr_n[low];    // low 와 high 의 값 변경
            arr_n[low] = arr_n[high];
            arr_n[high] = temp_n;
        }
    }
    // 피벗과 high 위치 교환
    int temp_n = arr_n[p];
    arr_n[p] = arr_n[high];
    arr_n[high] = temp_n;
    char* temp = arr[p];
    arr[p] = arr[high];
    arr[high] = temp;

    return high; // 피벗 위치 반환
}

void quick_sort(char** arr, int* arr_n, int left, int right, int mode){
    if(left < right){
        // printf("start quick (%d %d)\n",left, right);
        int pivot;
        if(mode == 0){
            pivot = partition(arr,arr_n,left,right);
        }
        else{
            pivot = partition1(arr,arr_n,left,right);
        }

        quick_sort(arr,arr_n,left,pivot-1,mode);
        quick_sort(arr,arr_n,pivot+1,right,mode);
    }
}

int main () {
    int MAX_STRING_LEN = 50;
    int n;
    scanf("%d",&n);
    char** arr = (char **) malloc(sizeof(char*)*n);
    int* arr_n = (int *) malloc(sizeof(int)*n);
    //first get the inputs by length
    for (int i = 0; i<n;i++){
        arr[i] = (char*) malloc(MAX_STRING_LEN * sizeof(char));
        scanf("%s", arr[i]);
        arr_n[i] = strlen(arr[i]);
    }
    //first sort by strlen
    quick_sort(arr,arr_n,0,n-1,0);
    int start = 0;
    int end = 0;
    while(start < n){
        end = start;
        while(arr_n[start] == arr_n[end]){
            end++;
        }
        quick_sort(arr,arr_n,start,end-1,1);
        start = end;
    }
    for(int i=0;i<n;i++){
        if(n != 1 && i != n-1){
            if(strcmp(arr[i],arr[i+1])!=0){
                printf("%s\n",arr[i]);
            }
        }
        else{
            printf("%s\n",arr[i]);
        }
        free(arr[i]);
    }
    free(arr);
    free(arr_n);

    return 0;
}
