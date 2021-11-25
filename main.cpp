#include <iostream>
#include "descompactador.h"

int main()
{
    try
    {
      Descompactador *descomp = new Descompactador();
      descomp->Descompactar();
      return 0;
    }
    catch (const std::exception& e) { // reference to the base of a polymorphic object
     std::cout << e.what();
     } // information from length_error printed
}
