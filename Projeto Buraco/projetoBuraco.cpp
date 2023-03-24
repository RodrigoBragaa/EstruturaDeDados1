#include <iostream>
#include <iomanip>
#include <locale.h>
#include <time.h>
#include <string>

using namespace std;

// Baralho
#define QUANTIDADE_BARALHOS  2
#define QUANTIDADE_NAIPES 4
#define QUANTIDADE_CARTAS_POR_NAIPE 13

// Naipes
#define COPAS  1
#define PAUS  2
#define OURO  3
#define ESPADA 4

// Jogadores
#define QUANTIDADE_JOGADORES 4
#define QUANTIDADE_CARTAS_POR_JOGADOR 11

void separador(){
    cout << endl << endl;
    for (int i = 0; i < 20; i++)
    {
        cout << "=";
    }
    cout << endl << endl;
    
}

string** _instanciarMatriz(int qtdLinhas, int qtdColunas){
    string **matriz = new string *[qtdLinhas];

    for (int i = 0; i < qtdLinhas; i++)
    {
        matriz[i] = new string [qtdColunas];        
    }

    return matriz;   
}

void _preencherCartasBaralho(string **baralhoParam){
    for (int baralho = 1, indiceBaralho = 0; baralho <= QUANTIDADE_BARALHOS; baralho++, indiceBaralho++)
    {
        for (int naipe = 1, indiceCarta = 0; naipe <= QUANTIDADE_NAIPES; naipe++)
        {
            for (int numCarta = 1; numCarta <= QUANTIDADE_CARTAS_POR_NAIPE; numCarta++)
            {
                string numeroCarta = to_string(numCarta);
                numeroCarta.insert(0, 2 - numeroCarta.size(), '0');

                string carta = to_string(naipe) + "-" + numeroCarta + "-" + to_string(baralho);
                baralhoParam[indiceBaralho][indiceCarta++] = carta;
            }
            
        }
    }
}

string** instanciarPreencherCartas(int qtdLinhas, int qtdColunas){
    string **baralho =  _instanciarMatriz(qtdLinhas, qtdColunas);
    _preencherCartasBaralho(baralho);

    return baralho;
}

string pegarCartaBaralho(string **baralho, int indiceBaralho, int indiceCarta){
    string carta = baralho[indiceBaralho][indiceCarta];

    baralho[indiceBaralho][indiceCarta] = "";

    return carta;
}

string sortearCarta(string **baralho){
 
    bool cartaForaDoBaralho;
    int quantidadeCartas, baralhoSorteado, cartaSorteada;
    
    quantidadeCartas = QUANTIDADE_CARTAS_POR_NAIPE * QUANTIDADE_NAIPES;
    
    baralhoSorteado = rand() % 2;
    cartaSorteada = rand() % quantidadeCartas;
    
    cartaForaDoBaralho = baralho[baralhoSorteado][cartaSorteada] == "";

    if(cartaForaDoBaralho){
        return sortearCarta(baralho);
    }

    return pegarCartaBaralho(baralho, baralhoSorteado, cartaSorteada);
}

void distribuirCartas(string **baralho, string **mao){

    // Distribuição "circular"
    for (int quantidadeCarta = 0; quantidadeCarta < QUANTIDADE_CARTAS_POR_JOGADOR; quantidadeCarta++)
    {
        for (int jogador = 0; jogador < QUANTIDADE_JOGADORES; jogador++)
        {
            string carta = sortearCarta(baralho);
            mao[jogador][quantidadeCarta] = carta;
        }
    }
}

void exibirMaoJogadores(string **mao){
    for (int jogador = 0; jogador < QUANTIDADE_JOGADORES; jogador++)
    {
        cout << jogador + 1 << "º Jogador: " << endl << endl;
        for (int indiceCarta = 0; indiceCarta < QUANTIDADE_CARTAS_POR_JOGADOR; indiceCarta++)
        {
            cout << mao[jogador][indiceCarta] << endl;
        }
        separador();
    }
}

int main(int argc, char** argv){
    srand(time(0));
    setlocale(LC_ALL, "");
 
    int quantidadeCartas = QUANTIDADE_CARTAS_POR_NAIPE * QUANTIDADE_NAIPES;

    string **mao = _instanciarMatriz(QUANTIDADE_JOGADORES, QUANTIDADE_CARTAS_POR_JOGADOR);
    string **baralho = instanciarPreencherCartas(QUANTIDADE_BARALHOS, quantidadeCartas);
    

    distribuirCartas(baralho, mao);

    exibirMaoJogadores(mao);

    return 0;
}