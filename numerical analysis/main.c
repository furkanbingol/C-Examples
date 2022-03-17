#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>

#define MAX 200

//Ortak Fonksiyon İşlemleri
void readPolynom(int *n, float vec[]);

void writePolynome(int *n, float vec[], int flag);

double performeResult(int n, float vec[], double x);

void derivatePolynome(int *n, float vec[]);

//Bisection
void bisectionmethod();

//Regula Falsi
void regula(float *x, float x0, float x1, float fx0, float fx1, int *itr);

int regulaFalsi();

//Newton Raphson
int newtonRaphson();

void copyy(float my_p[], const float p[MAX]);

//Ters Matris
float determinant(float [][MAX], float);

void cofactor(float [][MAX], float);

void transpose(float [][MAX], float [][MAX], float);

void inverseMatrix();

//Gauss eleminasyon
void gaussElemination();

//Gauss Seidal
void gaussSeidal();

//Sayısal Türev
void sayisalTurev();

//Simpson 1/3
void simpson();

//Trapez
void trapez();

//Gregory Newton
int fact(int);

void gregoryNewton();


int main() {
    setlocale(LC_ALL, "Turkish");

    int choice = 0;
    char tekrar = 'x';


    do {
        printf("Kaçıncı yöntemi yapmak istiyorsunuz?\n1.Bisection yöntemi\n2.Regula-Falsi yöntemi\n3.Newton-Rapshon yöntemi\n4.NxN'lik bir matrisin tersi\n5.Gauss Eleminasyon\n6.Gauss Seidal yöntemleri\n7.Sayısal Türev (merkezi, ileri ve geri farklar opsiyonlu)\n8.Simpson yöntemi \n9.Trapez yöntemi\n10.Değişken dönüşümsüz Gregory newton Enterpolasyonu\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Bisection Method\n");
                bisectionmethod();
                break;
            case 2:
                printf("Regula-Falsi yöntemi\n");
                regulaFalsi();
                break;
            case 3:
                printf("Newton-Rapshon yöntemi\n");
                newtonRaphson();
                break;
            case 4:
                printf("NxN'lik bir matrisin tersi\n");
                inverseMatrix();
                break;
            case 5:
                printf("Gauss Eleminasyon\n");
                gaussElemination();
                break;
            case 6:
                printf("Gauss Seidal yöntemleri\n");
                gaussSeidal();
                break;
            case 7:
                printf("Sayısal Türev (merkezi, ileri ve geri farklar opsiyonlu)\n");
                sayisalTurev();
                break;
            case 8:
                printf("Simpson yöntemi\n");
                simpson();
                break;
            case 9:
                printf("Trapez yöntemi\n");
                trapez();
                break;
            case 10:
                printf("Değişken dönüşümsüz Gregory Newton Enterpolasyonu\n");
                gregoryNewton();
                break;
        }

        printf("\nBaşka bir işlem yapmak ister misiniz? [e/h] ");
        scanf(" %c", &tekrar);
        printf("\n\n");
    } while (tekrar == 'e');
    return 0;
}



//Bisection
void bisectionmethod() {
    int n, j = 0;
    float xavg, xtop, xbot, epsilon, yavg, ybot,p[MAX];

    printf("\n\n");
    printf("Bisection Yöntemi İle Kök Bulma\n");
    
    readPolynom(&n, p);        //p[]: katsayılar dizisi
    writePolynome(&n, p, 0);


    printf("Alt sınırı giriniz:  ");
    scanf("%f", &xbot);

    printf("Üst sınırı giriniz: ");
    scanf("%f", &xtop);

    printf("Epsilon değerini giriniz: ");
    scanf("%f", &epsilon);

    if (performeResult(n, p, xtop) == 0) {
        printf("Kök = %f", xtop);
    } else if (performeResult(n, p, xbot) == 0) {
        printf("Kök = %f", xbot);
    } else {
        do {
            xavg = (xtop + xbot) / 2;
            yavg = performeResult(n, p, xavg);
            ybot = performeResult(n, p, xbot);

            if ((ybot * yavg) < 0) {
                xtop = xavg;
            } else {
                xbot = xavg;
            }
            j += 1;
            printf("\n%d. iterasyon: Kök = %.4f || abs(yavg) = %.4f || epsilon = %.4f\n",j,xavg ,fabsf(yavg),epsilon);
        } while (fabsf(yavg) > epsilon);
        printf("\nKök = %.4f", xavg);
    }
}

