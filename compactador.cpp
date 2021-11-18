#include "arvore.h"
#include "lista.h"
#include "bytes.h"
#include "listaLigada.h"
#include "compactador.h"
#include <stdio.h>
#include <iostream>
using namespace std;

void Compactador::Compactar()
{
    cout << "Digite o nome do arquivo a ser compactado: \n";
    cin >> this->nomeArqParaComp;

    this->arqParaComp = fopen(this->nomeArqParaComp, "rb");

    if (arqParaComp == NULL)
    {
        cout >> "Arquivo não encontrado!";
        exit(0);
    }

    cout << "Digite o nome do arquivo que guardará a compactacao: \n";
    cin >> this->nomeArqComp;

    this->arqComp = fopen(this->nomeArqComp, "wb");

    if (arqComp == NULL)
    {
        cout >> "Por favor digite corretamente o nome do arquivo!";
        exit(0);
    }

    ObterFreqByte(this->arqParaComp, this->lBytes);

    noArvore *arvore = FazerArvore(this->lBytes);

    unsigned int tamanho;
    unsigned char aux;
    unsigned char c;

    fwrite(this->lBytes, 256, sizeof(this->lBytes[0]), this->arqComp);
    fseek(this->arqComp, sizeof(unsigned int), SEEK_CUR);

    while (fread(&c, 1, 1, this->arqParaComp) >= 1)
    {
        char buffer[1024] = {0};

        BuscaCodigoByte(arvore, c, buffer, 0);

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
