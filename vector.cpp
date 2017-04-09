#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]){

	int valor = 0;
	vector<int> v;
	vector<int>::iterator p;

	while(scanf("%d", &valor) != EOF){
		v.push_back(valor);
	}

	//Ordenando para mostrar crescente

	std::sort(v.begin(), v.end());

	for(p = v.begin() ; p != v.end(); p++){
		printf("%d\n", *p);
	}
	
	printf("\n");

	//Usando reverso do vector para mostrar decrescente

	std::reverse(v.begin(), v.end());


	for(p = v.begin() ; p != v.end(); p++){
		printf("%d\n", *p);
	}




	return 0;
} 