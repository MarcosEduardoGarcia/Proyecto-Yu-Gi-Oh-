#ifndef HECHIZO_H
#define HECHIZO_H
#include <iostream>
#include "Cartas.h"

using namespace std;

//Existe una subdivision de clases para los hechizos

class Hechizo : public Cartas {



    public:

        Hechizo(string nombre, string CoID, string desc, string tipoCarta) : Cartas(nombre,CoID,desc,tipoCarta){ }


};


#endif // HECHIZO_H
