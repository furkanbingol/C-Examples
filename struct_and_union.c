#include <stdio.h>
#include <stdlib.h>
/*
Birinci elemanı tamsayı ve ikinci elemanı bir birleşim(union) olan yapı dizisini(en fazla 20 elemanlı) tanımlayınız.
Union tipindeki eleman, karakter ve reel sayı olan 2 elemandan oluşsun. Programınızda bir tamsayı değerine göre bir
karakter veya bir reel sayıyı girdi olarak alınız. Bu tamsayı değeri 1 ise bir karakter, 0 ise bir reel sayı girilmelidir.
Bu tamsayıları ve bu tamsayılara bağlı olarak karakter veya reel sayıları bu yapı dizisinde saklayınız. Veri girme işlemi 
ise tamsayı değerinin 0 ve 1 den farklı bir sayı girmesiyle sonlanmalıdır. Ayrıca yapı dizisi tarayarak reel sayıların
ortalamasını bulunuz.
*/

typedef struct yapi{
    int tip;
    union{
        char ch;
        float n;
    }BIRLESIM;
}YAPI;

int main(){
    YAPI y[20];         //max=20
    int choose,i=0,k=0,j;
    float average=0;
    
    do{
        printf("Lutfen bir tamsayi degeri giriniz: ");
        scanf("%d",&choose);
        if(choose==0){
            y[i].tip = 0;
            printf("Reel sayi giriniz: ");
            scanf("%f",&y[i].BIRLESIM.n);
            i++; k++;
        }
        else if(choose==1){
            y[i].tip = 1;
            printf("Lutfen bir karakter giriniz: ");
            scanf(" %c",&y[i].BIRLESIM.ch);
            i++;
        }
    }while(choose==0||choose==1);
    printf("\nProgram Sonlandi");
    
    printf("\ni: %d\n",i);
    for(j=0;j<i;j++){
        if(y[j].tip == 0){
            average = average + y[j].BIRLESIM.n;
        }
    }

    average = average/k;
    printf("\nReel sayilarin ortalamasi: %.2f",average);
    return 0;
}
