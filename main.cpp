#include <iostream>
#include "descompactador.h"
#include "Compactador.h"

int main()
{
    try
    {
        Descompactador *descomp = new Descompactador();
        Compactador *comp = new Compactador();

        printf("O que deseja fazer? \n");

        printf("Digite [1] para compactar um arquivo \n");
        printf("Digite [2] para descompactar um arquivo \n");
        printf("Digite [3] para sair do programa \n");

        char opcao;
        scanf("%c", &opcao);

        switch (opcao)
        {
            case '1':
                comp->Compactar();
                break;

            case '2':
                descomp->Descompactar();
                break;

            case '3':
                break;
            default:
                printf("Valor de operacao invalido\n");
                break;
        }
      return 0;
    }
    catch (const std::exception& e)
    {
     std::cout << e.what();
    }
}
