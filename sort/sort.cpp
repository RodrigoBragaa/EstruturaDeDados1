#include <iostream>
#include <iomanip>
#include <locale.h>

using namespace std;

void print(int* array, int tamanho){
    for (int i = 0; i < tamanho; i++)
    {
        cout << "[" << i << "]: " << array[i] << endl;
    }
    cout << endl << "========================="  << endl;
    
}

void quick_sort(int* array, int limiteInferior, int limiteSuperior){

    int indiceMin = limiteInferior;
    int indiceMax = limiteSuperior;
    
    int aux;
    int decrescente = true;
    int indiceMarcador;
    
    while(indiceMin != indiceMax){
        if(array[indiceMin] > array[indiceMax]){
            aux = array[indiceMin];

            array[indiceMin] = array[indiceMax];
            array[indiceMax] = aux;

            decrescente = !decrescente;
        }

        if(decrescente){
            indiceMax--;
        }else{
            indiceMin++;
        }
    }

    indiceMarcador = indiceMax;
	
    if(limiteSuperior - limiteInferior > 1){
        if(indiceMarcador > limiteInferior){
            quick_sort(array, limiteInferior, indiceMarcador - 1);
        }

        if(indiceMarcador < limiteSuperior){
            quick_sort(array, indiceMarcador + 1, limiteSuperior);
        }
    }

}

void sort(int* array, int tamanho){
    quick_sort(array, 0, tamanho - 1);
}

int main(int argc, char** argv){
    setlocale(LC_ALL, "");
    int size = 8;
    int valores[size] = {49, 38, 58, 87, 34, 93, 26, 13};

    print(valores, size);
    sort(valores, size);
    print(valores, size);
    return 0;
}