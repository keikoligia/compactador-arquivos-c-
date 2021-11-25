#include "arvore.h"
#include "lista.h"
#include <cstddef>

Lista::Lista(NoLista* inicio, int qtd)
{
  this->Inicio = inicio;
  this->Qtd = qtd;
}

Lista::Lista() { }

NoLista::NoLista() { }

NoArv* NoLista::GetNo(NoLista* no)
{
  return this->no;
}

NoLista* NoLista::NovoNoLista(NoArv* noArv)
{
  NoLista* novo = new NoLista();
  if (novo == NULL)
    return NULL;

  novo->no = noArv;
  novo->prox = NULL;

  return novo;
}

void Lista::SetInicio(NoLista *inicio)
{
  this->Inicio = inicio;
}

void Lista::SetQtd(int qtd)
{
  this->Qtd = qtd;
}

NoLista* Lista::GetInicio()
{
  return this->Inicio;
}

int Lista::GetQtd()
{
  return this->Qtd;
}

int Lista::GetQtdMais()
{
  return this->Qtd + 1;
}

int Lista::GetQtdMenos()
{
  return this->Qtd - 1;
}

NoLista* NoLista::GetProxLigada(NoLista* no)
{
  return this->prox;
}

void NoLista::SetProx(NoLista* no)
{
  this->prox;
}

void Lista::InsereNoFila(NoLista* n, Lista** l)
{
  if(!(*l)->GetInicio())
    (*l)->SetInicio(n);

  else if(n->no->Freq < (*l)->Inicio->no->Freq)
  {
    n->prox = (*l)->GetInicio();
    (*l)->SetInicio(n);
  }
  else
  {
    NoLista *aux = new NoLista();
    aux = (*l)->GetInicio()->GetProxLigada(n);

    NoLista *aux2 = new NoLista();
    aux2 = (*l)->GetInicio();

    while(aux && aux->no->Freq <= n->no->Freq)
    {
      aux2 = aux;
      aux = aux2->GetProxLigada(aux);
    }

    aux2->prox = n;
    n->prox = aux;
  }

  int qtd = (*l)->GetQtdMais();
  (*l)->SetQtd(qtd);
}

NoArv* Lista::CriaSubarvore(Lista **list)
{
  NoLista *noLista = new NoLista();
  noLista = (*list)->GetInicio();

  NoArv *noArv = new NoArv();
  noArv = noLista->GetNo(noLista);

  (*list)->SetInicio(noLista->GetProxLigada(noLista));

  delete(noLista);
  noLista = nullptr ;

  int quant = (*list)->GetQtdMenos();
  (*list)->SetQtd(quant);

  return noArv;
}
