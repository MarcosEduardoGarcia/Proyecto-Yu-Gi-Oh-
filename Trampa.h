#include "Hechizo.h"
#include <iostream>

using namespace std;

class Trampa : public Hechizo {


    private:
        int reducir;
    public:

        Trampa(string nombre, string CoID, string desc,int reducir);  //Constructor
        //Metodos
        void ReducirPoder(Monstruo &m);
        void generarCarta();
        void Invocar();

};
//Desarrollo del constructor
Trampa::Trampa(string nombre, string CoID, string desc,int reducir) : Hechizo(nombre,CoID,desc,"Trampa"){

            this->reducir = reducir;

}

//Metodos de la clase trampa

/*
El metodo reducir poder recibe por referencia un objeto de tipo mosntruo
con sus metodo set afectaremos su defensa en base al atributo int reducir de la trampa
*/
void Trampa::ReducirPoder(Monstruo &m){

    m.SetDef(reducir);
    cout <<"Def de "<<m.GetNombre()<<" se redujo a "<< m.GetDef()<<endl;
    cout <<endl;

}

/*
El metodo generar carta es un metodo sobreescrito definido como virtual en la
clase padre cartas este muestra sus propias caracteristicas delimitada con -- para visualizacion
*/

void Trampa::generarCarta(){

    for (int i=0;i<60;i++){cout << "--";}
    cout << endl;
    cout << endl;
    cout << "Nombre: "<<nombre<<endl;
    cout << "Coleccion ID: "<<CoID<<endl;
    cout << desc << endl;
    cout << "Tipo: "<< tipoCarta<<endl;
    cout << "Efecto negativo: "<< reducir << endl;
    cout << endl;
    for (int i=0;i<60;i++){cout << "--";}
    cout<<endl;
}

/*
El metodo invocar es declarado como virtual en la clase padre y es sobreescrito
Las cartas trampa tiene un efecto diferente al ser invocadas en el campo
*/

void Trampa :: Invocar(){

    cout << "Carta de trampa activada" << endl;
}

