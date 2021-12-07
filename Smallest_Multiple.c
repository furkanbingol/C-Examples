#include <stdio.h>
/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

int prime(int n){
    int i;
    if(n==2){
        return 1;
    }
    else{
        for(i=2;i<n;i++){
            if(n%i==0){
                return 0;
            }
        }
        return 1;
    }
}

int main(){
    int i,sum=1;

    for(i=2;i<=20;i++){
        if(prime(i)){
            sum *= i;
        }
    }
    sum *= 24;  // 9=3*(3), 16=2*(2*2*2)
    printf("Sum: %d",sum);
    return 0;
}
