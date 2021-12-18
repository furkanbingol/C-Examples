#include <stdio.h>
#include <stdlib.h>
/*
Bir buz pateni karşılaşmasında bir yarışmacının performansı 6.00 üzerinden puanlanarak 10 hakem tarafından
değerlendirilmektedir. Yarışmacının performans puanı ise hakemlerin vermiş olduğu en düşük ve en yüksek puan atılıp,
geri kalan puanların aritmetik ortalaması alınarak bulunmaktadır. Yazacağınız programda yarışmacının
adı,soyadı,performans puanını hesaplayıp ekranda görüntüleyiniz. Performans hesaplamasını tek parametreli
bir fonksiyonda yapınız. Bu fonksiyon yarışmacıya ait yapıyı(structı) parametre olarak almalı ve performans
puanını hesaplayarak geri döndürmelidir.
*/

typedef struct yarismaci{
    char ad[30];
    char soyad[30];
    float puan[10];
}YARISMACI;

float puan_hesapla(YARISMACI y);

int main(){
    YARISMACI y;
    int i;
    float perf_puani;
    printf("-----PATEN YARISMASI-----\n\n");
    printf("Yarismacinin ismini giriniz: ");
    scanf("%s",&y.ad);
    printf("Yarismacinin soyadini giriniz: ");
    scanf("%s",&y.soyad);

    printf("\nHakem puanlarini giriniz(6.00 uzerinden): \n");
    for(i=0;i<10;i++){
        printf("%d.hakemin puanini giriniz: ",i+1);
        scanf("%f",&y.puan[i]);
    }

    perf_puani = puan_hesapla(y);
    printf("\nYarismacinin performans puani: %.3f",perf_puani);
    return 0;
}

float puan_hesapla(YARISMACI y){
    int i=0,c=0,k=0;
    float max,min,answer=0;
    max = y.puan[i];
    min = y.puan[i];

    for(i=1;i<10;i++){
        if(y.puan[i] > max)
            max = y.puan[i];
        
        if(y.puan[i] < min)
            min = y.puan[i];
        
    }
    for(i=0;i<10;i++){
        if(y.puan[i]==max && c==1)
            answer = answer + y.puan[i];
        
        if(y.puan[i]==min && k==1)
            answer = answer + y.puan[i];

        if(y.puan[i]==max && c==0)
            c++;
        
        if(y.puan[i]==min && k==0)
            k++;
        
        if(y.puan[i]!=max && y.puan[i]!=min)
            answer = answer + y.puan[i];
    }
    return (answer/8);
}
