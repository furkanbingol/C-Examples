#include <stdio.h>
/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
What is the 10001st prime number?
*/

int prime(int n){
    int i;
    if(n==2){
        return 1;
    }
    for(i=2;i<n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int count=0,i=2;
    int answer;

    while(count!=10001){
        if(prime(i)){
            count++;
        }
        i++;
    }
    answer = i-1;
    printf("10001st prime number: %d",answer);
    return 0;
}
