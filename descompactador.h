#ifndef DESCOMPACTADOR
#define DESCOMPACTADOR
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

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
