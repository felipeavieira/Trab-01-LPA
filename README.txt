--------------------------------------------READ ME----------------------------------------------------
Os programas nesta pasta foram elaborados para a disciplina de linguagens de programa��o e Aplica��es,
do curso de Engenharia Mec�nica da Escola de Engenharia de S�o Carlos - EESC/USP

Autores:	Felipe de Alemida Vieira - N� USP: 9312686 - GitHub User Name: felipeavieira
		Tiago Foloni Tessarolli - N� USP: 9312794 - GitHub User Name: tiagoftessarolli

�ndice

1. Ambiente de trabalho e conte�do
2. Tutorial: como compilar o c�digo
3. Tutorial: como usar os progamas

1. Ambiente de trabalho e conte�do

1.1. Os c�digos fonte (.c) foram escritos e compilados no ambiente de desenvolvimento integrado (IDE)
Code::Blocks, vers�o 13.12 rev 9501 gcc 4.7.1 Windows/unicode - 32bit.

1.2. O compilador dos execut�veis (.exe) foi o mingw32-gcc.exe.

1.3. Foram utilizados os seguintes par�metros de compila��o:

Linker settings: -static-libgcc -static-libstdc++

1.4. Em todos os programas foram usadas duas bibliotecas: stdio.h e stdlib.h. No programa do fecho convexo,
foi utilizada, al�m da j� citadas, a biblioteca math.h. As bibliotecas est�o localizadasna pasta "Bibliotecas",
no reposit�rio do trabalho.

1.5. Alguns exemplos de entrada foram dados, e est�o localizados na pasta "Entradas-exemplo". Eles est�o no
formato .txt.

1.6. Os c�digos fonte (.c) e execut�veis (.exe) de todos os quatro programas est�o no reposit�rio do trabalho.

2. Tutorial: como compilar o c�digo

A maneira mais f�cil de compilar um programa em c � utilizando o gcc. A utiliza��o do gcc pode ser feita
por linha de comando no executavel do compilador ou utilizando um IDE, como o Code::Blocks (utilizado 
neste trabalho) ou o Dev-C++. No caso do windows, a vers�o do gcc se chama MinGW, e vem instalada em ambos
os IDEs citados acima.
Acessando o c�digo por um IDE, a compila��o pode ser feita clicando no bot�o Build, localizado na barra de 
tarefas. Ele ir� compilar o programa, criando um arquivo execut�vel na mesma pasta em que se encontra o 
c�digo fonte. Agora voc� poder� usar somente o execut�vel, sem a necessidade de carregar o c�digo.

3. Tutorial: como usar os programas

3.1. Regras gerais
Todos os programas desse diret�rio utilizam somente n�meros inteiros. Caso seja inserido um valor de tipo
diferente, isso poder� ocasionar erros e instabilidade. Ent�o use inteiros, sempre!
Pode ser inserido qualquer inteiro. Caso em alguma ocasi�o exista outra limita��o, o programa ir�
informa-la.
Todos os programas, ap�s exibir os resultados, ir� manter a tela at� que seja precionada um tecla qualquer,
ent�o tome cuidado para n�o perder os resultados por apertar uma tecla sem querer.

3.2. Closest Pair

Esse programa tem como objetivo achar o par (ou pares) de n�meros com menor dist�ncia entre eles.
Para iniciar, entre com o n�mero de inteiros que deseja inserir, sendo n>=2. Preencha as posi��es, digitando
um n�mero e apertando enter, e o programa retornar� a menor dist�ncia e os pares com menor dist�ncia entre os
n�meros. No caso de v�rias entradas iguais, como {5,5,5,5,5}, o programa retornar� a distancia 0 entre 5 e 5,
somente um vez.

3.3. Element Uniqueness

Esse programa tem como objetivo encontrar os elementos que ocorrem somente uma vez.
Para iniciar, entre com o n�mero de inteiros que deseja inserir, sendo n>=1. Preencha as posi��es, digitando
um n�mero e apertando enter e o programa retornar� os elementos que aparecem uma �nica vez.

3.4. Frequency Distribution

Esse programa tem como objetivo encontrar os elementos que ocorrem o maior n�mero de vezes.
Para iniciar, entre com o n�mero de inteiros que deseja inserir, sendo n>=1. Preencha as posi��es, digitando
um n�mero e apertando enter, e o programa retornar� o maior n�mero de repeti��es e quais elementos que tiveram
esse n�mero de repeti��es.

3.5. Convex Hull

Esse programa tem como objetivo encontrar, entre diversos pontos inseridos em um plano cartesiano, 
quais seriam os v�rtice de um pol�gono convexo que contenha todos os pontos inseridos e tenha a menor
�rea poss�vel. � importante lembrar que o programa encontra somente os vertices, portanto se um ponto 
for colinear a dois vertices e estiver entre eles, ele n�o aparecer� na sa�da do programa.
Para iniciar entre com o n�mero de inteiros que deseja inserir, sendo n>=3. Entre com as coordenadas x e y 
de cada ponto, usando o modelo "x y", sem as aspas, sem repetir pontos, e o programa retonar� os pontos que
s�o os v�rtices do pol�gono convexo formado. 
No caso de repeti��o de pontos, o programa geralmente s� imprime o ponto novamente, ou o ignora,
mas existem alguns casos que ele poder� entrar em um looping infinito. Ou seja, melhor n�o repetir.