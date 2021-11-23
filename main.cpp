#include <iostream>
#include "descompactador.h"
#include "compactador.h"

int main()
{
    Compactador *comp = new Compactador();
    comp->Compactar();

    //Descompactador *descomp = new Descompactador();
    //descomp->Descompactar();
  return 0;
}
