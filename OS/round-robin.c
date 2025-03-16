/*
 *            Author : Shannu
 *            Topic:   Round Robin Scheduling
 *            Date   : 3rd - March - 2025
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define p printf
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
    int n, quantum;
    int at[10], bt[10], rem_bt[10], wt[10], tat[10], ct[10];
    float totaltat =0, totalwt = 0;
    printf("Enter the total number of processes: ");
    scanf("%d", &n);
    printf("Enter the arrival time and burst time for each process:\n");

    FOR(n){
        printf("Process[%d]\n", i+1);
        printf("Arrival time: ");
        scanf("%d", &at[i]);
        printf("Burst time: ");
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
    }
    
    printf("Enter the Time Quntum: ");
    scanf("%d", &quantum);

    int t = 0;
    int done = 0;
    while (1){
        done = 1;
        FOR(n){
            if (at[i] <= t && rem_bt[i] > 0){
                done = 0;
                if(rem_bt[i] > quantum){
                    t += quantum;
                    rem_bt[i] -= quantum;
                }
                else{
                    t += rem_bt[i];
                    ct[i] = t;
                    wt[i] = ct[i] - at[i] - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if(done)break;
    }

    FOR(n){
        tat[i] = bt[i] + wt[i];
        totaltat += tat[i];
        totalwt += wt[i];
    }
    printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\t\n");
    FOR(n){
        printf("P[%d]\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("\n Avarage turnaround time: %.2f\n", totalwt/n);
    printf("\n Avarage waiting time: %.2f\n", totaltat/n);
    
    return 0;
}