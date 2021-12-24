#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
/*
Personel bilgilerinin alınmasını ve alındıktan sonra "adlarına" göre a dan z ye alfabetik 
olarak personel bilgilerinin listenmesini sağlayan C programını yazınız.
*/

typedef struct personel{
    char ad[MAX];
    char soyad[MAX];
    int yas;
    float maas;
    char cinsiyet[MAX];
    int sifre;
}PERSONEL;

void sirala(PERSONEL *x,int n);
void listele(PERSONEL *x,int n);

int main(){
    PERSONEL *x;
    int n,i;
    printf("Lutfen personel sayisini giriniz: ");
    scanf("%d",&n);

    x = (PERSONEL*)malloc(n*sizeof(PERSONEL));

    for(i=0;i<n;i++){
        printf("%d.personelin adini giriniz: ",i+1); scanf("%s",&x[i].ad);
        printf("%d.personelin soyadini giriniz: ",i+1); scanf("%s",&x[i].soyad);
        printf("%d.personelin yasini giriniz: ",i+1); scanf("%d",&x[i].yas);
        printf("%d.personelin maasini giriniz: ",i+1); scanf("%f",&x[i].maas);
        printf("%d.personelin cinsiyetini giriniz: ",i+1); scanf("%s",&x[i].cinsiyet);
        printf("%d.personelin sifresini giriniz: ",i+1); scanf("%d",&x[i].sifre);
        printf("\n");
    }

    sirala(x,n);
    listele(x,n);
    return 0;
}

void sirala(PERSONEL *x,int n){
    int i,j,k,largest;
    PERSONEL tmp;
    for(i=0;i<n-1;i++){
        largest = i;
        for(j=i+1;j<n;j++){
            k=0;
            while(x[largest].ad[k] != '\0' && x[j].ad[k] != '\0' && x[largest].ad[k] == x[j].ad[k]){
                k++;
            }
            if((x[largest].ad[k] > x[j].ad[k])){
                tmp = x[largest];
                x[largest] = x[j];
                x[j] = tmp; 
            }    
        }             
    }
}

void listele(PERSONEL *x,int n){
    int i;
    printf("\nSiralanmis personel listesi: \n");
    for(i=0;i<n;i++){
        printf("Personelin adi: %s\n",x[i].ad);
        printf("Personelin soyadi: %s\n",x[i].soyad); 
        printf("Personelin yasi: %d\n",x[i].yas); 
        printf("Personelin maasi: %.2f\n",x[i].maas); 
        printf("Personelin cinsiyeti: %s\n",x[i].cinsiyet); 
        printf("Personelin sifresi: %d\n\n",x[i].sifre);
    }
}
