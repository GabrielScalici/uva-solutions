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

int rr = 0;
int analise = 0;
int melhor_num1 = 0;
int totali = 1;
int melhor_num2 = 0;
int total = 0;
int n = 0, r, i;

void imprime(){
  //verificando para imprimir
  if (melhor_num2 == 0)
    cout << "Route " << r << " has no nice parts" << endl;
  else
    cout << "The nicest part of route "<< r << " is between stops " << melhor_num1 << " and " << melhor_num2+1 << endl;

}

int main(int argc, char const *argv[]){

	cin >> rr;

	for (r = 1; r <= rr; r++) {
		cin >> n;

    //Zerando as variaveis
		analise = 0;
		melhor_num1 = 0, totali = 1;
		melhor_num2 = 0;
		total = 0;

    //verificando a melhor solucao
		for (i = 1; i < n; i++) {
			int aux;
			cin >> aux;
			total += aux;

			if ((total > analise) || (total == analise && i - totali > melhor_num2 - melhor_num1)) {
        analise = total;
				melhor_num1 = totali;
				melhor_num2 = i;
			}
      
			if (total < 0) {
				total = 0;
				totali = i + 1;
			}
		}

    imprime();

	}

	return 0;
}
