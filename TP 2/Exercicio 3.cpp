#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ifstream arquivo("nomes.txt"); // Abre o arquivo para leitura

    if (!arquivo.is_open()) // Verifica se o arquivo foi aberto com sucesso
    {
        cerr << "Erro ao abrir o arquivo." << endl;
        return 1;
    }

    string nome;
    while (getline(arquivo, nome)) // Lê os nomes do arquivo linha por linha
    {
        // Remove espaços em branco do começo e fim do nome
        nome.erase(0, nome.find_first_not_of(" \t\r\n"));
        nome.erase(nome.find_last_not_of(" \t\r\n") + 1);

        // Separa o sobrenome do nome completo
        string sobrenome = nome.substr(nome.find_last_of(" ") + 1);
        string nomes = nome.substr(0, nome.find_last_of(" "));

        // Transforma os nomes no formato de agenda telefônica (sobrenome, nome(s))
        string sobrenome_formatado = sobrenome + ",";
        replace(nomes.begin(), nomes.end(), ' ', ',');
        string nome_formatado = nomes + " " + sobrenome_formatado;

        // Exibe o nome no formato de agenda telefônica na tela
        cout << nome_formatado << endl;
    }

    arquivo.close(); // Fecha o arquivo

    return 0;
}
