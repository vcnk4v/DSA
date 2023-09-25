#include "functions.h"
int size;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char s[6];
        scanf("%s",s);
        if(s[4]=='1'){
            int n1,n2;
            scanf("%d %d",&n1,&n2);
            int arr1[n1];
            int arr2[n2];
            for(int i=0;i<n1;i++){
                scanf("%d",&arr1[i]);
            }
            for(int i=0;i<n2;i++){
                scanf("%d",&arr2[i]);
            }
            int* arr=IntersectionArray(arr1,arr2,n1,n2);


            if(size==0){
                printf("-1\n");
                continue;
            }
            for(int i=0;i<size;i++){
                printf("%d ",arr[i]);
            }
            printf("\n");
        }
        else if(s[4]=='2'){
            int n;
            scanf("%d",&n);
            char str[n];
            scanf("%s",str);
            char ch;
            scanf("%c",&ch);
            scanf("%c",&ch);
            int count=countCharOccurrences(str,n,ch);
            printf("%d\n",count);
        }
        else if(s[4]=='3'){
            int n;
            scanf("%d",&n);
            char str[n];
            scanf("%s",str);
            char ch = findFirstNonRepeatingChar(str,n);
            if(ch=='.'){
                printf("-1\n");
            }
            else{
                printf("%c\n",ch);
            }
        }
        else if(s[4]=='4'){
            int n;
            scanf("%d",&n);
            char c[n][100];
            int maxlen=0;
            int ni[n];
            for(int i=0;i<n;i++){
                scanf("%d %s",&ni[i],c[i]);
                if(ni[i]>maxlen){
                    maxlen=ni[i];
                }
            }
            char* ptr[n];
            for(int i=0;i<n;i++){
                ptr[i]=c[i];
            }
            char** str_ptr=ptr;
            char* new=findLongestCommonPrefix(str_ptr,n,maxlen);
            int fl=0;
            for(int i=0;i<n-1;i++){
                if(c[i][0]!=c[i+1][0]){
                    fl=1;
                    break;
                }
            }
            if(fl==1){
                printf("-1\n");
            }
            else{
                printf("%s\n",new);
            }
        }
        else if(s[4]=='5'){
            int n;
            scanf("%d",&n);
            int arr[n];
            for(int i=0;i<n;i++){
                scanf("%d",&arr[i]);
            }
            int* new=maxMin(arr,n);
            int i;
            if(size==0){
                printf("-1\n");
                continue;
            }
            for(int i=0;i<size;i++){
                printf("%d ",new[i]);
            }
            printf("\n");
        }
        else if(s[4]=='6'){
            int n,m;
            scanf("%d %d",&n,&m);
            char str[n];
            char substr[m];
            scanf("%s",str);
            scanf("%s",substr);
            
            char* new=removeSubstring(str,n,substr,m); 
            if(n<=m || new[0]=='\0'){
                printf("-1\n");
                continue;
            }
            int i=0;
            while(new[i]!='\0'){
                printf("%c",new[i++]);
            }
            printf("\n");
        }
    } 
    return 0;
}