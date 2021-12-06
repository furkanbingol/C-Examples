#include <stdio.h>
#include <stdlib.h>
#define LIMIT 4000000
/*
1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
*/

int main(){
    int a=1,b=2,sum=2,tmp;

    tmp = a+b;
    while(tmp<LIMIT){
        if(tmp%2==0){
            sum += tmp;
        }
        a=b;
        b=tmp;
        tmp=a+b;
    }
    printf("Sum: %d",sum);
    return 0;
}
