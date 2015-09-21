#include <stdio.h>
#include <stdlib.h>
/* Esse programa funciona achando o ponto na extrema esquerda mais para baixo, que com certeza estara no fecho,
e entao rotacionando no sentido anti-horario para achar os vertices do fecho, ate chegarmos no inicio novamente.
Os vertices são encontrados testando o sentido de rotação no sentido ponto do fecho-> qualquer ponto -> ponto a ser testado.*/
struct coord {int x; int y; int fecho};
int sentido (struct coord a, struct coord b, struct coord c)// Essa funcao dará o sentido de rotacao dos pontos a->b->c.
{
    int i =(b.y - a.y)*(c.x - b.x)-(b.x - a.x)*(c.y - b.y);
    if (i<0) return 2;//Anti-horario.
    else
    if (i>0) return 1;//Horario.
    else return 0;//Colineares.
}
void fecho_convexo(struct coord * p,int n)//Acharemos os pontos do fecho.
{
    int i,j,k=0,l; //O k foi inicializado pois sera a posicao inicial do ponto extremo.
    if (n<3)//Não teremos um poligono, entao todos os pontos estao no fecho.
    {
        for (i=0;i<n;i++)
        {
            p[i].fecho=1;
        }
        return;
    }
    for (i = 1; i< n; i++)//Para achar o ponto na extrema esquerda mais a baixo.
    {
        if (p[i].x < p[k].x)k=i;
        if (p[i].x==p[k].x&&p[i].y<p[k].y)k=i;
    }
    j=k;
    do//Acharemos todos os vertices do fecho, pontos nas linhas ou repetidos são ignorados.
    {
        l=(j+1)%n;//Vai para o proximo ponto, volta para o 0 se l for igual a n-1.
        for (i=0;i<n;i++)
        {
            if (sentido(p[j], p[i], p[l]) == 2)l = i;// Realiza o teste do sentido com todos os pontos.
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
    printf("Ola, resolveremos o problema do \"Fecho Convexo\".\nQuantos pontos voce gostaria de entrar? ");
    scanf("%d",&n);
    if (n<1)//Para evitar comparacoes com o vazio ou lixo.
    {
        printf("Voce deve entrar com pelo menos um ponto!");
        getch();//Para segurar a tela.
        return;
    }
    p = (struct coord*)malloc(n*sizeof(struct coord));// Alocacao dinamica para preencher pontos
    for (i=0;i<n;i++)
    {
        printf("Ponto %d\nCoordenada x: ",i);
        scanf("%d",&p[i].x);
        printf("Coordenada y: ",i);
        scanf("%d",&p[i].y);
        p[i].fecho=0;//Inicializa a marcacao de presente ou nao no fecho.
    }
    fecho_convexo(p,n);
    printf("Os pontos do fecho convexo sao:\n");//Imprime os pontos marcados pela funcao fecho_convexo.
    for (i=0;i<n;i++)
    {
        if (p[i].fecho==1) printf("(%d,%d)\n",p[i].x,p[i].y);
    }
    free(p);
    getch();//So para segurar a tela.
}
