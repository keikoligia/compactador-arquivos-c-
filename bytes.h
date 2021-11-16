#ifndef BYTES
#define BYTES
#include <stdio.h>
#include "arvore.h"

class Bytes
{
  public:
    int GerarBit(FILE*, int, unsigned char*);
    void ObterFreqByte(FILE*, unsigned int*);
    bool BuscaCodigoByte(NoArvore*, unsigned char, char*, int);
};

#endif
