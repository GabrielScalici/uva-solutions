#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <cstring>
#include <cstdio>

#define COM 9999
#define TAM 100
#define PAD 60


using namespace std;
using std::min;
using std::sort;

//variaveis globais para facilitar uso nas funcoes
int aux[TAM][TAM];
int d[TAM];
int a[TAM];
int tempo[7];

//funcao de calcula distancia
void calcular(int k, unsigned int nx){
    unsigned int i, j;
    int num1, num2, count;
    sort(a, a+nx);
    for(i = 0; i < nx; i++){
        for(j = i + 1; j < nx; j++){
            num1 = a[i];
            num2 = a[j];
            count = (num2-num1)*tempo[k];
            //verificando se eh menor
            if(aux[num1][num2] > count){
                //atualizando as duas posicoes
                aux[num2][num1] = count;
                aux[num1][num2] = count;
            }
        }
    }
}


int main(int argc, char const *argv[]){
    unsigned int i, j;
    unsigned int n,m;
    char letra;
    int v[TAM];
    unsigned int proximo;

    //percorrendo enquanto tiver valores
    while(scanf("%d %d",&n,&m)==2){
        //armazenando e montando o vetor tempo
        for(i = 0; i < n; i++){
            cin >> tempo[i];
        }
        //percorrendo todo o tamanho atualizando d
        for(i = 0; i < TAM; i++){
          d[i]=COM;
        }
        //percorrendo todo o tamanho atualizando aux
        for(i = 0; i < TAM; i++){
            for(int j = 0; j< TAM; j++){
                aux[i][j]=COM;
            }
        }
        for(i = 0; i < n; i++){
            int resultado=0;
            //pegar todos os numeros dentro das possibilidades
            while(scanf("%d%c",&proximo,&letra)==2){
                a[resultado++]=proximo;
                if(letra=='\n') break;
            }

            //recalcularndo
            calcular(i,resultado);
        }
        memset(v, 0, sizeof(v));
        //zerando para  outas analises
        d[0]=0;

        //percorrendo todo o tamanho novamente
        for(i = 0; i <= TAM; i++){
            unsigned int x;
            int numero_auxiliar = COM;
            for(j = 0; j <= TAM; j++){
                if(!v[j] && (d[j] < numero_auxiliar)){
                  numero_auxiliar = d[x=j];
                }
            }
            v[x]=1;
            for(j = 0; j <= TAM; j++){
                d[j] = min(d[j], d[x] + aux[x][j] + PAD);
            }
        }

        if(!m ){
          cout << "0" << endl;
        }
        else if(d[m] >= COM){
          cout << "IMPOSSIBLE" << endl;
        }
        else{
            cout << (d[m]- PAD) << endl;
        }
    }
    return 0;
}
