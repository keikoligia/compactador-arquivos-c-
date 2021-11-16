#ifndef NOARVORE
#define NOARVORE
#include "lista.h"
#include "listaLigada.h"

class NoArvore
{
  private:
    NoArvore *NoEsq;
    NoArvore *NoDir;
    NoArvore *No;
    int Freq;
    char C;
    
  public:
    void SetNoEsq(NoArvore*);
    void SetNoDir(NoArvore*);
    void SetNo(NoArvore);
    void SetFreq(int);
    void SetC(unsigned char);
    int GetFreq();
    NoArvore* GetNoDir();
    NoArvore* GetNoEsq(); 
    char GetC();

    void SetValores(unsigned char, int, NoArvore, NoArvore);
    NoArvore *NovoNoArvore(unsigned char, int, NoArvore*, NoArvore*);
    NoArvore *CriaSubarvore(NoLista*);
    NoArvore *CriaSubarvore(NoLista**);
    NoArvore *FazerArvore(unsigned int *);
    void InsereNoFila(NoListaLigada*, NoLista*);
    void InsereNoFila(NoListaLigada*, NoLista**);
    NoArvore(unsigned char, int, NoArvore*, NoArvore*);
    NoArvore();
};

#endif