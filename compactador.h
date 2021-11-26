#ifndef COMPACTADOR
#define COMPACTADOR
#include "arvore.h"
#include "lista.h"
#include "bytes.h"
#include <stdio.h>

class Compactador
{
  private:
    FILE* arqParaComp;
    FILE* arqComp;
    char nomeArqComp[20];
    char nomeArqDesc[20];
    unsigned lBytes[256];
  public:
    Compactador();
    void Compactar();
};

#endif
