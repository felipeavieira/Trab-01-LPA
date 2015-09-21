#include <stdio.h>
#include <stdlib.h>
struct reps {int num; int rep; struct reps* prox};
void troca(int *v, int a, int b)//Funcao de troca que sera usada no quicksort
{
    int temp=v[a];
    v[a]=v[b];
    v[b]=temp;
}
void quicksort (int *v,int f, int l)// Funcao com o algorismo de ordenacao quicksort
{
    if(f>=l) return;
    int p=rand()%(l-f+1)+f;
    troca(v,p,f);
    p=f;
    int i=f, j=l;
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
struct reps * add_rep (int j, int k, struct reps* s)
{
    struct reps *novo = (struct reps*)malloc(sizeof(struct reps));
    novo->num=j;
    novo->rep=k;
    novo->prox=s;
    return novo;
}
void printnfree2 (int j, struct reps*s)
{
    struct reps *temp;
    printf("O maior numero de repeticoes foi de %d dos seguintes inteiros:\n",j);
    while (s!=NULL)
    {
        if (s->rep==j) printf("%d\n", s->num);
        temp=s->prox;
        free(s);//Liberacao da lista.
        s=temp;
    }
}
void test (struct reps*s) //Funcao que acha o maior numero de repeticoes e o passa para funcao de impressao.
{
    struct reps * t = s;
    int i,j;
    j=t->rep;
    while (t!=NULL)
    {
        if ((t->rep)>j) j=t->rep;
        t=t->prox;
    }
    printnfree2 (j,s);
}
void repetition (int*v,int n)// funcao que cria uma lista que relaciona os numeros entrados e suas repeticoes.
{
    int i,j,k=0;
    struct reps * lista = NULL;// Inicializa a lista
    i=0;
    while (i<n)
    {
        j=v[i];
        k=0;
        do
        {
            k++;
            i++;
        }
        while (v[i]==v[i-1]&&i!=n);
        lista = add_rep(j,k,lista);
    }
    test(lista);
}
void main()
{
    int *v,n,i;
    printf("Ola, quantos valores voce pretende entrar? ");
    scanf("%d",&n);
    if (n<1)//Para evitar comparacoes com o vazio ou lixo.
    {
        printf("Voce deve entrar com pelo menos um ponto!");
        getch();//Para segurar a tela.
        return;
    }
    v=calloc(n,sizeof(int));//alocação dinamica para preencher v com quantos numeros for preciso
    for(i=0;i<n;i++)//preenchimento de v
    {
        printf("Entre com um numero para a posicao %d: ",i);
        scanf("%d",&v[i]);
    }
    quicksort(v,0,n-1);
    repetition(v,n);
    free(v);
    getch(); //Para segurar a tela
}
