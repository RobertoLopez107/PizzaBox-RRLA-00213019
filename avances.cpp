#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#define PASSWORD "include"

using namespace std;

enum mainDish {pizza, pasta, lasagna};
enum drink {beer, soda, tea};
enum starter {garlicBread, pizzaRolls, cheeseSticks};
enum paymenType {cash, card};

int adoN=1;

struct address{
    string settlement, municipality, department;
    int houseNumber;
};

struct mainInfo{
    string name;
    vector <mainDish> pDish;
    vector <drink> pDrink;
    vector <starter> pStarter;
    paymenType pay;
    int idOrder;
    float total;
};

struct cola{
    mainInfo info;
    cola* sig;
};

struct delivery{
    address deliveryAddress;
    int cellphone;
    mainInfo deliveryInfo;

};

struct houseOrder{
    int pTable;
    mainInfo houseInfo;
};

cola* queue(cola* c, mainInfo Info);

bool isAdmin = false;
int idOrder = 1;
bool loginUser(void);

void Menu(); //declarando prototipo de la funcion SIEMPRE ANTES DEL MAIN
bool loginUser(void);
void AdminMenu();
void EmployeeMenu();
void addOrder(delivery* array);
void addOrder(houseOrder* array);
void printOrder(delivery* array);

int main(void){
    int option;

    if(loginUser() == false) //Verificacion para iniciar sesion
        return 0;

        if(isAdmin == true){
            //Funcion administrador.
            AdminMenu();
        }else{
            //Funcion empleado
            EmployeeMenu();
        }


    return 0;
}

bool loginUser(void){
    char option;
    string enterPass = "";
    cout << "Inicio de sesion" << endl;
    cout << "A - Administrador" << endl;
    cout << "E - Empleado" << endl;
    cout << "Su opcion:\t"; cin >> option;

    switch(option){
        case 'a':
        case 'A':
            cout << "Digite contrase�a: "; cin >> enterPass;

            if(enterPass.compare(PASSWORD) == 0){
                isAdmin = true;
                return true;
            }
            else{
                cout << "Contrase�a incorrecta" << endl;
            }


        break;
        case 'e':
        case 'E':
            isAdmin = false;
            return true;
        break;
    }
    return false;
}


//funcion
void AdminMenu(){

    int option;

    //Declaracion de variables y arreglos a usar
    delivery* dArray = NULL;
    houseOrder* hArray = NULL;
    do{
    cout<<"1. Agregar 1 pedido a domicilio."<<endl; //Guarda el nombre del cliente
    cout<<"2. Agregar 1 encargo en restaurante."<<endl;                         //Partes a evaluar 2-5
    cout<<"3. Ver pedidos a domicilio."<<endl;
    cout<<"4. Ver pedidos en el restaurante."<<endl;
    cout<<"5. Despachar ordenes a domicilio"<<endl;
    cout<<"6. Despachar ordenes en restaurante"<<endl;
    cout<<"7. Ver tiempo promedio de espera domicilio"<<endl;
    cout<<"8. Ver tiempo promedio de espera restaurante"<<endl;
    cout<<"9.Cancelar orden (domicilio o restaurante, solo admin)"<<endl;
    cout<<"10. Calcular total de venta."<<endl;
    cout<<"11. Cambiar de usuario"<<endl;
    cout<<"0. Salir\n Opcion "<<endl;

    cin >> option;


        switch (option)
        {
        case 1:
            addOrder(dArray);
        break;
        case 2:
            addOrder(hArray);
        break;
        case 3:
            printOrder(dArray);
        break;
        case 4:
        break;
        case 5:
        break;
        case 6:
        break;
        case 7:
        break;
        case 8:
        break;
        case 9:
        break;
        case 10:
        break;
        case 11:
        break;
        default:
        break;

        cin.ignore();
    }

    }while(option != 0);

}

