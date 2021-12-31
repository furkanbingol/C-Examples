#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Meyve structı tanımlayınız. Meyvelerin adi,agirligi,formu(yuvarlak/kare/dikdortgen),kaç tane meyve olduğunu
ve birim fiyatını tanımlayınız.
Sepet structı tanımlayınız. İçinde iki farklı meyve olsun.
2 adet fonksiyon yazınız. Bu fonksiyonlar sayesinde sepetin ve meyvelerin özelliklerini kullanıcı girsin.
Total Fiyat hesaplayan bir fonksiyon yazınız. Total Agirlik hesaplayan bir fonksiyon yaziniz. Sonucu adresle gönderin.
(Meyvenin formu "yuvarlak" ise 2 kat fiyat ödenir ve eğer meyvenin agirligi 200gr+ ise 3tl fiyata eklenir)
Çıktı olarak Toplam Agirlik ve Toplam Fiyatı bastiriniz.
*/

typedef struct meyve{
    char ad[20];
    float agirlik;
    char form[20];
    int adet;
    float fiyat;
}MEYVE; 

typedef struct sepet{
    MEYVE m[2];
}SEPET;

void sepet_olustur(SEPET *s);
void meyve_olustur(MEYVE *m);
void fiyat_hesapla(SEPET *s,float *f);
void agirlik_hesapla(SEPET *s,float *a);

int main(){
    SEPET s;
    float Tfiyat,Tagirlik;
    sepet_olustur(&s);
    agirlik_hesapla(&s,&Tagirlik);
    fiyat_hesapla(&s,&Tfiyat);
    
    printf("Toplam Agirlik: %.3f\n",Tagirlik);
    printf("Toplam Fiyat: %.3f\n",Tfiyat);
    return 0;
}

void sepet_olustur(SEPET *s){
    int i;
    for(i=0;i<2;i++){
        meyve_olustur(&s->m[i]);
    }
}

void meyve_olustur(MEYVE *m){
    printf("Meyvenin adini giriniz: "); scanf("%s",&m->ad);          
    printf("Meyvenin agirligini giriniz: "); scanf("%f",&m->agirlik);
    printf("Meyvenin formunu giriniz(yuvarlak/kare/dikdortgen): "); scanf("%s",&m->form);
    printf("Meyveden kac adet oldugunu giriniz: "); scanf("%d",&m->adet);
    printf("Meyvenin fiyatini giriniz: "); scanf("%f",&m->fiyat);
    printf("\n");
}

void fiyat_hesapla(SEPET *s,float *f){
    char c[15] = "yuvarlak";
    if(!strcmp(s->m[0].form,c)){
        s->m[0].fiyat *= 2;
    }
    if(!strcmp(s->m[1].form,c)){
        s->m[1].fiyat *= 2;
    }
    if(s->m[0].agirlik > 200){
        s->m[0].fiyat += 3;
    }
    if(s->m[1].agirlik > 200){
        s->m[1].fiyat += 3;
    }
    (*f) = (s->m[0].fiyat * s->m[0].adet) + (s->m[1].fiyat * s->m[1].adet);
}

void agirlik_hesapla(SEPET *s,float *a){
    (*a) = (s->m[0].agirlik * s->m[0].adet) + (s->m[1].agirlik * s->m[1].adet);
}
