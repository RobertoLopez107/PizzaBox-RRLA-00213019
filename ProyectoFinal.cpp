#include <iostream>
#include <ostream>
#include <string>  //Libreria para cadenas de textos
#include <vector> //Libreria para usar vectores
#define PASSWORD "include" //Asignacion de contraseña

using namespace std;

// Eunums
enum mainDish {pizza, pasta, lasagna};
enum drink {beer, soda, tea};
enum starter {garlicBread, pizzaRolls, cheeseSticks};
enum paymenType {cash, card};

//Estructuras

struct address{
    string settlement, municipality, department;
    int houseNumber;
};

struct mainInfo{
    string name;
    vector <mainDish> pDish;
    vector <drink> pDrink;
    vector <starter> pStarter;
    vector <paymenType> pay;
    int idOrder;
    float total;
    address Address;
    int numberPe;
    int number;
    string aux;
};

struct delivery{
    address deliveryAddress;
    int cellphone;
    mainInfo deliveryInfo;
};

struct RestaurantOrder{
    int pTable;
    mainInfo restaurantInfo;
};

//Declaracion de vectores

vector <mainInfo> lista;
vector <delivery> listaDelivery;
vector <RestaurantOrder> ListaRest;

bool isAdmin = false; //Para poder iniciar sesion
double timepromD=0,timepromR=0;  //Para calcular tiempo

//Prototipos

void Menu(); //declarando prototipo de la funcion SIEMPRE ANTES DEL MAIN
bool loginUser(void); //Funcion para iniciar sesion como admin o empleado
void AdminMenu(); //Menu para admin
void EmployeeMenu(); //Menu para empleado
delivery AddOrderDelivery(); //Funcion para agregar orden a domicilio
void printDeliveryOrders(delivery d); //Funcion para imprimir ordenes a domicilio
void ShowListDeli(); //Manda a llamar la funcion printDeliveryOrders
void ShowListRest(); //Manda a llamar la funcion printRestaurantOrders
RestaurantOrder AddOrderAtRes();  //Funcion para agregar orden en restaurante
void printRestaurantOrders(RestaurantOrder r); //Funcion para imprimir ordenes en restaurante
void TimePromD(double); //Funcion para calcular promedio de tiempo a domicilio
void TimePromR(double); //Funcion para calcular promedio de tiempo en restaurante
string printStarter(starter s);  //Convertores de los enums a string
string printMainDish (mainDish m);
string printDrink (drink d);
string printPayment (paymenType p);


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
  
//Funcion para iniciar sesion como admin o empleado

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

//Funcion para el menu administrador

void AdminMenu(){

    double time=-1;

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
            listaDelivery.insert(listaDelivery.end(),AddOrderDelivery());
        break;
        case 2:
            ListaRest.insert(ListaRest.end(),AddOrderAtRes());
        break;
        case 3:
            ShowListDeli();
        break;
        case 4:
            ShowListRest();
        break;
        case 5:
        break;
        case 6:
        break;
        case 7:
            TimePromD(time);
        break;
        case 8:
            TimePromR(time);
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

//Menu para empleado

void EmployeeMenu(){

    double time=-1;
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
            //Inserta datos en lista a domicilio
            listaDelivery.insert(listaDelivery.end(),AddOrderDelivery()); 
        break;
        case 2:
            //Inserta datos en lista de restaurante
            ListaRest.insert(ListaRest.end(),AddOrderAtRes());
        break;
        case 3:
            //Funcion para demostrar pedido a domicilio
            ShowListDeli();
        break;
        case 4:
            //Funcion para demostrar pedido en restaurante
            ShowListRest();
        break;
        case 5:
        break;
        case 6:
        break;
        case 7:
            //Funcion para demostrar tiempo promedio
            TimePromD(time);
        break;
        case 8:
            //Funcion para demostrar tiempo promedio
            TimePromR(time);
        break;
        case 9:
        break;
        case 10:
            //Funcion para cambiar de usuario
            loginUser();
        break;
        default:
        break;

        cin.ignore();
    }

    }while(option != 0);
}

// Funcion que hace que funcione los insert en AddOrderAtRes
RestaurantOrder AddOrdenRes(){
    RestaurantOrder r = AddOrderAtRes();
        bool continuar = true;
    do{
        ListaRest.insert(ListaRest.begin(), r);
        continuar = false;
    }while(continuar);

}

//Funcion para agregar el pedido en restaurante

