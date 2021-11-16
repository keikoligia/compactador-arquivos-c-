#ifndef LISTALIGADA
#define LISTALIGADA
#include "arvore.h" 
#include "lista.h"
#define ARVORE

class NoListaLigada
{
  private:
    NoArvore *No;
    NoListaLigada *Prox;
  public:
    void SetNo(NoArvore*);
    void SetProx(NoListaLigada*);
    void SetProx(int);
    NoArvore* GetNo();
    NoListaLigada* GetProxLigada();
    NoListaLigada *NovoNoLista(NoArvore*);
    NoListaLigada();
};

#endif