#include <iostream>
#include <string>
#include <windows.h> // biblioteca para utilizar a função Sleep()

using namespace std;

int main()
{
    string mensagem;
    cout << "Digite a mensagem a ser exibida: ";
    getline(cin, mensagem);

    int largura_tela = 80; // largura padrão da tela do console do Windows
    int largura_mensagem = mensagem.length();
    int espacos_esquerda = (largura_tela - largura_mensagem) / 2; // calcula quantos espaços em branco devem ser adicionados à esquerda da mensagem para centralizá-la
    cout << string(espacos_esquerda, ' ') << mensagem << endl; // exibe a mensagem centralizada na linha 5

    for (int linha = 6; linha <= 20; linha++) // percorre as linhas de 6 a 20
    {
        cout << string(espacos_esquerda, ' '); // exibe os espaços em branco à esquerda da mensagem
        for (int coluna = 0; coluna < largura_mensagem; coluna++) // percorre as colunas da mensagem
        {
            if (linha - coluna <= 5) // se a posição atual da letra está na "cascata" da linha atual
            {
                cout << mensagem[coluna]; // exibe a letra correspondente
            }
            else // se a posição atual da letra não está na "cascata" da linha atual
            {
                cout << ' '; // exibe um espaço em branco
            }
        }
        cout << endl; // quebra a linha após exibir a "cascata" da linha atual
        Sleep(100); // pausa por 100 milissegundos para dar o efeito de "cascata"
    }

    return 0;
}
