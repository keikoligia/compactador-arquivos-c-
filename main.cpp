#include <iostream>
#include "descompactador.h"
#include "compactador.h"

int main()
{
  //Descompactador *descomp = new Descompactador();
  //descomp->Descompactar();

  Compactador *comp = new Compactador();
  comp->Compactar();
  return 0;
}
