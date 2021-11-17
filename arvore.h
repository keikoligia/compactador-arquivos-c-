#ifndef NOARVORE
#define NOARVORE

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
    NoArvore *FazerArvore(unsigned int *);
    NoArvore(unsigned char, int, NoArvore*, NoArvore*);
    NoArvore();
};

#endif