#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char const *argv[]){

	map<string, int> m;
	map<string, int>::iterator p;

	//palavra lida
	string palavra;

	//Ler o documento inteiro
	while(cin >> palavra){
		//Verificar se a palavra existe
		p = m.find(palavra);
		if(p != m.end()){
			m[palavra] += 1;
		}else{
			m[palavra] = 1;
		}
		
	}

	//Ordenando o iterador
	//sort(m.begin(), m.end(), greater<string>());

	for(p = m.begin(); p != m.end(); p++){
		cout << p->first << " -> " << p->second << endl;
	}

	return 0;
} 