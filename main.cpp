#include <iostream>

#include "Monstruo.h"
#include "Magia.h"
#include "Trampa.h"
#include "Deck.h"

/*

Marcos Eduardo García Ortiz A01276213
Proyecto integrador TC1030.2
Este proyecto se centra en el entendimiento del juego de monstruos Yu-gi-Oh se cuenta con un menu donde se podran conocer
las acciones básicas del juego y una wikipedia de cartas donde se podra filtrar los tipos y ver sus caracteristicas

*/
using namespace std;

//Declaracion de prototipos de interfaz
void bienvenida();
void menu();
void carga();
void wikipedia();
void invocaciones();
void ataques();
void fusiones();
void equipo();
void aplicatrampa();
void quiz();


//main para mandar a llamar al menu
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
    cout << endl;

}

//Funcion de apertura en el codigo
void bienvenida(){

//Bienvenida
    string nombre;

    cout << endl;
    cout << "Bienvenido a la interfaz de simulacion de Yu-Gi-Oh! " << endl;
    cout << "Cual es tu nombre duelista? " ;
    cin >> nombre;
    cout << endl;
    cout << "Hola " << nombre << " te doy la bienvenida soy la IA de aprendizaje Yami" << endl;
    cout << endl;
    cout << "Aqui prodras tener tu primer acercamiento al mundo de Yu-Gi-Oh!" <<endl;
    cout << "Contamos con un gran menu dale un vistazo"<<endl;
    cout << endl;

}

//Menu principal para acceder a las secciones de aprendizaje
void menu(){

    carga();
    bienvenida();

    int opcion=0;


    do{
        cout << endl;
        cout << "\t :::::::::::::MENU:::::::::::::::::" <<endl;
        cout << "1.- Wikipedia" <<endl;
        cout << "2.- Invocaciones"<<endl;
        cout << "3.- Ataque entre monstruos"<<endl;
        cout << "4.- Fusionar monstruos"<<endl;
        cout << "5.- Equipar magia"<<endl;
        cout << "6.- Aplicar trampa"<<endl;
        cout << "7.- Quiz"<<endl;
        cout << "8.- Salir"<<endl;
        cout << "Elige una opcion: ";
        cin >> opcion;
        cout<<endl;
        //Menu opciones donde se llaman a las diversas funciones
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
                quiz();
                break;
            case 8:
                cout << "Hasta la proxima..."<<endl;
                break;
            case 777:
                cout << "$592359u3fnfv$&$&3::: Created by Marcos Garcia Ortiz 09/06/2019 (RaggedyGrain507):::#%#$/%FGGBe32643#";
                break;
            default: cout << "No es opcion"<<endl;
        }

    }while(opcion != 8 && opcion != 777);



}

//Funcion 1 de menu
void wikipedia(){
    carga();
    int opcion=0;
    Deck *principal = new Deck(); //Se crea el objeto deck con apuntadores en tiempo de ejecucion
    principal->CargarBaseCartas(); // Se carga el arreglo de cartas para operar con el

    do{

        cout << "\t::::::::::::Wikipedia:::::::::::\n"<<endl;
        cout << "Aqui podras ver la descripcion de las cartas de Yu-Gi-Oh!"<<endl;
        cout << "Actualmente contamos con: "<<endl;
        principal->cuentaTipos();
        cout << endl;
        cout << "Que tipo de cartas deseas ver? "<<endl;
        cout << "1.- Magicas"<<endl;
        cout << "2.- Monstruos" << endl;
        cout << "3.- Trampas" << endl;
        cout << "4.- Todas"<<endl;
        cout << "Presione 100 para regresar"<<endl;
        cout << "Digite opcion: ";
        cin >> opcion;
        cout << endl;
        //Menu secundario de  wikipedia para acceder a la descripcion de las cartas
        switch (opcion){

            case 1:
                cout << "\t:::::::::MAGICAS::::::::::"<<endl;
                cout << endl;
                principal->mostrarCartas("Magica");
                break;
            case 2:
                cout << "\t::::::::MONSTRUOS:::::::::"<<endl;
                cout << endl;
                principal->mostrarCartas("Monstruo");
                break;
            case 3:
                cout << "\t::::::::TRAMPAS:::::::"<<endl;
                cout << endl;
                principal->mostrarCartas("Trampa");
                break;
            case 4:
                principal->ArrojaNombres();
                cout << "Escoge un numero para ver mas info ";
                cin >> opcion;
                cout << endl;
                principal->desplegar(opcion);
                break;
            case 100:
                break;
            default:
                cout << "Opcion incorrecta"<<endl;
        }

    }
    while (opcion != 100);

    delete principal;  //Se borra el objeto del heap

}


