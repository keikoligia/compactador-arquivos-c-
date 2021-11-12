#ifndef COMPACTADOR
#define COMPACTADOR
#include "arvore.h"
#include "lista.h"
#include "listaLigada.h"
#include "bytes.h"
#include <stdio.h>

class Compactador
{
  private:
    FILE arqComp;
    FILE arqDesc;
    char nomeArqComp[20];
    char nomeArqDesc[20];
    unsigned lBytes[256];
    unsigned int posicao;
    unsigned char aux;
};

#endif