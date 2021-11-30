#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int derece;
    double katsayi;
}TERIM;

typedef struct{
    TERIM *terimler;
    int terimsayisi;
}POLINOM;


int main(){
    srand(time(NULL));
    int N,i;
    POLINOM p1;
    printf("Terim Sayisi giriniz: ");
    scanf("%d",&N);

    p1.terimsayisi = N;
    p1.terimler = (TERIM*)malloc(p1.terimsayisi*sizeof(TERIM));

    for(i=0;i<p1.terimsayisi;i++){
        p1.terimler[i].derece = i;
        p1.terimler[i].katsayi = rand()%10;
    }
    for(i=0;i<p1.terimsayisi;i++){
        if(i==p1.terimsayisi-1){
            printf("%.2lf X^%d",p1.terimler[i].katsayi,p1.terimler[i].derece);
        }
        else{
            printf("%.2lf X^%d + ",p1.terimler[i].katsayi,p1.terimler[i].derece);
        }
    }
    
    return 0;
}
