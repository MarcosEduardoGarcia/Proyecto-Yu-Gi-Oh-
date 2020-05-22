#include <iostream>
#include "Hechizo.h"

using namespace std;

class Magia : public Hechizo {

    private:
        int aumentar;

    public:

        Magia(string nombre, string CoID, string desc,string tipoCarta, int aumentar) : Hechizo(nombre,CoID,desc,tipoCarta) {

            this->aumentar = aumentar;

        }

        void DarPoder(Monstruo &m);
        void DarEscudo(Monstruo &m);
        void getCarta();

};

void Magia::DarPoder(Monstruo &m){

    m.SetAtk(aumentar);
    cout <<m.GetNombre()<<" recibe carta de magia ataque aumenta "<<"ATK "<< m.GetAtk()<<endl;

}

void Magia::DarEscudo(Monstruo &m){

    m.SetDef(aumentar);
    cout << m.GetNombre()<<" recibe carta de magia defensa aumenta" << "DEF "<<m.GetDef()<<endl;



}
void Magia::getCarta(){


    cout << "Nombre: "<<nombre<<endl;
    cout << "Coleccion ID: "<<CoID<<endl;
    cout << desc << endl;
    cout << "Tipo: "<< tipoCarta <<endl;
    cout << "Efecto de aumento: " << aumentar <<endl;
    cout <<endl;




}


