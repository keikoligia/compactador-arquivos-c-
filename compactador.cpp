#define ASCII 256
#define BYTE_SIZE 8

#include <math.h>
#include "compactador.h"
#include "bytes.h"
#include "arvore.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Compactador::Compactador(){}

void Compactador::Compactar()
{
    cout << "Digite o nome do arquivo a ser compactado: \n";
    cin >> this->nomeArqParaComp;

    this->arqParaComp = fopen(this->nomeArqParaComp, "r");

    if (arqParaComp == NULL)
    {
        cout << "Arquivo n�o encontrado!";
        exit(0);
    }

    cout << "Digite o nome do arquivo que guardar� a compactacao: \n";
    cin >> this->nomeArqComp;

    this->arqComp = fopen(this->nomeArqComp, "w");

    if (arqComp == NULL)
    {
        cout << "Por favor digite corretamente o nome do arquivo!";
        exit(0);
    }

    Bytes *bytes = new Bytes();
    bytes->ObterFreqByte(this->arqParaComp, this->lBytes);

    NoArvore *arvore = new NoArvore();
    arvore->FazerArvore(this->lBytes);

    unsigned int tamanho;
    unsigned char aux;
    unsigned char c;

    fwrite(this->lBytes, 256, sizeof(this->lBytes[0]), this->arqComp);
    fseek(this->arqComp, sizeof(unsigned int), SEEK_CUR);

    while (fread(&c, 1, 1, this->arqParaComp) >= 1)
    {
        char buffer[1024] = {0};

        bytes->BuscaCodigoByte(arvore, c, buffer, 0);

        for (char *i = buffer; *i; i++)
        {
            if (*i == '1')
            {
                aux = aux | (1 << (tamanho % 8));
            }
            tamanho++;

            if (tamanho % 8 == 0)
            {
                fwrite(&aux, 1, 1, this->arqComp);
                aux = 0;
            }
        }
    }

    fwrite(&aux, 1, 1, this->arqComp);
    fseek(this->arqComp, 256 * sizeof(unsigned int), SEEK_SET);
    fwrite(&tamanho, 1, sizeof(unsigned), this->arqComp);

    fclose(arqParaComp);
    fclose(arqComp);
}




