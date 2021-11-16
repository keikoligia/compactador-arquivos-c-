#include <string.h>
#include <stdlib.h>
#include "arvore.h"
#include "listaLigada.h"
#include "lista.h"

NoArvore NoArvore::*NovoNoArvore(unsigned char c, int freq, NoArvore *esq, NoArvore *dir)
{
  NoArvore *novo;
  if ((novo = malloc(sizeof(*novo))) == NULL)
      return NULL;

  novo->Freq = freq;
  novo->NoDir = dir;
  novo->NoEsq = esq;
  novo->C = c;

  return novo;
}

NoArvore NoArvore::CriaSubarvore(NoLista *list)
{
  NoListaLigada *noListaLigada = list->Inicio;
  NoArvore *noArv = noListaLigada->No;

  list.inicio = noListaLigada->Prox;

  delete(noListaLigada);
  noListaLigada = NULL;

  list->Qtd;

  return noArv;
}

NoArvore NoArvore::FazerArvore(unsigned *list)
{
  NoLista l = new NoLista(NULL, 0);

  for(int i = 0; i< 256; i++)
  {
    if(list[i])
      InsereNoFila(NovoNoLista(i, list[i], NULL, NULL)), &l);
    
    while (l.Qtd > 1)
    {
      NoArvore *noEsq = CriaSubArvore(&l);
      NoArvore *noDir = CriaSubArvore(&l);

      NoArvore *soma = NovoNoArv('#', noEsq->freq + noDir->freq, noEsq, noDir);

      InsereNoFila(NovoNoLista(soma), &l);
    }

    return CriaSubArvore(&l);
  }
}