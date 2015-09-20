#include <stdio.h>
#include <stdlib.h>
struct coord {int x; int y; int fecho};
int sentido (struct coord a, struct coord b, struct coord c)
{
    int i =(b.y - a.y)*(c.x - b.x)-(b.x - a.x)*(c.y - b.y);
    if (i<0) return 2;//Esta no anti-horario.
    else
    if (i>0) return 1;//Esta no horario.
    else return 0;//Sao colineares.
}
void fecho_convexo(struct coord * p,int n)
{
    int i,j,k,l;
    if (n<3)//não teremos um poligono, entao todos os pontos estao no fecho
    {
        for (i=0;i<n;i++)
        {
            p[i].fecho=1;
            printf("oi");
        }
        return;
    }
    k=0;
    for (i = 1; i< n; i++)//Para achar o ponto na extrema esquerda mais a baixo.
    {
        if (p[i].x < p[k].x)k=i;
        if (p[i].x==p[k].x&&p[i].y<p[k].y)k=i;
    }
    j=k;
    do
    {
        l=(j+1)%n;//vai para o proximo, volta para o 0 se l for igual a n-1
        for (i=0;i<n;i++)
        {
            if (sentido(p[j], p[i], p[l]) == 2)
                l = i;
        }
        p[j].fecho=1;
        j=l;
    }
    while (j != k);
}
void main()
{
    int n, i;
    struct coord * p;
    printf("Ola, resolveremos o problema do \"Fecho Convexo\".\nQuantos pontos voce gostaria de entrar? ");
    scanf("%d",&n);
    p = (struct coord*)malloc(n*sizeof(struct coord));
    for (i=0;i<n;i++)
    {
        printf("Ponto %d\nCoordenada x: ",i);
        scanf("%d",&p[i].x);
        printf("Coordenada y: ",i);
        scanf("%d",&p[i].y);
        p[i].fecho=0;
    }
    fecho_convexo(p,n);
    printf("Os pontos do fecho convexo sao:\n");
    for (i=0;i<n;i++)
    {
        if (p[i].fecho==1)
        {
            printf("(%d,%d)\n",p[i].x,p[i].y);
        }
    }
}
