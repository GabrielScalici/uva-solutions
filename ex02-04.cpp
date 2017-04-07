#include <stdio.h>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>

//definicao para a quantidade de rainhas
#define TAM 8

using namespace std;

//variavel global pois facilita usar na recursiva
int cont_linhas = 0;

int verifica(int posicao, int linha, int lista[TAM + 1]){
  //variaveis auxiliares para pegar o valor em modulo
  int num1;
  int num2;
    //percorrendo todas as posicoes possiveis
    for(int i = 1; i <= posicao - 1; i++){
      //usando os valores em modulo
      num1 = abs(lista[i] - linha);
      num2 = abs(i - posicao);
        //verifica se os valores sao iguais
      if(lista[i] == linha || num1 == num2){
        //caso de problema ja retorna
        return true;
      }
    }
    //se passou por tudo e nao deu problema
    return false;
}

//funcao recursiva que faz backtracking
void recursivo(int pos, int lista[TAM + 1], int a, int b){
    //enquanto nao chegar no final das linhas
    for(int i = 1; i <= TAM ; i++){
        //verifica se eh uma posicao valida
        if(verifica(pos, i, lista) == false){
            //coloca na lista
            lista[pos] = i;
            //verifica se eh igual ou se ja chegou no final
            if(lista[b] == a && pos == TAM){
                //exibe pois todas as rainhas foram colocadas
                if(cont_linhas < 9){
                  cout << " " << cont_linhas + 1 << "      " << lista[1];
                }else{
                  cout << cont_linhas + 1 << "      " << lista[1];
                }
                //aumenta a variavel global so para exibicao
                cont_linhas++;
                //imprimindo toda a lista
                for(int j = 2; j <= TAM; j++){
                    cout << " " << lista[j];
                }
                cout << "\n";
            } // end if interno
            //caso contrario chama a funcao novamente para a proxima posicao
            else{
                //chamada recursiva
                recursivo(pos + 1, lista, a, b);
            }
        }//end if externo
    }//end for
}

//funcao para mostrar o basico do output
void mostra(){
  cout << "SOLN\tCOLUMN\n";
  cout << " #\t1 2 3 4 5 6 7 8\n\n";
}

int main(int argc, char const *argv[]){
    //cria com tudo setado zerado
    int lista[TAM + 1] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int cont = 0;
    int n, lin, col;

    //pegando a quantidade de casos
    cin >> n;

    //enquanto nao pegar todas as linhas
    while(cont < n){
        //pegando a posicao inicial da rainha
        cin >> lin;
        cin >> col;
        //exibe o basico antes de mostrar a solucao
        mostra();
        //chamando a funcao recursiva
        recursivo(1, lista, lin, col);

        //para nao ter \n no ultimo
        if(cont != n-1){
        cout << "\n";
        }

        //zerando para as proximas analises
        cont_linhas = 0;
        cont++;
    }
    return 0;
}
