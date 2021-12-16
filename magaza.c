#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

/*
Struct yapısında mağaza listesi oluşturun.Her bir mağazanın adı,sokak ismi,mahallesi,telefon numarası,satış tutarı struct yapısının içinde tanımlayın.
Her mağazada 3 işçi çalışmakta.İşcilerin de struct yapısı içinde adını soyadını ve yaşını belirtin
Her bir mağazada 5 ürün satılmakta.Her ürünün kendine özel referans kodu ve fiyatı bulunmaktadır.
Bu üç mağaza işçi ve ürün için struct yapısını oluşturun. 
2 adet fonksiyon yazın. 
Birincisi her bir ürünün içini doldursun. 
ikincisi her işçiyi doldursun. 
Bu iki fonksiyonu kullanarak yeni bir fonksiyonda mağazanın içini doldursun. 
Doldurduğumuz değerleri mağaza,işçi ve ürün için ayrı ayrı bastıran 3 fonksiyon yazın. 
En yaşlı işçiyi ekrana bastıran fonksiyon yazın. 
Her bir mağazadaki ortalama ürün fıyatını bastıran fonksiyon yazın. 
Mağazanın bulunduğu mahalleyi bastıran bir fonksiyon yazın. 
En fazla satış rakamına sahip olan mağazayı ekrana bastıran bir fonksiyon yazın. 
Yukarıdaki fonksiyonları kullanarak 2 adet mağaza için aşagıdaki şekilde derlenen bir C programı yazın. 
*/

typedef struct urun{
    int id;
    float fiyat;
}URUN;

typedef struct isci{
    char ad[MAX];
    char soyad[MAX];
    int yas;
}ISCI;

typedef struct magaza{
    char ad[MAX];
    char sokak[MAX];
    char mahalle[MAX];
    char telefon[MAX];
    int satis;
    ISCI k[3];
    URUN u[5];
}MAGAZA;

void magaza_olustur(MAGAZA *m);
void isci_olustur(ISCI *k);
void urun_olustur(URUN *u);
void magaza_yazdir(MAGAZA *m);
void isci_yazdir(ISCI *k);
void urun_yazdir(URUN *u);
void en_yasli_isci(MAGAZA *m);
float ortalama_fiyat(MAGAZA m);
void mahalle(MAGAZA *m);
void en_fazla_satis(MAGAZA *m);


int main(){
    fflush(stdin);
    MAGAZA m[2];
    int i;
    float ort1,ort2;

    for(i=0;i<2;i++){
        printf("----- %d. MAGAZA -----\n",i+1);
        magaza_olustur(&m[i]);
    }
    printf("\n-------------------------------------------\n\n");
    for(i=0;i<2;i++){
        printf("##### %d. MAGAZA #####\n",i+1);
        magaza_yazdir(&m[i]);
        printf("\n");
    }
    en_yasli_isci(m);
    ort1 = ortalama_fiyat(m[0]);
    ort2 = ortalama_fiyat(m[1]);
    printf("1.magazanin ortalama urun fiyati: %.2f\n",ort1);
    printf("2.magazanin ortalama urun fiyati: %.2f\n\n",ort2);
    mahalle(m);
    en_fazla_satis(m);
    
    return 0;
}

void magaza_olustur(MAGAZA *m){
    int i;
    printf("Magazanin adini giriniz: ");
    scanf("%s",&m->ad);
    printf("Magazanin sokagini giriniz: ");
    scanf("%s",&m->sokak);
    printf("Magazanin mahallesini giriniz: ");
    scanf("%s",&m->mahalle);
    printf("Magazanin telefonunu giriniz: ");
    scanf("%s",&m->telefon);
    printf("Magazanin satis sayisini giriniz: ");
    scanf("%d",&m->satis);

    isci_olustur(m->k);
    urun_olustur(m->u);
}

void isci_olustur(ISCI *k){
    int i;
    for(i=0;i<3;i++){
        printf("%d. isciyi giriniz: \n",i+1);
        printf("Iscinin adini giriniz: ");
        scanf("%s",&k[i].ad);
        printf("Iscinin soyadini giriniz: ");
        scanf("%s",&k[i].soyad);
        printf("Iscinin yasini giriniz: ");
        scanf("%d",&k[i].yas);
    }
}       

void urun_olustur(URUN *u){
    int i;
    for(i=0;i<5;i++){
        printf("%d. urunu giriniz: \n",i+1);
        printf("Urunun id'sini giriniz: ");
        scanf("%d",&u[i].id);
        printf("Urunun fiyatini giriniz: ");
        scanf("%f",&u[i].fiyat);
    }
    
}

void magaza_yazdir(MAGAZA *m){
    printf("Magazanin adi: %s\n",m->ad);
    printf("Magazanin sokagi: %s\n",m->sokak);
    printf("Magazanin mahallesi: %s\n",m->mahalle);
    printf("Magazanin telefonu: %s\n",m->telefon);
    printf("Magazanin satis sayisi: %d\n",m->satis);
    isci_yazdir(m->k);
    urun_yazdir(m->u);
}

void isci_yazdir(ISCI *k){
    int i;
    for(i=0;i<3;i++){
        printf("Iscinin adi: %s , Iscinin soyadi: %s , Iscinin yasi: %d\n",k[i].ad,k[i].soyad,k[i].yas);
    }
}

void urun_yazdir(URUN *u){
    int i;
    for(i=0;i<5;i++){
        printf("Urunun id'si: %d , Urunun fiyati: %.3f\n",u[i].id,u[i].fiyat);
    }
}

void en_yasli_isci(MAGAZA *m){
    int i,j,a=0,b=0,max;
    max = m[0].k[0].yas;

    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            if(m[i].k[j].yas > max){
                max = m[i].k[j].yas;
                a = i;
                b = j;
            }
        }
    }
    printf("En yasli iscinin adi: %s\n",m[a].k[b].ad);
    printf("En yasli iscinin soyadi: %s\n",m[a].k[b].soyad);
    printf("En yasli iscinin yasi: %d\n\n",m[a].k[b].yas);
}

float ortalama_fiyat(MAGAZA m){
    float sum=0,average;
    int i;
    for(i=0;i<5;i++){
        sum = sum + m.u[i].fiyat;
    }
    average = sum/5;
    return average;
}
    
void mahalle(MAGAZA *m){
    int i;
    for(i=0;i<2;i++){
        printf("Magaza adi: %s\n",m[i].ad);
        printf("Mahallesi: %s\n",m[i].mahalle);
        printf("\n");
    }
}

void en_fazla_satis(MAGAZA *m){
    int i,max,b=0;
    max = m[0].satis;
    for(i=1;i<2;i++){
        if(m[i].satis > max){
            max = m[i].satis;
            b=i;
        }
    }
    printf("En fazla satisi olan magaza: %s , satis sayisi: %d\n\n",m[b].ad,m[b].satis);
}
