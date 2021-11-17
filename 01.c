#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int N,**matris,r;
    int i,j;
    int *satir_toplami,*sutun_toplami;
    printf("Lutfen N degerini giriniz: ");
    scanf("%d",&N);

    matris = (int**)malloc(N*sizeof(int*));
    if(matris == NULL){
        printf("Bellekte yer ayrilamadi!!");
        return -1;
    }
    for(i=0;i<N;i++){
        matris[i] = (int*)malloc(N*sizeof(int));
        if(matris[i] == NULL){
            printf("Bellekte yer ayrilamadi!!");
            return -1;
        }
    }

    satir_toplami = (int*)calloc(N,sizeof(int));
    sutun_toplami = (int*)calloc(N,sizeof(int));    
    if(satir_toplami == NULL || sutun_toplami == NULL){
        printf("Bellekte yer ayrilamadi!!");
        return -1;
    }

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            r = rand()%100 + 1;
            matris[i][j] = r;
            satir_toplami[i] += r;
            sutun_toplami[j] += r;
        }
    }
    
    matris = (int**)realloc(matris,(N+1)*sizeof(int*));

    if(matris==NULL){
        printf("Bellekte yer ayrilamadi!!");
        return -1;
    }
    for(i=0;i<(N+1);i++){
		matris[i] = (int*)realloc(matris[i], (N+1)*sizeof(int));
		if(matris[i] == NULL){
			printf("Bellekte yer ayrilamadi!!");
			return -1;
		}
	}

    for(i=0;i<(N+1);i++){
        matris[i][N] = satir_toplami[i];
        matris[N][i] = sutun_toplami[i];
    }
    matris[N][N] = 0;
    for(i=0;i<N;i++){
        matris[N][N] += satir_toplami[i]+sutun_toplami[i];
    }
    printf("\n");
    for(i=0;i<(N+1);i++){
        for(j=0;j<(N+1);j++){
            printf("%5d",matris[i][j]);
        }
        printf("\n");
    }
    
    for(i=0;i<(N+1);i++){
        free(matris[i]);
    }
    free(matris);
    free(satir_toplami);
    free(sutun_toplami);
    return 0;
}
