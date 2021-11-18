#ifndef NOLISTALIGADA
#define NOLISTALIGADA
#include "arvore.h"
#include "lista.h"

class NoListaLigada
{
  private:
    NoListaLigada *Prox;
    NoArvore *No;

  public:
    void SetProx(NoListaLigada*);
    void SetProx(int);
    NoListaLigada* GetProxLigada();
    NoListaLigada* NovoNoLista(NoArvore*);
    //feito - NoListaLigada();
};

#endif