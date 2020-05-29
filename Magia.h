#include <iostream>
#include "Hechizo.h"

using namespace std;

class Magia : public Hechizo {

    private:
        int aumentar;


    public:

        Magia(string nombre, string CoID, string desc,int aumentar) : Hechizo(nombre,CoID,desc,"Magica") {

            this->aumentar = aumentar;

        }

        void DarPoder(Monstruo &m);
        void generarCarta();
        void Invocar();

};

void Magia::DarPoder(Monstruo &m){

    m.SetAtk(aumentar);
    cout << m.GetAtk();

}

void Magia::generarCarta(){


    cout << "Nombre: "<<nombre<<endl;
    cout << "Coleccion ID: "<<CoID<<endl;
    cout << desc << endl;
    cout << "Tipo: "<< tipoCarta <<endl;
    cout << "Efecto de aumento: " << aumentar <<endl;
    cout << endl;

}

void Magia :: Invocar(){

    cout <<nombre<< " Carta de magia activada "<<endl;

}


