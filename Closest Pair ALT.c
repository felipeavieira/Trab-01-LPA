#include <stdio.h>
#include <stdlib.h>
void troca(int *v, int a, int b)//Funcao de troca que sera usada no quicksort.
{
    int temp=v[a];
    v[a]=v[b];
    v[b]=temp;
}
void quicksort (int *v,int f, int l)// Funcao com o algoritmo de ordenacao quicksort.
{
    if(f>=l) return;
    int p=rand()%(l-f+1)+f;
    troca(v,p,f);
    p=f;
    int i=f;
    int j=l;
    while(i<j)
    {
        while (v[i]<=v[p]&&i<=l) i++;
        while (v[j]>v[p]) j--;
        if (j>i) troca(v,i,j);
    }
    troca(v,j,p);
    quicksort(v,f,j-1);
    quicksort(v,j+1,l);
}
void pares(int *v, int n) //Compara, encontra menor diferenca e imprime.
{
    int dif, i;
    dif = v[1]-v[0];
    //Esse "for" ira comparar diferenca de valores e parar ao chegar ao final ou achar dois numeros iguais.
    for (i=1; i<n-1&&dif>0; i++)
    {
        if ((v[i+1]-v[i])<dif)
        {
            dif=v[i+1]-v[i];
        }
    }
    printf("A menor diferenca entre dois numeros foi de %d entre os seguintes inteiros:\n",dif);
    for (i=0;i<n-1;i++)
    {
        if (v[i+1]-v[i]==dif&&(v[i]!=v[i-1]||i==0)) printf("%d e %d\n",v[i],v[i+1]);
        //imprime se tiver a menor diferenca, e nao deixa repetir valores em caso de varias entradas iguais.
    }
}
void main()
{
    int *v,n,i;
    printf("Ola, quantos valores voce pretende entrar? ");
    scanf("%d",&n);
    if (n<2) // Para evitar comparacoes com vazio ou lixo
    {
        printf("Voce deve inserir pelo menos 2 numeros!");
        return;
    }
    v=calloc(n,sizeof(int));//alocação dinamica para preencher v com quantos numeros for preciso
    for(i=0;i<n;i++)//preenchimento de v
    {
        printf("Entre com um numero para a posicao %d: ",i);
        scanf("%d",&v[i]);
    }
    quicksort(v,0,n-1);
    pares(v,n);
    free(v);
}
