#include <stdio.h>
#include <stdlib.h>
/*
Masa tenisi turnuvası düzenlenmekte. Her ekibin bir adı var ve her ekip 2 adet oyuncudan oluşmakta
Oyuncuların adını soyadını ve yaşını tutan bir struct yapısı oluşturun.
Ekiplere ait ekibin adını,ilk oyuncuyu ve ikinci oyuncuyu tutan bir struct yapısı oluşturun.
Oyuncuların karakteristik özelliklerini tanımlayan bir fonksiyon yazın.(bu fonksiyonu degiskenin adresini cagirma ile yapiniz)
Ekiplerin karakterisik özelliklerini tanımlayan bir fonksiyon yazın.(bu fonksiyonu degiskenin adresini cagirma ile yapiniz)
Tanımladığınız oyuncuları ve ekipleri ekrana bastırmak için ayrı ayrı iki adet fonksiyon yazınız.
Yukarıdaki fonksiyonları kullanarak N ekip içeren ve bunları ekrana bastıran programı yazınız.
*/

typedef struct oyuncu{
    char ad[20];
    char soyad[20];
    int yas;
}OYUNCU;

typedef struct ekip{
    char ad[20];
    OYUNCU o1;
    OYUNCU o2;
}EKIP;

void ekip_olustur(EKIP *e,int N);
void ekip_bastir(EKIP *e,int N);

int main(){
    int N,i;
    printf("Ekip sayisini giriniz: ");
    scanf("%d",&N);
    EKIP e[N];

    printf("\n");
    ekip_olustur(e,N);
    ekip_bastir(e,N);
    return 0;
}

void ekip_olustur(EKIP *e,int N){
    int i;
    for(i=0;i<N;i++){
        printf("Ekip %d: \n",i+1);
        printf("Ekibin adini giriniz: "); scanf("%s",&e[i].ad);
        printf("Oyuncu 1: \n");
        printf("Ismi giriniz: "); scanf("%s",&e[i].o1.ad);
        printf("Soyismi giriniz: "); scanf("%s",&e[i].o1.soyad);
        printf("Yasi giriniz: "); scanf("%d",&e[i].o1.yas);
        printf("Oyuncu 2: \n");
        printf("Ismi giriniz: "); scanf("%s",&e[i].o2.ad);
        printf("Soyismi giriniz: "); scanf("%s",&e[i].o2.soyad);
        printf("Yasi giriniz: "); scanf("%d",&e[i].o2.yas);
        printf("\n");
    }
}

void ekip_bastir(EKIP *e,int N){
    int i;
    for(i=0;i<N;i++){
        printf("Ekip %d: \n",i+1);
        printf("Ekip adi: %s\n",e[i].ad);
        printf("Oyuncu 1: \n");
        printf("\tisim: %s\n\tsoyisim: %s\n\tyas: %d\n",e[i].o1.ad,e[i].o1.soyad,e[i].o1.yas);
        printf("Oyuncu 2: \n");
        printf("\tisim: %s\n\tsoyisim: %s\n\tyas: %d\n\n",e[i].o2.ad,e[i].o2.soyad,e[i].o2.yas);
    }
}
