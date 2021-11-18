#include <stdio.h>
/*
Floyd's Triangle:
1
2 3
4 5 6
7 8 9 10
...
*/

void floyd(int x){
    if(x<=0){
        printf("Gecersiz satir sayisi!");
    }
    else{
        int satir=1;
        int i,k=1;
        
        while(satir<=x){
            for(i=1;i<=satir;i++){
                printf("%d ",k);
                k++;
            }
        printf("\n");
        satir++;
        }
    }
}

int main(){
    int a;
    printf("----FLOYD'S TRIANGLE----\n");
    printf("Satir sayisini giriniz: ");
    scanf("%d",&a);

    floyd(a);
    return 0;
}
