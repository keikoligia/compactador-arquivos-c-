#include <stdio.h>

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
    void Descompactar();
    Descompactador();
};