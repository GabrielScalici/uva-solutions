#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>


#define AUX 1e9

using namespace std;

//variaveis globais para facilitar funcoes separadas
vector<int> lista;
int n, S;
vector<vector<pair<int, int> > > Result;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > fila_p;

//Funcao que faz o alg dijkstra
void dij(){
  //colocando a quantidade
  lista.assign(n, AUX);
  lista[S] = 0;
  fila_p.push(pair<int, int>(0, S));

  //verificando todos os elementos da fila
  while (fila_p.empty() == 0) {
      pair<int, int> front = fila_p.top(); fila_p.pop();
      int d = front.first, u = front.second;
      if (d == lista[u]) {

      //pegando todo a lista
      int tam = Result[u].size();
      for(int j = 0; j < tam ; j++){
          pair<int, int> v = Result[u][j];
          if (lista[u] + v.second < lista[v.first]) {
              lista[v.first] = lista[u] + v.second;
              fila_p.push(pair<int, int>(lista[v.first], v.first));
          }
      }
  }
}
}

//imprimindo a resposta
void imprime(unsigned int i, unsigned int T){
  cout << "Case #" << i+1 << ": ";
  if (lista[T] != AUX){
      cout << lista[T] << endl;
  }else{
    cout << "unreachable" << endl;
  }
}

int main(int argc, char const *argv[]){

  int N, m, T, a, b, w;
  //Pega a quantidade de casos
  cin >> N;

   //Percorre toda a quantidade de casos
   for(int i = 0; i < N; i++){
       cin >> n;
       cin >> m;
       cin >> S;
       cin >> T;
       Result.assign(n, vector<pair<int, int> >());

       //verificando todo o tamanho
       while (m > 0) {
           cin >> a;
           cin >> b;
           cin >> w;
           Result[a].push_back(pair<int, int>(b, w));
           Result[b].push_back(pair<int, int>(a, w));
           //tira para atualziar
           m--;
       }

       //fazendo o algoritmo
       dij();


      //imprimindo
      imprime(i, T);

   }
}
