#ifndef HECHIZO_H
#define HECHIZO_H
#include <iostream>
#include "Cartas.h"

using namespace std;

class Hechizo : public Cartas {


    public:

        Hechizo(string nombre, string CoID, string desc, string tipoCarta) : Cartas(nombre,CoID,desc,tipoCarta){

        }

        void DarPoder(Monstruo &m);
        void ReducirPoder(Monstruo &m);
        void DarEscudo(Monstruo &m);
        void ReducirEscudo(Monstruo &m);

};


#endif // HECHIZO_H
