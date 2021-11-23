#include "arvore.h"
#include "lista.h"
#include "bytes.h"
#include "descompactador.h"
#include <stdio.h>
#include <iostream>
#include <string>		// Necess�rio para usar strings

using namespace std;

Descompactador::Descompactador(){}

void Descompactador::Descompactar()
{
  cout << "Digite o nome do arquivo a ser descompactado: \n";
  cin >> this->nomeArqComp;
  this->arqComp = fopen(this->nomeArqComp, "r");

  if(arqComp == NULL)
  {
    cout << "Arquivo n�o encontrado!";
    exit(0);
  }

  cout << "Digite o nome do arquivo que guardar� a compacta��o: \n";
  cin >> this->nomeArqDesc;
  this->arqDesc = fopen(this->nomeArqDesc, "w");

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

    //enquanto o n� nao for folha
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
