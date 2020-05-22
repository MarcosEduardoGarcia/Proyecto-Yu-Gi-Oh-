#include <iostream>

#include "Monstruo.h"
#include "Magia.h"
#include "Trampa.h"
//Marcos Eduardo Garcia Ortiz A01276213

using namespace std;

int main(){

    int opcion;

    Monstruo obelisk("Obelisk","Divino","2wjfiorh","El desscenso de esta bestia...","Monstruo","[Bestia Divina]","******",2300,2500,true);
    Monstruo Slifer("Slifer","Divino","2nionfo3","El desscenso de esta bestia...","Monstruo","Bestia/divina","******",3000,2500,false);
    Magia espejo("Espejo","mdpwofme","aumenta vida","Magia",500);
    Trampa demon("Demon","mrpbmf","Carta demon","Magia",-100);


    obelisk.getCarta();
    cout << endl;
    Slifer.getCarta();
    cout << endl;
    espejo.getCarta();
    demon.getCarta();

    cout << "\t Pruebas de mecanica de combates 1.1" <<endl;

    cout << endl;
    cout << "Desea iniciar combate? obelisk vs slifer 1= si 0=no"<<endl;
    cin >> opcion;

    if (opcion==1) {

       obelisk.Atacar(Slifer);
       cout << endl;

    }

    cout << "Desea intentar fusion entre los mosntruos 1= si 0=no?"<<endl;
    cin >> opcion;
    if (opcion==1){

        obelisk.Fusion(Slifer);
    }


    cout << "Desea dar obelisk carta de magia 1= si 0=no?"<<endl;
    cin >> opcion;
    if (opcion == 1){

        espejo.DarPoder(obelisk);
        cout <<endl;

    }

    cout << "Desea afectar a Slifer con una carta trampa?"<<endl;
    cin >> opcion;
    if (opcion == 1){

        demon.ReducirPoder(Slifer);

    }


    cout << "Desea iniciar combate de nuevo? obelisk vs slifer "<<endl;
    cin >> opcion;

    if (opcion==1) {

       obelisk.Atacar(Slifer);
       cout << endl;

    }


    return 0;
}
