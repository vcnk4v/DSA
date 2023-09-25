#include "functions.h"
extern int size;
int* IntersectionArray(int* Arr1 , int* Arr2, int lenArr1, int lenArr2){
    int* arr=(int*)malloc(sizeof(int)*lenArr1);
    
    int ind=0;
    int max=1;
    for(int i=0;i<lenArr1;i++){
        if(Arr1[i]>max){
            max=Arr1[i];
        }
    }
    for(int i=0;i<lenArr2;i++){
        if(Arr2[i]>max){
            max=Arr2[i];
        }
    }

    int intersection1[max+1];
    int intersection2[max+1];
    for(int i=0;i<=max;i++){
        intersection1[i]=0;
        intersection2[i]=0;    
    }

    for(int i=0;i<lenArr1;i++){
        intersection1[Arr1[i]]++;
    }
    
    for(int i=0;i<lenArr2;i++){
        intersection2[Arr2[i]]++;
    }

    for(int i=0;i<=max;i++){
        int freq=0;
        if(intersection1[i]>0 && intersection2[i]>0){
            if(intersection1[i]>intersection2[i]){
                freq=intersection2[i];
            }
            else{
                freq=intersection1[i];
            }
            while(freq--){
                arr[ind++]=i;
            }
        }
    }
    arr=(int*)realloc(arr,sizeof(int)*(ind));
    size=ind;
    return arr;
}
int countCharOccurrences(const char* str, int length, char ch){
    int count=0;
    for(int i=0;i<length;i++){
        if(str[i]==ch){
            count++;
        }
    }
    return count;
}
char findFirstNonRepeatingChar(const char* str, int length){
    char ch='.';
    int freq[256];
    for(int i=0;i<256;i++){
        freq[i]=0;
    }
    for(int i=0;i<length;i++){
        freq[str[i]]++;
    }
    for(int i=0;i<length;i++){
        if(freq[str[i]]==1){
            ch=str[i];
            break;
        }
    }
    return ch;
}
char* findLongestCommonPrefix(char** strs, int numStr, int maxLen){
    char* common=(char*)malloc(sizeof(char)*maxLen);
    int count=0;

    int min_len=maxLen;
    for(int i=0;i<numStr;i++){
        int len=0;
        int j=0;
        while(strs[i][j++]!='\0'){
                len++;
        }
        if(len<min_len){
            min_len=len;
        }
        
    }

    for(int i=0;i<min_len;i++){
        for(int j=0;j<numStr-1;j++){
            if(strs[j][i]!=strs[j+1][i]){
                common[i]='\0';
                return common;
            }
        }
        common[i]=strs[0][i];
        count++;
    }
    common=(char*)realloc(common,sizeof(char)*count);
    return common;
}

char* removeSubstring(char* str, int strLength, const char* substr, int substrLength){
    char* new = (char*)malloc(sizeof(char)*(strLength-substrLength+1));
    int index=0;
    
    for(int i=0;i<strLength;i++){
        int fl=0;
        for(int j=0;j<substrLength;j++){
            if(str[i+j]!=substr[j]){
                fl=1;
                break;
            }
        }
        if(fl==1){
            new[index++]=str[i];
        }
        else{
            i+=substrLength-1;
        }
    }
    new[index++]='\0';
    return new;

}
int* maxMin(int* arr , int lenArr){
    int* newarr1=(int*)malloc(sizeof(int)*lenArr);
    int* newarr2=(int*)malloc(sizeof(int)*lenArr);
    int index1=0,index2=0;
    int max=arr[0];
    int min=arr[lenArr-1];
    newarr1[index1++]=0;
    newarr2[index2++]=lenArr-1;
    for(int i=0;i<lenArr;i++){
        if(arr[i]>max){
            newarr1[index1++]=i;
        }
        if(arr[i]>max){
            max=arr[i];
        }
    }
    for(int i=lenArr-1;i>=0;i--){
        if(arr[i]<min){
            newarr2[index2++]=i;
        }
        if(arr[i]<min){
            min=arr[i];
        }
    }
    int *new=IntersectionArray(newarr1,newarr2,index1,index2);
    

    return new;

}