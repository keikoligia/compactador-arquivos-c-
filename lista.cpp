#include "arvore.h"
#include "lista.h"

NoLista::NoLista(NoListaLigada* inicio, int qtd)
{
  this->Inicio = inicio;
  this->Qtd = qtd;
}

void NoLista::SetInicio(NoListaLigada *inicio)
{
  this->Inicio = inicio;
}

void NoLista::SetQtd(int qtd)
{
  this->Qtd = qtd;
}

NoListaLigada* NoLista::GetInicio()
{
  return this->Inicio;
}

int NoLista::GetQtd()
{
  return this->Qtd;
}

void NoLista::InsereNoFila(NoListaLigada* n, NoLista* l)
{
  if(!l->GetInicio())
    l->SetInicio(n);

  else if(n->GetNo()->GetFreq() < l->GetInicio()->GetNo()->GetFreq())
  {
    n->SetProx(l->GetInicio());
    l->SetInicio(n);
  }
  else
  {
    NoListaLigada *aux = new NoListaLigada();
    aux = l->GetInicio()->GetProxLigada();

    NoListaLigada *aux2 = l->GetInicio();

    while(aux && aux->GetNo()->GetFreq() <= n->GetNo()->GetFreq())
    {
      aux2 = aux;
      aux = aux2->GetProxLigada();
    }

    aux2->SetProx(n);
    n->SetProx(aux);
  }

  int qtd = l->GetQtd();
  l->SetQtd(qtd++);
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