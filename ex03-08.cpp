#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>

#define TAM 100
#define Set(a, s) memset (a, s, sizeof (a))

using namespace std;

char matrix [TAM] [TAM];
int row;
int col;
int cnt;
int dr [] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dc [] = {0, 1, 0, -1, 1, 1, -1, -1};
bool vis [TAM] [TAM];

void dfs (int r, int c)
{
    if ( r == row || r < 0 || c == col || c < 0 || matrix [r] [c] == 'L' || vis [r] [c] ) return;
    vis [r] [c] = true;
    cnt++;

    for ( int i = 0; i < 8; i++ )
        dfs (r + dr [i], c + dc [i]);
}


int main(int argc, char const *argv[]){

  int testCase;
    cin >> testCase;
    //scanf ("%d", &testCase);
    getchar (); getchar ();
    bool blank = false;

    while ( testCase-- ) {
        char inp [1000];
        row = col = 0;

        if (blank) cout << endl; blank = true;

        while ( gets (inp) && strlen (inp) > 0 ) {
            if (inp [0] == 'L' || inp [0] == 'W' ) {
                strcpy (matrix [row], inp);
                col = strlen (inp);
                row++;
            }
            else {
                int r, c;
                sscanf(inp, "%d %d", &r, &c);
                cnt = 0;
                Set (vis, false);
                dfs (r - 1, c - 1);
                printf ("%d\n", cnt);
            }
        }
    }



  return 0;
}
