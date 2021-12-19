#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Bir öğretmen, 30 kişilik sınıfta 10 soruluk çoktan seçmeli sorulardan oluşan bir sınav yapmıştır.
Bu sınavda her sorunun 4 şıkkı(a b c d) bulunmakta ve 4 yanlış 1 doğruyu götürmektedir. Bu programda
bir öğrencinin okul numarasını ve cevaplarını içeren bir yapı(struct) tanımlayınız ve sınıfta bulunan
her öğrencinin okul numarasını ve cevaplarını bu yapı dizisine okutunuz. Daha sonra öğretmenin hazırladığı
cevap anahtarını bir karakter dizisine okuyunuz ve her öğrencinin "10" üzerinden aldığı notu hesaplayınız.
Her öğrencinin okul numarası ile, hesaplanan sınav sonucunu bir başka yapı dizisinde tutunuz ve sonuçları
ekrana bastırınız.
*/

typedef struct ogrenci{
    char no[20];
    char cevaplar[10];
}OGRENCI;

typedef struct sonuc{
    char no[20];
    float not;
}SONUC;


int main(){
    int i,j,t,f;
    char anahtar[10];
    OGRENCI ogr[30];
    SONUC ogr2[30];

    printf("Cevap anahtarini giriniz:\n");
    for(i=0;i<10;i++){
        scanf(" %c",&anahtar[i]);
    }

    printf("---Ogrenci bilgilerini giriniz---\n");
    for(i=0;i<30;i++){
        t=f=0;
        printf("Ogrenci no: ");
        scanf("%s",&ogr[i].no);
        printf("---Cevaplari---\n");
        for(j=0;j<10;j++){
            scanf(" %c",&ogr[i].cevaplar[j]);
            if(ogr[i].cevaplar[j] == anahtar[j]){
                t++;
            }
            else if(ogr[i].cevaplar[j] != ' '){
                f++;
            }
        }
        strcpy(ogr2[i].no,ogr[i].no);
        ogr2[i].not = t - (f/4.0);
        printf("No: %s , Dogru: %d , Yanlis: %d , ",ogr2[i].no,t,f);
        printf("Ogrencinin neti: %.2f\n",ogr2[i].not);
    }
    return 0;
}
