#include <stdio.h>
#include <math.h>
/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below two million.
*/

int main(){
    unsigned long long int sum=0;
    int i,j;
    static int numbers[2000000];

    numbers[0] = numbers[1] = 0;
    for(i=2;i<2000000;i++){
        numbers[i] = 1;
    }

    for(i=2;i<sqrt(2000000);i++){
        if(numbers[i] == 1){
            for(j=i;(j*i)<2000000;j++){
                numbers[i*j] = 0;
            }
        }
    }

    for(i=0;i<2000000;i++){
        if(numbers[i] == 1){
            sum += i;
        }
    }   
    printf("Answer: %llu",sum);
    return 0;
}
