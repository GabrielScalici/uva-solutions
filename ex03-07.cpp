#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main(int argc, char const *argv[]){

	long combustivel = 0, aux = 0, andado = 0, dist = 0, percorrido = 0;
	float capacidade = 0, gas = 0;
	char analise;
	string passo;

	//comeca com a flag zero para passar no while
	int completo = 0;

	//percorrendo ate que encontre o final nas contas
	while (completo == 0) {

		//pegando a distancia e o proximo passo
		cin >> dist;
		cin >> passo;

		//adicionar o uso de gas
		percorrido = (dist - andado);
		andado = dist;
		//atualizando o gas
		gas += (aux * percorrido);
		gas += (combustivel / 100.0) * percorrido;

		//Analisando qual eh o evento
		analise = passo[0];

		//Verificando se comeca com G, qual é
		if(analise == 'G'){ // caso seja gas station
			if(passo[1] == 'a'){
				analise = 'A';
			}else{ //senao sera goal
				analise = 'O';
			}
		}

		//verifica para pegar o resto
		if(analise == 'F' || analise == 'A'){
			//pega o proximo acontecimento
			cin >> passo;
		}

		//estado do carro dependendo da analise
		switch(analise){
			case 'F':
				//pegando o gasto de Combustivel
				cin >> combustivel;
				//se chegou a 0, entao nao da para fazer mais nada
				if (combustivel == 0){
					completo = 1;
				}else{
					continue;
				}
				break;

			case 'L':
				aux++;
				break;

			case 'M':
				aux = 0;
				break;

			case 'A':
				//verifica se gas eh maior
				if (capacidade < gas){
					capacidade = gas;
				}
				//zerando pra nao atrapalhar
				gas = 0;
				break;

			case 'O':
				//verifica se gas eh maior
				if (capacidade < gas){
					capacidade = gas;
				}

				//exibindo para o usuario
				printf("%.3lf\n", capacidade);
				capacidade = 0;
				break;
		}

	}

	return 0;
}
