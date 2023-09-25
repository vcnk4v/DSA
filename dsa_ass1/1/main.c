#include "functions.h"

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        char operation[6];
        scanf("%s",operation);
        if(operation[4]=='1'){
            scanf("%d",&n);
            char str[n];
            scanf("%s",str);
            reverseString(str,n);
            printf("%s\n",str);
        }
        else if(operation[4]=='2'){
            scanf("%d",&n);
            char str[n];
            scanf("%s",str);
            char* c_str = compressString(str,n);
            printf("%s\n",c_str);
            free(c_str);
        }
        else if (operation[4]=='3')
        {
            int count=0;
            scanf("%d",&n);
            int arr[n];
            for(int i=0;i<n;i++){
                scanf("%d",&arr[i]);
            }
            int* new=uniqueElements(arr,n);
            int index=0;
            int max=-1;
            for(int i=0;i<n;i++){
                if(arr[i]>max){
                    max=arr[i];
                }
            }
            int freq[max+1];
            for(int i=0;i<max+1;i++){
                freq[i]=0;
            }
            for(int i=0;i<n;i++){
                if(freq[arr[i]]==0){
                    count++;
                    freq[arr[i]]=1;
                }
            }
            for(int i=0;i<count;i++){
                printf("%d ",new[i]);
            }
            printf("\n");
        }
        else if(operation[4]=='4'){
            int R,C;
            scanf("%d %d",&R,&C);
            int** new_matrix=(int**)malloc(R*(sizeof(int*)));
            for(int i=0;i<R;i++){
                new_matrix[i]=(int*)malloc(C*sizeof(int));
            }
            for(int i=0;i<R;i++) {
                for(int j=0;j<C;j++)
 {
    scanf("%d",&new_matrix[i][j]);
    
 }
}
           int** ptr=transpose(new_matrix,R,C);
            for(int i=0;i<C;i++){
                for(int j=0;j<R;j++){
                    printf("%d ",ptr[i][j]);
                }
                printf("\n");
            }
            for(int i=0;i<C;i++)
            {
                 free(ptr[i]);
}free(ptr);
for(int i=0; i < R ; i ++){
free(new_matrix[i]);}
free(new_matrix);
        }
    }
}