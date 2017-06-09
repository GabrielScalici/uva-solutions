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

#define TAM 100
#define MAX 1000000

using namespace std;

int matrix[TAM][TAM];
int valores[TAM][TAM];
int aux[TAM];
int anterior[TAM];

//funcao que faz a busca
int bfs(unsigned int N, unsigned int S, unsigned int T){

    int total = 0;
    unsigned int i;
    int pos;

    while(1){
        fill(aux, aux+N+1, 0);
        //usando a fila
        queue<int> Q;
        Q.push(S);
        aux[S] = MAX;

        while (!Q.empty() && aux[T] == 0) {
            //anotando e atualizando o valor da fila
            pos = Q.front();
            Q.pop();
            for (i = 1; i <= N; ++i) {
                if (aux[i] == 0 && matrix[pos][i] > valores[pos][i]) {
                    //atualizando a fila
                    Q.push(i);
                    anterior[i] = pos;
                    aux[i] = min(aux[pos], matrix[pos][i] - valores[pos][i]);
                }
            }
        }

        //Identificando a hora de parar
        if (aux[T] == 0){
          break;
        }

        //percorrendo até i ser diferente
        for (i = T; i != S; i = anterior[i]) {
            //Pegando as duas arestas
            valores[anterior[i]][i] += aux[T];
            valores[i][anterior[i]] -= aux[T];
        }
        //atuakizando o total
        total += aux[T];
    }
    return total;
}

int main(int argc, char const *argv[]){

    unsigned int N, S, T, C, i;
    int quantidade_total = 1;

    //enquanto houver dados
    while (cin >> N) {

        //caso encontre o zero, acabaram as analises
        if(N == 0){
          break;
        }

        //percorrendo tudo
        for (i = 1; i <= N; i++) {
            fill(matrix[i], matrix[i]+N+1, 0);
            fill(valores[i], valores[i]+N+1, 0);
        }

        //pegando os valores digitados
        cin >> S;
        cin >> T;
        cin >> C;
        int a, b, bandwidth;

        for (i = 0; i < C; i++) {
            //pegando os valores digitados
            cin >> a;
            cin >> b;
            cin >> bandwidth;

            matrix[b][a] = (matrix[a][b] += bandwidth);
        }

        //usando a funcao de busca
        int resultado_band = bfs(N, S, T);

        //Exibindo a resposta
        cout << "Network " << quantidade_total << endl;
        cout << "The bandwidth is " << resultado_band << "." << endl;
    }

    return 0;
}
