#include <vector>
#include <utility>
#include <stdio.h>
#include <stdlib.h>

#define UNVISITED 0
#define VISITED 1

using namespace std;


// estruturas uteis para representacao de grafos...
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;



// vetor de vertices
vi vertices;   

// a lista de adjacencia e um vetor de vetor de pares.
// cada par contem o vertice adjacente e o peso da aresta
// assumimos que o peco aqui eh inteiro...
vector<vii> AdjList(100);  


// busca em profundidade a partir de um vertice u
void dfs(int u){
	vertices[u] = VISITED;
	printf("%d\n", u+1);

	for(int j=0; j<AdjList[u].size(); j++){
		ii v = AdjList[u][j];  // v  eh um vertice do tipo (vizinho de u, peso)
		if (vertices[v.first] == UNVISITED)
			dfs(v.first);
	}
}


int main (){
	int u,v;     // edge pair...
	int n;		// # of vertices...

	scanf("%d\n", &n);
	printf("%d\n", n);
	for (int i=0; i<n; i++){
		vertices.push_back(UNVISITED);
		//AdjList.pushback(0);
		printf("%d ", vertices[i]);
	}
	printf("\n");

	while (scanf("%d %d", &u, &v) != EOF) {
		AdjList[u-1].push_back(make_pair(v-1,0));
		AdjList[v-1].push_back(make_pair(u-1,0));

	}
	dfs(0);

	return 0;
}
