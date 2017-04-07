#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include <cstring>

using namespace std;

//transformar o numero de negativo para positivo, facilitar comparacao
int transforma(int num){
  return num * (-1);
}

int main(int argc, char const *argv[]){
  int num = 0;
  int tmp_pilha = 0;
  int tmp_soma = 0;
  int aux = 1;
  int aux_soma = 0;
  //Fazendo com char[] para funcionar fgets
  char linha[100];

  while(fgets(linha, 100, stdin)){
    aux = 1;
    //declarando as pilhas
    stack <int> pilha;
    stack <int> soma_interna;
    //dividir no espaco
    char* pedaco = strtok(linha , " ");
    //Enquanto ouver numero lido na linha
    while(pedaco){
      //transformando para inteiro o que foi lido
      num = atoi(pedaco);
      //Se for negativo, coloca na pilha
      if(num < 0){
          pilha.push(transforma(num));
          soma_interna.push(0);
          //senao analisa o valor positivo com os valores na pilha
      }else{
          //caso a pilha ja esteja vazia
          if(pilha.empty() == true){
            //Seta 0 para auxiliar e ja para a analise
            aux = 0;
            break;
          }
          //Armazenar valor para soma
          tmp_soma = soma_interna.top();
          soma_interna.pop();
          //Armazena o valor para pilha
          tmp_pilha = pilha.top();
          pilha.pop();

          if(tmp_soma >= num || tmp_pilha != num){
            //Seta 0 para auxiliar e ja para a analise
            aux = 0;
            break;
          }
          //verificando a pilha de soma valida
          if(soma_interna.empty() == false){
             aux_soma = soma_interna.top();
             soma_interna.pop();
             //coloca novamente na pilha
             soma_interna.push(aux_soma + num);
          }
      }
     //para conseguir pegar o proximo numero
     pedaco = strtok(NULL , " ");

    }
    //Analisando booleana auxiliar e verificando se a pilha esta vazia
    if(aux == 1 && pilha.empty() == true){
      //booleana verdadeira e pilha vazia
      printf(":-) Matrioshka!\n");
    }else{
      //Caso a booleana tenha dado falso em algum passo ou a pilha nao esteja vazia
      printf(":-( Try again.\n");
    }
  }
 return 0;
}