void EmployeeMenu(){

    int option;

        //Declaracion de variables y arreglos a usar
    delivery* dArray = NULL;
    houseOrder* hArray = NULL;

    do{

    cout<<"1. Agregar 1 pedido a domicilio."<<endl; //Guarda el nombre del cliente
    cout<<"2. Agregar 1 encargo en restaurante."<<endl;                         //Partes a evaluar 2-5
    cout<<"3. Ver pedidos a domicilio."<<endl;
    cout<<"4. Ver pedidos en el restaurante."<<endl;
    cout<<"5. Despachar ordenes a domicilio"<<endl;
    cout<<"6. Despachar ordenes en restaurante"<<endl;
    cout<<"7. Ver tiempo promedio de espera domicilio"<<endl;
    cout<<"8. Ver tiempo promedio de espera restaurante"<<endl;
    cout<<"9. Calcular total de venta."<<endl;
    cout<<"10. Cambiar de usuario"<<endl;
    cout<<"0. Salir\n Opcion "<<endl;

    cin >> option;



        switch (option)
        {
        case 1:
            addOrder(dArray);
        break;
        case 2:
            addOrder(hArray);
        break;
        case 3:
            printOrder(dArray);
        break;
        case 4:
        break;
        case 5:
        break;
        case 6:
        break;
        case 7:
        break;
        case 8:
        break;
        case 9:
        break;
        case 10:
        break;
        default:
        break;

        cin.ignore();
    }

    }while(option != 0);
}

void addOrder(delivery* array){
    int size = 0;
    cout << "Cantidad de pedidos a ingresar: "; cin >> size;
    cin.ignore();

    array = new delivery [size];

    for (int i = 0; i < size; i++){
        int aux = 0;
        cout << "Nombre:\t"; getline(cin, vector<mainInfo>deliveryInfo.name);
        cout << "Direccion\t" << endl;
        cout << "Colonia:\t"; getline(cin, array[i].deliveryAddress.settlement);
        cout << "Municipio:\t"; getline(cin, array[i].deliveryAddress.municipality);
        cout << "Departamento:\t"; getline(cin, array[i].deliveryAddress.department);
        cout << "No. casa:\t"; cin>>array[i].deliveryAddress.houseNumber;
        cin.ignore();

        cout << "Entrada" << endl;
        cout << "1. Pan con ajo" << endl;
        cout << "2. Pizza rolls" << endl;
        cout << "3. Palitos de queso" << endl;
        cout << "Su opcion:\t"; cin >> aux;
        cin.ignore();

        if(aux == 1)
            array[i].deliveryInfo.pStarter = garlicBread;
        else if(aux == 2)
            array[i].deliveryInfo.pStarter = pizzaRolls;
        else if(aux == 3)
            array[i].deliveryInfo.pStarter = cheeseSticks;

        cout << "Plato principal" << endl;
        cout << "1. Pizza" << endl;
        cout << "2. Pasta" << endl;
        cout << "3. Lasagna" << endl;
        cout << "Su opcion:\t"; cin >> aux;
        cin.ignore();

        if(aux == 1)
            array[i].deliveryInfo.pDish = pizza;
        else if(aux == 2)
            array[i].deliveryInfo.pDish = pasta;
        else
            array[i].deliveryInfo.pDish = lasagna;

        cout << "Bebida" << endl;
        cout << "1. Cerveza" << endl;
        cout << "2. Soda" << endl;
        cout << "3. Te helado" << endl;
        cout << "Su opcion:\t"; cin >> aux;
        cin.ignore();

        if(aux == 1)
            array[i].deliveryInfo.pDrink = beer;
        else if(aux == 2)
            array[i].deliveryInfo.pDrink = soda;
        else
            array[i].deliveryInfo.pDrink = tea;

        array[i].deliveryInfo.idOrder = idOrder++;

        cout << "Tipo de pago" << endl;
        cout << "1. Tarjeta" << endl;
        cout << "2. Efectivo" << endl;
        cout << "Su opcion:\t"; cin >> aux;
        cin.ignore();

        if(aux == 1)
            array[i].deliveryInfo.pay = card;
        else
            array[i].deliveryInfo.pay = cash;

        cout << "Monto: "; cin >> array[i].deliveryInfo.total;
        cin.ignore();
        cout << "Telefono: "; cin >> array[i].cellphone;
        cin.ignore();

    }
}

