#include <stdio.h>
#include "arvore.h"
#include "lista.h"
#include "listaLigada.h"
#include "bytes.h"

int Bytes::GerarBit(FILE *arq, int pos, unsigned char *aux)
{
  if(pos % 8 == 0)
  {
    fread(aux, 1, 1, arq);
  }

  int result = ((*aux) & (1 << (pos % 8))); 

  if(result != 0) return 1;
  else
    return 0;
}

void Bytes::BuscaCodigoByte(NoArvore *no, unsigned char c, char *buffer, int tam)
{
    if (!(no->esq || no->dir) && no->c == c)
    {
      buffer[tam] = '\0';
      return true;
    }
    else
    {
      bool codEncontrado = false;

      if (no->esq)
      {
        buffer[tam] = '0';
        codEncontrado = buscaCodigoByte(no->esq, c, buffer, tam + 1);
      }

      if (!codEncontrado && no->dir)
      {
        buffer[tam] = '1';
        codEncontrado = buscaCodigoByte(no->dir, c, buffer, tam + 1);
      }

      if (!codEncontrado)
        buffer[tam] = '\0';

      return codEncontrado;
    }  
}

void Bytes::ObterFreqByte(FILE *arq, unsigned int *lista)
{
  unsigned char c;

  while (fread(&c, 1, 1, arq))
      lista[(unsigned char)c]++;

  fseek(arq, 0, SEEK_SET); 
}
