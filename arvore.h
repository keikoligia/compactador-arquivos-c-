#ifndef NOARVORE
#define NOARVORE
#include "lista.h"
#include "listaLigada.h"
#define LISTA

class NoArvore
{
  private:
    NoArvore *NoEsq;
    NoArvore *NoDir;
    NoArvore *No;
    int Freq;
    char c;
    
  public:
    NoArvore *NovoNoArvore(unsigned char, int, NoArvore, NoArvore);
    NoArvore CriaSubarvore(NoLista);
    NoArvore FazerArvore(NoLista);
    void InsereNoFila(NoListaLigada, NoLista);
};

#endif