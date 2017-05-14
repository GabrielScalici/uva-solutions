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

//vector principal do programas
vector <int>v[MAX];

//fucnao de busca em grafo
int busca(int no){

    int color[MAX]={0};
    int visit[MAX]={0};
    queue <int> q;
    int aux;

    //coloca na fila e adiciona o primeiro valor
    q.push(no);
    color[no]=1;

    while(q.empty() == 0){

        aux = q.front();
        q.pop();

        int d = color[aux]==1?2:1;

        //percorrendo todo o tamanho do vector
        for(int i=0; i< (int)v[aux].size(); i++){
            no = v[aux][i];

            if(color[aux] == color[no]){
              return 0;
            }

            if (visit[no] == 0){
                q.push(no);
                color[no]= d;
                visit[no]= 1;
            }
        }
    }
    return 1;
}

//funcao para limpar o vector
void limpa_vector(int n){
  //percorrendo tudo para limpar
  for (int i=0;i<n;i++){
    v[i].clear();
  }
}

//fucnao para exibir para o usuario
void exibir(){
  if (busca(0)){
    cout << "BICOLORABLE." << endl;
  }
  else{
    cout << "NOT BICOLORABLE." << endl;
  }
}

int main(int argc, char const *argv[]){

  int n,l;
  int x,y;

  //percorrendo até sair de dentro do laco
   while (cin >> n && n!= 0){
       cin >> l;

       //anotando os valores
       for (int i=0;i<l;i++){
          cin >> x;
          cin >> y;
          //scanf("%d%d",&a,&b);
          v[x].push_back(y);
          v[y].push_back(x);
       }

       //exibindo para o usuario
       exibir();

       //funcao para limapr o vector
       limpa_vector(n);

   }

  return 0;
}
