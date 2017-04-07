#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int main(int argc, char const *argv[]){


  //Variaveis para auxilio
  int tam = 0;
  int num1, num2;

  //Valores para indicar se deu certo.
  bool pilha = true;
  bool fila = true;
  bool p_fila = true;

  //Salvar valores em uma stack, queue e priority_queue
  while(scanf("%d", &tam) != EOF){
    //Criando as estruturas para analise
    priority_queue <int> pq;
    queue <int> q;
    stack <int> s;

    //printf("%d\n", tam);
    //Anotando os valores em queue, priority_queue e stack
    //tam casas para ler até o final do while
    while(tam > 0){
      scanf("%d %d", &num1, &num2);

      //verificando 1 -- colocar; 2 -- tirar
      if(num1 == 1){
        //adicionar num2 nas 3 estruturas
        pq.push(num2);
        q.push(num2);
        s.push(num2);
      }else if(num1 == 2){
        //retirada dos valores
        if(!s.empty() && pilha == true && s.top() == num2){
          //stack confere por enquanto
          //pilha = true;
          s.pop();
        }else{
          pilha = false;
        }
        if(!q.empty() && fila == true && q.front() == num2){
          //queue confere por enquanto
          //fila = true;
          q.pop();
        }else{
          fila = false;
        }
        if(!pq.empty() && p_fila == true && pq.top() == num2){
          //priority_queue confere
          //p_fila = true;
          pq.pop();
        }else{
          p_fila = false;
        }

      }
      //ler toda a quantidade tam de valores para analise
      tam--;
    }
    //Analisando os valores obtidos com as respostas
    if(pilha && !fila && !p_fila){
      printf("stack\n");
    }else if(!pilha && fila && !p_fila){
      printf("queue\n");
    }else if(!pilha && !fila && p_fila){
      printf("priority queue\n");
    }else if(pilha || fila || p_fila){
      printf("not sure\n");
    }else{
      printf("impossible\n");
    }

    pilha = fila = p_fila = true;
  }
  return 0;
}
