#include <stdio.h>
#include <stdlib.h>
#define MAX 50
/*
Adres defteri adında bir struct tanımlayınız. Tutulacak bilgiler ad,soyad,tel,adres,posta kodu şeklindedir.
Buna göre N adet kişinin bilgisini bir structta tutan C programını yazınız.
*/

typedef struct adres{
    char ad[MAX];
    char soyad[MAX];
    char tel[MAX];
    char adres[MAX];
    int posta_kodu;
}ADRES;

void degerAl(ADRES *a,int N);
void degerBastir(ADRES *a,int N);

int main(){ 
    ADRES *a;
    int N;
    printf("Kisi sayisini giriniz: ");
    scanf("%d",&N);
    printf("\n");

    a = (ADRES*)malloc(N*sizeof(ADRES));
    if(a==NULL){
        printf("Bellek ayrilamadi!");
        return -1;
    }

    degerAl(a,N);
    degerBastir(a,N);
    free(a);
    return 0;
}

void degerAl(ADRES *a,int N){
    int i;
    for(i=0;i<N;i++){
        printf("Kisinin adini giriniz: ");
        scanf("%s",&a[i].ad);
        printf("Kisinin soyadini giriniz: ");
        scanf("%s",&a[i].soyad);
        printf("Kisinin tel numarasini giriniz: ");
        scanf("%s",&a[i].tel);
        printf("Kisinin adresini giriniz: ");
        scanf("%s",&a[i].adres);
        printf("Kisinin posta kodunu giriniz: ");
        scanf("%d",&a[i].posta_kodu);
        printf("\n");
    }
}

void degerBastir(ADRES *a,int N){
    int i;
    for(i=0;i<N;i++){
        printf("%d. kisinin adi: %s\n",i+1,a[i].ad);
        printf("%d. kisinin soyadi: %s\n",i+1,a[i].soyad);
        printf("%d. kisinin tel numarasi: %s\n",i+1,a[i].tel);
        printf("%d. kisinin adresi: %s\n",i+1,a[i].adres);
        printf("%d. kisinin posta kodu: %d\n",i+1,a[i].posta_kodu);
        printf("\n");
    }
}
