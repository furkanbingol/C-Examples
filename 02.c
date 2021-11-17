#include <stdio.h>
#include <stdlib.h>
//3 zarýn üst yüzüne gelen sayýlarýnýn toplam sonucu bir kolonda, olasýlýðýný diðer kolonda tutunuz

int main(){
    int i,j;
    int x,y,z;
    float **olasilik;
    int *toplam;

    olasilik = (float**)calloc(16,sizeof(float*));
    if(olasilik == NULL){
        printf("Bellekte yer ayrilamadi!!");
        return -1;
    }
    for(i=0;i<16;i++){
        olasilik[i] = (float*)calloc(2,sizeof(float*));
        if(olasilik[i] == NULL){
            printf("Bellekte yer ayrilamadi!!");
            return -1;
        }
    }

    toplam = (int*)calloc(16,sizeof(int));
    if(toplam == NULL){
        printf("Bellekte yer ayrilamadi!!");
        return -1;
    }

    for(x=1;x<=6;x++){
        for(y=1;y<=6;y++){
            for(z=1;z<=6;z++){
                toplam[x+y+z-3]++;
            }
        }
    }

    for(i=0;i<16;i++){
        for(j=0;j<2;j++){
            if(j==0){
                olasilik[i][j] = i+3;
            }
            else{
                olasilik[i][j] = (toplam[i]/216.0);
            }   
        }
    }

    //Olasýlýk matrisini bastýrma
    printf("\n-----OLASILIK MATRISI-----\n");
    for(i=0;i<16;i++){
        for(j=0;j<2;j++){
            if(j==0){
                printf("%.0f   ",olasilik[i][j]);
            }
            else{
                printf("%.7f",olasilik[i][j]);
            }
        }
        printf("\n");
    }

    //matris ve kullandýgýmýz diziyi free() yapma islemi
    for(i=0;i<16;i++){
        free(olasilik[i]);
    }
    free(olasilik);

    free(toplam);
    return 0;
}
