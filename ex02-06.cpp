#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <math.h>

using namespace std;

//variavel global para facilitar uso de outras funcoes
int flag;

//funcao para verificar se eh valido as divisoes
void verifica(int n, int primo, int cont){
    //long pois alguns numeros sao grandes
    long long aux_primo = primo;
    //realiza o maximo de divisoes possiveis
    while (n / aux_primo && cont > 0){
        cont -= n / aux_primo;
        //Atualiza para continuar as divisoes
        aux_primo *= primo;
    }
    //Verificar se o contador é menor ou igual, pois deu certo a divisao
    if(cont <= 0)
      flag = 1;//retorna verdadeiro caso de certo
    else
      flag = 0;//caso cont nao esteja correto coloca zero
}


int main(int argc, char const *argv[]){

    int n, m;
    //Pegando o primeiro valor e seguindo o laço
    while (cin >> n){
        //Pegando o segundo valor
        cin >> m;
        //armazenar para trabalhar com essa informacao
        int aux_m = m;
        //flag para verificar se deu errado em alguma parte
        flag = 1;
        //Trablhar o m
        for (int i = 2; i * i <= aux_m; ++i){
            int cont = 0;
            //Caso nao divida, já para a analise
            if(flag == 0)
              break;
            //pegando o mod do valor inicia m
            while (aux_m % i == 0){
                aux_m /= i;
                cont++;
            }
            //verificando toda vez que o contador é maior que zero
            if (cont > 0)
                verifica(n, i, cont); //chama para atualizar o flag
        }
        //verificar ainda se é maior que um
        if (aux_m > 1 && flag)
            verifica(n, aux_m, 1);//chama para atualizar o flag
        //Mostrar o resultado para o usuário
        if(flag == 1){
          //Caso divida
          cout << m <<" divides " << n << "!"<< endl;
        }else{
          //Caso nao divida
          cout << m <<" does not divide " << n << "!"<< endl;
        }
    }
}
