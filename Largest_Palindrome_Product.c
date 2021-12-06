#include <stdio.h>
/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 x 99.
Find the largest palindrome made from the product of two 3-digit numbers.
*/

int palindrome(int n){
    int reversed=0,remainder;
    int tmp=n;

    while(tmp>0){   
        remainder = tmp%10;
        reversed = reversed*10 + remainder; 
        tmp = tmp/10;
    }
    if(reversed==n){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int i,j,tmp;
    int max_palindrome=0;

    for(i=999;i>=500;i--){
        for(j=999;j>=500;j--){
            if(palindrome(i*j)){
                tmp = i*j;
            }
            if(tmp>max_palindrome){
                max_palindrome = tmp;
            }
        }
    }
    printf("Largest palindrome made from the product of two 3-digit numbers: %d",max_palindrome);
    return 0;
}
