#include <string.h>
#include <stdlib.h>
#include "arvore.h"
#include "lista.h"

NoArvore::NoArvore(){}

NoArv::NoArv() {}
/*
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
  return (*this).NoDir;
}

NoArvore* NoArvore::GetNoEsq()
{
  return (*this).NoEsq;
}
*/
NoArv* NoArv::NovoNoArvore(unsigned char c, int freq, NoArv *esq, NoArv *dir)
{
  NoArv *novo = new NoArv();
  if (novo == NULL)
    return NULL;

    novo->C = c;
    novo->Freq = freq;
    novo->NoEsq = esq;
    novo->NoDir = dir;

  return novo;
}

NoArv* NoArvore::FazerArvore(unsigned int *list)
{
  NoLista *noLista = new NoLista();
  Lista *l = new Lista(NULL, 0);
  NoArv *noArv = new NoArv();

  for(int i = 0; i< 256; i++)
  {
    if(list[i])
      l->InsereNoFila(noLista->NovoNoLista(noArv->NovoNoArvore(i, list[i], NULL, NULL)), &l);
  }
    while (l->GetQtd() > 1)
    {
      NoArv *noEsq = l->CriaSubarvore(&l);
      NoArv *noDir = l->CriaSubarvore(&l);

      NoArv *soma = noArv->NovoNoArvore('#', noEsq->Freq + noDir->Freq, noEsq, noDir);

      l->InsereNoFila(noLista->NovoNoLista(soma), &l);
    }
    return l->CriaSubarvore(&l);
}
