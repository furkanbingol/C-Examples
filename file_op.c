#include <stdio.h>
#include <stdlib.h>

int main(){
    /*-------------------------
    FILE *fp;
    char isim[] = "Furkan";
    fp = fopen("abc.txt","w");

    if(fp==NULL){
        printf("Dosya olusturulamadi..");
        return -1;
    }
    
    fprintf(fp,"Bu dosya %s'in dosyasidir.",isim);
    fclose(fp);
    -------------------------*/

    /*-------------------------
    FILE *fp;
    int i,j;
    fp = fopen("Carpim_Tablosu.txt","w");
    
    if(fp==NULL){
        printf("Dosya olusturulamadi..");
        return -1;
    }

    for(i=1;i<=10;i++){
        for(j=1;j<=10;j++){
            fprintf(fp,"%d * %d = %d\n",i,j,i*j);
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
    -------------------------*/

    FILE *fp;
    char isim[20],okul[50],bolum[50];
    fp = fopen("ogrenci.txt","a");

    if(fp==NULL){
        printf("Dosya olusturulamadi..");
        return -1;
    }

    printf("Adiniz: ");
    gets(isim);
    printf("Okulunuz: ");
    gets(okul); 
    printf("Bolumunuz: ");
    gets(bolum);

    fprintf(fp,"Ogrencinin ismi: %s\nOgrencinin okulu: %s\nOgrencinin bolumu: %s\n\n",isim,okul,bolum);    
    fclose(fp);
    return 0;
}
