#include "Cartas.h"
#include <iostream>

using namespace std;
//Clase hija paro los monstruos

class Monstruo : public Cartas {


    private:
        string tipoMons;
        string nivel;
        int atk;
        int def;
        bool fusionable;
        bool status;

    public:

        //Iniciar el constructor

        Monstruo(string nombre,string atributo,string CoID, string desc,string tipoMons,string nivel,int atk,int def,bool fusionable);

        //Metodos
        void generarCarta();
        void Invocar();
        void Atacar(Monstruo &m);
        void Fusion(Monstruo &m);
        //Getters
        int GetAtk(){return atk;}
        int GetDef(){return def;}
        bool GetStatus(){return status;}
        //Setters
        void SetAtk(int val);
        void SetDef(int val);



};
//Desarrollamos el contructor
Monstruo::Monstruo(string nombre,string atributo,string CoID, string desc,string tipoMons,string nivel,int atk,int def,bool fusionable) : Cartas(nombre,atributo,CoID,desc,"Monstruo"){

            this->tipoMons = tipoMons;
            this->nivel = nivel;
            this->atk = atk;
            this->def = def;
            this->fusionable = fusionable;
            status = true;

}
//Metodos de la clase monstruo

/*
Este es un metodo sobreescrito pues es un metodo virtual en la clase padre

El metodo generar carta topa las atributos importantes de
cada una de las cartas y los presenta en pantalla separados
por barras de asteriscos pues en ocasiones se deberan presentar
mas de una carta ayudando a la visualizacion para el usuario


*/
void Monstruo::generarCarta(){

    for (int i=0;i<60;i++){cout << "*";}
    cout << endl;
    cout << endl;
    cout << "Nombre: "<<nombre<<endl;
    cout << "Atributo: "<<atributo<<endl;
    cout << "Coleccion ID: "<<CoID<<endl;
    cout << desc << endl;
    cout << "Tipo: "<< tipoCarta<<endl;
    cout<<"Nivel: " <<nivel<<endl;
    cout << "ATK/"<< atk << " DEF/"<<def<< endl;
    cout << endl;
    for (int i=0;i<60;i++){cout << "*";}
    cout<<endl;
}

/*

El metodo invocar es uno de los metodos sobreescritos pues es un
metodo virtual en la clase carta pues toda carta se invoca

*/
void Monstruo::Invocar(){

    cout << "Carta de mounstruo invocada en el campo"<<endl;
}
/*
El metodo atacar recibe por referencia un objeto tipo monstruo

Este es uno de los metodos basicos del juego de monstruos se enfretan el ataque del
mosntruo propio contra la defensa del monstruo del adversario existiendo tres posibilidades
ganar,empatar, o perder
*/

void Monstruo::Atacar(Monstruo &m){

    if(m.def < atk){
        cout << GetNombre() <<"Comienza ataque "<<endl;
        cout<< GetNombre()<<" Ha matado a " <<m.GetNombre()<<endl;
    }
    else if(m.def == atk){

        cout << "Empate no hay danio"<<endl;
    }
    else{
        cout << "Oponente recibe daño de diferencia "<<endl;
        cout << m.def-atk << " Puntos menos"<<endl;
        status = false;
    }

}

/*
Los monstruos pueden interactuar entre ellos de muchas maneras existe un atributo que no se
muestra dentro de la descripcion que consiste en si es fusionale o no esto se descubre mediante
experimentacion.

El metodo del mosntruo recibe como parametro un monstruo por referecia y evalua con un tipo de dato booleano
si ambos son true la fusion es posible.

*/

void Monstruo::Fusion(Monstruo &m){

    if (fusionable == m.fusionable && nombre != m.nombre){
        cout << "Nueva bestia" <<endl;
    }
    else{
        cout << "Fusion no existente" <<endl;
    }

}

//Setters usados para alterar la defensa y ataque de los mosntruos
void Monstruo::SetAtk(int val){

    atk = atk + val;

}

void Monstruo::SetDef(int val){

    def = def + val;
}





