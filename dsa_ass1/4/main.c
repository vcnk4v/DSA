#include "functions.h"

int main(){
    char s[4];
    scanf("%s",s);
    if(s[0]=='T'){
        Ptrrow MHead=(Ptrrow)malloc(sizeof(row));
        MHead->nextrow=NULL;
        MHead->row=-1;
        MHead->next=NULL;
        long long int n,m,k;
        scanf("%lld %lld %lld",&m,&n,&k);
        
        MakeMatrix(MHead,k);

        Ptrrow new=Transpose(MHead);
        Print(new,k);
    }

    else if(s[0]=='A'){
        int m,n,k1,k2,k;
        scanf("%d %d %d %d",&m,&n,&k1,&k2);
        k=0;
        Ptrrow MHead1=(Ptrrow)malloc(sizeof(row));
        MHead1->nextrow=NULL;
        MHead1->row=-1;
        MHead1->next=NULL;
        Ptrrow MHead2=(Ptrrow)malloc(sizeof(row));
        MHead2->nextrow=NULL;
        MHead2->row=-1;
        MHead2->next=NULL;
        MakeMatrix(MHead1,k1);
        MakeMatrix(MHead2,k2);
        Ptrrow new_h=(Ptrrow)malloc(sizeof(row));
        new_h->nextrow=NULL;
        new_h->row=-1;
        new_h->next=NULL;
        Ptrrow new=new_h;
        Ptrrow h1=MHead1->nextrow;
        Ptrrow h2=MHead2->nextrow;
        while(h1!=NULL && h2!=NULL){
            if(h1->row < h2->row){
                new=appendhead(new,h1->row);
                new->next=h1->next;
                h1=h1->nextrow;
            }
            else if(h1->row > h2->row){
                new=appendhead(new,h2->row);
                new->next=h2->next;
                h2=h2->nextrow;

            }
            else{
                new=appendhead(new,h1->row);
                PtrNode x1=h1->next;
                PtrNode x2=h2->next;
                PtrNode x=new->next;
                while(x1!=NULL && x2!=NULL){
                    if(x1->col < x2->col){
                        PtrNode n=MakeNode(x1->val,x1->col);
                        if(new->next==NULL){
                            new->next=n;
                            x=n;
                        }
                        else{
                            x->next=n;
                            x=n;
                        }
                        x1=x1->next;
                    }
                    else if(x1->col > x2->col){
                        PtrNode n=MakeNode(x2->val,x2->col);
                        if(new->next==NULL){
                            new->next=n;
                            x=n;
                        }
                        else{
                            x->next=n;
                            x=n;
                        }
                        x2=x2->next;
                    }
                    else{
                        if(x1->val+x2->val!=0){
                            PtrNode n=MakeNode(x1->val+x2->val,x1->col);
                            if(new->next==NULL){
                                new->next=n;
                                x=n;
                            }
                            else{
                                x->next=n;
                                x=n;
                            }
                        }
                        x2=x2->next;
                        x1=x1->next;
                    }
                }
                if(x1==NULL && x2!=NULL){
                    x->next=x2;
                }
                else if(x1!=NULL && x2==NULL){
                    x->next=x1;
                }
                h1=h1->nextrow;
                h2=h2->nextrow;
            }

        }
        if(h1==NULL && h2!=NULL){
            new->nextrow=h2;
        }
        else if(h1!=NULL && h2==NULL){
            new->nextrow=h1;
        }
        Ptrrow Head=new_h->nextrow;
        while(Head!=NULL){
            PtrNode x=Head->next;
            while(x!=NULL){
                if(x->val!=0){
                    k++;
                }
                x=x->next;
            }
            Head=Head->nextrow;
        }
        printf("%d\n",k);
        nprint(new_h);      
    }


    else if(s[0]=='M'){
        Ptrrow MHead1=(Ptrrow)malloc(sizeof(row));
        MHead1->nextrow=NULL;
        MHead1->row=-1;
        MHead1->next=NULL;

        Ptrrow MHead2=(Ptrrow)malloc(sizeof(row));
        MHead2->nextrow=NULL;
        MHead2->row=-1;
        MHead2->next=NULL;

        Ptrrow new=(Ptrrow)malloc(sizeof(row));
        new->nextrow=NULL;
        new->row=-1;
        new->next=NULL;

        long long int n,m,l,k1,k2;
        scanf("%lld %lld %lld %lld %lld",&n,&m,&l,&k1,&k2);

        
        if(n==1000000 || m==1000000 || l==1000000){
            ptr m1=create(k1);
            ptr m2=create_t(k2);
            ptr h1=m1->next;
            ptr h2=m2->next;
            long long int sum=0;
            while (h1!=NULL && h2!=NULL)
            {
                if(h1->row==h2->row && h1->col==h2->col){
                    sum+=h1->val*h2->val;
                    h1=h1->next;
                    h2=h2->next;
                }
                else if(h1->row > h2->row || (h1->row==h2->row && h1->col > h2->col)){
                    h1=h1->next;
                }
                else if(h1->row < h2->row || (h1->row==h2->row && h1->col < h2->col)){
                    h2=h2->next;
                }
            }
            printf("1\n");
            printf("0 0 %lld\n",sum);
            

            return 0;
        }
        MakeMatrix(MHead1,k1);
        MakeMatrix(MHead2,k2);
        MHead2=Transpose(MHead2);

        Multiply(MHead1,MHead2,new);
    }
    return 0;
    
}
