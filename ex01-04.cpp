#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[]){
  int cont = 0;
  int lin;
  int a, b, c;
  bool flag;

  scanf("%d", &lin);

  while(cont < lin){
    int x, y, z;

    scanf("%d %d %d", &a, &b, &c );

    //com o valor de x
    for(x = -200; x <= 200; x++){
      //com o valor de y
      for(y = -200; y <= 200; y++){
        //com o valor de z
        for(z = -200; z<= 200; z++){
          //analisando se as equacoes sao validas
          if(flag == false && x+y+z == a && x*y*z == b && x*x+y*y+z*z == c){
            //condicoes validas entao

            flag = true;
            break;
          }
        }
        if(flag == true){
          break;
        }
      }
      if(flag == true){
        break;
      }
    }

    if(flag == false){
      printf("No solution.\n");
    }else{
      printf("%d %d %d\n", x, y, z);
    }

    //setando false para continuar a analise e aumentando o contador de linhas
    flag = false;
    cont++;
  }

  return 0;
}