RestaurantOrder AddOrderAtRes(){
    RestaurantOrder r;

    int size = 0;
    cout << "Cantidad de pedidos a ingresar: ";
    cin >> size;
    cin.ignore();

    for (int i = 0; i < size; i++){
        double totalprice = 0, time = 0;
        int aux = 0;
        cout << "Nombre:\t";
        getline(cin,r.restaurantInfo.name);
        cout << "Ingrese el numero de personas:" << endl;
        cin >> r.restaurantInfo.numberPe;
        cout << "Entrada: " << endl;
        cout << "1. Pan con ajo" << endl;
        cout << "2. Pizza rolls" << endl;
        cout << "3. Palitos de queso" << endl;
        cout << "Su opcion:\t";
        cin >> aux;
        cin.ignore();

        if(aux==1){   //Se acumulan los tiempos
            totalprice=totalprice+2;
            time = time + 2;
        }else if(aux==2){
            totalprice=totalprice+2.50;
            time = time + 3;
        }else{
            totalprice=totalprice+3.25;
            time = time + 3;
        }

        switch(aux){
            case 1: r.restaurantInfo.pStarter.insert(r.restaurantInfo.pStarter.end(), garlicBread); break;
            case 2: r.restaurantInfo.pStarter.insert(r.restaurantInfo.pStarter.end(), pizzaRolls); break;
            case 3: r.restaurantInfo.pStarter.insert(r.restaurantInfo.pStarter.end(), cheeseSticks); break;
        }

        cout << "Plato principal: " << endl;
        cout << "1. Pizza " << endl;
        cout << "2. Pasta " << endl;
        cout << "3. Lasagna " << endl;
        cin >> aux;
        cin.ignore();

        if(aux==1){
            totalprice=totalprice+7.50;
            time = time + 4;
        }else if(aux==2){
            totalprice=totalprice+6.25;
            time = time + 3;
        }else{
            totalprice=totalprice+9.25;
            time = time + 5;
        }

                switch(aux){
                case 1: r.restaurantInfo.pDish.insert(r.restaurantInfo.pDish.end(), pizza); break;
                case 2: r.restaurantInfo.pDish.insert(r.restaurantInfo.pDish.end(), pasta); break;
                case 3: r.restaurantInfo.pDish.insert(r.restaurantInfo.pDish.end(), lasagna); break;
        }

        cout << "Bebidas: " << endl;
        cout << "1. Cerveza " << endl;
        cout << "2. Soda " << endl;
        cout << "3. Te " << endl;
        cin >> aux;
        cin.ignore();

         if(aux==1){
            totalprice=totalprice+2;
            time = time + 2;
        }else if(aux==2){
            totalprice=totalprice+2.50;
            time = time + 2;
        }else{
            totalprice=totalprice+2;
            time = time + 2;
        }


                switch(aux){
                case 1: r.restaurantInfo.pDrink.insert(r.restaurantInfo.pDrink.end(), beer); break;
                case 2: r.restaurantInfo.pDrink.insert(r.restaurantInfo.pDrink.end(), soda); break;
                case 3: r.restaurantInfo.pDrink.insert(r.restaurantInfo.pDrink.end(), tea); break;
            }

        TimePromR(time);  //Manda a llamar la funcion de tiempo para sacar promedio

        cout<<endl<<"Cancelar por orden: $"<<totalprice<<endl<<endl;

        cout << "Tipo de pago" << endl;
        cout << "1. Efectivo" << endl;
        cout << "2. Tarjeta";
        cin >> aux;

         switch(aux){
                case 1: r.restaurantInfo.pay.insert(r.restaurantInfo.pay.end(), cash); break;
                case 2: r.restaurantInfo.pay.insert(r.restaurantInfo.pay.end(), card); break;
            }

        cin.ignore();
    }
    return r;  //Retorna los datos ingresados

}

//Funcion para agregar el pedido a domicilio

delivery agregarOrden(){
    delivery d = AddOrderDelivery();
        bool continuar = true;
    do{
        listaDelivery.insert(listaDelivery.begin(), d);
        continuar = false;
    }while(continuar);

}

//Funcion donde se ingresan los datos a domicilio

