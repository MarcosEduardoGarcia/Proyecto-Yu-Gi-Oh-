#ifndef DECK_H
#define DECK_H
#include "Cartas.h"

#include <iostream>

/*
En esta clase se generaran objetos de tipo deck en particular con un arreglo denominado baseCartas
YuGiOh cuenta con una extensa variedad de cartas se generan las cartas mas famosas de la primera generación
y se guardaran en un arreglo con limite de 50 cartas

*/

using namespace std;

class Deck {

    private:
        Cartas *baseCartas[50]; //arreglo de cartas con apuntador para usar el polimorfismo
        int contador;    //Contador util para reccorer el arreglo

    public:
        //Constructor por default
        Deck():contador(0){};
        //Metodos de la clase Deck
        void CargarBaseCartas();
        void mostrarCartas();
        void cuentaTipos();
        void mostrarCartas(string tipoCarta);
        void desplegar(int opcion);
        void ActivarInvocacion(int opcion);
        void ArrojaNombres();
        void Ataquesencillo(int monstruo1,int monstruo2);
        void fusionMons(int opcion1,int opcion2);
        void EquiparMagia(int monstruo,int magia);
        void AplicarTrampa(int monstruo,int trampa);
        void Ganador(int monstruo1);



};
/*
Creamos el arreglo de baseCartas y lo llenamos con objetos de las
distintas clases Monstruo,Magia y Trampo en tiempo de ejecucion con "new" en el heap,
de inicio en el arreglo existen los objetos como
cartas y con el polimorfismo haran uso de su propio metodo cuando sea llamado
*/
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

    baseCartas[contador] = new Trampa("Mascara de la debilidad","YS15-STD19","Se le resta a un mosntruo 700",-1700);
    contador++;

    baseCartas[contador] = new Trampa("Hacha destrozada","BP02-SP187","Selecciona a un monstruo y este perdera 500 puntos",-700);
    contador++;


}
//Arroja toda la base de datos usando su metodo correspondiente de generar carta segun sea Monstruo,Magia o Trampa
void Deck :: mostrarCartas(){


    for(int i=0;i<contador;i++){
        cout << i <<" " ;
        baseCartas[i]->generarCarta();

    }

}
/*
Arroja todas las cartas de un mismo tipo sobrecargando este metodo
Recorremos el arreglo buscando las cartas donde el atributo de tipoCarta
coincidan con el paramtero de tipo string y obteniendo su posicion en el arreglo
imrpiendo el iterador i
*/
void Deck :: mostrarCartas(string tipoCarta){

    for (int i=0;i<contador;i++){

        if(baseCartas[i]->GetTipoCarta() == tipoCarta){
            cout << i << " ";
            baseCartas[i]->generarCarta();
            cout << endl;
        }
    }

}

/*
El metodo desplegar nos permitira desplegar la informacion de una sola carta recibe como
parametro la posicion de la carta en el arreglo llamamos su metodo con -> pues lo declaramos
con new y con el polimorfismo llamara al metodo generar carta segun el tipo de objeto

*/
void Deck::desplegar(int opcion){

    baseCartas[opcion]->generarCarta();

}
/*
Metodo para contar el numero de tipo de cartas que existen en la base de cartas
teniendo tres variables enteras en cero con un for iremos recorriendo el arreglo
baseCarta obteniendo mediante un get el tipo de Carta y segun sea su tipo llenaremos
las variables acumulativas mostrando al final la cantidad de cartas de cada tipo

*/
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
    cout << "Cartas de magia: " << num_mag << endl;
    cout << "Cartas de monstruos: " << num_mon << endl;
    cout << "Cartas de trampa: " << num_tram << endl;
}



/*
Metodo para activar la invocacion usando polimorfismo dado el
numero de posicion de una carta en el arreglo llamaremos el
metodo invocar usando el metodo de la clase que le corresponda

*/
void Deck::ActivarInvocacion(int opcion){

    baseCartas[opcion]->Invocar();

}
/*
Metodo para dar solo los nombres de las cartas
Para mostrar en un menor espacio las cartas mostraremos unicamente el atributo
de nombre y tipo de carta mediante getters recorriendo el arreglo con un ciclo for
*/
void Deck ::ArrojaNombres(){

    for (int i=0;i<contador;i++){

        cout << i << " " ;
        cout<<baseCartas[i]->GetNombre()<<"  ("<<baseCartas[i]->GetTipoCarta()<<")"<<endl;

    }
    cout <<endl;

}


//Metodos de ataque, fusion y equipar magia entre monstruos dentro del arreglo mediante el dynamic cast

