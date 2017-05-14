#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>

#define MAX 100

using namespace std;

int main(int argc, char const *argv[]){

  int i = 0, n = 0, m = 0, x = 0, y = 0, numero = 0, aux = 0;
  //estruturas usadas
  vector <int> v[MAX];
  queue <int> fila;
  int quant[MAX];
  //vetor final
  int ordenado[5];

  //iniciando tudo com 0
  for(i = 0; i < MAX; i++){
    quant[i] = 0;
  }


  //enquanto for diferente de zero
  while(cin >> n){

      cin >> m;

      //verifica se passou do valor maximo
      if(n > MAX || m > MAX){
        //o maximo eh 100
        break;
      }

      //adicionaod a quantidade de itens no vetor
      for(i = 0; i < m; i++){
          //pegando
          cin >> x;
          cin >> y;

          //coloca na pos
          v[x].push_back(y);
          quant[y]++;
      }

      //atulizando quando a fila tiver o valor 0
      for(i = 0; i < n; i++){
          if(quant[i+1] == 0){
              fila.push(i+1);
          }
      }

      //enquanto tiver valor na fila
      while(fila.empty() == 0){

          //armazena e tira da fila
          numero = fila.front();
          fila.pop();

          //armazenando no vetor final e aumentando o contador
          ordenado[aux] = numero;
          aux++;

          //convertendo para inteiro
          int tam = (int)v[numero].size();

          for(i = 0; i < tam; i++ ) {
              quant[v[numero][i]]--;
              if (quant[v[numero][i]] == 0 ){
                  fila.push(v[numero][i]);
              }
          }

      }

      //exibindo o vetor ordenado
      for (i = 0; i < n; i++ ){
          if(i == 0){
            cout << ordenado[0];
          }else{
            cout << " " << ordenado[i];
          }
      }

      //imprimindo a quebra de linha quando n != 0 senao ja acabou
      if(n!=0){
        cout << endl;
      }
  }

  return 0;
}