void addOrder(houseOrder* array){
    int size = 0;
    cout << "Cantidad de pedidos a ingresar: "; cin >> size;
    cin.ignore();

    array = new houseOrder [size];

    for (int i = 0; i < size; i++){
        int aux = 0;
        cout << "Nombre:\t"; getline(cin, array[i].houseInfo.name);


        cout << "Entrada" << endl;
        cout << "1. Pan con ajo" << endl;
        cout << "2. Pizza rolls" << endl;
        cout << "3. Palitos de queso" << endl;
        cout << "Su opcion:\t"; cin >> aux;
        cin.ignore();

        if(aux == 1)
            array[i].houseInfo.pStarter = garlicBread;
        else if(aux == 2)
            array[i].houseInfo.pStarter = pizzaRolls;
        else if(aux == 3)
            array[i].houseInfo.pStarter = cheeseSticks;

        cout << "Plato principal" << endl;
        cout << "1. Pizza" << endl;
        cout << "2. Pasta" << endl;
        cout << "3. Lasagna" << endl
;        cout << "Su opcion:\t"; cin >> aux;
        cin.ignore();

        if(aux == 1)
            array[i].houseInfo.pDish = pizza;
        else if(aux == 2)
            array[i].houseInfo.pDish = pasta;
        else
            array[i].houseInfo.pDish = lasagna;

        cout << "Bebida" << endl;
        cout << "1. Cerveza" << endl;
        cout << "2. Soda" << endl;
        cout << "3. Te helado" << endl;
        cout << "Su opcion:\t"; cin >> aux;
        cin.ignore();

        if(aux == 1)
            array[i].houseInfo.pDrink = beer;
        else if(aux == 2)
            array[i].houseInfo.pDrink = soda;
        else
            array[i].houseInfo.pDrink = tea;

        array[i].houseInfo.idOrder = idOrder++;

        cout << "Tipo de pago" << endl;
        cout << "1. Tarjeta" << endl;
        cout << "2. Efectivo" << endl;
        cout << "Su opcion:\t"; cin >> aux;
        cin.ignore();

        if(aux == 1)
            array[i].houseInfo.pay = card;
        else
            array[i].houseInfo.pay = cash;

        cout << "Monto: "; cin >> array[i].houseInfo.total;
        cin.ignore();

    }

}

void printOrder(delivery* array){

    for (int i = 0; i < adoN; i++){
        cout << "Nombre:\t"<<array[i].deliveryInfo.name;
        cout << "Direccion\t" << endl;
        cout << "Colonia:\t" <<array[i].deliveryAddress.settlement;
        cout << "Municipio:\t" <<array[i].deliveryAddress.municipality;
        cout << "Departamento:\t" << array[i].deliveryAddress.department;
        cout << "No. casa:\t"<< array[i].deliveryAddress.houseNumber;
    }

}

void printOrder(houseOrder* array){

    for (int i = 0; i < adoN; i++){
        cout << "Nombre:\t"<<array[i].houseInfo .name<<endl;
        cout << "Numero de personas por mesa: "<<endl;
        cout << "Ingrese el plato principal: 1.Pizza 2.Pasta 3.Lasagna"<<endl;
        cout << "Ingrese la bebida: 1.Cerveza 2.Soda 3.Te helado"<< endl;
        cout << "Ingrese la entrada: 1.Rollos de piza 2.Pan con ajo 3.Palitos de queso";
        cout << "Monto: ";
        cout << "Tipo de pago";
    }

}
