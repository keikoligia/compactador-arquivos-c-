#include "descompactador.cpp"
#include "compactador.cpp"
#include <iostream>

int main()
{
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
}
