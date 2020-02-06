#include <iostream>
#include <string>
#include <vector>
#define PASSWORD "include"

using namespace std;

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
    vector <mainDish> pDish;
    vector <drink> pDrink;
    vector <starter> pStarter;
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


bool isAdmin = false;
int idOrder = 1;
bool loginUser(void);

void Menu(); //declarando prototipo de la funcion SIEMPRE ANTES DEL MAIN
bool loginUser(void);
void AdminMenu();
void EmployeeMenu();
mainInfo solicitarOrden();
void printMenu(mainInfo p, address a);
void mostrarLista();
void agregarOrden();

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

void AdminMenu(){

    int option;
    do{
    cout<<"1. Agregar 1 pedido a domicilio."<<endl;
    cout<<"2. Agregar 1 encargo en restaurante."<<endl;
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
    cin >> option; cin.ignore();

        switch (option)
        {
        case 1:
            solicitarOrden();
        break;
        case 2:
        break;
        case 3:
            mostrarLista();
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
            loginUser();
        break;
        default:
        break;
        cin.ignore();
    }

    }while(option != 0);

}

void EmployeeMenu(){

    int option;

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
    cin >> option;  cin.ignore();



        switch (option)
        {
        case 1:
            solicitarOrden();
        break;
        case 2:
        break;
        case 3:
            mostrarLista();
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
            loginUser();
        break;
        default:
        break;

        cin.ignore();
    }

    }while(option != 0);
}

vector <mainInfo> lista;

void agregarOrden(){
    mainInfo p = solicitarOrden();
        bool continuar = true;
    do{
        lista.insert(lista.begin(), p);
        continuar = false;
    }while(continuar);

}

mainInfo solicitarOrden(){
    mainInfo p;
    address a;
    int size = 0;
    cout << "Cantidad de pedidos a ingresar: ";
    cin >> size;
    cin.ignore();

    for (int i = 0; i < size; i++){
        int aux = 0;
        cout << "Nombre:\t";
        cin >> p.name;
        cout << "Direccion->\t";
        cout << "Colonia:\t";
        cin >> a.settlement;
        cout << "Municipio:\t";
        cin >> a.municipality;
        cout << "Departamento:\t";
        cin >> a.department;
        cout << "No. casa:\t";
        cin >> a.houseNumber;
        cin.ignore();

        cout << "Entrada: " << endl;
        cout << "1. Pan con ajo" << endl;
        cout << "2. Pizza rolls" << endl;
        cout << "3. Palitos de queso" << endl;
        cout << "Su opcion:\t";
        cin >> aux;
        cin.ignore();

        int contBread = 0;
        int contRolls = 0;
        int contSticks = 0;

        switch(aux){
            case 1:
                garlicBread;
                contBread ++;
            break;
            case 2:
                pizzaRolls;
                contRolls ++;
            break;
            case 3:
                cheeseSticks;
                contSticks++;
            break;
        }

        cout << "Plato principal: " << endl;
        cout << "1. Pizza " << endl;
        cout << "2. Pasta " << endl;
        cout << "3. Lasagna " << endl;
        cin >> aux;
        cin.ignore();

                switch(aux){
            case 1:
                pizza;
            break;
            case 2:
                pasta;
            break;
            case 3:
                lasagna;
            break;
        }

        cout << "Bebidas: " << endl;
        cout << "1. Cerveza " << endl;
        cout << "2. Soda " << endl;
        cout << "3. Te " << endl;
        cin >> aux;
        cin.ignore();

                switch(aux){
            case 1:
                beer;
            break;
            case 2:
                soda;
            break;
            case 3:
                tea;
            break;
        }

        cout << "Tipo de pago" << endl;
        cout << "1. Efectivo" << endl;
        cout << "2. Tarjeta";
        cin >> aux;
        cin.ignore();

        switch(aux){
            case 1:
                cash;
            break;
            case 2:
                card;
            break;
        }

    }
    return p;

}

void printMenu(mainInfo p, address a){

    cout << "Nombre: " << p.name << endl;
    cout << "Direccion: " << endl;
    cout << "Colonia: " << a.settlement << endl;
    cout << "Municipio: " << a.municipality << endl;
    cout << "Departamento: " << a.department << endl;
    cout << endl;
}

void mostrarLista() {
    for (int i = 0; i < lista.size(); i++)
        printMenu(lista[i]);
}

