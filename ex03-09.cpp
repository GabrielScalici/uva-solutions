#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <cstdio>
#include <queue>

#define MAX 1001
#define TAM 4

using namespace std;

//variaveis globais
int cores[MAX][MAX],dist[MAX][MAX];
int principal[MAX][MAX];
//usado para pegar a opcao do usuario de qual parte pegar
int entrada_1 = 0, entrada_2 = 0;
int x, y;

//Funcao auxiliar para memset
void func_memset(){
  memset(cores, 0, sizeof(cores));
  memset(dist, 0, sizeof(dist));
  memset(principal, 0, sizeof(principal));
}

void pegando_infos_finais(){
  //Pegando os valores da lin e col pelo usuario
  cin >> x;
  cin >> y;
  //pegando qual a opcao do usuario
  cin >> entrada_1;
  cin >> entrada_2;
}

int main(int argc, char const *argv[]){

  int m, n;

  int X[TAM] = {-1,0,0,1}, Y[TAM] = {0,-1,1,0};

  int quantidade,linha,aux;
  //fila para implementar a busca
  queue <int> fila;
  //Implementando a busca
  int ux,uy,vx,vy;

    while(cin >> m){
      cin >> n;

      if(m == 0 && n ==0 ){
        break;
      }

      //juncao das funcoes memset
      func_memset();

      cin >> quantidade;

      //Vendo todas as possibilidades
      for(int i = 0; i < quantidade ; i++){
          //Pegando os valores digitados pelo usuario
          cin >> linha;
          cin >> aux;

        for(int j = 1; j <= aux; j++){
              int aux_num;
              cin >> aux_num;
              principal[linha][aux_num]=1;
        }
      }

      //Pegando as informacoes para pesquisa e resposta para usuario
      pegando_infos_finais();

      //atualizando a fila
      fila.push(x);
      fila.push(y);

      cores[x][y] = 1;
      dist[x][y] = 0;

      //Percorrendo a fila toda
      while(fila.empty() != 1){
          //Atualizando os valores da fila
          ux = fila.front();
          fila.pop();
          uy = fila.front();
          fila.pop();

          for(int k = 0; k < TAM; k++){
              vx = ux + X[k];
              vy = uy + Y[k];
              //Verifica se está valido, senao nao faz nada
              if((vx >= 0 && vx <= m) && (vy >= 0 && vy <= n) && principal[vx][vy]==0){
                  if(!cores[vx][vy] && !dist[vx][vy]){
                    //Caso seja diferente, seta 1 e atualiza os falores da fila
                      cores[vx][vy] = 1;
                      fila.push(vx);
                      fila.push(vy);
                      //atualiza o valor para continuar analise
                      dist[vx][vy] = dist[ux][uy]+1;
                  }
              }
           }
      }
      //exibindo a parte do vetor ja atualizada
      cout << dist[entrada_1][entrada_2] << endl;
    }
    return 0;
}
