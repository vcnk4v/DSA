#include "functions.h"

int* uniqueElements(int* arr, int length){
    int* new=(int*)malloc(sizeof(int)*(length+1));
    int index=0;
    int max=-1;
    for(int i=0;i<length;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    int freq[max+1];
    for(int i=0;i<max+1;i++){
        freq[i]=0;
    }
    for(int i=0;i<length;i++){
        if(freq[arr[i]]==0){
            new[index++]=arr[i];
            freq[arr[i]]=1;
        }
    }
    new=(int*)realloc(new,sizeof(int)*(index));
    return new;
}
void reverseString(char* str, int length){
    char arr[length+1];
    for(int i=0;i<=length;i++){
        arr[i]=str[i];
    }
    for(int i=0;i<length;i++){
        str[i]=arr[length-i-1];
    }
}

char* compressString(char* str, int length){
    char* c_str=(char*)malloc(sizeof(char)*2*length);
    int count;
    char c[10000];
    int index=0;
    for(int i=0;i<length;i++){
        count=1;
        c_str[index++]=str[i];
        for(int j=i+1;j<length;j++){
            if(str[i]==str[j]){
                count++;
                i++;
            }
            else{
                break;
            }
        }
        sprintf(c,"%d",count);
        int k=0;
        while(c[k]!='\0'){
            c_str[index++]=c[k++];
        }
    }
    c_str[index]='\0';
    return c_str;
}
int** transpose(int** matrix , int NumRow , int NumCol){
    int** ptr=(int**)malloc(NumCol*(sizeof(int*)));
    for(int i=0;i<NumCol;i++){
        ptr[i]=(int*)malloc(NumRow*sizeof(int));
    }
    for(int i=0;i<NumCol;i++){
        for(int j=0;j<NumRow;j++){
            ptr[i][j]=matrix[j][i];
        }
    }
    return ptr;
}
