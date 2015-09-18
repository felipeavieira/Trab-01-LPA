#include <stdio.h>
#include <stdlib.h>
void troca(int *v, int a, int b)//função de troca que será usada no quicksort
{
    int temp=v[a];
    v[a]=v[b];
    v[b]=temp;
}
void quicksort (int *v,int f, int l)// função com o algorismo de ordenação quicksort
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
void pares(int *v, int n) /*A função pares servirá para comparar os pares de números inseridos,
para encontrar a menor diferença entre dois, para então mostra-los, junto com a diferença*/
{
    int dif, i, f, l;
    f=v[0];
    l=v[1];
    dif = v[1]-v[0];
    for (i=1; i<n-1&&dif>0; i++)/*Esse for irá comparar valores até o final ou até achar dois valores iguais,
    que são a menor diferença possível*/
    {
        if ((v[i+1]-v[i])<dif)
        {
            dif=v[i+1]-v[i];
            f=v[i];
            l=v[i+1];
        }
    }
    printf("A menor diferenca entre dois numeros foi de %d entre o %d e o %d.",dif, f,l);
}
void main()
{
    int *v,n,i;
    printf("Ola, quantos valores voce pretende entrar? ");
    scanf("%d",&n);
    v=calloc(n,sizeof(int));//alocação dinâmica para preencher v com quantos números for preciso
    for(i=0;i<n;i++)//preenchimento de v
    {
        printf("Entre com um numero para a posicao %d: ",i);
        scanf("%d",&v[i]);
    }
    quicksort(v,0,n-1);
    pares(v,n);
    free(v);
}
