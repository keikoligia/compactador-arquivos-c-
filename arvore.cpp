#include <string.h>
#include <stdlib.h>
#include "arvore.h"
#include "lista.h"

NoArvore::NoArvore(){}

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
  return this->NoDir;
}

NoArvore* NoArvore::GetNoEsq()
{
  return this->NoEsq;
}

NoArvore* NoArvore::NovoNoArvore(unsigned char c, int freq, NoArvore *esq, NoArvore *dir)
{
  NoArvore *novo = new NoArvore(c, freq, esq, dir);
  if (novo == NULL)
    return NULL;

  return novo;
}

NoArvore* NoArvore::FazerArvore(unsigned int *list)
{
  NoLista *noLista = new NoLista();
  Lista *l = new Lista(NULL, 0);

  for(int i = 0; i< 256; i++)
  {
    if(list[i])
      l->InsereNoFila(noLista->NovoNoLista(this->NovoNoArvore(i, list[i], NULL, NULL)), &l);
  }
    while (l->GetQtd() > 1)
    {
      NoArvore *noEsq = new NoArvore();
      noEsq = l->CriaSubarvore(&l);

      NoArvore *noDir = new NoArvore();
      noDir = l->CriaSubarvore(&l);

      NoArvore *soma = this->NovoNoArvore('#', noEsq->GetFreq() + noDir->GetFreq(), noEsq, noDir);

      l->InsereNoFila(noLista->NovoNoLista(soma), &l);
    }
    return l->CriaSubarvore(&l);
}
