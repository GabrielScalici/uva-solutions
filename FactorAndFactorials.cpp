#include <iostream>
#include <map>

//definicoes para adaptacao do trabalho
#define TAM_PRIMOS 25
#define TAM_LINHA 15

using namespace std;

int main(int argc, char const *argv[] ){
  int n;
  int i, j;

  //vetor com todos os numeros primos
  int primos[TAM_PRIMOS]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

  //Pegando os valores diferentes de 0
  while(cin >> n && n > 0){

    //Imprimir a notacao correta para mostrar ao usuario
    if(n < 10)
        cout << "  " << n << "! = ";
    else
        cout << " " << n << "! = ";

    //declarando o mapa com a frequencia de cada numero primo
    map<int,int>quantidade;

    //Atualizando o map de primos
    for(i = 2; i <= n; i++){
            int num = i;
            //percorrendo toda as lista de primos
            for(j = 0 ; j < TAM_PRIMOS ; j++){
                if(num >= primos[j]){
                    //verificando se eh divisivel e atuaiza num
                    if(num%primos[j] == 0) {
                        //aumenta no map
                        quantidade[primos[j]]++;                          //realiza a divisao para atualizar o numero
                        num/=primos[j];
                        //volta um para continaur analise
                        j--;
                    }
                }else{
                  break;
                }
              }
          }

      //Só para saber na hora de imprimir
      int maximo;
      for(i = 0; i < TAM_PRIMOS ; i++){
            //enquanto for menor, continua rodando
            if(n >= primos[i])
                maximo = i;
            else
                break; // Para quando encontrou pq ja esta atualizado
      }
      int flag = 0;
      //Para imprimir na proxima linha caso passe de 15 numeros
      if(maximo < TAM_LINHA){
         for(i = 0; i <= maximo; i++){
            if(i == maximo){
                cout << quantidade[primos[i]];
            }else{
                if(i == 0){
                  cout << " ";
                }
                cout << quantidade[primos[i]] << "  ";
            }
          }
      //Caso nao tenha passado de 15 numeros
      }else{
          //Imprimindo os primeiro 15 numeros na linha superior
          for(i = 0; i < TAM_LINHA; i++){
              //Imprimindo os 15 primeiros numeros de frequencia
              if(i == 14){
                    cout << quantidade[primos[i]];
              }else{
                  if(quantidade[primos[i]] < 10){
                    if(flag == 1){
                      cout << " " << quantidade[primos[i]] << "  ";
                      flag = 0;
                    }else{
                      cout << quantidade[primos[i]] << "  ";
                    }

                  }else{
                    cout << quantidade[primos[i]] << " ";
                    flag = 1;
                  }
              }
            }

            //Imprimindo o espaco da linha de baixo
            cout << endl <<"        ";
            //continuar imprimindo na linha de baixo
            for(i = 15; i <= maximo ; i++){
              if(i == maximo)
                  cout << quantidade[primos[i]];
              else
                  cout << quantidade[primos[i]] << "  ";
            }
        }
          //pular linha para outros numeros fatoriais
          cout << endl;
  }
    return 0;
}
