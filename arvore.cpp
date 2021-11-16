#include <string.h>
#include <stdlib.h>
#include "arvore.h"
#include "listaLigada.h"
#include "lista.h"
#include "bytes.h"

NoArvore::NoArvore(unsigned char c, int freq, NoArvore *esq, NoArvore *dir)
{
  this->C = c;
  this->Freq = freq;
  this->NoEsq = esq;
  this->NoDir = dir;
}

void NoArvore::SetNoEsq(NoArvore *noEsq)
{
  this->NoEsq = noEsq;
}

void NoArvore::SetNoDir(NoArvore *noDir)
{
  this->NoDir = noDir;
}

void NoArvore::SetFreq(int freq)
{
  this->Freq = freq;
}

void NoArvore::SetC(unsigned char c)
{
  this->C = c;
}

int NoLista::GetQtd()
{
  return this->Qtd;
}

int NoArvore::GetFreq()
{
  return this->Freq;
}

char NoArvore::GetC()
{
  return this->C;
}

NoArvore* NoArvore::GetNoDir()
{
  return this->NoDir;
}

NoArvore* NoArvore::GetNoEsq()
{
  return this->NoEsq;
}

void NoArvore::InsereNoFila(NoListaLigada* n, NoLista* l)
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

NoArvore* NoArvore::NovoNoArvore(unsigned char c, int freq, NoArvore *esq, NoArvore *dir)
{
  NoArvore *novo = new NoArvore(c, freq, esq, dir);
  if (novo == NULL)
    return NULL;
    
  return novo;
}

NoArvore* NoArvore::CriaSubarvore(NoLista *list)
{
  NoListaLigada *noListaLigada = new NoListaLigada();
  noListaLigada = list->GetInicio();

  NoArvore *noArv = new NoArvore();
  noArv = noListaLigada->GetNo();

  list->SetInicio(noListaLigada->GetProxLigada());

  delete(noListaLigada);
  noListaLigada = NULL;

  int quant = list->GetQtd();
  list->SetQtd(quant--);

  return noArv;
}

NoArvore* NoArvore::FazerArvore(unsigned int *list)
{
  NoLista *l = new NoLista(NULL, 0);
  NoListaLigada *listaLigada = new NoListaLigada();

  for(int i = 0; i< 256; i++)
  {
    if(list[i])
      this->InsereNoFila(listaLigada->NovoNoLista(this->NovoNoArvore(i, list[i], NULL, NULL)), &l);
    
    while (l->GetQtd() > 1)
    {
      NoArvore *noEsq = this->CriaSubarvore(l);
      NoArvore *noDir = this->CriaSubarvore(l);

      NoArvore *soma = this->NovoNoArvore('#', noEsq->GetFreq() + noDir->GetFreq(), noEsq, noDir);

      this->InsereNoFila(listaLigada->NovoNoLista(soma), &l); 
    }

    return this->CriaSubarvore(&l);
  }
}