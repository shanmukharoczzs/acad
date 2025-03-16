//SHANNU

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define p printf
#define FOR(x) for(int i=0;i<x;i++)
#define FOR2(a,b) for(int i=a;i<b;i++)
#define FOR3(a,b,c) for(int i=a;i<=b;i+=c)
#define FORR(a) for(int i=a;i>=0;i--)
#define long long ll;
void getArray(int size){
   ll arr[size];
   FOR(size){
   scanf("%lld",&arr[i]);
}
}
void printArray(ll *arr , ll size ){
   FOR(size){
       printf("%lld ",arr[i]);
   }
}
void swap(ll *a , ll *b){
   ll temp = *a;
   *a = *b;
   *b = temp;
}
int main() {
    ll arr,size;
    printf("Enter the size\n");
    scanf("%lld" ,&size);
    getArray(size);
    printArray(arr,size);
    return 0;
}