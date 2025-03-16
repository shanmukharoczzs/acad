/*
*       Author : Shannu
*       Date   : 09-11-2024
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void conquer(int *arr, int s, int mid, int e){
    int merged[e-s+1];
    int idx1 = s;
    int x = 0;
    int idx2 = mid+1;

    while(idx1<=mid && idx2<=e){
        if(arr[idx1]<arr[idx2]){
            merged[x++] = arr[idx1++];
        }

        else{
            merged[x++] = arr[idx2++];
        }
    }

    while(idx1<=mid){
        merged[x++] = arr[idx1++];
    }

    while(idx2<=e){
        merged[x++] = arr[idx2++];
    }

    for(int i = 0, j = s; i<sizeof(merged)/sizeof(merged[0]); i++, j++){
        arr[j] = merged[i];
    }

}

void merge(int *arr, int s, int e){
    if(s<e){
        int mid = (s+e)/2;
        merge(arr, s, mid);
        merge(arr, mid + 1 , e);
        conquer(arr, s, mid, e);
    }
}

int main() {

    int arr[8] = {3,4,6,7,99,93,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    merge(arr, 0, n-1);
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}