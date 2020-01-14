#include <iostream>
#include <fstream> //Se pone esta libreria para poder leer y editar ficheros.
#include <string>

using namespace std;
void Menu(); //declarando prototipo de la funcion SIEMPRE ANTES DEL MAIN
int RegistroCliente();

int main()
{
    //string line;
    int opcion;
    cout<<"Bienvenido a Pizza Box"<<endl;
    //El menu se ejecuta mientras la opcion sea distinta a cero
    do{
        Menu(); //Mandando a llamar la funcion
        cin>>opcion;
    switch(opcion){
        case 1: RegistroCliente();
     }
    }while(opcion !=0); //condicion linea 17, con el do.

    return 0;
}

//funcion
void Menu(){
    cout<<"1. Registrar cliente . . . "<<endl; //Guarda el nombre del cliente
    cout<<"2. "<<endl;
    cout<<"3. "<<endl;
    cout<<"4. "<<endl;
    cout<<"5. "<<endl;
    cout<<"0. Salir\t Opcion "<<endl;
}
int RegistroCliente(){ //funcion para registrar el cliente con su pedido

}