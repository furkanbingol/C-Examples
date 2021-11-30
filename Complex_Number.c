#include <stdio.h>
#include <stdlib.h>
//Complex Number -- a+bi

typedef struct{
    float a;
    float b;
}complex;

int main(){
    complex n1;
    complex n2;
    complex sonuc;
    char op;
    printf("Birinci karmasik sayiyi giriniz: ");
    scanf("%f%f",&n1.a,&n1.b);
    printf("Ikinci karmasik sayiyi giriniz: ");
    scanf("%f%f",&n2.a,&n2.b);

    printf("Operator giriniz(+ -): ");
    scanf(" %c",&op);
    
    if(op=='+'){
        sonuc.a = n1.a + n2.a;
        sonuc.b = n1.b + n2.b;
        if(sonuc.b>=0){
            printf("Sonuc: %.2f+%.2fi",sonuc.a,sonuc.b);
        }
        else{
            printf("Sonuc: %.2f%.2fi",sonuc.a,sonuc.b);
        }
    }
    else if(op=='-'){
        sonuc.a = n1.a - n2.a;
        sonuc.b = n1.b - n2.b;
        if(sonuc.b>=0){
            printf("Sonuc: %.2f+%.2fi",sonuc.a,sonuc.b);
        }
        else{
            printf("Sonuc: %.2f%.2fi",sonuc.a,sonuc.b);
        }
    }
    else{
        printf("Gecersiz operator girdiniz!");
    }
    return 0;
}
