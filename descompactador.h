#ifndef DESCOMPACTADOR
#define DESCOMPACTADOR
#include <fstream>
#include <stdlib.h>

class Descompactador
{
  private:
    FILE *arqComp;
    FILE *arqDesc;
    char nomeArqComp[20];
    char nomeArqDesc[20];
    unsigned lBytes[256];
    unsigned char aux;
  public:
    Descompactador();
    void Descompactar();
};

#endif