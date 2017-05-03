#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include <cstring>
#include <cmath>

#define TAM_MAX 1000
#define EPS 1e-10
#define MIN 0.0
#define MAX 1.0

using namespace std;

int main(int argc, char const *argv[]){

  //variaveis que nao precisa reiniciar nas interacoes
  float p, i;

  while(cin >> p){
    //outras variavies que precisam ressetar
    float q, r, s, t, u;
    //criando valores de analise
    double min = MIN, max = MAX, meio = 0, total;

    //pegando as outras variaveis
    cin >> q;
    cin >> r;
    cin >> s;
    cin >> t;
    cin >> u;

    //Fazendo as contas (ate 100)
    for (i = 0; i < TAM_MAX; i++){
        //calculando o meio
        meio = (min+max)/2;
        //calculando o total para mudar os valores
        total = (p*exp(-meio) + q*sin(meio) + r*cos(meio) + s*tan(meio) + t*pow(meio,2) + u);
        //analisando
        if (total < 0){
          max = meio;
        }else{
          min = meio;
        }
    }

    //calculando o total para exibir
    total = (p*exp(-meio) + q*sin(meio) + r*cos(meio) + s*tan(meio) + t*pow(meio,2) + u);

    //verificando se tem solucao
    if (total < EPS){
      //imprimi o valor do meio
      printf("%.4lf\n",meio);
    }else{
    //mostra que nao tem solucao
      cout << "No solution" << endl;
    }

  }

  return 0;
}
