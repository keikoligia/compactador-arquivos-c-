#ifndef NOARVORE
#define NOARVORE

struct NoArv
{
    NoArv();
    NoArv *NoEsq;
    NoArv *NoDir;
    NoArv *No;
    int Freq;
    char C;
    NoArv *NovoNoArvore(unsigned char, int, NoArv*, NoArv*);
    NoArv* FazerArvore(unsigned int *);
    void imprimirArvore(NoArv*, int);

};

class NoArvore
{
  public:
    void SetNoEsq(NoArvore*);
    void SetNoDir(NoArvore*);
    void SetNo(NoArvore);
    void SetFreq(int);
    void SetC(unsigned char);
    void SetValores(unsigned char, int, NoArvore, NoArvore);
    void SetProx(NoArvore*);

    int GetFreq();
    NoArvore* GetNoDir();
    NoArvore* GetNoEsq();
    char GetC();

    NoArvore(unsigned char, int, NoArvore*, NoArvore*);
    NoArvore();
};

#endif
