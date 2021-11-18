#include <string.h>
#include <stdlib.h>
#include "arvore.h"
#include "listaLigada.h"

void NoListaLigada::SetNo(NoArvore *no)
{
  this->No = no;
}

void NoListaLigada::SetProx(NoListaLigada *prox)
{
  this->Prox = prox;
}

NoArvore* NoListaLigada::GetNo()
{
  return this->No;
}

NoListaLigada* NoListaLigada::GetProxLigada()
{
  return this->Prox;
}

NoListaLigada* NoLista::NovoNoLista(NoArvore *noArv)
{
  NoListaLigada *novo = new NoListaLigada();
  if (novo == NULL) 
    return NULL;
    
  novo->SetNo(noArv);
  novo->SetProx(NULL);

  return novo;
}