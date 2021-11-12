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
    FILE arqParaComp;
    FILE arqComp;
    char nomeArqComp[20];
    char nomeArqDesc[20];
    unsigned lBytes[256];
    unsigned int posicao;
    unsigned char c;
    unsigned int tamanho;
    unsigned char aux;
};

#endif