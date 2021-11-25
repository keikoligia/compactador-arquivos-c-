#include "arvore.h"
#include "lista.h"
#include "bytes.h"
#include "descompactador.h"
#include <stdio.h>
#include <iostream>
#include <string>		// Necessário para usar strings

using namespace std;

Descompactador::Descompactador(){}

void Descompactador::Descompactar()
{
  cout << "Digite o nome do arquivo a ser descompactado: \n";
  cin >> this->nomeArqComp;
  this->arqComp = fopen(this->nomeArqComp, "rb");

  if(arqComp == NULL)
  {
    cout << "Arquivo não encontrado!";
    exit(0);
  }

  cout << "Digite o nome do arquivo que guardará a compactação: \n";
  cin >> this->nomeArqDesc;
  this->arqDesc = fopen(this->nomeArqDesc, "wb");

  if(arqDesc == NULL)
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
        {
            //cout << noAtual->GetC() << "1no1";
            noAtual = noAtual->GetNoDir();

        }
        else
        {
            //cout << noAtual->GetC();
            noAtual = noAtual->GetNoEsq();
        }
      }

      char caractere = noAtual->GetC();
      cout << caractere;
      fwrite(&(caractere), 1, 1, this->arqDesc);
  }

  fclose(arqComp);
  fclose(arqDesc);
};