/*
Los objetos dentro del arreglo existen como cartas en si por lo que
llamar un metodo exclusivo de una clase es imposible es justamente lo
contrario a lo que demuestra el polimorfismo mediante dynamic_cast le
diremos al programa que tipo de objeto es para asi poder acceder a sus metodos
*/


/*
Ataquesencillo nos permite tomar dos objetos del arreglo y enfrentarlos para ello primero
debemos asegurarnos que ambos objetos sean de tipo monstruo mediante obtener el
GetTipoCarta y una vez cumplida esta condicion mediante dynamic_cast le
diremos al programa que son mosntruos para asi acceder a sus metodos exculusivos
*/
void Deck :: Ataquesencillo(int monstruo1,int monstruo2){


    if (baseCartas[monstruo1]->GetTipoCarta()=="Monstruo" && baseCartas[monstruo2]->GetTipoCarta()=="Monstruo"){

        Monstruo *m = dynamic_cast<Monstruo*>(baseCartas[monstruo1]);
        Monstruo *m2 = dynamic_cast<Monstruo*>(baseCartas[monstruo2]);

        m ->Atacar(*m2);

    }
    else{
        cout << "No es ataque valido solo se permite ataque entre monstruos"<<endl;
    }

}


/*
Fusionmons nos permite tomar dos objetos del arreglo y fusionarlos para ello primero
debemos asegurarnos que ambos objetos sean de tipo monstruo mediante obtener el
GetTipoCarta y una vez cumplida esta condicion mediante dynamic_cast le diremos
al programa que son monstruos para asi acceder a sus metodos exculusivos
*/

void Deck::fusionMons(int opcion1,int opcion2){

    if (baseCartas[opcion1]->GetTipoCarta()=="Monstruo" && baseCartas[opcion2]->GetTipoCarta()=="Monstruo"){

        Monstruo *m = dynamic_cast<Monstruo*>(baseCartas[opcion1]);
        Monstruo *m2 = dynamic_cast<Monstruo*>(baseCartas[opcion2]);

        m ->Fusion(*m2);

    }
    else{
        cout << "No es una fusion valida solo se permite fusionar monstruos"<<endl;
    }

}


/*
Equipar magia nos permite tomar un mosntruo y darle magia para ello tendremos
que tomar un objeto de tipo mosntru y uno de tipo magia mediante una condicion una
vez estando seguros del tipo de objetos que son con dynamic_cast los definiremos
como su tipo para poder usar sus metodos
*/

void Deck::EquiparMagia(int monstruo,int magia){


    if (baseCartas[monstruo]->GetTipoCarta()=="Monstruo" && baseCartas[magia]->GetTipoCarta()=="Magica"){



        Monstruo *m = dynamic_cast<Monstruo*>(baseCartas[monstruo]);
        Magia *mag = dynamic_cast<Magia*>(baseCartas[magia]);

        mag->DarPoder(*m);
    }
    else{
        cout << "Selecion de cartas incorrecta"<<endl;
        cout << endl;
    }

}

/*
Aplicartrampa nos permite tomar un monstruo y aplicarle una trampa para ello tendremos
que tomar un objeto de tipo mosntruo y uno de tipo trampa mediante una condicion una
vez estando seguros del tipo de objetos que son con dynamic_cast los definiremos
como su tipo para poder usar sus metodos
*/

void Deck::AplicarTrampa(int monstruo,int trampa){


    if (baseCartas[monstruo]->GetTipoCarta()=="Monstruo" && baseCartas[trampa]->GetTipoCarta()=="Trampa"){



        Monstruo *m = dynamic_cast<Monstruo*>(baseCartas[monstruo]);
        Trampa *tra = dynamic_cast<Trampa*>(baseCartas[trampa]);

        tra->ReducirPoder(*m);
    }
    else{
        cout << "Selecion de cartas incorrecta"<<endl;
        cout << endl;
    }

}
/*
Determinar el ganador de un duelo es lo mas importante cada monstruo cuenta con un
atributo bool denominado status que se inicializa por default en true lo que indica
que esta vivo al atacar puede llegar a perder la batalla y morir por lo que su status
cambiara a false mostrando el mensaje de haber ganado o haber fallado.
*/
void Deck::Ganador(int monstruo1){

    Monstruo *m = dynamic_cast<Monstruo*>(baseCartas[monstruo1]);

    if(m->GetStatus()==true){
        cout << "GANASTE!!!!!";
    }
    else{
        cout << "Perdiste sigue estudiando, cree en el corazon de las cartas"<<endl;
    }

}


#endif // DECK_H





