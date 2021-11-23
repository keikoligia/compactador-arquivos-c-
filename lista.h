#ifndef NOLISTA
#define NOLISTA
#include "arvore.h"

struct NoLista
{
  NoLista();
  NoArvore *no;
  struct NoLista *prox;
  NoLista* NovoNoLista(NoArvore*);
  NoArvore* GetNo(NoLista*);
  NoLista* GetProxLigada(NoLista*);
  void SetProx(NoLista*);
};

class Lista
{
  private:
    NoLista *Inicio;
    int Qtd;

  public:
    Lista(NoLista*, int);
    Lista();

    NoLista *GetInicio();
    int GetQtd();
    void SetInicio(NoLista*);
    void SetQtd(int);
    void SetNo(NoArvore*); //seta o no da lista

    NoArvore *CriaSubarvore(Lista*);
    NoArvore *CriaSubarvore(Lista**);
    void InsereNoFila1(NoLista*, Lista*);
    void InsereNoFila(NoLista*, Lista**);

    void SetProx(int);
    //NoLista* NovoNoLista(NoArvore*);
};

#endif
