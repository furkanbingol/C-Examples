//Perfect Number
#include <stdio.h>

int mukemmelsayi(int a){
    int bolen_toplami=0;
    int i;

    for(i=1;i<a;i++){
        if(a%i==0){
            bolen_toplami += i;
        }
    }
    if(bolen_toplami==a){
        return 1;
    }
    else{
        return 0;
    }

}

int main(){
    int x,sonuc;
    printf("Lutfen bir sayi giriniz: ");
    scanf("%d",&x);

    sonuc = mukemmelsayi(x);

    if(sonuc==0){
        printf("%d sayisi mukemmel sayi degildir.",x);
    }
    else{
        printf("%d sayisi mukemmel sayidir",x);
    }
 
    return 0;
}
