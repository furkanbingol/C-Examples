#include <stdio.h>
#include <math.h>
#define K 600851475143
/*
The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?
*/

int prime(int n){
    int i;
    for(i=3;i<n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int max_prime,i;

    for(i=3;i<sqrt(K);i+=2){
        if((K%i==0)&&(prime(i))){
            max_prime = i;
        }
    }
    printf("Largest prime factor of the number 600851475143 : %d",max_prime);
    return 0;
}
