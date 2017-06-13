#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <cstdio>

using namespace std;

#define TAM 50
#define GRANDE 1000000

int matrix[TAM][TAM];

int caminhos_total(int n,int k){
    int res;
    //condicao de parada
    if(k < 0 || n < 0 ){
        //retorna 0 para a recursao
        return 0;
    }
    //verificando se eh valido
    if(matrix[n][k] != -1){
        //ja retorna o valor
        return matrix[n][k];
    }else{
        //senao realiza as contas
        res = 0;
        for(int i = 0; i <= n; i++){
            //soma ate onde der
            res += (caminhos_total(n-i,k-1) % GRANDE);
        }
        //retorna depois de todas as contas
        return matrix[n][k] = res % GRANDE;
    }
}

int main(int argc, char const *argv[]){

    //Percorrendo para setar os valores iniciais
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            //Vai setado -2
            matrix[i][j]= -1;
        }
        //Seta 1
        matrix[0][0] = 1;
    }

    //Rodando as entradas do usuario
    int num1 ,num2;
    //percorrendo todas as entradas
    while(cin >> num1){
      cin >> num2;
      //caso encontre o 0 acabaram as entradas
      if(num1 == 0 || num2 == 0){
        break;
      }else{
        //chamar a funcao recursiva e já exibir
        cout << caminhos_total(num1,num2) << endl;
      }
    }

    return 0;
}
