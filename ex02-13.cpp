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

#define TAM 100

//criando as varaveis
int a[TAM];
int vetor_lista[TAM];
int vetor_analise[TAM];
int sol = 1;

//funcao para armazenar o vetor
void armazena_vetor(int n){
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
}


int main(int argc, char const *argv[]){

  unsigned int t;

  //pegando a quantidade de casos
  cin >> t;

  //percorrendo todos os casos
	for (unsigned int i = 0; i < t; i++){

    int n;
		cin >> n;

    //Caso passe do valor maximo, encerra o programa
    if(n > TAM){
      break;
    }

    //Anotando os valores do vector
    armazena_vetor(n);

    //Iniciando as contas
		vetor_lista[n] = 0;
		vetor_analise[n] = 0;
		for (int i = n - 1; i >= 0; i--) {
      //zerando para nap usar lixo
      vetor_lista[i] = 0;
			vetor_analise[i] = 0;

			for (int j = i + 1; j < n; j++) {
        //primeira condicao
        if (a[i] < a[j] && vetor_lista[j] > vetor_lista[i]){
					vetor_lista[i] = vetor_lista[j];
        }

        //segunda condicao
        if (a[i] > a[j] && vetor_analise[j] > vetor_analise[i]){
					vetor_analise[i] = vetor_analise[j];
        }
			}
      //atualiando os valores
			vetor_lista[i]++;
			vetor_analise[i]++;

      //atualizando o valor da solução
      if (vetor_lista[i] + vetor_analise[i] > sol){
				sol = vetor_lista[i] + vetor_analise[i];
      }
		}

    //quando sair retira um para arrumar a contas
    sol--;

    //exibindo a resposta
    printf("%d\n", sol);
	}
	return 0;
}
