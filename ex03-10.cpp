#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>

#define MAX 1000

using namespace std;

//Estrutura de grafo
struct aresta{
	int origem;
  int destino;
  int preco;
};

//variaveis globais para facilitar funcoes
unsigned int N, M;
int dist[MAX];
unsigned int i, j;
aresta edge[MAX];

//algoritmo que resolve as arestas
int algoritmo_solver(){
	memset(dist, 0, sizeof(dist));

	for(i = 0; i < N; i++){
		int update = 0;
    //percorrendo toda a quantidade M
		for(j = 0; j < M; j++){
			int nd = dist[edge[j].origem] + edge[j].preco;
			if(nd < dist[edge[j].destino]){
				dist[edge[j].destino] = nd;
				update = 1;
			}
		}

    //caso nao seja valido
		if( !update ){
			return 0;
		}
	}
	return 1;
}

int main(int argc, char const *argv[]){
  int x;
  cin >> x;

	while(x > 0){
    //Criando as arestas
    cin >> N;
    cin >> M;
    for(i = 0; i < M; i++){
      int num1, num2, num3;
      cin >> num1;
      cin >> num2;
      cin >> num3;
      edge[i] = (aresta){num1, num2, num3};
    }

    //anotando a resposta do solver
    int resultado = algoritmo_solver();

    //mostrando o resultado
    if(resultado){
      cout << "possible" << endl;
    }else{
      cout << "not possible" << endl;
    }

    //seguindo a analise
    x--;
	}

	return 0;
}
