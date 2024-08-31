#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// OBS

// No meu IDE o system("clear"); nao e reconhecido, entao eu utilizo o system("cls"); tem a msm funçao

// VARIAVEIS

int Matriz[3][3]; // A matriz de 2x2 nao precisa ser setada pois aqueles que nao sao definidos ficam como 0, entao matriz de 2x2 usando essa de 3x3 ficaria: linha 1 - [1][2][0] linha 2 - [3][4][0] linha 3 - [0][0][0]
int Tipo, Escolha, Menor, Maior, Mediano;

// DETERMINANTE

int CalcularDeterminante(int matriz[3][3], int Tipo){

/*

    Calcular determinante e na diagonal, exemplo:

    [1]   [2] = (1 * 4) - (2 * 3)     [1]   [2]   [3] |  essa parte e um espelho do inicio |  = (1 * 5 * 9) - (2 * 6 * 7) - (3 * 4 * 8)
        X                                 \     \     | \                                  |
    [3]   [4]                         [4]   [5]   [6] |  [4]                               |
   .                                            \     | \    \                             |
   .                                  [7]   [8]   [9] |  [7]  [8]                          |                           

*/

    Tipo++; //Adiciona 1 ao tipo da matriz, pois ela e escolhida por : Matriz 2x2 = 1, Matriz 3x3 = 2, logo somando 1 a escolha, ele se torna o numero da matriz 

    if (Tipo ==2 ) { //Verifica se a Matriz e de 2x2 ou 3x3
        return (matriz[0][0] * matriz[1][1]) - (matriz[0][1] * matriz[1][0]);
    }else if (Tipo == 3 ) {
        return (matriz[0][0] * matriz[1][1] * matriz[2][2]) - (matriz[0][1] * matriz[1][0] * matriz[0][2]) - (matriz[2][0] * matriz[0][1] * matriz[1][2]);
    }

    return 0;

};

// DIAGONAL

int CalcularDiagonal(int matriz[3][3]){

    /*
    
    O for e usado para pegar o valor na diagonal para somar

    primeiro loop - i = 0 | logo ele pegara o valor que esta na matriz[0][0]
    segundo loop - i = 1 | logo ele pegara o valor que esta na matriz[1][1]
    Terceiro loop - i = 2 | logo ele pegara o valor que esta na matriz[2][2]
    e assim por diante ate completar o tamanho da matriz

    */

    int SomaD = 0;

    for (int i = 0; i < Tipo+1; i++) {
        SomaD += matriz[i][i];
    }

    return SomaD;

};

// MENOR / MAIOR / MEDIANO

