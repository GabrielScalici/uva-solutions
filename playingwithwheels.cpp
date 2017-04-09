#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int main(int argc, char const *argv[]){
  int n; //numero de casos de teste
  int num; //anotar valores no inicial e final
  int restricoes; //quantas restricoes tem
  int encontrou;  //flag para caso tenha encontrado solucao
  //Comeco da logica para percorrer tudo
  cin >> n;
  while(n--){
    //estrutura para armazenar os valores
    vector<int> v_ini;
    vector<int> v_fim;
    vector<int> aux;
    //fila dos vetores (para facilitar a analise)para BFS
    queue< vector<int> > fila;
    //vetor como chave, int = true para visitado, false para n visitado
    map< vector<int>, int> visitado;
    map< vector<int>, int> cont;

    //Pegando vetor inicial
      cin >> num;
      v_ini.push_back(num);
      cin >> num;
      v_ini.push_back(num);
      cin >> num;
      v_ini.push_back(num);
      cin >> num;
      v_ini.push_back(num);

    //armazena o pai de todos na fila
    fila.push(v_ini);

      //Pegando vetor solucao
      cin >> num;
      v_fim.push_back(num);
      cin >> num;
      v_fim.push_back(num);
      cin >> num;
      v_fim.push_back(num);
      cin >> num;
      v_fim.push_back(num);

    //quantidade de restricoes e ve as restricoes
    cin >> restricoes;
    for(int i = 0; i < restricoes; i++){
      aux.clear();
      int a;
      for(int j = 0; j < 4; j++){
        cin >> a;
        aux.push_back(a);
      }
      //so marca como visitado
      visitado[aux] = 1;
    }
    //percorre ate a fila ficar vazia
    while(fila.empty() == false){
      //vetor auxiliar para armazenar restricoes
      vector<int> filho;
      //pega o valor para analise depois tira da fila
      aux = fila.front();
      fila.pop();
      //caso ainda nao tenha sido visitado, entao visite
      if(visitado[aux] == 0){
        //visitar consta em calcular os filhos e colocar na fila
        //visita
        visitado[aux] = 1;
        //verifica se chegou na solucao correta
        if(aux == v_fim){
          //avisa que encontrou para exibir
          encontrou = 1;
          //achou entao para de percorrer esse while
          break;
        }
        //verificando com a subtracao de 1 em cada numeros
        for(int i = 0; i < 4; i++){
          //pois os filhos muda apenas um numero de cada vez
          filho = aux;
          filho[i] -= 1;
          //verificar se passou de 0 para ir para o final
          if(filho[i] < 0){
            //ja deu uma volta completa entao resseta
            filho[i] = 9;
          }
          //verifica se eh valido (restricoes) para colocar na fila
          //senao nem analisada
          if(!visitado[filho]){
            //colcoa na fila para ser analisado futuramente
            fila.push(filho);
          }else{
            //Nao faz nada
          }
          //atualizando os passos percorridos
          cont[filho] = cont[aux] + 1;
          //para a subtracao de 1 em cada numero
          //pois os filhos muda apenas um numero de cada vez
          filho = aux;
          filho[i] += 1;
          //verificar se passou de 10 para comecar do comeco
          if(filho[i] > 9){
            //ja deu uma volta completa entao resseta
            filho[i] = 0;
          }
          //verifica se eh valido (restricoes) para colocar na fila
          //senao nem analisada
          if(!visitado[filho]){
            //colcoa na fila para ser analisado futuramente
            fila.push(filho);
          }else{
            //Nao faz nada
          }
          //atualizando os passos percorridos
          cont[filho] = cont[aux] + 1;
        }
      //caso ja tenha sido visitado entao nao faça nada
      }else{
        //OBS: as restricoes ja foram visitadas, entao quando encontrar
        //alguma ela nao sera analisada, nem os filhos dela, visto que
        //eh eliminada por ser uma movimentacao errada, entao nao
        //tem necessidade de dar continuidade a analise
      }
    }//end while interno
    //exibindo
    if(encontrou == 1){
      cout << cont[v_fim] << endl; //Mostra map cont que aarmazenas os passos
      encontrou = 0;
    }else{
      cout << "-1" << endl;//Imprimi -1
    }
  }// end while externo
  return 0;
}
