#include <iostream>
#include <string>

using namespace std;

int main()
{
    string mensagem;
    cout << "Digite a mensagem a ser verificada: ";
    getline(cin, mensagem);

    // Verifica se a mensagem é um palíndromo
    bool palindromo = true;
    int tamanho = mensagem.length();
    for (int i = 0; i < tamanho/2; i++)
    {
        if (mensagem[i] != mensagem[tamanho-i-1])
        {
            palindromo = false;
            break;
        }
    }

    // Exibe o resultado da verificação
    if (palindromo)
    {
        cout << "A mensagem e um palindromo." << endl;
    }
    else
    {
        cout << "A mensagem nao e um palindromo." << endl;
    }

    return 0;
}
