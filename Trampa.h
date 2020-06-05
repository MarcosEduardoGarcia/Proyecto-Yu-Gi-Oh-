#include "Hechizo.h"
#include <iostream>

using namespace std;

class Trampa : public Hechizo {


    private:
        int reducir;


    public:

        Trampa(string nombre, string CoID, string desc,int reducir) : Hechizo(nombre,CoID,desc,"Trampa"){

            this->reducir = reducir;


        }

        void ReducirPoder(Monstruo &m);
        void generarCarta();
        void Invocar();

};
//Metodos de la clase trampa
void Trampa::ReducirPoder(Monstruo &m){

    m.SetAtk(reducir);
    cout <<"Ataque se redujo a: "<< m.GetAtk();

}

void Trampa::generarCarta(){

    for (int i=0;i<60;i++){cout << "--";}
    cout<<endl;
    cout << "Nombre: "<<nombre<<endl;
    cout << "Coleccion ID: "<<CoID<<endl;
    cout << desc << endl;
    cout << "Tipo: "<< tipoCarta<<endl;
    cout << "Efecto negativo: "<< reducir << endl;
    cout << endl;
    for (int i=0;i<60;i++){cout << "--";}
    cout<<endl;
}

void Trampa :: Invocar(){

    cout << "Carta de trampa activada" << endl;
}

