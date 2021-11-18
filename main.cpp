<<<<<<< HEAD
=======
#include "descompactador.cpp"
#include "compactador.cpp"
>>>>>>> 696279ea48e9f43db83986eb5e8367d9b04fc9f6
#include <iostream>
#include "descompactador.h"

int main()
{
<<<<<<< HEAD
  Descompactador *descomp = new Descompactador();
  descomp->Descompactar(); 
  return 0;
=======
    cout << "O que deseja fazer? \n";

    cout << "Digite [1] para compactar um arquivo \n";
    cout << "Digite [2] para descompactar um arquivo \n";
    cout << "Digite [3] para sair do programa \n";

    char opcao;
    cin >> this->opcao;

    switch (opcao)
    {
        case '1':
            Compactador comp;
            comp.Compactar();
            break;
        case '2':
            Descompactador descomp;
            descomp.Descompactar();
            break;
        case'3':
            break;
        default:
            cout << "Valor de operacao invalido\n";
            break;
    }
    return 0;
>>>>>>> 696279ea48e9f43db83986eb5e8367d9b04fc9f6
}
