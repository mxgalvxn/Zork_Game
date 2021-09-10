#ifndef Comandos_h
#define Comandos_h

#include <iostream>
#include <cstdlib>
#include <time.h>
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define RED "\e[0;31m"
#define BWHT "\e[1;37m"
#define BYEL "\e[1;33m" //Menu

using namespace std;

#include "Item.h"
#include "Personaje.h"
#include "Cuarto.h"
#include "Enemigo.h"


class Comandos{
   public:
      Comandos();
      Comandos(string);
    
      void Pelea(Personaje* , Personaje* );
      void Inventario( Personaje* );
      void Curar(Personaje* );
      bool abrirPuerta(Personaje* , Cuarto* );
      void Menu( Personaje*, Cuarto*, Personaje*);

    private:
      string comando;
};

Comandos::Comandos(){
   comando="";
}

Comandos::Comandos(string com){
   comando=com;

}


void Comandos:: Pelea(Personaje* prota, Personaje* enemigo){
   cout<<RED"---------------Fight!------------------\n"<<endl;   
   while (enemigo->getHp() > 0){
      if (prota->getHp() <0){
         cout<< BYEL"\nTe petateaste bro"<< endl;
         cout << BYEL"\n------------GAME OVER-------------\n"<< endl;
         exit (-1);
      }
      else{
         cout<< ""<<endl;
         enemigo->mostrarVida();
         cout<< ""<<endl;
         int num= 1 + rand()%100+1;
         int n3= 1 + rand()%300+1;
         float respuesta;
         cout<< BWHT"\nOrales mijo, cuanto es: "<< num <<" + "<< n3 <<endl;
      
         cin>> respuesta;
         // Active esta opcion para que todas las respuestas sean correctas 
         // respuesta = num+n3;
         cout<< respuesta<<endl;
         if (respuesta == num + n3){
               prota->Atacar(enemigo);
         }
         else{
               enemigo->Atacar(prota);
               prota->mostrarVida();
            }
      }
   }
   cout << BYEL"\n--------------Winner--------------\n" << endl;
   enemigo->dropItem(prota);
}


void Comandos::Inventario( Personaje* prota){
   string opcion;
   cout<<CYN "\nQuieres ver tu inventario?\n"<<endl;
   cin>> opcion;
   if (opcion == "si"){
      cout<< ""<<endl;
      prota->mostrarInventario();
   }
   else{
      cout<< "okay continuemos..."<<endl;
   }
}

void Comandos:: Curar(Personaje* prota){
   prota->eliminarInventario("Gansito");
   prota->setHp(prota->getHp()+10);
   cout<< "Haz recuperado 10 pts de vida"<<endl;
   prota->mostrarVida();
   cout<< ""<<endl;
}

bool Comandos::abrirPuerta(Personaje* prota, Cuarto* cuarto1 ){
   int posicion = -1;
   int cant = prota->getCantItems();
   for ( int l = 0; l< cant ; l++){
      string objeto = prota->getItem(l);
      if (objeto == "Llave"){
         posicion = l;
      } 
   }     
   if (posicion != -1){
      cout<<CYN"\nPasaste de nivel "<<endl;
      prota->eliminarInventario("Llave");
      prota->setPosicion(cuarto1);
      cout << cuarto1<< endl;  
      return true;
   }
   else{
         cout<< CYN"\nNo puedes abrir esa puerta \n Necesitas una llave"<<endl;
         return false;
   }
   
         
}

void Comandos::Menu(Personaje* prota, Cuarto* c1, Personaje* malo ){
   Item* Llave = new Item("Llave");
   Item* gansito = new Item("Gansito");
   char  accion;
   int pelea =0;
   bool puerta; 

   while(accion != 'd' ){
      if (malo->getHp() > 0){
      cout<<CYN"\nHa aparecido "<< malo->getNombre()<<"\n"<<endl;
      }

      cout<< BYEL"\nQue quieres hacer?"<<endl;
      cout<< BYEL"a: Abrir la puerta"<<endl;
      cout<< BYEL"b Pelear "<<endl;
      cout<< BYEL"c: Ver tu inventario "<<endl;
      cin>> accion;
      switch (accion){
         case 'a':
            puerta = abrirPuerta(prota, c1);
            if (puerta == true){
            accion = 'd';
            }
            break;
         case 'b':
            if (pelea == 0){
               Pelea(prota, malo);
               prota->agregarItem(Llave);
               pelea++;
               if ( prota->getHp() <100){
                  cout <<GRN"\nMishi:Hmm.. espera\n Veo que tienes un balazo, \npero no te preocupes esto te ayudara\n"<<endl;
                  prota->agregarItem(gansito);
                  gansito->mostrarDesc();
                  cout << CYN"\nQuires utilizar el gansito?"<<endl;
                  string opcion1;
                  cin>> opcion1;
                  if (opcion1 == "si"){
                        Curar(prota);
                  }
                  else{
                     cout<<CYN"continuemos..."<<endl;
                  }
               }         
            }
            else{
                     cout<<RED"\nBut nobody came..."<<endl;
               }
         break;
         case 'c': 
            Inventario(prota);
            break;

         default:
         cout<< "Ingresa una opcion valida porfis" <<endl;
         break;
      }

   }    
}

#endif