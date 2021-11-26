#ifndef NOLISTA
#define NOLISTA
#include "arvore.h"

struct NoLista
{
  NoLista();
  NoArv *no;
  struct NoLista *prox;
  NoLista* NovoNoLista(NoArv*);
  NoArv* GetNo(NoLista*);
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
    int GetQtdMais();
    int GetQtdMenos();
    void SetInicio(NoLista*);
    void SetQtd(int);
    void SetNo(NoArv*); //seta o no da lista

    //NoArvore *CriaSubarvore(Lista*);
    NoArv* CriaSubarvore(Lista**);
    //void InsereNoFila1(NoLista*, Lista*);
    void InsereNoFila(NoLista*, Lista**);

    void SetProx(int);
    //NoLista* NovoNoLista(NoArvore*);
};

#endif
