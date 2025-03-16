//SHANNU


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define FOR(x) for(int i=0;i<x;i++)
#define FOR2(a,b) for(int i=a;i<b;i++)
#define FOR3(a,b,c) for(int i=a;i<=b;i+=c)
#define FORR(a) for(int i=a;i>=0;i--)
typedef long long ll;

void getArray(int size){
   ll arr[size];
   FOR(size){
       scanf("%d",&arr[i]);
   }
}

void printArray(int *arr, int size){
   FOR(size){
       printf("%d ",arr[i]);
   }
}

void swap(ll *a , ll *b){
   ll temp = *a;
   *a = *b;
   *b = temp;
}

int main() {
   
    return 0;
}