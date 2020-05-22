#include "Hechizo.h"
#include <iostream>

using namespace std;

class Trampa : public Hechizo {


    private:
        int reducir;

    public:

        Trampa(string nombre, string CoID, string desc, string tipoCarta,int reducir) : Hechizo(nombre,CoID,desc,tipoCarta){

            this->reducir = reducir;

        }

        void ReducirPoder(Monstruo &m);
        void ReducirEscudo(Monstruo &m);
        void getCarta();

};

void Trampa::ReducirPoder(Monstruo &m){

    m.SetAtk(reducir);
    cout <<m.GetNombre()<<" ATK "<< m.GetAtk()<<endl;

}

void Trampa::ReducirEscudo(Monstruo &m){

    m.SetDef(reducir);
    cout << m.GetNombre()<<" se ve afectado por carta trampa defensa baja DEF " <<  m.GetDef()<<endl;

}

void Trampa::getCarta(){

    cout << "Nombre: "<<nombre<<endl;
    cout << "Coleccion ID: "<<CoID<<endl;
    cout << desc << endl;
    cout << "Tipo: "<< tipoCarta<<endl;
    cout << "Efecto negativo: "<< reducir << endl;
    cout << endl;

}

