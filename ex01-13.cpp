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

using namespace std;

int rr = 0;
int best_niceness = 0;
int best_i = 0, sumi = 1;
int best_j = 0;
int sum = 0;
int n = 0, r;

void imprimi(){
  if (best_j == 0)
    cout << "Route " << r << " has no nice parts" << endl;
  else
    cout << "The nicest part of route "<< r << " is between stops " << best_i << " and " << best_j+1 << endl;
}

int main(int argc, char const *argv[]){

	cin >> rr;

	for (r = 1; r <= rr; r++) {
		cin >> n;

    //Zerando as variaveis
		best_niceness = 0;
		best_i = 0, sumi = 1;
		best_j = 0;
		sum = 0;

		for (int i = 1; i < n; i++) {
			int niceness;
			cin >> niceness;
			sum += niceness;

			if ((sum > best_niceness) || (sum == best_niceness && i - sumi > best_j - best_i)) {
        best_niceness = sum;
				best_i = sumi;
				best_j = i;
			}
			if (sum < 0) {
				sum = 0;
				sumi = i + 1;
			}
		}

    imprimi();

	}

	return 0;
}
