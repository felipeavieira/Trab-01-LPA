--------------------------------------------READ ME----------------------------------------------------
Os programas nesta pasta foram elaborados para a disciplina de linguagens de programação e Aplicações,
do curso de Engenharia Mecânica da Escola de Engenharia de São Carlos - EESC/USP

Autores:	Felipe de Alemida Vieira - Nº USP: 9312686 - GitHub User Name: felipeavieira
		Tiago Foloni Tessarolli - Nº USP: 9312794 - GitHub User Name: tiagoftessarolli

Índice

1. Ambiente de trabalho e conteúdo
2. Tutorial: como compilar o código
3. Tutorial: como usar os progamas

1. Ambiente de trabalho e conteúdo

1.1. Os códigos fonte (.c) foram escritos e compilados no ambiente de desenvolvimento integrado (IDE)
Code::Blocks, versão 13.12 rev 9501 gcc 4.7.1 Windows/unicode - 32bit.

1.2. O compilador dos executáveis (.exe) foi o mingw32-gcc.exe.

1.3. Foram utilizados os seguintes parâmetros de compilação:

Linker settings: -static-libgcc -static-libstdc++

1.4. Em todos os programas foram usadas duas bibliotecas: stdio.h e stdlib.h. No programa do fecho convexo,
foi utilizada, além da já citadas, a biblioteca math.h. As bibliotecas estão localizadasna pasta "Bibliotecas",
no repositório do trabalho.

1.5. Alguns exemplos de entrada foram dados, e estão localizados na pasta "Entradas-exemplo". Eles estão no
formato .txt.

1.6. Os códigos fonte (.c) e executáveis (.exe) de todos os quatro programas estão no repositório do trabalho.

2. Tutorial: como compilar o código

A maneira mais fácil de compilar um programa em c é utilizando o gcc. A utilização do gcc pode ser feita
por linha de comando no executavel do compilador ou utilizando um IDE, como o Code::Blocks (utilizado 
neste trabalho) ou o Dev-C++. No caso do windows, a versão do gcc se chama MinGW, e vem instalada em ambos
os IDEs citados acima.
Acessando o código por um IDE, a compilação pode ser feita clicando no botão Build, localizado na barra de 
tarefas. Ele irá compilar o programa, criando um arquivo executável na mesma pasta em que se encontra o 
código fonte. Agora você poderá usar somente o executável, sem a necessidade de carregar o código.

3. Tutorial: como usar os programas

3.1. Regras gerais
Todos os programas desse diretório utilizam somente números inteiros. Caso seja inserido um valor de tipo
diferente, isso poderá ocasionar erros e instabilidade. Então use inteiros, sempre!
Pode ser inserido qualquer inteiro. Caso em alguma ocasião exista outra limitação, o programa irá
informa-la.
Todos os programas, após exibir os resultados, irá manter a tela até que seja precionada um tecla qualquer,
então tome cuidado para não perder os resultados por apertar uma tecla sem querer.

3.2. Closest Pair

Esse programa tem como objetivo achar o par (ou pares) de números com menor distância entre eles.
Para iniciar, entre com o número de inteiros que deseja inserir, sendo n>=2. Preencha as posições, digitando
um número e apertando enter, e o programa retornará a menor distância e os pares com menor distância entre os
números. No caso de várias entradas iguais, como {5,5,5,5,5}, o programa retornará a distancia 0 entre 5 e 5,
somente um vez.

3.3. Element Uniqueness

Esse programa tem como objetivo encontrar os elementos que ocorrem somente uma vez.
Para iniciar, entre com o número de inteiros que deseja inserir, sendo n>=1. Preencha as posições, digitando
um número e apertando enter e o programa retornará os elementos que aparecem uma única vez.

3.4. Frequency Distribution

Esse programa tem como objetivo encontrar os elementos que ocorrem o maior número de vezes.
Para iniciar, entre com o número de inteiros que deseja inserir, sendo n>=1. Preencha as posições, digitando
um número e apertando enter, e o programa retornará o maior número de repetições e quais elementos que tiveram
esse número de repetições.

3.5. Convex Hull

Esse programa tem como objetivo encontrar, entre diversos pontos inseridos em um plano cartesiano, 
quais seriam os vértice de um polígono convexo que contenha todos os pontos inseridos e tenha a menor
área possível. É importante lembrar que o programa encontra somente os vertices, portanto se um ponto 
for colinear a dois vertices e estiver entre eles, ele não aparecerá na saída do programa.
Para iniciar entre com o número de inteiros que deseja inserir, sendo n>=3. Entre com as coordenadas x e y 
de cada ponto, usando o modelo "x y", sem as aspas, sem repetir pontos, e o programa retonará os pontos que
são os vértices do polígono convexo formado. 
No caso de repetição de pontos, o programa geralmente só imprime o ponto novamente, ou o ignora,
mas existem alguns casos que ele poderá entrar em um looping infinito. Ou seja, melhor não repetir.