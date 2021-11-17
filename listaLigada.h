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
    void SetNo(NoArvore*);
    void SetProx(NoListaLigada*);
    void SetProx(int);
    NoArvore* GetNo();
    NoListaLigada* GetProxLigada();
    NoListaLigada* NovoNoLista(NoArvore*);
    NoListaLigada();
};

#endif