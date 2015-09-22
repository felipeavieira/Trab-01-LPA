#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* Esse programa funciona achando o ponto na extrema esquerda mais para baixo, que com certeza estara no fecho,
e entao rotacionando no sentido anti-horario para achar os vertices do fecho, ate chegarmos no inicio novamente.
Os vertices são encontrados testando o sentido de rotação no sentido (ponto do fecho)->(qualquer ponto)->(ponto a ser testado).*/
struct coord {int x; int y; int fecho};
int dist (struct coord p, struct coord a, struct coord b, int na, int nb)
{//Essa funcao dara qual ponto esta mais proximo de p. Isso servira para quando os pontos forem colineares, ele pegara só o mais distante.
    float dista, distb;
    dista = sqrt((p.x-a.x)*(p.x-a.x)+(p.y-a.y)*(p.y-a.y));
    distb = sqrt((p.x-b.x)*(p.x-b.x)+(p.y-b.y)*(p.y-b.y));
    if (dista>distb)
        return na;
    else
        return nb;
}
int sentido (struct coord a, struct coord b, struct coord c)// Essa funcao dará o sentido de rotacao dos pontos a->b->c.
{
    int i =(b.y - a.y)*(c.x - b.x)-(b.x - a.x)*(c.y - b.y);
    if (i==0)
        return 0;//Colineares.
    return (i>0)? 1:2;//1 -Horario ou 2-Anti-horario.
}
void fecho_convexo(struct coord * p,int n)//Acharemos os pontos do fecho.
{
    int i,j,k=0,l; //O k foi inicializado pois sera a posicao inicial do ponto extremo.
    for (i = 1; i< n; i++)//Para achar o ponto na extrema esquerda mais a baixo.
    {
        if (p[i].x < p[k].x)
            k=i;
        if (p[i].x==p[k].x&&p[i].y<p[k].y)
            k=i;
    }
    j=k;
    do//Acharemos todos os vertices do fecho, pontos nas linhas são ignorados.
    {
        l=(j+1)%n;//Vai para o proximo ponto, volta para o 0 se l for igual a n-1.
        for (i=0;i<n;i++)
        {
                if (sentido(p[j], p[i], p[l]) == 0)
                    l = dist(p[j],p[i],p[l],i,l);// Se forem colineares, a funcao dará o mais distante.
                    else
                        if (sentido(p[j], p[i], p[l]) == 2)
                            l = i;// Realiza o teste do sentido com todos os pontos.
        }
        p[j].fecho=1;//Marca o ponto como vertice
        j=l;
    }
    while (j != k);
}
void main()
{
    int n, i;
    struct coord * p;
    printf("Ola, resolveremos o problema do \"Fecho Convexo\". So use inteiros nesse programa e nao repita pontos.\nQuantos pontos voce gostaria de entrar? ");
    scanf("%d",&n);
    if (n<3)//Um poligono precisa ter tres pontos no minimo!!
    {
        printf("Voce deve entrar com pelo menos tres pontos para formar um poligono!");
        getch();//Para segurar a tela.
        return;
    }
    p = (struct coord*)malloc(n*sizeof(struct coord));// Alocacao dinamica para preencher pontos
    printf("Entre com os pontos no formato \"x y\", sem as aspas. Nao esqueca do espaco!\n");
    for (i=0;i<n;i++)
    {
        printf("Ponto %d: ",i);
        scanf("%d %d",&p[i].x, &p[i].y);
        p[i].fecho=0;//Inicializa a marcacao de presente ou nao no fecho.
    }
    fecho_convexo(p,n);
    printf("Os pontos do fecho convexo sao:\n");//Imprime os pontos marcados pela funcao fecho_convexo.
    for (i=0;i<n;i++)
    {
        if (p[i].fecho==1)
            printf("(%d,%d)\n",p[i].x,p[i].y);
    }
    free(p);
    getch();//So para segurar a tela.
}