int CalcularMenorMaiorMediano(int matriz[3][3], int Tipo){

    int MedianoTemp[9], pos = 0;

    /*
    
    Aqui criamos duas variaveis, a primeira e um vetor temporario para ordenar a matriz em ordem crescente, a segunda e a posiçao desse vetor

    */

    for (int i = 0; i < Tipo+1; i++) { //Loop para adicionar todos os valores da matriz no vetor
        for (int ii = 0; ii < Tipo+1; ii++) {
            MedianoTemp[pos++] = matriz[i][ii]; //A cada loop o [pos++] setara 1 a variavel de posiçao para ir ordenando ( ainda nao em forma crescente )
        }
    }



    for (int i = 0; i < pos-1; i++) {//Loop para ordenar o vetor em ordem crescente | OBS : o pos aqui ja esta com o valor 9

        for (int ii = i+1; ii < pos; ii++) {

            /*
            
            Esse ja e mais complexo de explicar, mas eu darei o meu melhor!

            ta, o segundo loop ja começa com i+1 pois precisa esta sempre a frente do primeiro loop, pois se a posiçao do primeiro loop [0] ter o valor maior que a do segundo loop [1], entao eles serao trocados de lugar
            usando uma variavel temporaria, na qual vai armazenar a informaçao da variavel do primeiro loop, essa variavel vai ser substituida pela do segundo loop, e logo apos a do segundo loop sera substituida
            pelo valor que esta na variavel temporaria, exemplo

            vetor[4] = 10, 3, 7, 5;

            vetor[0] (10) > vetor[1] (3) entao
            {

            temp = vetor[0]; (10)
            vetor[0] = vetor[1]; (3)
            vetor[1] = temp; (10)

            }

            ficando assim: vetor[4] = 3, 10, 7, 5

            e ai ele faz o segundo loop avançar:


            lembrando que o vetor foi modificado ficando: (3, 10, 7, 5)

            vetor[1] (10) > vetor[2] (7) entao
            {

            temp = vetor[1]; (10)
            vetor[1] = vetor[2]; (7)
            vetor[2] = temp; (10)

            }

            ficando assim: vetor[4] = 3, 7, 10, 5

            */

            if (MedianoTemp[i] > MedianoTemp[ii]) {

                int temp = MedianoTemp[i];
                MedianoTemp[i] = MedianoTemp[ii];
                MedianoTemp[ii] = temp;

            }

        }

    }

    /*

    Aqui e mais simples que a anterior

    a variavel menor ira pegar o primeiro valor da variavel temporaria na qual ja esta em ordem crescente, logo ele pegara o menor.
    a variavel maior ira pegar o valor da posiçao-1, que sera o ultimo, afinal vetores começam por 0, logo o ultimo valor sera 8, e ja que a variavel posiçao esta setada como 9, ela precisa ser subtraida por 1.
    a variavel mediano sera pega dividindo a posiçao por 2, assim pegando a posiçao que esta mais proximo do meio do vetor.
    */

    Menor = MedianoTemp[0];
    Maior = MedianoTemp[pos-1];
    Mediano = MedianoTemp[pos/2];

};

// Requisiçoes

int Requisicao(){

    printf("escolha o tamanho da matriz \n");
    printf("Matriz 2x2 = 1\n");
    printf("Matriz 3x3 = 2\n");
    scanf("%d", &Tipo);
    system("cls"); // system("clear"); nao e reconhecido pelo meu pc (motivo: nao sei kkkk)

    return Tipo;    

}

int Requisicao2x2(){

    // Apenas uma interface bonitinha

    printf("Linha 1 [*] [0]\n");
    printf("Linha 2 [0] [0]\n");
    scanf("%i", &Matriz[0][0]);

    system("cls");
    printf("Linha 1 [%d] [*]\n",Matriz[0][0]); 
    printf("Linha 2 [0] [0]\n");
    scanf("%i", &Matriz[0][1]);

    system("cls");
    printf("Linha 1 [%d] [%d]\n",Matriz[0][0], Matriz[0][1]);
    printf("Linha 2 [*] [0]\n");
    scanf("%i", &Matriz[1][0]);

    system("cls");
    printf("Linha 1 [%d] [%d]\n",Matriz[0][0], Matriz[0][1]);
    printf("Linha 2 [%d] [*]\n",Matriz[1][0]);
    scanf("%i", &Matriz[1][1]);

    system("cls");
    printf("Linha 1 [%d] [%d]\n",Matriz[0][0], Matriz[0][1]);
    printf("Linha 2 [%d] [%d]\n\n",Matriz[1][0] ,Matriz[1][1]);

    // Parte do Calculos

    printf("Determinante : %d \n",CalcularDeterminante(Matriz, Tipo));
    printf("Soma Diagonal : %d \n",CalcularDiagonal(Matriz));

    CalcularMenorMaiorMediano(Matriz, Tipo); // A funçao e chamada para definir as variaveis que serao usadas a seguir para os seus respectivos calculos.
    printf("Menor : %d\n", Menor);
    printf("Maior : %d\n", Maior);
    printf("Mediano : %d\n", Mediano);

}

