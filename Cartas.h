#ifndef CARTAS_H
#define CARTAS_H

//Clase padre
/*
    Clase cartas sera una clase abstracta pues no se instanciaran objetos de este tipo
*/
#include <iostream>
using namespace std;

class Cartas {

    protected:
        string nombre,atributo,CoID,desc,tipoCarta;  //tipoCarta puede ser Monstruo, Magica o Trampa

    public:

        //Creamos constructor Monstruo
        Cartas(string nombre,string atributo,string CoID, string desc,string tipoCarta);
        //Constructor cartas Hechizo
        Cartas(string nombre,string CoID,string desc,string tipoCarta);

        virtual void generarCarta()=0;   //Clases virtuales puras se sobreescribiran
        virtual void Invocar()=0;     //Clase virtual puras se sobreescribe
        //getters
        string GetNombre(){return nombre;}
        string GetAtributo(){return atributo;}
        string GetCoID(){return CoID;}
        string GetDescripcion(){return desc;}
        string GetTipoCarta(){return tipoCarta;}

};
//Desarrollo de métodos

Cartas :: Cartas(string nombre,string atributo,string CoID, string desc,string tipoCarta){  //Constructor usado para monstruos

    this->nombre = nombre;
    this->atributo = atributo;
    this->CoID = CoID;
    this->desc = desc;
    this->tipoCarta = tipoCarta;

}

Cartas :: Cartas(string nombre,string CoID,string desc,string tipoCarta){   //Constructor usado para hechizos


    this->nombre = nombre;
    this->CoID = CoID;
    this->desc = desc;
    this->tipoCarta = tipoCarta;

}


#endif // CARTAS_H
