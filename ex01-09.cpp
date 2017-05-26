#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>

#define MAX 100
#define GRANDE 100000.0
#define TAM 2

using namespace std;

int main(int argc, char const *argv[]){

    double P[MAX][TAM];
    int i;
    int T, n;

    //Pegando a quantidade
    scanf("%d", &T);
    //Pegsndo a quantidade de casos
    scanf("%d", &n);
    //Percorrendo a quantidade de casos
    for(int i = 0; i < n; i++){
        //pegando os valores
        float num1;
        scanf("%f\n", &num1);
        P[i][0] = num1;
        float num2;
        scanf("%f\n", &num2);
        P[i][1] = num2;
    }

    //Fazendo Dijkstra
    float dist[MAX];
    int arv[MAX];

    memset(arv, 0, sizeof(arv));

    //iniciando com uma distancia grande
    for(i = 0; i < MAX; i++){
        if(i == 0){
          dist[i] = 0;
        }else{
          dist[i] = GRANDE;
        }
    }

    //variaveis para o codigo abaixo
    int aux = 0;
    double total = 0;

    //percorrendo enquanto for valido (nao visitado)
    while(arv[aux] == 0){
        arv[aux] = 1;
        total = total + dist[aux];

        //percorrendo n vezes para ver todos os nos
        for(i = 0; i < n; i++){
            if(arv[i] == 0){
                //variaveis com as contas
                int resul1 = pow(P[aux][0]-P[i][0],2);
                int resul2 = pow(P[aux][1]-P[i][1],2);

                //realizando as contas
                float resul_total = sqrt(resul1 + resul2);

                //analisando a dist minima
                if(resul_total < dist[i]){
                  dist[i] = resul_total;
                }
            }
        }

        //inicia com valor grande para analise
        int min = GRANDE;

        //percorrendo todos os possiveis (n)
        for(i = 0; i < n; i++){
            if(arv[i] == 0){
                if(min > dist[i]){
                    //atualizando o aux e o valor min
                    aux = i;
                    min = dist[i];
                }
            }
        }
    }

    //imprimindo para o usuario
    printf("%.2f\n",total);

  return 0;
}
