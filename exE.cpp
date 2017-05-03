#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include <cstring>

//tamanho maximo do numero analisado
#define MAX 2000000

using namespace std;

//fila como variavel global
deque<int> fila;
vector< deque<int> > resposta;


void verifica(int ini, int aux){

  //fazendo o for ate a quantidade maxima de vezes do mesmo i aparecer
  for (int i = ini; i * i <= aux; i++){
    if (aux%i == 0) {
        fila.push_back(i);
        verifica(i, aux/i);
        fila.pop_back();
    }
    //caso nao seja divisivel, o for continua e vai para o proximo numero
  }
  //armazenar o ultimo antes de colocar no vector de fils
  fila.push_back(aux);
  resposta.push_back(fila);
  fila.pop_back();

}


int main(int argc, char const *argv[]){

   int num;
   int aux;
   int tam_total, tam_parcial;
   int inicio_contagem;

   //analisando caso por caso até o zero
   while(cin >> num){
     //parando quando achar o zero
     if(num == 0){
       break;
     }
     //antes de comecar zera a fila
     fila.clear();
     resposta.clear();
     //anotando o valor em uma variavel reserva
     aux = num;
     inicio_contagem = 2;

     //chama se tiver para fatorar
     if(num < 2){
       //nao faz nada pois nao tem como fatorar
       cout << "0" << endl;
     }else{
       //chama a funcao recursiva
       verifica(inicio_contagem, aux);

       tam_total = resposta.size();
       cout << tam_total - 1 << endl;

       //imprimir os valores
       for(int i = 0; i < tam_total - 1; i++){
       //pegando o tamanho parcial
       tam_parcial = resposta[i].size();
       for(int j = 0; j < tam_parcial; j++){
         //exibindo fila por fila salva no set
         if(j > 0){
           cout << " " << resposta[i][j];
         }else{
           cout << resposta[i][j];
         }
       }
       //pula uma linha
       cout << endl;
       }
     }
   }




  return 0;
}