//Case 2 del menu
void invocaciones(){

    int opcion=0;
    int opcionPrincipal=0;
    Deck *principal = new Deck(); //Se crea el objeto deck con apuntadores en tiempo de ejecucion
    principal->CargarBaseCartas(); // Se carga el arreglo de cartas para operar con el

    cout << "La accion mas basica del juego se basa en la INVOCACION de cartas no puedes hacer nada sin invocar tus cartas"<<endl;
    cout << endl;

    do{


        cout << "1.- Probar invocacion"<<endl;
        cout << "2.- Regresar"<<endl;
        cout << "Teclee opcion: ";
        cin >> opcionPrincipal;

        if(opcionPrincipal==1){

            principal->ArrojaNombres();
            cout << "Trata de invocar una carta escribe su numero: ";
            cin >> opcion;
            cout << endl;
            principal->ActivarInvocacion(opcion);
            cout << endl;

        }

    }while(opcionPrincipal!=2);


    delete principal; //Se borra el objeto del heap
}

//Caso 3 del menu
void ataques(){

    int opcion1=0,opcion2=0;
    int opcionPrincipal=0;
    Deck *principal = new Deck(); //Se crea el objeto deck con apuntadores en tiempo de ejecucion
    principal->CargarBaseCartas(); // Se carga el arreglo de cartas para operar con el

    cout << "La manera de ganar un duelo sera destruyendo a los monstruos de tu oponente";
    cout << "\nse enfrentan el ATK de tu mosntruo vs la DEF del monstruo rival"<<endl;
    cout <<endl;

    do{
    cout << endl;
    cout << "1.- Iniciar ataque"<<endl;
    cout << "2.- Regresar"<<endl;
    cout << "Teclee opcion: ";
    cin >> opcionPrincipal;

    if(opcionPrincipal==1){

        principal->ArrojaNombres();
        cout << "Selecciona dos monstruos"<<endl;
        cout << "Monstruo 1: ";
        cin >> opcion1;
        principal->desplegar(opcion1);
        cout << "Monstruo 2: ";
        cin >> opcion2;
        principal->desplegar(opcion2);
        carga();
        principal->Ataquesencillo(opcion1,opcion2);
    }

    }while(opcionPrincipal!=2);

    delete principal; //Se borra el objeto del heap

}

//caso 4 del menu
void fusiones(){

    int opcion1=0,opcion2=0;
    int opcionPrincipal;
    Deck *principal = new Deck(); //Se crea el objeto deck con apuntadores en tiempo de ejecucion
    principal->CargarBaseCartas(); // Se carga el arreglo de cartas para operar con el

    cout << "Los monstruos cuentan con un atributo secreto de fusion por ahora solo descubriras si crean una nueva bestia o no"<<endl;
    cout << endl;

    do{
    cout << "1.- Probar fusion"<<endl;
    cout << "2.- Regresar" <<endl;
    cout << "Digite opcion: ";
    cin >> opcionPrincipal;
    cout << endl;
    if(opcionPrincipal == 1){

        principal->ArrojaNombres();
        cout << "Selecciona dos monstruos"<<endl;
        cout << "Monstruo 1: ";
        cin >> opcion1;
        principal->desplegar(opcion1);

        cout << "Monstruo 2: ";
        cin >> opcion2;
        principal->desplegar(opcion2);

        carga();
        principal->fusionMons(opcion1,opcion2);

    }

    }while(opcionPrincipal != 2);

    delete principal; //Se borra el objeto del heap
}

//Caso 5 del menu
void equipo(){

    int opcion1=0,opcion2=0;
    int opcionPrincipal=0;
    Deck *principal = new Deck(); //Se crea el objeto deck con apuntadores en tiempo de ejecucion
    principal->CargarBaseCartas(); // Se carga el arreglo de cartas para operar con el

    cout << "Ahora veras como la magia potencia a un monstruo" << endl;
    cout << endl;

    do{
        cout << "1.- Equipar Magia"<<endl;
        cout << "2.- Salir"<<endl;
        cout <<"Teclee una opcion: ";
        cin >> opcionPrincipal;
        if(opcionPrincipal == 1){

            principal->ArrojaNombres();
            cout << "Selecciona un monstruo y una carta de magia"<<endl;

            cout << "Monstruo : ";
            cin >> opcion1;
            cout <<endl;
            principal->desplegar(opcion1);

            cout << "Carta de magia: ";
            cin >> opcion2;
            principal->desplegar(opcion2);
            carga();
            principal->EquiparMagia(opcion1,opcion2);

        }

    }while(opcionPrincipal != 2);

    delete principal; //Se borra el objeto del heap
}

