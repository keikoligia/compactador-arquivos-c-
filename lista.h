#ifndef LISTA
#define LISTA
#include "arvore.h"
#include "listaLigada.h"

class NoLista
{
  private:
    NoListaLigada *Inicio;
    int Qtd;
  public:
    NoListaLigada *GetInicio();
    int GetQtd();
    void SetInicio(NoListaLigada*);
    void SetQtd(int);
    NoLista(NoListaLigada*, int);
    NoArvore *CriaSubarvore(NoLista*);
    NoArvore *CriaSubarvore(NoLista**);
    void InsereNoFila(NoListaLigada*, NoLista*);
    void InsereNoFila(NoListaLigada*, NoLista**);
};

#endif