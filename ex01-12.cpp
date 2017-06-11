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

int main(int argc, char const *argv[]){

  //Estruturas
  int matrix[10][100], custo[10][10];;
  //Variaveis comuns de cin
  int m = 0, c = 0, N = 0;

 //Pegando a quantidade de casos
 cin >> N;

 //percorrendo todo o tamanho para anotar
 while (N--){
   cin >> m >> c;
   for (int i=1; i<=c; i++){
    cin >> custo[i][0];
    for (int j=1; j<=custo[i][0]; j++){
      //Anotando todos os custos
      cin >> custo[i][j];
    }
   }



//Solucao

//Setando para comecar de forma correta
memset(matrix,0,sizeof(matrix));

//percorrendo os custos primeiro
for (int i=1; i<=custo[1][0]; i++)
  if (m-custo[1][i]>=0) matrix[1][m-custo[1][i]]=1;

//percorrendo todos
for (int i=2; i<=c; i++){
  for (int j=0; j<=m; j++){
    if (matrix[i-1][j]){
      for (int k=1; k<=custo[i][0]; k++){
        int aux = j-custo[i][k];
        if (aux>=0){
          matrix[i][j-custo[i][k]]=1;
        }

      }
    }
  }
}

//Funcao para exibir para o usuario
int i = 0;
for (i=0; i<=m && !matrix[c][i]; i++);
if (i==m+1) cout << "no solution" << endl;
else cout << m-i << endl;



 }
 return 0;
}
