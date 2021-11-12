#ifndef LISTALIGADA
#define LISTALIGADA
#include "arvore.h" 
#define ARVORE

class NoListaLigada
{
  private:
    NoArvore *No;
    NoListaLigada *Prox;
  public:
    NoArvore *NovoNoArvore(NoArvore);

};

#endif