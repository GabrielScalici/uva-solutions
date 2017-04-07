#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <ctype.h>
using namespace std;

int main(int argc, char const *argv[]){

	map<char, char> m;
	char letra;

	//Cadastrando os valores da criptografia
	m.insert(make_pair('Q', 'Q'));
	m.insert(make_pair('W', 'Q'));
	m.insert(make_pair('E', 'W'));
	m.insert(make_pair('R', 'E'));
	m.insert(make_pair('T', 'R'));
	m.insert(make_pair('Y', 'T'));
	m.insert(make_pair('U', 'Y'));
	m.insert(make_pair('I', 'U'));
	m.insert(make_pair('O', 'I'));
	m.insert(make_pair('P', 'O'));
	m.insert(make_pair('[', 'P'));
	m.insert(make_pair(']', '['));
	m.insert(make_pair('\\', ']'));

	/*m.insert(make_pair('q', 'q'));
	m.insert(make_pair('w', 'q'));
	m.insert(make_pair('e', 'w'));
	m.insert(make_pair('r', 'e'));
	m.insert(make_pair('t', 'r'));
	m.insert(make_pair('y', 't'));
	m.insert(make_pair('u', 'y'));
	m.insert(make_pair('i', 'u'));
	m.insert(make_pair('o', 'i'));
	m.insert(make_pair('p', 'o'));*/



	m.insert(make_pair('A', 'A'));
	m.insert(make_pair('S', 'A'));
	m.insert(make_pair('D', 'S'));
	m.insert(make_pair('F', 'D'));
	m.insert(make_pair('G', 'F'));
	m.insert(make_pair('H', 'G'));
	m.insert(make_pair('J', 'H'));
	m.insert(make_pair('K', 'J'));
	m.insert(make_pair('L', 'K'));
	m.insert(make_pair(';', 'L'));
	m.insert(make_pair(047, ';'));
	
	/*m.insert(make_pair('a', 'a'));
	m.insert(make_pair('s', 'a'));
	m.insert(make_pair('d', 's'));
	m.insert(make_pair('f', 'd'));
	m.insert(make_pair('g', 'f'));
	m.insert(make_pair('h', 'g'));
	m.insert(make_pair('j', 'h'));
	m.insert(make_pair('k', 'j'));
	m.insert(make_pair('l', 'k'));*/


	m.insert(make_pair('Z', 'Z'));
	m.insert(make_pair('X', 'Z'));
	m.insert(make_pair('C', 'X'));
	m.insert(make_pair('V', 'C'));
	m.insert(make_pair('B', 'V'));
	m.insert(make_pair('N', 'B'));
	m.insert(make_pair('M', 'N'));
	m.insert(make_pair(',', 'M'));
	m.insert(make_pair('.', ','));
	m.insert(make_pair('/', '.'));
	/*m.insert(make_pair('z', 'z'));
	m.insert(make_pair('x', 'z'));
	m.insert(make_pair('c', 'x'));
	m.insert(make_pair('v', 'c'));
	m.insert(make_pair('b', 'v'));
	m.insert(make_pair('n', 'b'));
	m.insert(make_pair('m', 'n'));*/

	m.insert(make_pair('1', '`'));
	m.insert(make_pair('2', '1'));
	m.insert(make_pair('3', '2'));
	m.insert(make_pair('4', '3'));
	m.insert(make_pair('5', '4'));
	m.insert(make_pair('6', '5'));
	m.insert(make_pair('7', '6'));
	m.insert(make_pair('8', '7'));
	m.insert(make_pair('9', '8'));
	m.insert(make_pair('0', '9'));
	m.insert(make_pair('-', '0'));
	m.insert(make_pair('=', '-'));




	while(scanf("%c", &letra) != EOF){
		if(letra == '\n'){
			printf("\n");
		}else if(letra == ' '){
			printf(" ");
		}else if(letra == '\r'){

		}else{
			printf("%c", m[letra]);
		}
	}

	//printf("\n");

	return 0;
} 