//Regula Falsi
void regula(float *x, float x0, float x1, float fx0, float fx1, int *itr) {
    *x = x0 - ((x1 - x0) / (fx1 - fx0)) * fx0;
    ++(*itr);
    printf("İterasyon numarası: %2d , X = %7.5f\n", *itr, *x);
}

int regulaFalsi() {
    int itr = 0, maxmitr;
    int n;
    float p[MAX], x0, x1, x2, x3, hata;
    readPolynom(&n, p);
    writePolynome(&n, p, 0);

    printf("\nAlt siniri, Ust siniri, Hata oranini ve maksimum iterasyon sayisini giriniz: \n");
    scanf("%f %f %f %d", &x0, &x1, &hata, &maxmitr);

    regula(&x2, x0, x1, performeResult(n, p, x0), performeResult(n, p, x1), &itr);
    do {
        if (performeResult(n, p, x0) * performeResult(n, p, x2) < 0)
            x1 = x2;
        else
            x0 = x2;
        regula(&x3, x0, x1, performeResult(n, p, x0), performeResult(n, p, x1), &itr);
        if (fabsf(x3 - x2) < hata) {
            printf("%d iterasyon sonra| Kök = %6.5f| Hata Oranı: %.5f\n", itr, x3, fabsf(x3 - x2));
            return 0;
        }
        x2 = x3;
    } while (itr < maxmitr);
    printf("Çözüm yakinsamıyor veya iterasyonlar yetersiz\n");
}

//Newton Raphson
int newtonRaphson() {
	float p[MAX],  my_p[MAX];
    int n;
    double h, x0, x1, hata;
    int itr, maxitr;
    

    readPolynom(&n, p);
    writePolynome(&n, p, 0);

    printf("x0 giriniz, hata oranini giriniz, maksimum iterasyon sayisini giriniz: ");
    scanf("%lf %lf %d", &x0, &hata, &maxitr);

    copyy(my_p, p);

    derivatePolynome(&n, p);
    writePolynome(&n, p, 1);

    for (itr = 1; itr <= maxitr; itr++) {
        h = (performeResult(n + 1, my_p, x0) / performeResult(n, p, x0));
        x1 = x0 - h;
        printf("\n%d.iterasyon| x= %.5f  |%d.iterasyondaki hata oranı: %.5f", itr, x1, itr, fabs(x1 - x0));

        if (fabs(h) < hata) {
            printf("\n\nToplam iterasyon sayısı:%d , Kök:%.5f\n", itr, x1);

            return 0;
        }
        x0 = x1;
    }
    printf("Çözüm yakinsamıyor veya iterasyonlar yetersiz\n");
    return 1;
}

void copyy(float my_p[], const float p[MAX]) {
    int i;
    for (i = 0; i < MAX; i++)
        my_p[i] = p[i];
}

//Ters Matris
void inverseMatrix() {
    float a[MAX][MAX], d;
    int i, j, k;
    printf("Kare Matrisin Boyutunu giriniz : ");
    scanf("%d", &k);
    printf("%dX%dMatrisin elemanlarını giriniz : \n", k, k);
    for (i = 0; i < k; i++) {
        for (j = 0; j < k; j++) {
            scanf("%f", &a[i][j]);
        }
    }
    d = determinant(a, k);
    if (d == 0)
        printf("\nDeterminant=0, matrisin tersi yoktur.\n");
    else
        cofactor(a, k);
}

