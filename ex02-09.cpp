#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <stdio.h>
#include <cstring>

using namespace std;

int v1[100000],v2[100000];
int w[100000],p[100000];

//struct contendo os dados
struct No{
    No(int a,int b,int c):v1(a),v2(b),dis(c){}
    int operator <(const No b)const {return dis>b.dis;}
    int v1,v2,dis;
};

//funcao de comparacao
int find(int num){
    if(p[num]== num)
    {
      return num; //retorna apenas o numero
    }else{
      return p[num] = find(p[num]);//faz uma chamada resursiva
    }
}

int main(int argc, char const *argv[]){
   int n, m;
   int num_a, num_b, num_c, num_d = 0, num_sum=0;

   //lendo até que de problema para ler N
   while(cin >> n){
        cin >> m;
        //verificando se chegou no final
        if(n == 0 && m == 0){
            break;
        }
        //variabeis usadas nessa parte
        int analise = 0;
        int aux = 0;
        int a = 0, b = 0, c = 0;

        //Percorrendo as M vezes
        for (int i = 0; i < m; i++){
          //pegando os valores de a, b e c;
          cin >> a;
          cin >> b;
          cin >> c;
          //addedge(a,b,c);
          v1[aux]=a;
          v2[aux]=b;
          w[aux]=c;
          //aumentando para nao modificar o mesmo valor
          aux++;
          analise += c;
        }

        //asn()
        priority_queue<No>q;

        for (int i = 0; i < aux; i++){
          q.push(No(v1[i],v2[i],w[i]));
        }

        for (int i = 0; i < n; i++){
          p[i]=i;
        }

        while(num_d < n-1){
            //trabalhando com a fila
            num_a = q.top().v1;
            num_b = q.top().v2;
            num_c = q.top().dis;
            q.pop();

            //analisa percorrendo recursivamente
            if(find(num_a)!=find(num_b)){
              p[find(num_a)] = p[find(num_b)];
              //atualiza os valores para nao interferir em outros calculos
              num_sum += num_c;
              num_d++;
            }
        }

        //anotando o resultado principal
        float result = analise - num_sum;

        //imprimindo a resposta para o usuario
        cout << result << endl;

    }

   return 0;
}
