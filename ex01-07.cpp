#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include <cstring>
#include <math.h>


using namespace std;

int main(int argc, char const *argv[]){

  int campsites;
  int nights;
  float total = 0;
  int aux;

  cin >> campsites;
  cin >> nights;

  int cont = campsites + 1;

  while(cont){
    cin >> aux;
    total += aux;
    cont--;
  }

  total = total/nights;
  total = ceil(total);

  cout << total << endl;


  return 0;
}
