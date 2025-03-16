#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int A[], int n , int val){
    n++;
    A[n] = val;
    int i = n;
    while(i > 1){
        int parent =  i/2;
        if(A[parent] < A[i]){
            swap(&A[parent],&A[i]);
            i = parent;
        }
        else{
            return;
        }
    }
}
void delete(int A[], int n){
    A[1] = A[n];
    n--;
    int i = 1;
    while(i <= n){
        int left = (2*i <= n) ? A[i * 2] : A[i];
        int right = (2*i+1 <= n) ? A[(i * 2) +1] : A[i];
        int large = left > right ? 2 * i : (2*i)+1;
        if((2*i <= n || 2*i+1 <= n) && A[i] < A[large]){
            swap(&A[i], &A[large]);
            i = large;
        }
        else{
            return;
        }
    }
}

int main(){
    int arr[10];
    int A[11];
    for(int i=0; i<10; i++){
        scanf("%d", &arr[i]);
    }

    for(int i = 0 ; i < 10 ; i++){
        insert(A,i+1,arr[i]);
    }
    for(int i = 1 ; i < 11 ; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    delete(A,10);
    for(int i = 1 ; i < 10 ; i++){
        printf("%d ", A[i]);
    }
}