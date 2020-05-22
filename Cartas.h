#ifndef CARTAS_H
#define CARTAS_H

//Clase padre
#include <iostream>
using namespace std;

class Cartas {

    protected:
        string nombre,atributo,CoID,desc,tipoCarta;

    public:

        //Creamos constructor Monstruo
        Cartas(string nombre,string atributo,string CoID, string desc,string tipoCarta);
        //Constructor cartas Hechizo
        Cartas(string nombre,string CoID,string desc,string tipoCarta);

        void getCarta();
        void Invocar();
        //getters
        string GetNombre(){return nombre;}
        string GetAtributo(){return atributo;}
        string GetCoID(){return CoID;}
        string GetDescripcion(){return desc;}
        string GetTipoCarta(){return tipoCarta;}

};
//Desarrollo de métodos
Cartas :: Cartas(string nombre,string atributo,string CoID, string desc,string tipoCarta){

    this->nombre = nombre;
    this->atributo = atributo;
    this->CoID = CoID;
    this->desc = desc;
    this->tipoCarta = tipoCarta;

}

Cartas :: Cartas(string nombre,string CoID,string desc,string tipoCarta){


    this->nombre = nombre;
    this->CoID = CoID;
    this->desc = desc;
    this->tipoCarta = tipoCarta;

}

void Cartas::getCarta(){

    cout << "Nombre: "<<nombre<<endl;
    cout << "Atributo: "<<atributo<<endl;
    cout << "Coleccion ID: "<<CoID<<endl;
    cout << desc << endl;
    cout << "Tipo: "<< tipoCarta<<endl;
    cout << endl;

}

void Cartas::Invocar(){

    cout << nombre << "Invocado"<<endl;

}




#endif // CARTAS_H
