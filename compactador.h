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
    char nomeArqParaComp[20];
    char nomeArqComp[20];
    unsigned lBytes[256];
    unsigned int posicao;
    unsigned char c;
    unsigned int tamanho;
    unsigned char aux;
 public:
    Compactador();
    void Compactar();
};

#endif
