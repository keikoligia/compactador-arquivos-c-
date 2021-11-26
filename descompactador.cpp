#include "arvore.h"
#include "lista.h"
#include "bytes.h"
#include "descompactador.h"
#include <stdio.h>
#include <iostream>

using namespace std;

Descompactador::Descompactador(){}

void Descompactador::Descompactar()
{
  cout << "Digite o nome do arquivo a ser descompactado: \n";
  cin >> this->nomeArqComp;
  this->arqComp = fopen(this->nomeArqComp, "r");

  if(arqComp == NULL)
  {
    cout << "Arquivo nao encontrado!";
    exit(0);
  }

  cout << "Digite o nome do arquivo que guardara a compactacao: \n";
  cin >> this->nomeArqDesc;
  this->arqDesc = fopen(this->nomeArqDesc, "w");

  if(arqDesc == NULL)
  {
    cout << "Por favor digite corretamente o nome do arquivo!";
    exit(0);
  }

  fread(this->lBytes, sizeof(unsigned int), 256,  this->arqComp);

  NoArv *arvore = new NoArv();

  NoArv *raiz = arvore->FazerArvore(this->lBytes);

  //arvore->imprimirArvore(raiz, 0);

  unsigned tamanho;
  fread(&tamanho, sizeof(tamanho), 1, this->arqComp);

  unsigned int posicao;
  Bytes *bytes = new Bytes();

  unsigned char aux = 0;

  while (posicao < tamanho)
  {
    //cout << posicao << tamanho << "\n";
    NoArv *noAtual = new NoArv();
    noAtual = raiz;

    //enquanto o n� nao for folha
    while (noAtual->NoEsq || noAtual->NoDir)
    {
        if(bytes->GerarBit(this->arqComp, posicao++, &aux))
            noAtual = noAtual->NoDir;
            //caso gerarbit = 1
        else
            noAtual = noAtual->NoEsq;
            //caso 0
    }
      fwrite(&(noAtual->C), 1, 1, this->arqDesc);
  }
  fclose(arqComp);
  fclose(arqDesc);
};