delivery AddOrderDelivery(){
    delivery d;
    int size = 0;
    cout << "Cantidad de pedidos a ingresar: ";
    cin >> size;
    cin.ignore();

    for (int i = 0; i < size; i++){
        double totalprice = 0, time = 0;
        int aux = 0;
        cout << "Nombre:\t";
        getline(cin,d.deliveryInfo.name);
        cout << "Direccion->\t";
        cout << "Colonia:\t";
        getline(cin,d.deliveryInfo.Address.settlement);
        cout << "Municipio:\t";
        getline(cin,d.deliveryInfo.Address.municipality);
        cout << "Departamento:\t";
        getline(cin,d.deliveryInfo.Address.department);
        cout << "No. casa:\t";
        cin >> d.deliveryInfo.Address.houseNumber;
        cout << "Ingrese su numero de telefono" << endl;
        cin >> d.deliveryInfo.number;
        cin.ignore();

        cout << "Entrada: " << endl;
        cout << "1. Pan con ajo" << endl;
        cout << "2. Pizza rolls" << endl;
        cout << "3. Palitos de queso" << endl;
        cout << "Su opcion:\t";
        cin >> aux;
        cin.ignore();

        if(aux==1){
            totalprice=totalprice+2;
            time = time + 2;
        }else if(aux==2){
            totalprice=totalprice+2.50;
            time = time + 3;
        }else{
            totalprice=totalprice+3.25;
            time = time + 3;
        }



        switch(aux){
            case 1: d.deliveryInfo.pStarter.insert(d.deliveryInfo.pStarter.end(), garlicBread); break;
            case 2: d.deliveryInfo.pStarter.insert(d.deliveryInfo.pStarter.end(), pizzaRolls); break;
            case 3: d.deliveryInfo.pStarter.insert(d.deliveryInfo.pStarter.end(), cheeseSticks); break;
        }

        cout << "Plato principal: " << endl;
        cout << "1. Pizza " << endl;
        cout << "2. Pasta " << endl;
        cout << "3. Lasagna " << endl;
        cin >> aux;
        cin.ignore();

         if(aux==1){
            totalprice=totalprice+7.50;
            time = time + 4;
        }else if(aux==2){
            totalprice=totalprice+6.25;
            time = time + 3;
        }else{
            totalprice=totalprice+9.25;
            time = time + 5;
        }

                switch(aux){
                case 1: d.deliveryInfo.pDish.insert(d.deliveryInfo.pDish.end(), pizza); break;
                case 2: d.deliveryInfo.pDish.insert(d.deliveryInfo.pDish.end(), pasta); break;
                case 3: d.deliveryInfo.pDish.insert(d.deliveryInfo.pDish.end(), lasagna); break;
        }

        cout << "Bebidas: " << endl;
        cout << "1. Cerveza " << endl;
        cout << "2. Soda " << endl;
        cout << "3. Te " << endl;
        cin >> aux;
        cin.ignore();

        if(aux==1){
            totalprice=totalprice+2;
            time= time+2;
        }else if(aux==2){
            totalprice=totalprice+2.50;
            time= time+2;
        }else{
            totalprice=totalprice+2;
            time= time+2;
        }

                switch(aux){
                case 1: d.deliveryInfo.pDrink.insert(d.deliveryInfo.pDrink.end(), beer); break;
                case 2: d.deliveryInfo.pDrink.insert(d.deliveryInfo.pDrink.end(), soda); break;
                case 3: d.deliveryInfo.pDrink.insert(d.deliveryInfo.pDrink.end(), tea); break;

        }

        TimePromD(time);

        cout<<endl<<"Cancelar por orden: $"<<totalprice<<endl<<endl;


        cout << "Tipo de pago" << endl;
        cout << "1. Efectivo" << endl;
        cout << "2. Tarjeta";
        cin >> aux;

         switch(aux){
                case 1: d.deliveryInfo.pay.insert(d.deliveryInfo.pay.end(), cash); break;
                case 2: d.deliveryInfo.pay.insert(d.deliveryInfo.pay.end(), card); break;
            }
        cin.ignore();
    }
    return d;

}

//Funcion para imprimir los datos a domicilio

