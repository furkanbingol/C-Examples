#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
Kullanıcı tarafından iki süre bilgisi girilmektedir. Buna göre iki süre bilgisi arasındaki
farkı hesaplayınız.
*/

typedef struct zaman{
    int saniye;
    int dakika;
    int saat;
}ZAMAN;

void fark_suresi(ZAMAN t1,ZAMAN t2,ZAMAN *fark);

int main(){
    ZAMAN t1;
    ZAMAN t2;
    ZAMAN fark;

    printf("---Lutfen ilk zaman bilgisini giriniz---\n");
    printf("Ilk zamanin saniyesini giriniz: "); 
    scanf("%d",&t1.saniye);
    printf("Ilk zamanin dakikasini giriniz: "); 
    scanf("%d",&t1.dakika);
    printf("Ilk zamanin saatini giriniz: "); 
    scanf("%d",&t1.saat);
    printf("---------------------\n");
    printf("---Lutfen ikinci zaman bilgisini giriniz---\n");
    printf("Ikinci zamanin saniyesini giriniz: "); 
    scanf("%d",&t2.saniye);
    printf("Ikinci zamanin dakikasini giriniz: "); 
    scanf("%d",&t2.dakika);
    printf("Ikinci zamanin saatini giriniz: "); 
    scanf("%d",&t2.saat);

    fark_suresi(t1,t2,&fark);
    printf("\nZaman Farki(s:dk:sn)=  %d : %d : %d",fark.saat,fark.dakika,fark.saniye);      
    return 0;
}

void fark_suresi(ZAMAN t1,ZAMAN t2,ZAMAN *fark){
    int tmp1,tmp2;
    int saniye,dakika,saat=0;
    tmp1 = (t1.saat)*3600 + (t1.dakika)*60 + t1.saniye;
    tmp2 = (t2.saat)*3600 + (t2.dakika)*60 + t2.saniye;

    saniye = abs(tmp1-tmp2);
    dakika = saniye/60;
    saniye = saniye - dakika*60;
    while(dakika>=60){
        saat++;
        dakika-=60;
    }
    fark->saat = saat;
    fark->dakika = dakika;
    fark->saniye = saniye;
}
