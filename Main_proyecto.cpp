#include <iostream>
#include <cstdlib>
#include <time.h>
#define GRN "\e[0;32m" //Color del dialogo del gato
#define CYN "\e[0;36m" //Color de los mensajes
#define RED "\e[0;31m" //Color de los enemigos
#define UWHT "\e[4;37m"
using namespace std;

#include "Item.h"
#include "Personaje.h"
#include "Cuarto.h"
#include "Enemigo.h"
#include "Comandos.h"


int main(){
   system("cls");
    //Bienvenida
    cout << UWHT"Bienvenido a sobreviviendo en el tercer mundo"<< endl;
    cout << UWHT"Ingrese tu nombre carnal: ";
    string nombre;
    cin>>nombre;
    
   
    //Establecimiento de la descripción de los cuartos
    string desc = "Te encuentras en la farmacia similares";
    string desc2 = "Te encuentras en Tepito!";
    string desc3 = "Te encuentras en Medellin!";
    string desc4 = "Te encuentras en Obregon!";
    string desc5 = "Te encuentras en Cd Juarez!";
    string desc6 = "LLegaste a la salida";

    //Establecimiento de los cuartos
    Cuarto* c = new Cuarto(desc, true);
    Cuarto* c1 = new Cuarto(desc2, true);
    Cuarto* c2 = new Cuarto(desc3, true);
    Cuarto* c3 = new Cuarto(desc4, true);  
    Cuarto* c4 = new Cuarto(desc5, true);
    Cuarto* c5 = new Cuarto(desc6, true);

    Comandos control("");
    
    //Personaje principal
    Personaje* protagonista = new Personaje(nombre, c, "Prota", 100);
   
    //Items disponibles
    Item* it = new Item("Gansito");
    Item* it2 = new Item("Gansito");
    Item* it3 = new Item("Tapipeso");
    Item* it4 = new Item("Llave");

    //Establecimiento de los enemigos
    Personaje* malo1 = new Enemigo("Cholo", c, "Enemigo", 20, it3, protagonista);
    Personaje* malo2 = new Enemigo("Empleado de movistar", c1, "Enemigo", 50, it2, protagonista);
    Personaje* malo3 = new Enemigo("2 Cholos", c2, "Enemigo", 40, it3, protagonista);
    Personaje* malo4 = new Enemigo("Maestra de Matematicas", c3, "Enemigo", 70, it2, protagonista);
    Personaje* jefe = new Enemigo("Chabelo", c3, "Enemigo", 100, it4, protagonista);

    cout<< "\n\n"<<endl;
   

//    Empieza el juego

    cout <<GRN<< nombre<< "!  ...  " << nombre << "!  ...  "<< endl;
    cout <<CYN "\nEscuchas a alguien llamandote, te duele la cabeza, no recuerdas que paso ayer" <<endl;
    cout <<CYN" abres los ojos con dificultad para descubrir que estas en un lugar que no conoces," <<endl;
    cout <<CYN" cuando consigues sentarte te das cuenta que hay un Mishi enfrente de ti, te esta viendo fijamente\n"<< endl;

    cout <<GRN"\nMishi: Hola "<< nombre << " tardaste mucho en despertar, ya hasta me dio hambre"<<endl;
    cout <<GRN"Bueno ahora que estas consciente te enseñare lo basico\n"<< endl;


    protagonista->setPosicion(c);
    cout << c << endl; 
  
    
    if(protagonista->getPosicion() == c){
            
        cout<<RED"\nHa aparecido "<< malo1->getNombre()<<"\n"<<endl;
            
        cout <<GRN"Mishi : Ese es el primer enemigo al que te enfrentaras"<<endl;
        cout<< GRN"Para ganar tienes que obtener todas las respuestas correctas\n"<<endl;

        control.Pelea(protagonista, malo1); 
    }
        
    cout << RED"----------------------------------------------------------------------" << endl;
    cout <<GRN "Mishi: excelente ganaste tu primera pelea! Ahora revisa tu inventario para ver lo que obtuviste\n"<<endl;
    
    //Contro de excepcion al abrir el inventario
    try{
        control.Inventario(protagonista);
    }
    catch(const char* msg){
        cerr << msg << endl;
    }
    
    //Si el personaje recibe daño se le da una posción
    if ( protagonista->getHp() <100){
        string opcion1;
        cout <<GRN"\nMishi:Hmm.. espera\n Veo que tienes un balazo, \npero no te preocupes esto te ayudara\n"<<endl;
        protagonista->agregarItem(it);
        it->mostrarDesc();
        cout << CYN"\nQuires utilizar el gansito?"<<endl;
        cin>> opcion1;
        if (opcion1 == "si"){
            control.Curar(protagonista);
        }
        else{
           cout<<CYN"continuemos..."<<endl;
        }
        
   }
    else{
      cout<< ""<<endl;
      cout <<GRN"\nMishi: Mas adelante te enfrentaras a otros enemigos mucho mas fuertes "<<endl;
      cout << GRN"Ahora hay que salir de aqui\n"<<endl;}
      cout<<CYN;

   protagonista->agregarItem(it4);

    //Contro de excepcion al abrir una puerta
    try{
        control.abrirPuerta(protagonista, c1);
    }
    catch(const char* msg){
        cerr << msg << endl;
    }
    
   
   cout <<GRN"\nMishi: Bueno creo que ya lo tienes, mi trabajo aqui ha terminado y como tengo hambre me voy \n"<<endl;
      
    // Nivel 1
    control.Menu( protagonista, c2, malo2);
    cout<<"Nuevo nivel"<<endl;

    // Nivel 2
    control.Menu( protagonista, c3, malo3);
    cout<<"Nuevo nivel"<<endl;
    
    // Nivel 3
    control.Menu( protagonista, c4, malo4);
    cout<<"Nuevo nivel"<<endl;
    
    // Nivel 4
    control.Menu(protagonista, c5, jefe);
    
    
    cout<< "\n--------------------------------"<<endl;
    cout<<"Felicidades huiste de LATAM"<<endl;
    cout<< "\n--------------------------------"<<endl;



}