float determinant(float a[MAX][MAX], float k) {
    float s = 1, det, b[MAX][MAX];
    int i, j, m, n, c;
    if (k == 1) {
        return (a[0][0]);
    } else {
        det = 0;
        for (c = 0; c < k; c++) {
            m = 0;
            n = 0;
            for (i = 0; i < k; i++) {
                for (j = 0; j < k; j++) {
                    b[i][j] = 0;
                    if (i != 0 && j != c) {
                        b[m][n] = a[i][j];
                        if (n < (k - 2))
                            n++;
                        else {
                            n = 0;
                            m++;
                        }
                    }
                }
            }
            det = det + s * (a[0][c] * determinant(b, k - 1));
            s = -1 * s;
        }
    }

    return (det);
}

void cofactor(float num[MAX][MAX], float f) {
    float b[MAX][MAX], fac[MAX][MAX];
    int p, q, m, n, i, j;
    for (q = 0; q < f; q++) {
        for (p = 0; p < f; p++) {
            m = 0;
            n = 0;
            for (i = 0; i < f; i++) {
                for (j = 0; j < f; j++) {
                    if (i != q && j != p) {
                        b[m][n] = num[i][j];
                        if (n < (f - 2))
                            n++;
                        else {
                            n = 0;
                            m++;
                        }
                    }
                }
            }
            fac[q][p] = pow(-1, q + p) * determinant(b, f - 1);
        }
    }
    transpose(num, fac, f);
}

void transpose(float num[MAX][MAX], float fac[MAX][MAX], float r) { 
    int i, j;
    float b[MAX][MAX], inverse[MAX][MAX], d;

    for (i = 0; i < r; i++) {
        for (j = 0; j < r; j++) {
            b[i][j] = fac[j][i];
        }
    }
    d = determinant(num, r);
    for (i = 0; i < r; i++) {
        for (j = 0; j < r; j++) {
            inverse[i][j] = b[i][j] / d;
        }
    }
    printf("\n\nMatrisin Tersi : \n");

    for (i = 0; i < r; i++) {
        for (j = 0; j < r; j++) {
            printf("\t%f", inverse[i][j]);
        }
        printf("\n");
    }
}

//Gauss Eleminasyon
void gaussElemination() {
    int i, j, k, n;
    float A[MAX][MAX], c, x[MAX], sum;
    printf("\nKare Matrisin Boyutunu Giriniz: ");
    scanf("%d", &n);
    printf("\nGenişletilmiş Katsayılar Matrisini Giriniz: \n\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= (n + 1); j++) {
            printf("A[%d][%d] : ", i, j);
            scanf("%f", &A[i][j]);
        }
    }
    for (j = 1; j <= n; j++)
    {
        for (i = 1; i <= n; i++) {
            if (i > j) {      
                c = A[i][j] / A[j][j];
                for (k = 1; k <= n + 1; k++) {
                    A[i][k] = A[i][k] - c * A[j][k];
                }
            }
        }
    }
    x[n] = A[n][n + 1] / A[n][n];

    for (i = n - 1; i >= 1; i--) {
        sum = 0;
        for (j = i + 1; j <= n; j++) {
            sum = sum + A[i][j] * x[j];
        }
        x[i] = (A[i][n + 1] - sum) / A[i][i];
    }
    printf("\nCevap: \n");
    for (i = 1; i <= n; i++) {
        printf("\nx%d = %.2f\t", i, x[i]);
    }
}

