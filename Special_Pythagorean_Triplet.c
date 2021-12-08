#include <stdio.h>
/*
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which, a^2 + b^2 = c^2
For example; 3^2 + 4^2 = 5^2
There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

int main(){
    int a,b,c,answer;
    
    for(a=0;a<333;a++){
        for(b=0;b<500;b++){
            for(c=0;c<1000;c++){
                if((a<b<c) && ((a*a)+(b*b)==(c*c)) && (a+b+c==1000)){
                    answer = a*b*c;
                    break;
                }
            }
        }
    }
    printf("Answer: %d",answer);
    return 0;
}
