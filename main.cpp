#include <iostream>

#include "Monstruo.h"
#include "Magia.h"
#include "Trampa.h"
#include "Deck.h"

/*
Proyecto integrador TC1030.2
Este proyecto se centra en el entendimiento del juego de monstruos Yu-gi-Oh se cuenta con un menu donde se podran conocer
las acciones básicas del juego y una wikipedia de cartas donde se podra filtrar los tipos y ver sus caracteristicas

*/
using namespace std;

void bienvenida();
void menu();
void carga();
void wikipedia();
void invocaciones();
void ataques();
void fusiones();
void equipo();
void aplicatrampa();

int main(){

    menu();

    return 0;
}
//Funcion para imitar un tiempo de carga
void carga(){

    int i = 0;

	do{

		if (i==0){

			cout << "Cargando."<<endl;

		}
		if(i==200000000){
			cout << "Cargando.."<<endl;
		}

		if(i==400000000){
			cout << "Cargando..."<<endl;
		}
		i = i+1;
	}
	while(i<800000000);


}
//Funcion de apertura en el codigo
void bienvenida(){

//Bienvenida
    string nombre;

    cout << endl;
    cout << "Bienvenido a la interfaz de simulacion de Yu-Gi-Oh! " << endl;
    cout << "Cual es tu nombre duelista? " ;
    cin >> nombre;
    cout << "Hola " << nombre << " te doy la bienvenida soy la IA de aprendizaje Yami" << endl;
    cout << endl;
    cout << "Aqui prodras tener tu primer acercamiento al mundo de Yu-Gi-Oh!" <<endl;
    cout << "Contamos con un gran menu dale un vistazo"<<endl;
    cout << endl;




}
//Menu principal
void menu(){

    carga();
    bienvenida();

    int opcion;


    do{
        cout << endl;
        cout << "\t :::::::::::::MENU:::::::::::::::::" <<endl;
        cout << "1.- Wikipedia" <<endl;
        cout << "2.- Invocaciones"<<endl;
        cout << "3.- Ataque entre monstruos"<<endl;
        cout << "4.- Fusionar monstruos"<<endl;
        cout << "5.- Equipar magia"<<endl;
        cout << "6.- Aplicar trampa"<<endl;
        cout << "7.- Salir"<<endl;
        cout << "Elige una opcion: ";
        cin >> opcion;
        cout<<endl;

        switch(opcion){
            case 1:
                wikipedia();
                break;
            case 2:
                invocaciones();
                break;
            case 3:
                ataques();
                break;
            case 4:
                fusiones();
                break;
            case 5:
                equipo();
                break;
            case 6:
                aplicatrampa();
                break;
            case 7:
                cout << "Hasta la proxima...";
                break;
            default: cout << "No es opcion"<<endl;
        }

    }while(opcion != 7);



}

void wikipedia(){
    carga();
    int opcion;
    Deck *principal = new Deck();
    principal->CargarBaseCartas();

    //do{

        cout << "\t::::::::::::Wikipedia:::::::::::\n"<<endl;
        cout << "Actualmente contamos con: "<<endl;
        principal->cuentaTipos();
        cout << endl;
        cout << "Que tipo de cartas deseas ver? "<<endl;
        cout << "1.- Magicas"<<endl;
        cout << "2.- Monstruos" << endl;
        cout << "3.- Trampas" << endl;
        cout << "4.- Todas"<<endl;
        cout << "Digite opcion: ";
        cin >> opcion;
        if(opcion==1){
            principal->mostrarCartas("Magica");
        }
        if(opcion==2){
            principal->mostrarCartas("Monstruo");
        }
        if(opcion==3){
            principal->mostrarCartas("Trampa");
        }
        if(opcion==4){
            principal->ArrojaNombres();
            cout << "Escoge un numero para ver mas info ";
            cin >> opcion;
            cout << endl;
            principal->desplegar(opcion);
        }

    //}
    //while (opcion != 100);
    delete principal;

}

void invocaciones(){

    Deck *principal = new Deck();
    principal->CargarBaseCartas();

    cout << "La accion mas basica del juego se basa en la INVOCACION de cartas no puedes hacer nada sin invocar tus cartas"<<endl;
    cout << endl;
    principal->ArrojaNombres();
    principal->ActivarInvocacion();


    delete principal;

}

void ataques(){
    cout << "La manera de ganar un duelo sera destruyendo a los monstruos de tu oponente\n descubre que pasa cuando se atacan, si tienes duda de los ataques consulta nuestra wikipedia"<<endl;
    cout <<endl;
    Deck *principal = new Deck();
    principal->CargarBaseCartas();
    principal->ArrojaNombres();
    //cout << endl;
    principal->Ataquesencillo();
    delete principal;

}

void fusiones(){

    Deck *principal = new Deck();
    principal->CargarBaseCartas();
    principal->ArrojaNombres();
    principal->fusionMons();
    delete principal;

}

void equipo(){

    Deck *principal = new Deck();
    principal->CargarBaseCartas();
    principal->ArrojaNombres();
    principal->EquiparMagia();
    delete principal;

}

void aplicatrampa(){

    Deck *principal = new Deck();
    principal->CargarBaseCartas();
    principal->ArrojaNombres();
    principal->AplicarTrampa();
    delete principal;

}







