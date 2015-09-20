#include <stdio.h>
#include <stdlib.h>
/* A logica usada nessa resolucao eh a seguinte: se pegarmos o ponto na extrema esquerda, ele estara no fecho.
A partir dai, procuraremos pontos b que facam com que a sequencia anterior->b->c seja sempre no no sentido antihorario ou colinear,
para qualquer ponto c. Quando chegarmos ao inicio teremos um fecho fechado*/
struct coord {int x; int y; int fecho};
int sentido (struct coord a, struct coord b, struct coord c)
{
    int i =(b.y - a.y)*(c.x - b.x)-(b.x - a.x)*(c.y - b.y);
    // A expressao ira dizer se o sentido a->b->c esta no horario, anti-horario, ou se são colineares.
    if (i<0)
    {
        return 0;//Esta no anti-horario.
    }
    else
    {
     if (i>0)
    {
        return 1;//Esta no horario.
    }
    else
    {
        return 2;//Sao colineares.
    }
    }
}
void fecho convexo(struct coord * p,int n)
{
    int i,j,k,l;
    for (int i = 1; i < n; i++)//Para achar o ponto na extrema esquerda.
    {
        if (p[i].x < p[k].x)
        k = i;
    }
    p[k].fecho=1;
    do
    {
    for (i=0;i<n;i++)
    {

    }
    }
    while(l!=k)
}
void main()
{
    int n, i;
    struct coord * p;
    printf("Ola, resolveremos o problema do \"Fecho Convexo\".\nQuantos pontos voce gostaria de entrar? ");
    scanf("%d",&n);
    if (n<3)// Saida no caso de nao formar um poligono.
    {
        printf("Voce nao pode fazer um fecho convexo com menos de 3 pontos!");
        getch();
        return;
    }
    p = (struct coord*)malloc(n*sizeof(struct coord));
    for (i=0;i<n;i++)
    {
        printf("Ponto %d\nCoordenada x: ",i);
        scanf("%d",&p[i].x);
        printf("Coordenada y: ",i);
        scanf("%d",&p[i].y);
        p[i].fecho=0;//Indicara se esta ou nao no fecho.
    }
}
