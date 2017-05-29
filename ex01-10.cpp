#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>

#define N 10000
#define COMP 1e9
#define VERDADEIRO 1
#define UN unsigned

using namespace std;


struct Node{
    UN int v, w;
    Node(){}
    Node(UN int vv, UN int ww) :v(vv), w(ww){}
    bool operator<(const Node& a)const{return w > a.w; }
};

vector<Node>vetor[N];

//algoritmo dijkstra
int dij(UN int s, UN int t, UN int n)
{
    UN int visitado[N]= {};
    UN int dist[N];
    UN int proximo;

    // usando func fill
    fill(dist, dist + n, COMP);

    dist[s] = 0;
    priority_queue<Node> fila;
    fila.push(Node(s, 0));

    //roda ate achar alguma saida pelo algoritmo
    while (VERDADEIRO){
        proximo = -1;
        //arrumando a fila
        while (fila.empty() == 0 && visitado[proximo = fila.top().v]){
            fila.pop();
        }
        if (proximo == -1 || proximo == t){
          //ja retorna e sai da func
          return dist[t];
        }

        //marca como visitado
        visitado[proximo] = 1;
        for (Node node : vetor[proximo]){
            if (visitado[node.v] == 0 && (dist[proximo] + node.w) < dist[node.v]){
                dist[node.v] = (dist[proximo] + node.w);
                //adiciona na fila
                fila.push(Node(node.v, dist[node.v]));
            }
        }
    }
    //retorna o final de toda a analise
    return dist[t];
}

//imprimindo a resposta
void imprimir(UN int c, UN int res){
  //Imprimindo para o usuario
  cout << "Case #" << (c+1) << ": ";

  //verificando se teve resposta ou nao
  if (res != COMP)
      cout << res << endl;
  else
      cout << "unreachable" << endl;
}

void atualiza(UN int tam){
  UN int u, v, w;
  for (UN int i = 0; i < tam; i++){
    cin >> u;
    cin >> v;
    cin >> w;
    vetor[u].push_back(Node(v, w));
    vetor[v].push_back(Node(u, w));
  }
}

void limpar_fila(UN int tam){
  for (UN int i = 0; i < tam; i++){
    vetor[i].clear();
  }
}

int main(int argc, char const *argv[]){
    UN int quantidade;
    UN int res;

    //pegando as primeiras informacoes
    cin >> quantidade;
    for (UN int c = 0; c < quantidade; c++){
        //variaveis unsigned usadas na logica
        UN int n, m, s, t;

        cin >> n;

        //limpando fila
        limpar_fila(n);

        cin >> m;
        cin >> s;
        cin >> t;

        //percorrendo atualizando a fila
        atualiza(m);

        //fazendo o lg dijstra
        res = dij(s, t, n);

        //imprimindo os resultados
        imprimir(c, res);

    }
    return 0;
}
