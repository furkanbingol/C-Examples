#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 200
/*
My name is John --> John is name My
*/

int main(){
    char cumle[MAX];
    char ters_cumle[MAX];
    int i,index=0;
    int baslangic,bitis;

    printf("Lutfen bir cumle giriniz: ");
    gets(cumle);

    baslangic = strlen(cumle)-1;
    bitis = strlen(cumle)-1;

    while(baslangic>0){
        if(cumle[baslangic]==' '){
            for(i=baslangic+1;i<=bitis;i++){
                ters_cumle[index] = cumle[i];
                index++; 
            }
            ters_cumle[index] = ' ';
            index++;
            bitis = baslangic-1;
        }
        baslangic--;
    }

    for(i=0;i<=bitis;i++){    //son kelime icin ayrı bir for
        ters_cumle[index] = cumle[i];
        index++;
    }

    ters_cumle[index] = '\0';
    printf("Cumlenin tersi: %s",ters_cumle);
    return 0;
}
