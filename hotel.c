#include <stdio.h>
#include <stdlib.h>
/*
Müşteriler 15 euroya kahvaltı,35 euroya akşam yemeği veya hiç para ödemeyerek yemek hizmeti almayabilirler.
Otel hizmeti almak zorunlu değildir. Fakat almak isteyenler için 2 otel seçeneği mevcut. 2 yıldızlı otel 75 euro,
3 yıldızlı otel 100 euro. Otel hizmetinde aynı odadan 2 kişi yararlanabilir. Fakat yemekte dahil edildiğinde sadece
yemek ücreti 2 katına çıkar.
Müşteri adında bir struct tanımlayınız. Structta müşterinin ismi,soyismi,kahvaltı,akşam yemeği,otel hizmeti ve otel hizmeti
alacaksa arkadaşıyla kalıp kalmayacağını tanımlayınız.
N adet müşteri tanımlayınız.
Kahvaltı yapan insanları sayan bir fonksiyon yazınız.
Müşterilerin ödeyeceği fiyatı hesaplayan bir fonksiyon yazınız.
2 yıldızlı otelde konaklayan müşterilerin adını soyadını, total kahvaltı sayısını ve ödeyeceği ücreti ekrana bastıran C programını yazınız.
*/

typedef struct musteri{
    char ad[20];
    char soyad[20];
    int kahvalti;     //0:yapmıyor , 1:yapıyor
    int aksamyemegi;  //0:yapmıyor , 1:yapıyor
    int hotel;        //1:otel yok , 2:2 yıldızlı , 3:3 yıldızlı
    int yalniz_mi;    //0:yalniz   , 1:arkadasiyla
}MUSTERI;

void musteri_ekle(MUSTERI *m,int N);
void kahvalti_yapan_musteri_sayisi(MUSTERI *m,int N,int *a);
void odenecek_tutar(MUSTERI *m,int N,int *b);
void iki_yildizli(MUSTERI *m,int N,int *a,int *b);


int main(){
    int N,i;
    printf("Musteri sayisini giriniz: ");
    scanf("%d",&N);
    MUSTERI m[N];
    int a[N],b[N];
    for(i=0;i<N;i++){
        a[i] = 0;
        b[i] = 0;
    }

    musteri_ekle(m,N);
    kahvalti_yapan_musteri_sayisi(m,N,a);
    odenecek_tutar(m,N,b);
    iki_yildizli(m,N,a,b);
    return 0;
}

void musteri_ekle(MUSTERI *m,int N){
    int i;
    for(i=0;i<N;i++){
        fflush(stdin);
        printf("%d. musterinin adini giriniz: ",i+1); gets(m[i].ad); 
        printf("%d. musterinin soyadini giriniz: ",i+1); gets(m[i].soyad);
        printf("%d. musteri kahvalti yapti mi(0:h|1:e): ",i+1); scanf("%d",&m[i].kahvalti);
        printf("%d. musteri aksam yemegi yapti mi(0:h|1:e): ",i+1); scanf("%d",&m[i].aksamyemegi);
        printf("%d. musterinin oteli(1:yok|2:2 yildizli|3:3 yildizli): ",i+1); scanf("%d",&m[i].hotel);
        printf("%d. musteri oteldeyse yalniz mi,arkadasiyla mi(0:yalniz|1:arkadasiyla): ",i+1); scanf("%d",&m[i].yalniz_mi);
        printf("\n");
    }
}

void kahvalti_yapan_musteri_sayisi(MUSTERI *m,int N,int *a){
    int i;
    for(i=0;i<N;i++){
        if(m[i].kahvalti == 1){
            a[i]++;
        }
    }
}

void odenecek_tutar(MUSTERI *m,int N,int *b){
    int i;
    for(i=0;i<N;i++){
        if(m[i].kahvalti == 1){
            b[i] += 15;
        }
        if(m[i].aksamyemegi == 1){
            b[i] += 35;
        }
        if(m[i].yalniz_mi == 1){
            b[i] *= 2;
        }
        if(m[i].hotel == 2){
            b[i] += 75;
        }
        if(m[i].hotel == 3){
            b[i] += 100;
        }
    }
}

void iki_yildizli(MUSTERI *m,int N,int *a,int *b){
    int i,c=0;
    printf("\n\nIki yildizli otelde konaklayan musteriler: \n");
    for(i=0;i<N;i++){
        if(m[i].hotel == 2){
            printf("adi: %s\n",m[i].ad);
            printf("soyadi: %s\n",m[i].soyad);
            printf("odeyecegi ucret: %d\n",b[i]);
            if(a[i] == 1){
                c++;
            }
            printf("\n");
        }
    }
    printf("Iki yildizli otelde konaklayip siparis edilen toplam kahvalti sayisi: %d\n",c);
}
