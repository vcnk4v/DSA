#include "functions.h"
int main() {
    int t;
    scanf("%d",&t);
    PtrNode Head=(PtrNode)malloc(sizeof(Node));
    Head->Element=0;
    Head->NextNode=NULL;
    while(t--){
        char s[6];
        scanf("%s",s);
        if(s[4]=='1'){
            int n;
            scanf("%d",&n);
            Insert(Head,n);
        }
        else if(s[4]=='2'){
            int n;
            scanf("%d",&n);
            Find(Head,n);
        }
        else if(s[4]=='3'){
            Print(Head);
            printf("\n");
        }
    }
    return 0;
}
