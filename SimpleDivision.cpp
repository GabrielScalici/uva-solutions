#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include <cstring>

#define LIMITE 1001

using namespace std;

int main(int argc, char const *argv[]){
  int num;

  while(cin >> num){
    //Criando um vetor novo para nao atrapalhar outras linhas
    int vet[LIMITE];
    int i = 0;
    int total = 0;
    int aux = 0;
    int temp = 0;
    //Se encontrou o zero aqui, acabaram as entradas
    if(num == 0){
      //Sai do while
      break;
    }else{
      //Anota o primeiro valor no vetor
      vet[i] = num;
      i++;
      while(cin >> num){
        //Condicao para ver se a linha acabou
        if(num == 0){
        //Sai desse while e vai para o proximo (proxima linha)
        break;
        //Senao anota no vetor o proximo numero
        }else{
          vet[i] = num;
          i++;
        }
      }
      //Comecar fazer a conta analisando o vetor com os inteiros armazenados
      for(int j = 1; j < i; j++){
        //Caso especial para a posicao 1 e 0 do vetor
        if(j == 1){
          //subtraindo os valores
          total = vet[1] - vet[0];
          //Pode dar negativo entao pegar o modulo
          total = abs(total);
        }else{//caso nao sejam os primeiros valores
            //subtraindo os outros valores armazenados no vetor
            aux = vet[i] - vet[i-1];
            //pegando o modulo
            aux = abs(aux);

            //Atualizando o total, usando total e aux
            if(total == 0){
              total = aux;
            }else if(aux == 0){
              //total continua com o mesmo valor
            }
            //realizando as contas com mod
            int aux_total = total;
            int aux_aux = aux;
            //Calcula o maior divisor
            while(aux_total%aux_aux != 0){
              //atualiza os valores
              temp = aux_total;
              aux_total = aux_aux;
              aux_aux = temp%aux_aux;
            }

            //atualizando o valor do total
            total = aux_aux;
        }
      }//fim do for com as contas
      cout << total << endl;
    }

  }


  return 0;
}
