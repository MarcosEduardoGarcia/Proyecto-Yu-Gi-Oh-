#ifndef DECK_H
#define DECK_H
#include "Cartas.h"

#include <iostream>

using namespace std;

class Deck {

    private:
        Cartas *baseCartas[50];
        Cartas *deckPersonal[30];
        int contador;

    public:
        //Constructor
        Deck():contador(0){};

        void CargarBaseCartas();
        void mostrarCartas();
        void cuentaTipos();
        void mostrarCartas(string tipoCarta);
        //void creardeck();
        void ActivarInvocacion();
        void ArrojaNombres();
        //void Ataquesencillo();
        //void cuentaCartas(deckPersonal);



};

//Llenamos el arreglo de baseCartas en tiempo de ejecucion para poder usar polimorfismo
void Deck :: CargarBaseCartas(){


    baseCartas[contador] = new Monstruo("Obelisco el atormentador","Divino","2wjfiorh","El desscenso de esta bestia...","[Bestia Divina]","******",2300,2500,true);
    contador++;
    baseCartas[contador] = new Monstruo("Silfer el dragon de los cielos","Divinidad","LC01-EN002","Los cielos se estremecen y los truenos rugen indicando la llegada de esta criatura \n y el amanecer del verdadero poder",
                                        "[Bestia Divina]","**********",5000,5000,false);
    contador++;
    baseCartas[contador] = new Monstruo("Dragon alado de Ra","Divinidad","LC01-EN003","Los espiritus cantan acerca d euna poderosa bestia que gobierna sobre todo lo que es mistico",
                                        "[Bestia Divina","**********",5000,5000,false);
    contador++;
    baseCartas[contador] = new Monstruo("Dragon blanco de ojos azules","Luz","LC01-EN004","Este legendario dragon es una poderosa maquina de destrucción, virtualmente invencible",
                                        "[Dragon]","********",3000,2500,true);
    contador++;
    baseCartas[contador] = new Monstruo("Mago oscuro","Oscuro","LC01-EN003","El mago definitivo en terminos de ataque y defensa","[Lanzador de conjuros]","*******",2500,2100,true);
    contador++;

    baseCartas[contador] = new Monstruo("Dragon negro de ojos rojos","Oscuridad","LC01-EN006","Un dragon feroz con ataque mortal","[Dragon]","*******",2400,2000,true);
    contador++;

    baseCartas[contador] = new Monstruo("Craneo convocado","Oscuridad","YSYR-SP004","Un demonio con poderes oscuros para confundir al enemigo","[Demonio]","******",2500,1200,true);
    contador++;

    baseCartas[contador] = new Monstruo("Kuriboh","Oscuridad","MIL1-SP034","Pequeña bola de pelos Durante el turno de tu adversario en el calculo de daño puedes descartar esta carta no recibes daño","[Demonio/efecto]","*",300,200,false);
    contador++;

    baseCartas[contador] = new Magia("Cuerno del unicornio","BP02-SP134","El mounstruo equipado aumenta 700 puntos",700);
    contador++;

    baseCartas[contador] = new Magia("Hacha del desespero","YS14-SP026","El monstruo equipado gana 1000 puntos",1000);
    contador++;

    baseCartas[contador] = new Magia("Cuerno de luz","DB1-SP004","Aumenta el ataque en 800",800);
    contador++;

    baseCartas[contador] = new Trampa("Mascara de la debilidad","YS15-STD19","Se le resta a un mosntruo 700",-700);
    contador++;

    baseCartas[contador] = new Trampa("Hacha destrozada","BP02-SP187","Selecciona a un monstruo y este perdera 500 puntos",-700);
    contador++;


}
//Arroja toda la base de datos con su metodo correspondiente de generar carta
void Deck :: mostrarCartas(){


    for(int i=0;i<contador;i++){
        cout << i <<" " ;
        baseCartas[i]->generarCarta();

    }

}
//Arroja todas las cartas de un tipo
void Deck :: mostrarCartas(string tipoCarta){

    for (int i=0;i<contador;i++){

        if(baseCartas[i]->GetTipoCarta() == tipoCarta){

            baseCartas[i]->generarCarta();
        }
    }

}
//Metodo para contar el numero de tipo de cartas
void Deck :: cuentaTipos(){

    int num_mag = 0;
    int num_mon = 0;
    int num_tram = 0;

    for (int i=0;i<contador;i++){

        if (baseCartas[i]->GetTipoCarta()== "Magica"){

            num_mag += 1;
        }
        else if (baseCartas[i]->GetTipoCarta()== "Monstruo"){

            num_mon += 1;
        }
        else{
            num_tram +=  1;
        }

    }
    cout << "Numero de magicas " << num_mag << endl;
    cout << "Numero de monstruos " << num_mon << endl;
    cout << "Numero de trampas " << num_tram << endl;
}


//METODO EN DESARROLLO
//void creardeck(){

  //  int decision;


    //for(int i=0;i<5;i++){

      //  cout << "introduzca numero";
        //cin >> decision;

        //deckPersonal[i] = baseCartas[decision];

    //}



//}

//Metodo para activar la invocacion usando polimorfismo
void Deck::ActivarInvocacion(){

    int opcion;

    cout << "Trata de invocar una carta escribe su numero: "<<endl;
    cin >> opcion;

    baseCartas[opcion]->Invocar();

}

void Deck ::ArrojaNombres(){

    for (int i=0;i<contador;i++){

        cout << i << " " ;
        cout<<baseCartas[i]->GetNombre()<<endl;

    }

}
//METODO EN DESARROLLO
//void Deck :: Ataquecomplejo(){


  //  int opcion1,opcion2;

    //cout << "Selecciona dos monstruos"<<endl;
    //cin >> opcion1 >> opcion2;


    //if (baseCartas[opcion1]->GetTipoCarta()=="Monstruo" && baseCartas[opcion2]->GetTipoCarta()=="Monstruo"){

      //  baseCartas[opcion1]->Atacar(baseCartas[opcion2]);

    //}


//}


#endif // DECK_H





