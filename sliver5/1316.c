#include <stdio.h>
#include <string.h>


int main(){
    int n, cnt=0;
    scanf("%d", &n);
    char text[100];
    for(int i=0; i<n; i++){
        char text_log[100];
        int log_num=0;
        int groupflag = 0;
        scanf("%s",text);
        if(strlen(text)==1){
            cnt++;
            continue;
        }
        for(int j=0;j<strlen(text);j++){
            
            if(j == 0) {
                text_log[j] = text[j];
                log_num++;
            }
            else if(text[j] == text[j-1]){
                
            }
            else{
                for(int k=0;k<log_num;k++){
                    if(text_log[k] == text[j]){
                        groupflag = 1;
                        break;
                    }
                }
                if(groupflag == 0){
                    text_log[log_num] = text[j];
                    log_num++;
                }
            }
        }
        if(groupflag == 0){
            cnt++;
        }
        //cnt++
    }
    printf("%d",cnt);
    return 0;
}