//Caso 6 del menu
void aplicatrampa(){
    int opcion1=0,opcion2=0;
    int opcionPrincipal=0;

    Deck *principal = new Deck(); //Se crea el objeto deck con apuntadores en tiempo de ejecucion
    principal->CargarBaseCartas(); // Se carga el arreglo de cartas para operar con el
    cout << "Deblitar a monstruos es la clave para derrotar a tus oponentes para ello tienes las cartas de trampa"<<endl;
    do{
        cout << "1.- Aplicar trampa"<<endl;
        cout << "2.- Salir"<<endl;
        cout << "Teclee una opcion: ";
        cin >> opcionPrincipal;
        cout << endl;

        if(opcionPrincipal == 1){
            principal->ArrojaNombres();
            cout << "Selecciona un monstruo y una carta de trampa"<<endl;
            cout << "Monstruo : ";
            cin >> opcion1;
            principal->desplegar(opcion1);
            cout << "Carta de trampa: ";
            cin >> opcion2;
            principal->desplegar(opcion2);
            carga();
            principal->AplicarTrampa(opcion1,opcion2);
        }


    }while(opcionPrincipal !=2 );


    delete principal; //Se borra el objeto del heap
}
//caso 7 del menu
void quiz(){

    Deck *principal = new Deck(); //Se crea el objeto deck con apuntadores en tiempo de ejecucion
    principal->CargarBaseCartas(); // Se carga el arreglo de cartas para operar con el
    int opcion=0;
    int movimientos=2;
     int opcionSec=0;

    cout << "Llego el momento de probar tus habilidades mediante este quiz"<<endl;
    cout << "Derrota a la bestia mas poderosa del juego para demostrar que eres digno"<<endl;
    cout << "Intrucciones: Se te dara un monstruo propio y un monstruo al cual vencer con cierta cantidad de movimientos, deberas usar los medios dados para vencerlo"<<endl;
    cout << "Ultima leccion: Cuando inicia un batalla se dice !!!!ES HORA DEL DUELO!!!!!"<<endl;
    cout << endl;
    cout << "Tu monstruo"<<endl;
    cout << endl;
    principal->desplegar(4);
    cout << endl;
    cout << "Monstruo a vencer"<<endl;
    cout << endl;
    principal->desplegar(2);
    cout << endl;
    cout << "Que deseas hacer?"<<endl;
    cout << endl;

    do{

        cout << "1.- DAR CARTA MAGICA "<<endl;

        cout << "2.- USAR CARTA TRAMPA"<<endl;
        cout << "Teclee opcion: ";
        cin >> opcion;
        cout << endl;

        switch(opcion){



           case 1:

               principal->mostrarCartas("Magica");
               cout << "Que carta deseas usar?"<<endl;
               cout << "Teclea su numero: ";
               cin >> opcionSec;
               cout << endl;
               principal->EquiparMagia(4,opcionSec);
               cout << endl;
               break;

           case 2:

               principal->mostrarCartas("Trampa");
               cout << "Que carta deseas usar?"<<endl;
               cout << "Teclea su numero: ";
               cin >> opcionSec;
               principal->AplicarTrampa(2,opcionSec);
               cout << endl;
               break;

        }

        movimientos = movimientos - 1;
        cout << "Movimientos restantes "<<movimientos<<endl;
        cout << endl;
    }while(movimientos != 0);



    cout << "Inicie ataque con 1"<<endl;
    cout << "Teclee opcion: ";
    cin >> opcion;
    cout << endl;
    while (opcion != 1){

        cout << "tecla incorrecta presione 1: ";
        cin >> opcion;
    }

    if (opcion == 1){
        carga();
        principal->Ataquesencillo(4,2);
        cout << endl;
        principal->Ganador(4);
    }

    delete principal; //Se borra el objeto del heap
}


