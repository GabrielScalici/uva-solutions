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

    }


  }


  return 0;
}
