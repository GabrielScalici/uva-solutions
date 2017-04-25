#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <math.h>

#define PRIMO 131071

using namespace std;

int main(int argc, char const *argv[]) {

    char num;
    long total = 0;

    while(cin >> num) {
        //se achou o final do arquivo, para de analisar
        if(num == EOF)
            break;
        //Se encontrou o mostrador de final de numero, verifica o total
        if(num == '#') {
          if(total == 0)
            cout << "YES" << endl; // caso tenha dado divisao exata
          else
            cout << "NO" << endl; // caso a divisao nao tenha sido exata

          //zera o total quando troca de linha
          total = 0;
        } else{
            //enquanto nao for # continua rodando e fazendo as contas
            total = total*2 + num - '0';
            total = total%PRIMO;
        }
    }
    return 0;
}
