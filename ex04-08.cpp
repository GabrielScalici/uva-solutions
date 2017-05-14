#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>

#define TAM 20

using namespace std;

int main(int argc, char const *argv[]){
    //valores iniciais pegos no cin
    int row ,cols ,c, verifica;
    string linha;
    int visited[TAM][TAM];


    //enquanto tiver dados
    while(cin >> row && cin >> cols && cin >> c){

        int f = 0, aux = 0;
        //flag para saber se ha loop
        int flag = 0;
        vector<string> v;

        if(row ==0 && cols ==0 && c==0){
            break;
        // Se ainda tem dados faz a analise
        }else{

          f=0;
          c--;

          //lendo todas as linhas
          for(int i=0; i< row; i++){
              cin >> linha;
              v.push_back(linha);//mais facil trabalhar com vector
          }

          memset(visited,-1,sizeof(visited));

          visited[f][c]=0;

          verifica = 1;

          while(verifica == 1){

              //aumenta para contuuar a analise
              aux++;

              //verificando o que esta sendo lido
              if(v[f][c]=='S'){
                f++;
              }else if(v[f][c]=='N'){
                f--;
              }else if(v[f][c]=='W'){
                c--;
              }else {
                c++;
              }

              if(f >= row){
                verifica = 0;
              }else if(c < 0){
                verifica = 0;
              }else if(f < 0){
                verifica = 0;
              }else if(c >= cols){
                verifica = 0;
              }

              if(visited[f][c]== -1){
                visited[f][c] = aux;
              }else{
                flag = 1;
                verifica = 0;
              }
          }

          //analisando a flag para exibir
          if(flag == 1){
            int result = (aux - visited[f][c]);
            cout << visited[f][c] <<" step(s) before a loop of "<< result <<" step(s)"<< endl;
          }
          else{
            cout<< aux <<" step(s) to exit" << endl;
          }
      }
    }

  return 0;
}
