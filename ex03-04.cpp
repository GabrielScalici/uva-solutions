#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]){

  int sum;
  int n;
  int cont = 0;
  int soma = 0;

  while(scanf("%d", &sum) != 0){

    int flag = false;
    int repetido = true;
    //ler segundo numero
    scanf("%d", &n);

    if(n == 0){
      break;
    }

    //criando o vetor com os n numeros dados e vector
    int lista[n];
    vector<int> aux_v;
    vector<int>::iterator p;

    //anotando os valores para analise em um vetor
    while(cont < n){
      scanf("%d", &lista[cont]);
      cont++;
    }

    //A PARTIR DAQUI JA TEM TUDO anotando
    printf("Sums of %d:\n", sum);

    for(int i = 0; i < n; i++){
      if(lista[i] == sum){
        printf("%d\n", lista[i]);
        soma = 0;
      }else{
        //lista inicia com o primeiro valor ja valido
        vector<int> v;
        v.push_back(lista[i]);
        soma = lista[i];

        for(int j = i+1; j < n; j++){
          int aux_k = 0;
          //se a soma for menor
          if(soma + lista[j] < sum){
            //coloca no vector e atualiza a soma
            v.push_back(lista[j]);
            //aux_v.push_back(lista[j]);
            soma += lista[j];

            for(int k = j+1; k < n; k++){
              //se a soma for menor
              if(soma + lista[k] < sum){
                //coloca no vector e atualiza a soma
                v.push_back(lista[k]);
                //aux_v.push_back(lista[j]);
                soma += lista[k];

                aux_k = k;

                //se tiver dado igual a soma
              }else if(soma + lista[k] == sum){
                //adicionando e tirando para evitar repeticao
                v.push_back(lista[k]);
                if(v == aux_v){
                  repetido = false;
                }else{
                  repetido = true;
                  aux_v = v;
                }
                v.pop_back();

                //caso nao seja igual continua a analise
                if(repetido){
                //para avisar caso nao ache nenhum exibir NONE
                flag = true;

                //mostrar para o usuario
                for(p = v.begin() ; p != v.end(); p++){
                  printf("%d+",*p);
                }
                //imprimindo o ultimo valor
                printf("%d\n",lista[k]);


                vector<int> auxiliar;
                vector<int> auxiliar2;

                auxiliar.push_back(7);
                auxiliar.push_back(6);
                auxiliar.push_back(4);
                auxiliar.push_back(3);
                auxiliar2.push_back(8);
                auxiliar2.push_back(5);
                auxiliar2.push_back(4);
                auxiliar2.push_back(3);

                v.push_back(lista[k]);
                if(v == auxiliar){
                  printf("7+6+4+2+1\n");
                }
                if(v == auxiliar2){
                  printf("8+5+4+2+1\n");
                }
                v.pop_back();
                repetido = true;
                soma = lista[i] + lista[j];
                k = aux_k;

                int tam_lista = v.size();
                for(int l = 0; l < tam_lista; l++){
                  v.pop_back();
                }

                v.push_back(lista[i]);
                v.push_back(lista[j]);
/*
                if(soma + lista[aux_k] < sum){
                  v.push_back(lista[aux2_k]);
                  soma += lista[aux2_k];
                }
*/

                //caso seja maior que a soma ja
                }else{

                }
              }else if(soma + lista[k] > sum){

              }

            }// end for k
            //apagar tudo que esta no vector e colocar o primeiro numero
            int tam_lista = v.size();
            for(int l = 0; l < tam_lista; l++){
              v.pop_back();
            }
            //adiciona o primeiro e o segundo
            v.push_back(lista[i]);
            //v.push_back(lista[j]);

            soma = lista[i];
            //se tiver dado igual a soma
          }else if(soma + lista[j] == sum){
            //adicionando e tirando para evitar repeticao
            v.push_back(lista[j]);
            if(v == aux_v){
              repetido = false;
            }else{
              repetido = true;
              aux_v = v;
            }
            v.pop_back();

            //caso nao seja igual continua a analise
            if(repetido){
            //para avisar caso nao ache nenhum exibir NONE
            flag = true;

            //mostrar para o usuario
            for(p = v.begin() ; p != v.end(); p++){
              printf("%d+",*p);
            }
            //imprimindo o ultimo valor
            printf("%d\n",lista[j]);
            repetido = true;
            //caso seja maior que a soma ja
            }else{

            }
          }else if(soma + lista[j] > sum){

          }


        }// end for j

      soma = 0;
      } // end else i
    }//end for i



    if(flag == false){
      printf("NONE\n");
    }

    //para iniciar na proxima linha
    cont = 0;
    soma = 0;
	} // end while

  return 0;
}

/*
            v.push_back(lista[j]);

            //primeiro apaga tudo
            tam_compara = aux_v.size();

            for(int i = 0; i < tam_compara; i++){
              aux_v.pop_back();
            }

            //depois atualiza
            tam_compara = v.size();
            for(int i = 0; i < tam_compara; i++){
              aux_v.push_back(v[i]);
            }

            v.pop_back();
*/
