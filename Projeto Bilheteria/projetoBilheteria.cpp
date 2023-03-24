#include <iostream>
#include <iomanip>
#include <locale.h>

using namespace std;

// Opções menu
#define FINALIZAR 0
#define RESERVAR 1
#define MAPA 2
#define FATURAMENTO 3

// Tamanho das fileiras (linha) e poltronas (coluna)
#define QUANTIDADE_FILEIRAS 15
#define QUANTIDADE_POLTRONAS 40

#pragma region Funcoes genericas

void separador(){
    cout << endl << endl;
    for (int i = 0; i < 20; i++)
    {
        cout << "=";
    }
    cout << endl << endl;
    
}

bool** _instanciarMatriz(int qtdLinhas, int qtdColunas){
    bool **matriz = new bool *[qtdLinhas];

    for (int i = 0; i < qtdLinhas; i++)
    {
        matriz[i] = new bool [qtdColunas];

        // Iniciar matriz com false (poltronas não reservadas)
        for (int j = 0; j < qtdColunas; j++)
        {
            matriz[i][j] = false;
        }
        
    }

    return matriz;   
}
#pragma endregion

#pragma region Finalizar

void finalizar(){
   cout << "Obrigado por usar o projeto Bilheteria :)" << endl;
   cout << "Volte sempre!!" << endl;
}
#pragma endregion

#pragma region Visualizar Faturamento

float valorBilhetePelaFileira(int fileira){
    float fileira1a5 = 50;
    float fileira6a10 = 30;
    float fileira11a15= 15;

    if(fileira < 5){
        return fileira1a5;
    } else if(fileira < 10){
        return fileira6a10;
    } else {
        return fileira11a15;
    }
}

void visualizarFaturamento(bool **poltronas){
    int qtdLugaresReservados = 0;
    float valorBilheteria = 0;

    cout << "Faturamento" << endl << endl;

    for (int i = 0; i < QUANTIDADE_FILEIRAS; i++)
    for (int j = 0; j < QUANTIDADE_POLTRONAS; j++)
    {
        bool poltronaReservada = poltronas[i][j];
        
        if(poltronaReservada){
            qtdLugaresReservados++;
            valorBilheteria += valorBilhetePelaFileira(i);
        }

    }

    cout << "Qtde de lugares ocupados: " << qtdLugaresReservados << endl;
    cout << "Valor da bilheteria: R$ " << setprecision(2) << valorBilheteria << endl;

}
#pragma endregion

#pragma region Visualizar Mapa

void visualizarMapaOcupacao(bool **poltronas){

    cout << "Mapa de ocupação" << endl << endl;

    for (int i = 0; i < QUANTIDADE_FILEIRAS; i++)
    {
        cout << setw(2) << setfill('0') << i + 1 << ": ";
        for (int j = 0; j < QUANTIDADE_POLTRONAS; j++)
        {
            char representacaoLugar = poltronas[i][j] ? '#' : '.';
            cout << setw(1) << representacaoLugar << " | ";

        }
        cout << endl;
    }
}
#pragma endregion

#pragma region Reservar Poltrona

bool marcarPoltronaComoReservada(bool **poltronas, int fileira, int poltrona){
    bool poltronaLivre = !poltronas[fileira][poltrona];

    if(poltronaLivre){
        poltronas[fileira][poltrona] = true;
    }

    return poltronaLivre;
}

int inputPoltrona(){
    int poltrona;

    do
    {
        cout << "Digite a poltrona que deseja reservar: ";
        cin >> poltrona;

        if(poltrona < 1 || poltrona > QUANTIDADE_POLTRONAS){
            cout << "Poltrona invalida, por favor escolha uma poltrona de 1 até " << QUANTIDADE_POLTRONAS << "!"  << endl << endl;
        }

    } while (poltrona < 1 || poltrona > QUANTIDADE_POLTRONAS);

    return poltrona;
}

int inputFileira(){
    int fileira;

    do
    {
        cout << "Digite a fileira que deseja reservar: ";
        cin >> fileira;

        if(fileira < 1 || fileira > QUANTIDADE_FILEIRAS){
            cout << "Fileira invalida, por favor escolha uma fileira de 1 até " << QUANTIDADE_FILEIRAS << "!" << endl << endl;
        }

    } while (fileira < 1 || fileira > QUANTIDADE_FILEIRAS);

    return fileira;
}

void reservarPoltrona(bool **poltronas){
    int fileira, poltrona;
    bool poltronaLivre;

    cout << "Reservar poltrona" << endl << endl;


    fileira = inputFileira();
    poltrona = inputPoltrona();

    poltronaLivre = marcarPoltronaComoReservada(poltronas, fileira - 1, poltrona - 1);

    if(poltronaLivre){
        cout << endl << "A poltrona " << poltrona << " da fileira " << fileira << " foi reservada com sucesso!! :)" << endl; 
    }else{
        cout << endl << "A poltrona " << poltrona << " da fileira " << fileira << " já está reservada :(" << endl; 
    }

}
#pragma endregion

int selecionarOpcaoMenu(){
    int opcao;

    cout << "Escolha a opção que deseja visualizar" << endl << endl;


    cout << "0. Finalizar" << endl;
    cout << "1. Reservar poltrona" << endl;
    cout << "2. Mapa de ocupação" << endl;
    cout << "3. Faturamento" << endl;

    cout << endl << "opção: " ;
    cin >> opcao;

    return opcao;
}

int main(int argc, char** argv){
    setlocale(LC_ALL, "");
    
    int opcao;
    bool **poltronas =  _instanciarMatriz(QUANTIDADE_FILEIRAS, QUANTIDADE_POLTRONAS);

    cout << fixed;
    cout << "Bem-vindo ao projeto bilheteria";
    separador();

    while (opcao != FINALIZAR)
    {        
        opcao = selecionarOpcaoMenu();
        
        separador();
        switch (opcao)
        {
            case FINALIZAR:
                finalizar();
            break;

            case RESERVAR:
                reservarPoltrona(poltronas);
            break;

            case MAPA:
                visualizarMapaOcupacao(poltronas);
            break;

            case FATURAMENTO:
                visualizarFaturamento(poltronas);
            break;
        
            default:
                cout << endl << "Opção invalida - por favor selecione um valor de 0 até 3" << endl << endl;
            break;
        }

        separador();

    }       

    return 0;
}