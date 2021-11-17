#include "arvore.h"
#include "lista.h"
#include "listaLigada.h"
#include "bytes.h"
#include "descompactador.h"
#include <iostream>

int main(int argc, char const *argv[])
{
  Descompactador *descomp = new Descompactador();
  descomp->Descompactar();
  return 0;
}
