#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int IsSorted(int* array,int n){
    if(n==0||n==1){
        return 1;
    }

    if(array[0]<array[1] && IsSorted(array+1, n-1)){
        return 1;
    }
    return 0;
}

int FirstOcc(int* array,int n,int key){
    if(n==0)    return-1;
    if(array[0]==key)   return 0;
    int sub = FirstOcc(array+1,n-1,key);
    if(sub!=-1){
        return sub+1;
    }
    return -1;
}

int lastOcc(int* array,int n,int key){
    int c=0;
    if(n==0)    return-1;
    int sub = lastOcc(array+1,n-1,key);
    if(sub==-1){
        if(array[0]==key){
        return 0;
        }
        return -1;
    }
    return sub+1;
}

void BubbleSort(int* array,int n,int ){
    if(n==0||n==1){
        return;
    }
    BubbleSort(array+1,n-1);
    if(array[0]<array[1]){
        return;
    }
    else{
        int t = array[0];
        array[0] = array[1];
        array[1] = t;
        return;
    }
}

void MergeSort(int *array ,int start,int end){
    if(start>=end){
        return;
    }
    int mid = (start+end) >> 1;
    MergeSort(array,start,mid);
    MergeSort(array,mid+1,end);
    

}

void merge(int array,int start,int end){
    int i=start;
    int j=mid+1;
    int k=0;
    int DumArray[100];
    int Dsize =0;

    while (i<=mid && j<=end){
        if(array[i]<array[j]){
            DumArray[k++]=array[i++];
            Dsize++;
        }
        else{
            DumArray[k++]=array[j++];
            Dsize++;
        }
    }
    while(j<=end){
        DumArray[k++]=array[j++];
        Dsize++;
    }
    while(i<=mid){
        DumArray[k++]=array[i++];
        Dsize++;
    }
    printArray(array,Dsize);
}

void printArray(int *array,int n){
    for(int i=0;i<n;i++){
        printf("%d ",array[i]);
    }
}
int main() {
    int array[5]={5, 4, 3, 2, 1}; 
    MergeSort(array,5);
    
    return 0;
}