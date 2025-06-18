#include <iostream>     // Para cout, endl
#include <string>       // Para string
#include <string>
#include "funciones.h"
#include "tiradaDado12.h"



using namespace std;



void jugarPartida(string nombreJugador1, string nombreJugador2, int iniciador) {
    int stockDados1[12]{}, stockDados2[12]{};
    int dados1 = 6, dados2 = 6;
    int puntaje1 = 0, puntaje2 = 0;

    cargarVector(stockDados1, dados1);
    cargarVector(stockDados2, dados2);

    int turnoActual = iniciador;

    //control de rondas
  for (int ronda = 1; ronda <= 3; ronda++) {
    cout << "\n RONDA " << ronda << "\n";
    //control de turnos
    int puntajeTiradaJ1 = 0;
    int puntajeTiradaJ2 = 0;
    int dado, cantDados;

    for (int i = 0; i < 2; i++) {
            cantDados = 0;
        //Tirada Jugador 1
        if (turnoActual == 1) {
            cout << "\nTurno de " << nombreJugador1 << endl;

            int numeroTarget = tiradaDado12();
            cout << "Numero objetivo: " << numeroTarget << endl;

            cargarVector(stockDados1, dados1);
            cout << "Dados disponibles:\n";
            for (int j = 0; j < dados1; j++) {
                cout << "[" << j << "] = " << stockDados1[j] <<"\t";

            }

            // seleccionarDados();
             while(numeroTarget=!puntajeTiradaJ1 || dado==0)
            {
                
                cout<<"Ingrese el numeros del dado que desea elegir (1 - "<<dados1<<"), recuerde que deberan sumar el puntaje obtenido en el Numero objetivo"<<endl;
                cout<<"De lo contrario, es decir, no poder llegar al Numero objetivo de ninguna manera, se considerara una tirada fallida y debera ingresar 0"<<endl;
                do{
                cin>>dado;
                if(dado > dados1)
                {
                    cout<<"Numero no valido, por favor ingrese nuevamente. "<<endl;
                }
                }while (dado > dados1);
                cantDados++;
                puntajeTiradaJ1 = stockDados1[dado];

            }
            if(dado==0)
            {
                cout<<"Obtuviste una tirada fallida, por lo que recibis un dado de tu rival. "<<endl;
                system("pause");
                dados1 = dados1+1;
                dados2 = dados2-1;
            }
            else{
            dados1 -=cantDados;
            dados2 +=cantDados;
            puntaje1+=puntajeTiradaJ1;
            cout << endl;
            }
            
            turnoActual = 2;
            system("pause");
            
        }
        //Tirada Jugador 2
         else {
            cout << "\nTurno de " << nombreJugador2 << endl;

            int numeroTarget = tiradaDado12();
            cout << "Numero objetivo: " << numeroTarget << endl;

            // Cargar y mostrar dados del jugador 2
            cargarVector(stockDados2, dados2);
            cout << "Dados disponibles:\n";
            for (int j = 0; j < dados2; j++) {
                cout << "[" << j << "] = " << stockDados2[j] <<"\t";
            }
            cout << endl;

            // seleccionarDados();
            while(numeroTarget=!puntajeTiradaJ2 || dado==0)
            {
                
                cout<<"Ingrese el numeros del dado que desea elegir (1 - "<<dados2<<"), recuerde que deberan sumar el puntaje obtenido en el Numero objetivo"<<endl;
                cout<<"De lo contrario, es decir, no poder llegar al Numero objetivo de ninguna manera, se considerara una tirada fallida y debera ingresar 0"<<endl;
                do{
                cin>>dado;
                if(dado > dados2)
                {
                    cout<<"Numero no valido, por favor ingrese nuevamente. "<<endl;
                }
                }while (dado > dados2);
                cantDados++;
                puntajeTiradaJ2 = stockDados2[dado];

            }
            if(dado==0)
            {
                cout<<"Obtuviste una tirada fallida, por lo que recibis un dado de tu rival. "<<endl;
                system("pause");
                dados2 = dados2+1;
                dados1 = dados1-1;
            }
            else{
            dados2 -=cantDados;
            dados1 +=cantDados;
            puntaje2+=puntajeTiradaJ2;
            cout << endl;
            }
            
            turnoActual = 1;
            system("pause");
        }
    }
}
    // Puntaje
    cout << "\nPuntajes:\n";
    cout << nombreJugador1 << ": " << puntaje1 << " puntos\n";
    cout << nombreJugador2 << ": " << puntaje2 << " puntos\n";
     if (puntaje1 > puntaje2)
        cout << "Ganador: " << nombreJugador1 << endl;
    else if (puntaje2 > puntaje1)
        cout << "Ganador: " << nombreJugador2 << endl;
    else
        cout << "Empate" << endl;



}
