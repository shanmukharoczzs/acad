/*
 *      Algo -->  Stressens Algorithm
 *      Time Complexity --> O(n^2.81)
 *      Date : 18 Sept 
*/

#include<stdio.h>
#include<stdlib.h>

int stressen(int a, int b) {
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a == b)
        return a;
    if (a % 2 == 0) {
        if (b % 2 == 0)
            return stressen(a / 2, b / 2);
        else
            return stressen(a / 2, (b - 1) / 2);
    }
    if (a > b)
        return stressen((a - b), b);
    else
        return stressen((b - a), a);
}

int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("GCD of %d and %d is %d\n", a, b, stressen(a, b));
    return 0;
}