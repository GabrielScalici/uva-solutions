/* Esta versao do Single-Source Shortest Path (SSSP) eh o 
algoritmo de Dijkstra para arestas com pesos (nao negativos..)
usaremos uma versao com fila de prioridade para manter as
arestas com menor peso na frente....
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
	vi dist(V, INF); 
	vi parent(V);   // grava a trilha, guardando o pai  de cada vertice..

	dist[s] = 0;  // a distancia de s para s eh zero !!!

	// a fila comecao com o elemento source s e a distancia claro eh zero...
	// armazenaremos (distancia d, vertice u) nesta ordem...
	priority_queue<ii, vector<ii>, greater<ii> > pq; 
	pq.push(ii(0,s)); 


	while(!pq.empty()){  // enquanto houver elementos na fila...

		ii front = pq.top(); pq.pop();
		int d = front.first;  u = front.second;

		// atencao.. faca um teste no papel...este algoritmo permite que valore distintos
		// de distancias para um mesmo mesmo vertice u seja armazenada nela.. essa
		// verificacao abaixo faz com que uma distancia maior seja ignorada...
		if (d > dist[u]) continue;

		// para todos os adjacentes de u
		for(int j=0; j<adjList[u].size(); j++){
			ii v = adjList[u][j];
			if (dist[u] + v.second < dist[v.first]){
				dist[v.first] = dist[u]+ v.second; //vai acumulando a distancia..
				parent[v.first] = u;
				pq.push(ii(dist[v.first], v.first));
			}
		}
	}

	printPath(s,t, parent); 
	printf("\n");
	printf("Distancia de %d para os demais vertices...\n", s);
	for (int i=0; i<V; i++)
		printf("dist(%d) = %d ", i, dist[i]);
	printf("\n");
	return 0;
}