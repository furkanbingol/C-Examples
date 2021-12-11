#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 5
/*
Verilen 3 boyutlu noktaların orjine olan uzaklıklarını "Selection Sort" algoritmasıyla büyükten kücüge
veya kücükten büyüge sıralayan bir algoritmayı C dilinde çözünüz
*/

typedef struct nokta{
    int x;
    int y;
    int z;
}NOKTA;

float distance(int x,int y,int z);
void swap(NOKTA *a,NOKTA *b);
int ascending(float d1,float d2);
int descending(float d1,float d2);
void selection_sort(NOKTA *a,const int size,int (*compare)(float distance1,float distance2));
void printOrdered(NOKTA *a);

int main(){
    int xArr[MAX] = {12,2,4,8,10};
    int yArr[MAX] = {10,5,2,3,12};
    int zArr[MAX] = {5,2,0,4,1};
    int order;
    int i;

    NOKTA *a;  //NOKTA struct tipinde bir array oluşturduk
    a = (NOKTA*)malloc(MAX*sizeof(NOKTA));

    for(i=0;i<MAX;i++){
        a[i].x = xArr[i];
        a[i].y = yArr[i];
        a[i].z = zArr[i];
        printf("Nokta %d: (%d,%d,%d) : ",i+1,a[i].x,a[i].y,a[i].z);
        printf("Orjine olan uzaklik: %.2f\n",distance(a[i].x,a[i].y,a[i].z));
    }

    printf("\nLutfen siralamayi giriniz(1:artan sira | 2:azalan sira): ");
    scanf("%d",&order);
    
    if(order==1){
        selection_sort(a,MAX,ascending);
    }
    else{
        selection_sort(a,MAX,descending);
    }
    printOrdered(a);
    return 0;
}

void swap(NOKTA *a,NOKTA *b){
    NOKTA tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int ascending(float d1,float d2){
    return (d1<d2);
}

int descending(float d1,float d2){
    return (d1>=d2);
}

float distance(int x,int y,int z){
    return sqrt(pow(x,2)+pow(y,2)+pow(z,2));
}

void selection_sort(NOKTA *a,const int size,int (*compare)(float distance1,float distance2)){
    int i,j;
    int m;
    float d1,d2;

    for(i=0;i<size-1;i++){
        m = i;
        for(j=i+1;j<size;j++){
            d1 = distance(a[m].x,a[m].y,a[m].z);
            d2 = distance(a[j].x,a[j].y,a[j].z);

            if(!compare(d1,d2)){
                m = j;
            }
        }
        if(m!=i){
            swap(&a[i],&a[m]);
        }
    }
}

void printOrdered(NOKTA *a){
    int i;
    for(i=0;i<MAX;i++){
        printf("(%d,%d,%d) ",a[i].x,a[i].y,a[i].z);
    }
}
