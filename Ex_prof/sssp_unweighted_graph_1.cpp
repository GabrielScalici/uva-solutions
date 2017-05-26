/* Esta versao do Single-Source Shortest Path (SSSP) funciona
com uma busca em largura, breadth-first search (BFS) apenas..
ONDE AS ARESTAS DO GRAFO NAO TEM PESO...
portanto, basta saber qual a altura um vertice esta em relacao 
a uma determinada origem: cada transicao tem peso 1....
*/

#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define INF 1000000

// estruturas uteis para representacao de grafos...
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

void printPath(int s, int t, vi p){
	if (t == s){
		printf("%d", s);
		return;
	}
	printPath(s, p[t], p);
	printf(" -> %d", t);
}


int main(){
	vector<vii> adjList(100);    // uma lista de adjacencia: para cada vertice v, tem-se um conjunto de tuplas (u,w)
	int A;  // nro de Arestas
	int V; // nro de Vertices
	int u,v,w;
	int s; // vertice source....   
	int t;  // vertice target...
 
	scanf("%d", &A);
	scanf("%d", &V);
	scanf("%d", &s);
	scanf("%d", &t);


	// lembre-se, o grafo nao eh direcionado!
	for (int i=0; i<A; i++) {
		scanf("%d %d %d", &u, &v, &w);
		adjList[u].push_back(make_pair(v,w));
		adjList[v].push_back(make_pair(u,w));
	}

	// o vetor de distancia a partir de um vertice quqlquer tem inicialmente distancia INFINITA
	vi d(V, INF); 
	vi parent(V);   // grava a trilha, guardando o pai  de cada vertice..

	d[s] = 0;  // a distancia de s para s eh zero !!!

	// breadth search... utilizar fila....
	// inicia com s na fila...
	queue<int> q; q.push(s); 


	while(!q.empty()){  // enquanto houver elementos na fila...
		int u = q.front(); q.pop();

		// para todos os adjacentes de u
		for(int j=0; j<adjList[u].size(); j++){
			ii v = adjList[u][j];
			// o vertice nao foi visitado ainda
			if (d[v.first] == INF){
				d[v.first] = d[u]+1; //vai acumulando a distancia..
				parent[v.first] = u;
				q.push(v.first);
			}
		}
	}

	printPath(s,t, parent); 
	printf("\n");
	printf("Distancia de %d para os demais vertices...\n", s);
	for (int i=0; i<V; i++)
		printf("dist(%d) = %d ", i, d[i]);
	printf("\n");
	return 0;
}