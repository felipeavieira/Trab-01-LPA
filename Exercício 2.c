#include <stdio.h>
#include <stdlib.h>
struct elementos {int num; struct elementos* prox};
void troca (int* v, int a, int b)
{
    int temp = v[a];
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
void add (int i,struct elementos* q)
{
    struct elementos *novo = (struct elementos*)malloc(sizeof(struct elementos));
    novo->num=i;
    novo->prox=q;
    q=novo;
}
void printnfree(struct elementos* w)
{
    struct elementos *temp;
    while (w=!NULL)
    {
        printf("%d ", w->num);
        temp=w;
        w=w->prox;
        free(temp);
    }
}
void unicos (int*v,int n)
{
    int cont = 0,i;
    struct elementos *lista = NULL;
    for (i=0;i<n;i++)
    {
        if (i==n-1)
        {
            if (v[i]=!v[i-1])
            {
                add(v[i],lista);
                cont++;
            }
        }
        else
        {
            if (v[i]!=v[i+1])
            {
                add(v[i],lista);
                cont++;
            }
            else
            {
                while (v[i]==v[i+1]&&i<n-2)
                {
                    i++;
                }
            }
        }
    }
    if (cont==0)
    {
        printf("Nao foram encontrados valores com somente uma ocorrencia");
    }
    else
    {
        printf("Foram encontrados %d numeros com uma ocorrencia, eles sao: ", cont);
        printnfree(lista);
    }
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
    unicos(v,n);
    free(v);
}
