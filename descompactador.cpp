#ifndef DESCOMPACTADOR
#define DESCOMPACTADOR
#include "arvore.h"
#include "lista.h"
#include "bytes.h"
#include "listaLigada.h"
#include "descompactador.h"
#include <stdio.h>
#include <iostream>
using namespace std;

Descompactador::Descompactador()
{
  
}

void Descompactador::Descompactar()
{
  cout << "Digite o nome do arquivo a ser descompactado: \n";
  cin >> this->nomeArqComp;
  this->arqComp = fopen(this->nomeArqComp, "r");

  if(arqComp == NULL)
  {
    cout << "Arquivo não encontrado!";
    exit(0);
  }

  cout << "Digite o nome do arquivo que guardará a compactação: \n";
  cin >> this->nomeArqComp;
  this->arqComp = fopen(this->nomeArqComp, "r");

  if(arqComp == NULL)
  {
    cout << "Por favor digite corretamente o nome do arquivo!";
    exit(0);
  }
  
  fread(this->lBytes, sizeof(unsigned int), 256,  this->arqComp);

  NoArvore *arvore = new NoArvore();
  arvore->FazerArvore(this->lBytes);

  unsigned tamanho;
  fread(&tamanho, sizeof(tamanho), 1, this->arqComp);
  
  unsigned int posicao;
  Bytes *bytes = new Bytes();

  while (posicao < tamanho)
  {
    NoArvore *noAtual = new NoArvore();
    noAtual = arvore;

    //enquanto o nó nao for folha
    while (noAtual->GetNoEsq() || noAtual->GetNoDir())
    {
        if(bytes->GerarBit(arqComp, posicao++, &aux))
            noAtual = noAtual->GetNoDir();
            //caso gerarbit = 1
        else
            noAtual = noAtual->GetNoEsq();
            //caso 0
      }

      char caractere = noAtual->GetC();
      fwrite(&(caractere), 1, 1, this->arqDesc);
  }
  
  fclose(arqComp);
  fclose(arqDesc);
};

#endif