//Gauss Seidal
void gaussSeidal() {
    float a[MAX][MAX], m[MAX], n[MAX];
    int p, q, i, j, k;
    printf("Kare Matrisin Boyutunu Giriniz : ");
    scanf("%d", &p);

    for (i = 0; i < p; i++) {
        for (j = 0; j < p; j++) {
            printf("a[%d, %d]=", i, j);
            scanf("%f", &a[i][j]);
        }
    }
    printf("\nEşitliğin sağındaki değerleri(sonuçları) giriniz: \n");
    for (i = 0; i < p; i++) {
        printf("b[%d, %d]=", i, j);
        scanf("%f", &a[i][p]);
    }

    //köşegenleri max yapma
    for (i = 0; i < p; i++)
        for (k = i + 1; k < p; k++)
            if (fabsf(a[i][i]) < fabsf(a[k][i]))
                for (j = 0; j <= p; j++) {
                    float temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }

    printf("\nx'in ilk değerlerini giriniz: \n");
    for (i = 0; i < p; i++) {
        printf("x:[%d]=", i);
        scanf("%f", &m[i]);
    }
    printf("\nİterasyon sayısını giriniz : ");
    scanf("%d", &q);
    int iter = q;
    while (q > 0) {
        for (i = 0; i < p; i++) {
            n[i] = (a[i][p] / a[i][i]);
            for (j = 0; j < p; j++) {
                if (j != i) {
                    n[i] = n[i] - ((a[i][j] / a[i][i]) * m[j]);
                    m[i] = n[i];
                }
            }
            printf("%d.iterasyon : x%d = %.4f\t\t", iter - q + 1, i + 1, n[i]);

        }
        printf("\n");
        q--;
    }
}

//Sayısal Türev
void sayisalTurev(){
	int n, choice;
    float p[MAX],x0,h,sonuc;
    char tekrar = 'x';
    choice = 0;
    
    readPolynom(&n, p);
    writePolynome(&n, p, 0);
    printf("\nNoktayı giriniz, adım aralığını(h) giriniz: \n");
    scanf("%f %f", &x0, &h);
	
	do {
        printf("\nSayısal Türevi Hangi yolla bulmak istersiniz:\n1)İleri Fark ile\n2)Geri Fark ile\n3)Merkezi Fark ile\n");
		scanf("%d",&choice);

        switch (choice) {
            case 1:
                printf("\nİleri Fark:\nYöntem: (f(x0+h)-f(x0)) / h\n");
				sonuc= (performeResult(n, p, x0+h) - performeResult(n, p, x0)) / h;
				printf("Fonksiyonun Sayısal Türevi: %.3f", sonuc); 	
                break;
            case 2:
                printf("\nGeri Fark:\nYöntem: (f(x0)-f(x0-h)) / h\n");
				sonuc= (performeResult(n, p, x0) - performeResult(n, p, x0-h)) / h;
				printf("Fonksiyonun Sayısal Türevi: %.3f", sonuc);
                break;
            case 3:
                printf("\nMerkezi Fark:\nYöntem: (f(x0+h)-f(x0-h)) / 2h\n");
				sonuc= (performeResult(n, p, x0+h) - performeResult(n, p, x0-h)) / (2*h);
				printf("Fonksiyonun Sayısal Türevi: %.3f", sonuc);
               	break;
        }
        printf("\nSayısal Türev için başka bir işlem yapmak ister misiniz? [e/h] ");
        scanf(" %c", &tekrar);
        printf("\n\n");
    } while (tekrar == 'e');
	
}

//Simpson 1/3
void simpson(){
	float p[MAX],a,b,h,sum1=0,sum2=0,sum,y0,yN;
	int n,N,i;
	readPolynom(&n, p);
    writePolynome(&n, p, 0);
    
    printf("Alt limiti giriniz: ");
	scanf("%f",&a);
	printf("Üst limiti giriniz: ");
	scanf("%f",&b);
	printf("n değerini giriniz(Çift olmalı): ");
	scanf("%d",&N);
	
	h= fabsf(b-a)/N;
	y0= performeResult(n, p, a);
	yN= performeResult(n, p, a+N*h);

	for(i=1; i<N; i++)
		if(i%2 == 0)
			sum1 = sum1 + performeResult(n, p, a+i*h);  //formülde Çiftlerin 2 katı alınır. 
		else
			sum2 = sum2 + performeResult(n, p, a+i*h);  //formülde Teklerin 4 katı alınır.
			
	sum =(h/3)*(y0 + yN + 4*sum2 + 2*sum1);
	
	printf("\nİntegralin sonucu: %.4f",sum);
}

