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

#define MIN(a,b) ((a)<(b)?(a):(b))
#define N 201
#define DEF 1e9

using namespace std;

//variaveis globais
int corte_1[N], busca[N][N];

int solve(int esquerda, int direita, int ponteiro_es, int ponteiro_dir)
{
    int tamanho = direita - esquerda;
    if (ponteiro_es == ponteiro_dir){
        return tamanho;
    }else if (ponteiro_es > ponteiro_dir){
        return 0;
    }else if (busca[ponteiro_es][ponteiro_dir] != DEF){
        return busca[ponteiro_es][ponteiro_dir];
    }

    for (int i = ponteiro_es; i <= ponteiro_dir; i++){
      //variaveis auxiliares
      int aux0 = busca[ponteiro_es][ponteiro_dir];
      int aux1 = solve(esquerda, corte_1[i], ponteiro_es, i - 1);
      int aux2 = solve(corte_1[i], direita, i + 1, ponteiro_dir) + tamanho;
        //adicionando o valor do minimo
        busca[ponteiro_es][ponteiro_dir] = MIN(aux0, aux1 + aux2);
    }
    //retornando
    return busca[ponteiro_es][ponteiro_dir];
}


int main(int argc, char const *argv[]){

    int tamanho;
    unsigned int quant;

    //percorrendo enquanto houver testes
    while (cin >> tamanho){
        if(tamanho == 0){
          break;
        }
        cin >> quant;
        //pegando os valores
        for(unsigned int i = 0; i < quant; i++)
            cin >> corte_1[i];
        //analisando
        for(int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                //atribuindo o valor padrao
                busca[i][j] = DEF;
            }
        }

        //Vendo a solucao e exibindo para o usuario
        int solucao = solve(0, tamanho, 0, quant - 1);
        cout << "The minimum cutting is " << solucao << "." << endl;

    }
    return 0;
}
