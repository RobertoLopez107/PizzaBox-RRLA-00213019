#include <iostream>
#include <string>

#define PASSWORD "include"

using namespace std;

//Definicion de tipo enum

enum mainDish {pizza, pasta, lasagna};
enum drink {beer, soda, tea};
enum starter {garlicBread, pizzaRolls, cheeseSticks};
enum paymenType {cash, card};

struct address{
    string settlement, municipality, department;
    int houseNumber;
};

struct mainInfo{
    string name;
    mainDish pDish;
    drink pDrink;
    starter pStarter;
    paymenType pay;
    int idOrder;
    float total;
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

//variables globales
bool isAdmin = false;
int idOrder = 1;

//prototipos
bool loginUser(void);

int main(void){
    int option;
    //Declaracion de variables y arreglos a usar
    delivery* dArray = NULL;
    houseOrder* hArray = NULL;
    if(loginUser() == false) //Verificacion para iniciar sesion
        return 0;
    //Logica principal para la ejecucion del programa
    do{
        printMenu(); cin >> option;
        cin.ignore();

        switch (option)
        {
        //Agregar ordenes a domicilio
        case 1:
            addOrder(dArray);
        break;
        //Agregar ordenes en restaurante
        case 2:
            addOrder(hArray);
        break;
        case 3:

        break;
        case 4:

        break;
        case 0:
        break;
        default:
        break;
        }

    }while(option != 0);


    return 0;
}

bool loginUser(void){
    char option;
    string enterPass = "";
    char option;
    cout << "Inicio de sesion" << endl;
    cout << "A - Administrador" << endl;
    cout << "E - Empleado" << endl;
    cout << "Su opcion:\t"; cin >> option;

    switch(option){
        case 'a':
        case 'A':
            cout << "Digite contraseña: "; cin >> enterPass;

            if(enterPass.compare(PASSWORD) == 0){
                isAdmin = true;
                return true;
            }
            else{
                cout << "Contraseña incorrecta" << endl;
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

void printMenu(void){
    cout<<"1. Agregar 1 pedido a domicilio."<<endl; //Guarda el nombre del cliente
    cout<<"2. Agregar 1 encargo en restaurante."<<endl;                         //Partes a evaluar 2-5
    cout<<"3. Ver pedidos a domicilio."<<endl;
    cout<<"4. Ver pedidos en el restaurante."<<endl;
    cout<<"5. Despachar ordenes a domicilio"<<endl;
    cout<<"6. Despachar ordenes en restaurante"<<endl;
    cout<<"7. Ver tiempo promedio de espera domicilio"<<endl;
    cout<<"8. Ver tiempo promedio de espera restaurante"<<endl;
//  cout<<"9.Cancelar orden (domicilio o restaurante, solo admin)"<<endl;
    cout<<"10. Calcular total de venta."<<endl;
    cout<<"11. Cambiar de usuario"<<endl;
    cout<<"0. Salir\t Opcion "<<endl;
}

void addOrder(delivery* array){
    int size = 0;
    cout << "Cantidad de pedidos a ingresar: "; cin >> size;
    cin.ignore();

    array = new delivery [size];

    for (int i = 0; i < size; i++){
        int aux = 0;
        cout << "Nombre:\t"; getline(cin, array[i].deliveryInfo.name);
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
        cout << "Telefono"; cin >> array[i].cellphone;
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