//Trapez
void trapez(){
	int n,N,i;
  	float p[MAX],a,b,h,x,sum=0,sonuc,y0,yN;
  	readPolynom(&n, p);
    writePolynome(&n, p, 0);
  	
  	printf("Alt limiti giriniz: ");
	scanf("%f",&a);
	printf("Üst limiti giriniz: ");
	scanf("%f",&b);
	printf("n değerini giriniz(Çift olmalı): ");
	scanf("%d",&N);
  	
  	h= fabsf(b-a)/N;
  	y0= performeResult(n, p, a+0*h);
	yN= performeResult(n, p, a+N*h);
	
  	for(i=1;i<N;i++){
    	x = a+i*h;
    	sum= sum + performeResult(n, p, x);
  	}
  	sonuc= (h)*((y0+yN)/2 + sum);
  	
  	printf("\nİntegralin sonucu: %.4f\n",sonuc);
}

//Gregory Newton
void gregoryNewton(){
	
	float static arr[MAX][MAX];
	float x,h,p,y,px=1;
	int i,j,n,ch=30;
	printf("\nKaç veri gireceğinizi yazınız:");
	scanf("%d",&n);
	printf("\nVerileri Giriniz:\n");
	for(i=0;i<n;i++){
		printf("X%d=",i+1);
		scanf("%f",&arr[i][0]);
		printf("Y%d=",i+1);
		scanf("%f",&arr[i][1]);
	}
	//Fark Tablosu oluşturma
	for(j=2;j<=n;j++){
		for(i=0;i<n-1;i++){
			arr[i][j]=arr[i+1][j-1]-arr[i][j-1];
		}
	}
	//Tabloyu yazdırma
	printf("\nFark Tablosu: ");
	printf("\n\tX\t\tY");
	for(i=0;i<=n-2;i++){
		printf("\t\t%c^%dY",ch,i+1);
	}	
	for(i=0;i<n;i++){
		printf("\n\n");
		for(j=0;j<n+1-i;j++){
			printf("\t%.3f\t",arr[i][j]);
		}
	}
	
	printf("\n\nFonksiyonda cevabını bulmak istediğiniz x değerini giriniz:");
	scanf("%f",&x);
	
	//f(x)'in x noktasındaki değerini hesaplama
	h=arr[1][0]-arr[0][0];  //aralık farkı
	p=(x-arr[0][0])/h;
	y=arr[0][1];
	for(i=1;i<n;i++){
 		px=px*(p-(i-1));
		y=y+(arr[0][i+1]*px)/fact(i);   //formül
	}

	printf("\n");
	printf("\nFonksiyonda x=%.3f iken y=%.3f",x,y);
}

//faktoriyel
int fact(int n){     
	int i,f=1;
	for(i=1;i<=n;i++)
		f=f*i;
	return f;
}

//Ortak fonksiyon işlemleri
void readPolynom(int *n, float vec[]) {     //n:fonksiyonun derecesi | vec[]:katsayılar dizisi
    int i;
    printf("Polinomun derecesi:\n->>");
    scanf("%d", n);

    printf("Katsayıları giriniz: \n");
    for (i = 0; i <= *n; ++i) {
    	printf("\n%d.dereceye sahip terimin katsayısını giriniz: ",i);
        scanf("%f", &vec[i]);
    }
}

void writePolynome(int *n, float vec[], int flag) {
    int i;

    if (flag == 0) {
        printf("P(x) = ");
    } else {
        printf("P'(x) = ");
    }
    printf("%.2f ", vec[0]);
    for (i = 1; i <= *n; ++i) {

        printf("+ %.2fx^%d ", vec[i], i);
    }
    printf("\n");
}

double performeResult(int n, float vec[], double x) {
    int i;
    double valToComputeDer = vec[0], t = 1;

    for (i = 1; i <= n; ++i) {
        t *= x;
        valToComputeDer += vec[i] * t;
    }
    return valToComputeDer;
}

void derivatePolynome(int *n, float vec[]) {   //Türev Polinomu,Newton Raphsonda kullanılır
    int i;
    vec[0] = vec[1];     

    for (i = 1; i <= *n; ++i) {

        vec[i] = vec[i + 1] * (i + 1);   
    }
    (*n)--;
}
