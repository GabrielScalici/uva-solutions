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

vector<int> lista;

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

  int N, n, m, S, T, a, b, w;

  vector<vector<pair<int, int> > > Result;
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > fila_p;

  cin >> N;

   for(int i = 0; i < N; i++){

       cin >> n;
       cin >> m;
       cin >> S;
       cin >> T;
       Result.assign(n, vector<pair<int, int> >());

       while (m > 0) {

           cin >> a;
           cin >> b;
           cin >> w;
           Result[a].push_back(pair<int, int>(b, w));
           Result[b].push_back(pair<int, int>(a, w));

           m--;
       }

       lista.assign(n, AUX);
       lista[S] = 0;
       fila_p.push(pair<int, int>(0, S));

       while (fila_p.empty() == 0) {
           pair<int, int> front = fila_p.top(); fila_p.pop();
           int d = front.first, u = front.second;
           if (d == lista[u]) {

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

    imprime(i, T);

   }
}
