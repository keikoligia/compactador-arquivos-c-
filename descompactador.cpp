#include "arvore.h"
#include "lista.h"
#include "listaLigada.h"
#include "descompactador.h"
#include "bytes.h"
#include <stdio.h>
#include <iostream>
using namespace std;

void Descompactador::Descompactar()
{
  Descompactador *descomp = new Descompactador();

  cout << "Digite o nome do arquivo a ser descompactado: \n";
  cin >> descomp->nomeArqComp;
  descomp->arqComp = fopen(descomp->nomeArqComp, "r");

  if(arqComp == NULL)
  {
    cout << "Arquivo não encontrado!";
    exit(0);
  }

  cout << "Digite o nome do arquivo que guardará a compactação: \n";
  cin >> descomp->nomeArqComp;
  descomp->arqComp = fopen(descomp->nomeArqComp, "r");

  if(arqComp == NULL)
  {
    cout << "Por favor digite corretamente o nome do arquivo!";
    exit(0);
  }
  
  fread(descomp->lBytes, sizeof(unsigned int), 256,  descomp->arqComp);

  NoArvore *arvore = new NoArvore();
  arvore->FazerArvore(descomp->lBytes);

}