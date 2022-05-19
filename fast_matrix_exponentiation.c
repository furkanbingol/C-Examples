#include <stdio.h>
 
void multiply(int a[2][2], int b[2][2])
{
    int mul[2][2];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            mul[i][j] = 0;
            for (int k = 0; k < 2; k++)
                mul[i][j] += a[i][k]*b[k][j];
        }
    }
 
    for (int i=0; i<2; i++)
        for (int j=0; j<2; j++)
            a[i][j] = mul[i][j];
}


int power(int F[2][2], int n)
{
    int M[2][2] = {{1,1},{1,0}};

    if (n==1)
        return F[0][0] + F[0][1];
 
    power(F, n/2);
 
    multiply(F, F);
 
    if (n%2 != 0)
        multiply(F, M);
 
    return F[0][0] + F[0][1];
}
 
int findNthTerm(int n)
{
    int F[2][2] = {{1,1},{1,0}};
 
    //base case
    if(n==0)
        return 0;
    if(n==1 || n==2)
        return 1;
 
    return power(F, n-2);
}
 
int main()
{
  int n;
  printf("n: "); scanf("%d",&n);
  printf("fibonacci result: %d",findNthTerm(n));
  return 0;
}
