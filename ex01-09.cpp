#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>

#define MAX 100
#define MIN 100000.0

using namespace std;

double P[MAX][2];
int n;
//double sum;

void dikjstra(){
    double ax;
    double dist[MAX];
    bool intree[MAX];

    memset(intree,0,sizeof(intree));
    for(int i=0;i<MAX;i++) dist[i]=1000000.0;

    int v=0;
    dist[0]=0;
    double sum=0;

    while(!intree[v]){
        intree[v]=1;
        sum+=dist[v];

        for(int i=0;i<n;i++){
            if(!intree[i]){
                ax=sqrt(pow(P[v][0]-P[i][0],2)+pow(P[v][1]-P[i][1],2));
                if(ax<dist[i]) dist[i]=ax;
            }
        }

        v=0;
        //Valor grande para análise
        double min = MIN;

        for(int i=0;i<n;i++){
            if(!intree[i]){
                if(dist[i]<min){
                    v=i;
                    min=dist[i];
                }
            }
        }

    }

    printf("%.2f\n",sum);
}

int main(int argc, char const *argv[]){

    int T;

    double a,b;

    scanf("%d", &T);

    for(int i=0;i<T;i++){

        scanf("%d", &n);

        for(int j=0;j<n;j++){

            scanf("%lf\n", &a);
            scanf("%lf\n", &b);

            P[j][0]=a;
            P[j][1]=b;
        }

        dikjstra();
        if(i!=T-1){
            printf("\n");
        }
    }

  return 0;
}
