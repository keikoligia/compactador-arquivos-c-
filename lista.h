#ifndef NOLISTA
#define NOLISTA
#include "arvore.h"

struct NoLista
{
  NoArvore *no;
  struct NoLista *prox;
  NoLista(){};
  NoLista* NoLista::NovoNoLista(NoArvore*);
};
typedef NoLista* NoLista;

class Lista
{
  private:
    NoLista *Inicio;
    int Qtd;
    
  public:
    Lista(NoLista*, int);

    NoLista *GetInicio();
    int GetQtd();
    void SetInicio(NoLista*);
    void SetQtd(int);
    void SetNo(NoArvore*); //seta o no da lista

    NoArvore* GetNo();
    NoArvore *CriaSubarvore(Lista*);
    NoArvore *CriaSubarvore(Lista**);
    void InsereNoFila1(NoLista*, Lista*);
    void InsereNoFila(NoLista, Lista**);

    void SetProx(NoLista*);
    void SetProx(int);
    NoLista* GetProxLigada(NoLista*);
    NoLista* NovoNoLista(NoArvore*);
};

#endif