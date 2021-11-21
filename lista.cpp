#include "arvore.h"
#include "lista.h"

Lista::Lista(NoLista* inicio, int qtd)
{
  this->Inicio = inicio;
  this->Qtd = qtd;
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

NoLista* Lista::GetProxLigada()
{
  return this->Pr
}
/*
void Lista::SetProx(NoLista* no)
{
  this->Inicio->no->prox;
}*/

void Lista::InsereNoFila(NoLista* n, Lista* l)
{
  if(!l->GetInicio())
    l->SetInicio(n);

  else if((*n)->no->GetFreq() < (*(*l).GetInicio())->no->GetFreq())
  {
    (*n)->no->SetProx(*(*l->GetInicio()));
    l->SetInicio(n);
  }
  else
  {
    NoLista *aux = new NoLista();
    aux = (*(*l)->GetInicio())->GetProxLigada();

    NoLista *aux2 = new NoLista();
    aux2 = l->GetInicio();

    while(aux && aux->GetNo()->GetFreq() <= n->GetNo()->GetFreq())
    {
      aux2 = aux;
      aux = aux2->GetProxLigada();
    }

    aux2->SetProx(n);
    (*n)->no->SetProx(aux);
  }

  int qtd = l->GetQtd();
  (*l)->SetQtd(qtd++);
}

NoArvore* NoLista::CriaSubarvore(NoLista *list)
{
  NoListaLigada *noListaLigada = new NoListaLigada();
  noListaLigada = list->GetInicio();

  NoArvore *noArv = new NoArvore();
  noArv = noListaLigada->GetNo();

  list->SetInicio(noListaLigada->GetProxLigada());

  delete(noListaLigada);
  noListaLigada = nullptr ;

  int quant = list->GetQtd();
  list->SetQtd(quant--);

  return noArv;
}