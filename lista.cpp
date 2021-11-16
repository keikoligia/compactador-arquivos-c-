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