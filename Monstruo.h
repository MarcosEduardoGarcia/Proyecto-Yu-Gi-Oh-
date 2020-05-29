#include "Cartas.h"
#include <iostream>

using namespace std;
//Clase hija

class Monstruo : public Cartas {


    private:
        string tipoMons;
        string nivel;
        int atk;
        int def;
        bool fusionable;

    public:

        //Iniciar el constructor

        Monstruo(string nombre,string atributo,string CoID, string desc,string tipoMons,string nivel,int atk,int def,bool fusionable) : Cartas(nombre,atributo,CoID,desc,"Monstruo"){

            this->tipoMons = tipoMons;
            this->nivel = nivel;
            this->atk = atk;
            this->def = def;
            this->fusionable = fusionable;


        }

        void generarCarta();
        void Invocar();
        int GetAtk(){return atk;}
        int GetDef(){return def;}
        void Atacar(Monstruo &m );
        void Fusion(Monstruo &m);
        void SetAtk(int val);



};

void Monstruo::generarCarta(){


    cout << "Nombre: "<<nombre<<endl;
    cout << "Atributo: "<<atributo<<endl;
    cout << "Coleccion ID: "<<CoID<<endl;
    cout << desc << endl;
    cout << "Tipo: "<< tipoCarta<<endl;
    cout<<"Nivel: " <<nivel<<endl;
    cout << "ATK/"<< atk << " DEF/"<<def<< endl;
    cout << endl;

}

void Monstruo::Invocar(){

    cout << "Carta de mounstruo invocada en el campo"<<endl;


}


void Monstruo::Atacar(Monstruo &m){

    if(m.def < atk){
        cout << GetNombre() <<"Comienza ataque "<<endl;
        cout<< GetNombre()<<" Ha matado a " <<m.GetNombre();
    }
    else{
        cout << "Oponente recibe daño de diferencia ";
    }

}

void Monstruo::Fusion(Monstruo &m){

    if (fusionable == m.fusionable){
        cout << "Nueva bestia" <<endl;
    }
    else{
        cout << "Fusion no existente" <<endl;
    }

}

void Monstruo::SetAtk(int val){

    atk = atk + val;

}





