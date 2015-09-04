#include <stdio.h>
#include <stdlib.h>
struct cpares {int fp; int lp};
struct cpares pares(int *v, int n)
{
    int dif, i, mdif, f, l;
    f=v[0];
    l=v[1];
    dif = v[1]-v[0];
    for (i=1; i<n-1; i++)
    {
        if ((v[i+1]-v[i])<dif)
        {
            dif=v[i+1]-v[i];
            f=v[i];
            l=v[i+1];
        }
    }
    struct cpares p;
    p.fp=f;
    p.lp=l;
    return p;
}
void troca(int *v, int a, int b)
{
    int temp=v[a];
    v[a]=v[b];
    v[b]=temp;
}
void quicksort (int *v,int f, int l)
{
    if(f>=l)
    {
        return;
    }
    int p=rand()%(l-f+1)+f;
    troca(v,p,f);
    p=f;
    int i=f;
    int j=l;
    while(i<j)
    {
        while (v[i]<=v[p]&&i<=l)
        {
            i++;
        }
        while (v[j]>v[p])
        {
            j--;
        }
        if (j>i)
        {
            troca(v,i,j);
        }
    }
    troca(v,j,p);
    quicksort(v,f,j-1);
    quicksort(v,j+1,l);
}
void main()
{
    int *v,n,i;
    printf("Ola, quantos valores voce pretende entrar? ");
    scanf("%d",&n);
    v=calloc(n,sizeof(int));
    for(i=0;i<n;i++)
    {
        printf("Entre com um numero para a posicao %d: ",i);
        scanf("%d",&v[i]);
    }
    quicksort(v,0,n-1);
    struct cpares p;
    p=pares(v,n);
    printf("A menor diferenca entre dois numeros foi de %d entre o %d e o %d.",(p.lp-p.fp),p.fp,p.lp);
}