int Requisicao3x3(){

    // Mesma coisa que a funçao de Requisiçao 2x2 so que com 1 linha a mais

    printf("Linha 1 [*] [0] [0]\n");
    printf("Linha 2 [0] [0] [0]\n");
    printf("Linha 3 [0] [0] [0]\n");
    scanf("%i", &Matriz[0][0]);

    system("cls");
    printf("Linha 1 [%d] [*] [0]\n",Matriz[0][0]); 
    printf("Linha 1 [0] [0] [0]\n");
    printf("Linha 3 [0] [0] [0]\n");
    scanf("%i", &Matriz[0][1]);

    system("cls");
    printf("Linha 1 [%d] [%d] [*]\n",Matriz[0][0], Matriz[0][1]);
    printf("Linha 2 [0] [0] [0]\n");
    printf("Linha 3 [0] [0] [0]\n");
    scanf("%i", &Matriz[0][2]);

    system("cls");
    printf("Linha 1 [%d] [%d] [%d]\n",Matriz[0][0], Matriz[0][1], Matriz[0][2]);
    printf("Linha 2 [*] [0] [0]\n");
    printf("Linha 3 [0] [0] [0]\n");
    scanf("%i", &Matriz[1][0]);

    system("cls");
    printf("Linha 1 [%d] [%d] [%d]\n",Matriz[0][0], Matriz[0][1], Matriz[0][2]);
    printf("Linha 2 [%d] [*] [0]\n",Matriz[1][0]);
    printf("Linha 3 [0] [0] [0]\n");
    scanf("%i", &Matriz[1][1]);

    system("cls");
    printf("Linha 1 [%d] [%d] [%d]\n",Matriz[0][0], Matriz[0][1], Matriz[0][2]);
    printf("Linha 2 [%d] [%d] [*]\n",Matriz[1][0], Matriz[1][1]);
    printf("Linha 3 [0] [0] [0]\n");
    scanf("%i", &Matriz[1][2]);

    system("cls");
    printf("Linha 1 [%d] [%d] [%d]\n",Matriz[0][0], Matriz[0][1], Matriz[0][2]);
    printf("Linha 2 [%d] [%d] [%d]\n",Matriz[1][0], Matriz[1][1], Matriz[1][2]);
    printf("Linha 3 [*] [0] [0]\n");
    scanf("%i", &Matriz[2][0]);

    system("cls");
    printf("Linha 1 [%d] [%d] [%d]\n",Matriz[0][0], Matriz[0][1], Matriz[0][2]);
    printf("Linha 2 [%d] [%d] [%d]\n",Matriz[1][0], Matriz[1][1], Matriz[1][2]);
    printf("Linha 3 [%d] [*] [0]\n",Matriz[2][0]);
    scanf("%i", &Matriz[2][1]);

    system("cls");
    printf("Linha 1 [%d] [%d] [%d]\n",Matriz[0][0], Matriz[0][1], Matriz[0][2]);
    printf("Linha 2 [%d] [%d] [%d]\n",Matriz[1][0], Matriz[1][1], Matriz[1][2]);
    printf("Linha 3 [%d] [%d] [*]\n",Matriz[2][0], Matriz[2][1]);
    scanf("%i", &Matriz[2][2]);

    system("cls");
    printf("Linha 1 [%d] [%d] [%d]\n",Matriz[0][0], Matriz[0][1], Matriz[0][2]);
    printf("Linha 2 [%d] [%d] [%d]\n",Matriz[1][0], Matriz[1][1], Matriz[1][2]);
    printf("Linha 3 [%d] [%d] [%d]\n",Matriz[2][0], Matriz[2][1], Matriz[2][2]);


    // Aqui nao muda nada entre a 2x2

    printf("Determinante : %d \n",CalcularDeterminante(Matriz, Tipo));
    printf("Soma Diagonal : %d \n",CalcularDiagonal(Matriz));

    CalcularMenorMaiorMediano(Matriz, Tipo);
    printf("Menor : %d\n", Menor);
    printf("Maior : %d\n", Maior);
    printf("Mediano : %d\n", Mediano);

}

// ---------------

int main() {

    // Considero boa pratica deixar o Main limpo para facil manutençao, afinal tudo que precisa fica organizado usando as funçoes,
    // caso precise mudar algo na requisiçao 2x2 e so ir na funçao 2x2 ao invez de procurar pelo codigo todo.

    Requisicao();

    if (Tipo == 1)
    {
        Requisicao2x2();
    }
    else if (Tipo == 2)
    {
        Requisicao3x3();
    }

    return 0;

}