void printDeliveryOrders(delivery d){

    cout << "Nombre: " << d.deliveryInfo.name << endl;
    cout << "Direccion: " << endl;
    cout << "Colonia: " << d.deliveryInfo.Address.settlement << endl;
    cout << "Municipio: " << d.deliveryInfo.Address.municipality << endl;
    cout << "Departamento: " << d.deliveryInfo.Address.department << endl;
    cout << "No de casa: " << d.deliveryInfo.Address.houseNumber << endl;
    cout << "Numero de telefono: " << d.deliveryInfo.number << endl;

    for(int i = 0; i <= d.deliveryInfo.pStarter.size()-1; i++){
          cout << "Entrada: " << printStarter(d.deliveryInfo.pStarter[i]) << endl;
    }

    for(int i = 0; i <= d.deliveryInfo.pDish.size()-1; i++){
          cout << "Plato principal: " << printMainDish(d.deliveryInfo.pDish[i]) << endl;
    }

    for(int i = 0; i <= d.deliveryInfo.pDrink.size()-1; i++){
          cout << "Bebida: " << printDrink(d.deliveryInfo.pDrink[i]) << endl;
    }

    for(int i = 0; i <= d.deliveryInfo.pay.size()-1 ; i++){
          cout << "Tipo de pago: " << printPayment(d.deliveryInfo.pay[i]) << endl;
    }

}

//Funcion para imprimir los datos en restaurante

void printRestaurantOrders(RestaurantOrder r){
    cout << "Nombre: " << r.restaurantInfo.name << endl;
    cout << "Numero de personas en mesa: " <<r.restaurantInfo.numberPe << endl;

    for(int i = 0; i <= r.restaurantInfo.pStarter.size()-1; i++){
          cout << "Entrada: " << printStarter(r.restaurantInfo.pStarter[i]) << endl;
    }

    for(int i = 0; i <= r.restaurantInfo.pDish.size()-1; i++){
          cout << "Plato principal: " << printMainDish(r.restaurantInfo.pDish[i]) << endl;
    }

    for(int i = 0; i <= r.restaurantInfo.pDrink.size()-1; i++){
          cout << "Bebida: " << printDrink(r.restaurantInfo.pDrink[i]) << endl;
    }

    for(int i = 0; i <= r.restaurantInfo.pay.size()-1; i++){
          cout << "Tipo de pago: " << printPayment(r.restaurantInfo.pay[i]) << endl;
    }

}

//Manda a llamar la funcion printDeliveryOrders e indica la cantidad de pedidos

void ShowListDeli() {
        cout << "cantidad " << listaDelivery.size() << endl;
    for (int i = 0; i < listaDelivery.size(); i++)
        printDeliveryOrders(listaDelivery[i]);
}

//Manda a llamar la funcion printRestaurantOrders e indica la cantidad de pedidos

void ShowListRest() {
    cout << "cantidad " << ListaRest.size() << endl;
    for (int i = 0; i < ListaRest.size(); i++)
        printRestaurantOrders(ListaRest[i]);
}

//Funcion para calcular tiempo promedio a domicilio

void TimePromD(double time){

    if(timepromD==0){
            timepromD=time;
    }else if(timepromD <= 1){
        timepromD=(timepromD+time)/2;
    }

    cout<<endl<<"TIEMPO PROMEDIO: "<<timepromD<<" min"<<endl<<endl;
}

//Funcion para calcular tiempo promedio de restaurante

void TimePromR(double time){

        if(timepromR==0){
                timepromR=time;
        }else if(timepromR <= 1){
            timepromR=(timepromR+time)/2;
        }


    cout<<endl<<"TIEMPO PROMEDIO: "<<timepromR<<" min"<<endl<<endl;

}

//Convierte los ingresado en los enums a strings para las entradas

string printStarter(starter s){
    string cadena = " ";
    switch (s)
    {
    case 0: cadena = "Pan con ajo"; break;
    case 1: cadena = "Pizza Rolls"; break;
    case 2: cadena = "Palitos de queso"; break;
    }
    return cadena;
}

//Convierte los ingresado en los enums a strings para los platos principales

string printMainDish (mainDish m){
    string cadena = " ";
    switch (m)
    {
    case 0: cadena = "Pizza"; break;
    case 1: cadena = "Pasta"; break;
    case 2: cadena = "Lasagna"; break;
    }
    return cadena;
}

//Convierte los ingresado en los enums a strings para las bebidas

string printDrink (drink d){
    string cadena = " ";
    switch (d)
    {
    case 0: cadena = "Cerveza"; break;
    case 1: cadena = "Soda"; break;
    case 2: cadena = "Te"; break;
    }
    return cadena;
}

//Convierte los ingresado en los enums a strings para el tipo de pago

string printPayment (paymenType p){
    string cadena = " ";
    switch (p)
    {
    case 0: cadena = "efectivo"; break;
    case 1: cadena = "Tarjeta"; break;
    }
    return cadena;
}
