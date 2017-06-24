#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <cstdio>

#define MAX 100
#define MAX_SEGUNDA 12

using namespace std;

int n, q, d, m;
int dp[MAX][MAX_SEGUNDA][MAX];
int a[MAX];

//funcao para realizar os calculos
int calcular(int indx, int num, int remd) {

    //condicoes de parada
    if (num == 0 && remd == 0){
        return 1;
    }else if (indx == n || num == 0){
        return 0;
    }else if (dp[indx][num][remd] != -1) {
        return dp[indx][num][remd];
    }

    //pegando o valor absoluto
    int val_abs;
    if (remd + a[indx] >= 0){
        val_abs = remd + a[indx] % d;
    }
    val_abs = (d + (remd + a[indx] % d)) % d;

    //caso nao seja, retorne recurisivamente
    return dp[indx][num][remd] = calcular(indx + 1, num - 1, val_abs) + calcular(indx + 1, num, remd);
}

int main(int argc, char const *argv[]){

    int casos = 1;

    //percorrendo até as entradas acabarem
    while (1) {
        cin >> n >> q;

        //caso encontre o zero, para
        if (n == 0) {
            break;
        }

        //anotando os valores inciais
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        //comecando imprimir os casos
        cout << "SET " << casos << ":" << endl;
        casos++;

        //Exibindo os resultados
        for (int i = 1; i <= q; i++) {
            //pegando os valores
            cin >> d;
            cin >> m;

            memset(dp, -1, sizeof(dp));

            //recalcularndo os casos
            int aux = calcular(0, m, 0);

            //exibindo para o usuario
            cout << "QUERY " << i << ": " << aux << endl;
        }
    }
    return 0;
}
