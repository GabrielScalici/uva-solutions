#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>

#define COM 1<<29
#define MAX 100
#define TAM 26

using namespace std;

//variaves globais para facilitar nas funcoes
int matrix[2][30][30];
int n;
char linha[MAX];
char a[MAX],b[MAX];


int main(int argc, char const *argv[]){

    int i, j, k, w, c;

    //percorrendo todos os valores
    while(cin >> n &&n){
        for(i=0;i<TAM;++i){
            for(j=0;j<26;++j){
                matrix[0][i][j] = COM;
                matrix[1][i][j] = COM;
            }
        }
        //percorrendo para setar 0 nas matrizes
        for(i=0;i<TAM;++i){
            //primeira dimensao apenas
            matrix[0][i][i] = 0;
            matrix[1][i][i] = 0;
        }
        //vendo toda a quantidade possivel (n)
        while(n > 0){
            //pegando a string de leitura
            cin >> linha;
            w = (linha[0]=='Y')?0:1;

            //pegando os valores dados
            cin >> linha;
            cin >> a;
            cin >> b;
            cin >> c;

            //analizand para atualizar matriz
            if(matrix[w][a[0]-'A'][b[0]-'A']>c){
                matrix[w][a[0]-'A'][b[0]-'A'] = c;
            }
            if(linha[0]=='B'  && matrix[w][b[0]-'A'][a[0]-'A']>c){
                matrix[w][b[0]-'A'][a[0]-'A'] = c;
            }

            n--;
        }
        //percorrendo todas as dimensoes
        for(w=0;w<2;++w){
            for(k=0;k<TAM;++k){
                for(i=0;i<TAM;++i){
                    for(j=0;j<TAM;++j){
                        if(matrix[w][i][j] > matrix[w][i][k]+matrix[w][k][j]){
                            matrix[w][i][j] = matrix[w][i][k]+matrix[w][k][j];
                        }
                    }
                }
            }
        }
        //pegando o valor de a e b;
        cin >> a;
        cin >> b;
        j = a[0]-'A';
        k = b[0]-'A';
        //Percorrendo todo o tamanho
        for(i=c=0;i<TAM;++i){
            if(matrix[0][j][i]+matrix[1][k][i] < matrix[0][j][c]+matrix[1][k][c]){
                c = i;
            }
        }
        //verificando se nao foi possivel
        if(matrix[0][j][c]+matrix[1][k][c] >= COM){
            cout << "You will never meet." << endl;
        }else {
          //caso seja possivel
            cout << matrix[0][j][c]+matrix[1][k][c];
            for(i=c;i<TAM;++i){
                if(matrix[0][j][i]+matrix[1][k][i] == matrix[0][j][c]+matrix[1][k][c]){
                    //logica para imprimir o numero correto
                    printf(" %c",i+'A');
                }
            }
              //imprimindo no final para pular a linha
              cout << endl;
        }
    }

    return 0;
}
