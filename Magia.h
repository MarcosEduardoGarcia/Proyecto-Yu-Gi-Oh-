#include <iostream>
#include "Hechizo.h"

using namespace std;

class Magia : public Hechizo {

    private:
        int aumentar;


    public:

        Magia(string nombre, string CoID, string desc,int aumentar); //Constructor
        //Metodos
        void DarPoder(Monstruo &m);
        void generarCarta();
        void Invocar();

};
//Desarrollando el constructor
Magia::Magia(string nombre, string CoID, string desc,int aumentar) : Hechizo(nombre,CoID,desc,"Magica") {

    this->aumentar = aumentar;

}


//Metodos de la clase magia
/*
El metodo dar poder recibe como parametro un mosntruo al cual se le
modificara su atributo de ataque potenciandolo
*/
void Magia::DarPoder(Monstruo &m){

    m.SetAtk(aumentar);
    cout <<"Poder de atk de "<<m.GetNombre()<<" aumenta a: "<< m.GetAtk()<<endl;
    cout << endl;

}


/*
El metodo generar carta es sobreescrito pues es virtual en la clase padre cartas
Muestra los atributos propios de la cartas de magia delimitados con lineas diagonales
para estilo y visualizacion
*/

void Magia::generarCarta(){

    for(int i=0;i<50;i++){cout << "/";}
    cout << endl;
    cout << endl;
    cout << "Nombre: "<<nombre<<endl;
    cout << "Coleccion ID: "<<CoID<<endl;
    cout << desc << endl;
    cout << "Tipo: "<< tipoCarta <<endl;
    cout << "Efecto de aumento: " << aumentar <<endl;
    cout <<endl;
    for(int i=0;i<50;i++){cout << "/";}
    cout << endl;

}

/*

Metodo sobreescrito pues es virtual en la clase padre
Las cartas magicas tienen un efecto diferente al ser invocadas en el campo de batalla

*/
void Magia :: Invocar(){

    cout <<nombre<< " Carta de magia activada "<<endl;

}


