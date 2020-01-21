#include <iostream>
#include <fstream> //Se pone esta libreria para poder leer y editar ficheros.
#include <string>

using namespace std;
void Menu(); //declarando prototipo de la funcion SIEMPRE ANTES DEL MAIN
void atHome();
void atRestaurant();
void orderatHome();
void orderatRes();

string keyword = "include";
string password;
int user;

struct domicilio{
string name;
string direction;
int number;
int maindish;
int starter;
int drink;
int amount;
string paymenttype;
};

struct restaurant{
string name2;
int peoplenum;
int maindish2;
int starter2;
int drink2;
int amount2;
int paymenttype2;
};

int main(){

    cout<<"Elija que tipo de usuario es: 1. Administrador 2. Empleado"<<endl;
    cin>>user;

    cout << "Ingrese la contraseña: \t";
    cin >> password;

    if(keyword != password){
    cout<<"Error contraseña incorrecta. ";
    return 0;
}

    int opcion;
    cout<<"Bienvenido a Pizza Box"<<endl;
    //El menu se ejecuta mientras la opcion sea distinta a cero
    do{
        Menu(); //Mandando a llamar la funcion
        cin>>opcion;
    switch(opcion){
        case 1: atHome();
        break;
        case 2: atRestaurant();
        break;
        case 3: orderatHome();
        break;
        case 4: orderatRes();
        break;
     }
    }while(opcion !=0); //condicion linea 17, con el do.

    return 0;
}

//funcion
void Menu(){
    cout<<"1. Agregar 1 pedido a domicilio."<<endl; //Guarda el nombre del cliente
    cout<<"2. Agregar 1 encargo en restaurante."<<endl;                         //Partes a evaluar 2-5
    cout<<"3. Ver pedidos a domicilio."<<endl;
    cout<<"4. Ver encargos en el restaurante."<<endl;
    cout<<"5. Ver total de venta."<<endl;
    cout<<"0. Salir\t Opcion "<<endl;
}
void atHome(){ //funcion para registrar el cliente con su pedido
    domicilio dom;

    cin.ignore();

    cout<< "Ingrese su nombre: "<<endl;
    getline(cin, dom.name);

    cout<< "Ingrese su direccion: "<<endl;
    getline(cin, dom.direction);

    cout<< "Ingrese su numero de telefono"<<endl;
    cin>> dom.number;

    cout<< "Ingrese su plato principal: 1.Pizza 2.Ensalada 3. Pasta"<<endl;
    cin>> dom.maindish;

    cout<< "Ingrese su entrada: 1.Palitroques 2.Nuditos "<<endl;
    cin>> dom.starter;

    cout<< "Ingrese el tipo de bebida: 1.Gaseiosa 2.Te"<<endl;
    cin>> dom.drink;

    cout<< "Su total es:"<<endl;
    cin>> dom.amount;

    cout<< "Tipo de pago: 1. Efectivo o Tarjeta."<<endl;
    cin>> dom.paymenttype;
}

void atRestaurant(){
    restaurant restau;

    cin.ignore();

    cout<< "Ingrese su nombre: "<<endl;
    getline(cin, restau.name2);

    cout<< "Ingrese las personas que estaran en mesa: "<<endl;
    cin>> restau.peoplenum;

    cout<< "Ingrese su plato principal: 1.Pizza 2.Ensalada 3. Pasta"<<endl;
    cin>> restau.maindish2;

    cout<< "Ingrese su entrada: 1.Palitroques 2.Nuditos "<<endl;
    cin>> restau.starter2;

    cout<< "Ingrese el tipo de bebida: 1.Gaseiosa 2.Te"<<endl;
    cin>> restau.drink2;

    cout<< "Monto:"<<endl;
    cin>> restau.amount2;

    cout<< "Tipo de pago: 1. Efectivo o Tarjeta."<<endl;
    cin>> restau.paymenttype2;

}

void orderatHome(){
    domicilio dom;
    cout<<"Nombre: "<<dom.name<<endl;
    cout<<"Direccion: "<<dom.direction<<endl;
    cout<<"Numero de telefono: "<<dom.number<<endl;
    cout<<"Plato principal"<<dom.maindish<<endl;
    cout<<"Entrada: "<<dom.starter<<endl;
    cout<<"Bebida: "<<dom.drink<<endl;
    cout<<"Monto: "<<dom.amount<<endl;
    cout<<"Tipo de pago: "<<dom.paymenttype;
}

void orderatRes(){
    restaurant restau;
    cout<<"Nombre: "<<restau.name2<<endl;
    cout<<"Cantidad de personas en mesa: "<<restau.peoplenum<<endl;
    cout<<"Plato principal: "<<restau.maindish2<<endl;
    cout<<"Entrada"<<restau.starter2<<endl;
    cout<<"Bebida: "<<restau.drink2<<endl;
    cout<<"Monto: "<<restau.amount2<<endl;
    cout<<"Tipo de pago: "<<restau.paymenttype2;
}
