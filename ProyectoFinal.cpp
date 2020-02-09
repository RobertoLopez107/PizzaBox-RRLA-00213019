#include <iostream>
#include <ostream>
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
    vector <paymenType> pay;
    int idOrder;
    float total;
    address Address;
    int numberPe;
    int number;
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

vector <mainInfo> lista;
vector <delivery> listaDelivery;
vector <RestaurantOrder> ListaRest;

bool isAdmin = false;
double timepromD=0,timepromR=0;
int idOrder = 1;
bool loginUser(void);

void Menu(); //declarando prototipo de la funcion SIEMPRE ANTES DEL MAIN
bool loginUser(void);
void AdminMenu();
void EmployeeMenu();
delivery AddOrderDelivery();
void printDeliveryOrders(mainInfo p);
void ShowListDeli();
void ShowListRest();
RestaurantOrder AddOrderAtRes();
void printRestaurantOrders(RestaurantOrder r);
void TimePromD(double);
void TimePromR(double);


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
            loginUser();
        break;
        default:
        break;

        cin.ignore();
    }

    }while(option != 0);
}


RestaurantOrder AddOrdenRes(){
    RestaurantOrder r = AddOrderAtRes();
        bool continuar = true;
    do{
        ListaRest.insert(ListaRest.begin(), r);
        continuar = false;
    }while(continuar);

}

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
            case 1: r.restaurantInfo.pStarter.insert(r.restaurantInfo.pStarter.end(), garlicBread); break;
            case 2: r.restaurantInfo.pStarter.insert(r.restaurantInfo.pStarter.end(), pizzaRolls); break;
            case 3: r.restaurantInfo.pStarter.insert(r.restaurantInfo.pStarter.end(), cheeseSticks); break;
        }
        //.pStarter[i]

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

        TimePromR(time);

        cout<<endl<<"Cancelar por orden: $"<<totalprice<<endl<<endl;

        cout << "Tipo de pago" << endl;
        cout << "1. Efectivo" << endl;
        cout << "2. Tarjeta";
        cin >> aux;

        switch(aux){
            case 1: r.restaurantInfo.pay.insert(r.restaurantInfo.pay.end(),cash);break;
            case 2: r.restaurantInfo.pay.insert(r.restaurantInfo.pay.end(),card);break;
        }
        cin.ignore();
    }
    return r;

}

delivery agregarOrden(){
    delivery d = AddOrderDelivery();
        bool continuar = true;
    do{
        listaDelivery.insert(listaDelivery.begin(), d);
        continuar = false;
    }while(continuar);

}

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
            case 1: d.deliveryInfo.pay.insert(d.deliveryInfo.pay.end(),cash);break;
            case 2: d.deliveryInfo.pay.insert(d.deliveryInfo.pay.end(),card);break;
        }
        cin.ignore();
    }
    return d;

}

void printDeliveryOrders(delivery d){

    cout << "Nombre: " << d.deliveryInfo.name << endl;
    cout << "Direccion: " << endl;
    cout << "Colonia: " << d.deliveryInfo.Address.settlement << endl;
    cout << "Municipio: " << d.deliveryInfo.Address.municipality << endl;
    cout << "Departamento: " << d.deliveryInfo.Address.department << endl;
    cout << "No de casa" << d.deliveryInfo.Address.houseNumber << endl;
    cout << "Numero de telefono: " << d.deliveryInfo.number << endl;

    for(int i = 0; i <= listaDelivery.size(); i++){
        cout << "Entrada: " << d.deliveryInfo.pStarter[i] << " " << endl;
        cout << "Plato Principal"<< d.deliveryInfo.pDish[i] << " " << endl;
        cout << "Bebida" << d.deliveryInfo.pDrink[i] << " " << endl;
        cout << "Tipo de pago" << d.deliveryInfo.pay[i] << " " << endl;
    }
}

void printRestaurantOrders(RestaurantOrder r){
    cout << "Nombre: " << r.restaurantInfo.name << endl;
    cout << "Numero de personas en mesa: " <<r.restaurantInfo.numberPe;

    for(int i = 0; listaDelivery.size(); i++)
        cout << r.restaurantInfo.pStarter[i];

    for(int i = 0; listaDelivery.size(); i++)
        cout << r.restaurantInfo.pDish[i];

    for(int i = 0; listaDelivery.size(); i++)
        cout << r.restaurantInfo.pDrink[i];

    for(int i = 0; listaDelivery.size(); i++)
        cout << r.restaurantInfo.pay[i];

}

void ShowListDeli() {
        cout << "cantidad " << listaDelivery.size() << endl;
    for (int i = 0; i < listaDelivery.size(); i++)
        printDeliveryOrders(listaDelivery[i]);
}

void ShowListRest() {
    cout << "cantidad " << ListaRest.size() << endl;
    for (int i = 0; i < ListaRest.size(); i++)
        printRestaurantOrders(ListaRest[i]);
}

void TimePromD(double time){

    if(timepromD==0){
            timepromD=time;
    }else if(timepromD <= 1){
        timepromD=(timepromD+time)/2;
    }

    cout<<endl<<"TIEMPO PROMEDIO: "<<timepromD<<" min"<<endl<<endl;
}

void TimePromR(double time){

        if(timepromR==0){
                timepromR=time;
        }else if(timepromR <= 1){
            timepromR=(timepromR+time)/2;
        }


    cout<<endl<<"TIEMPO PROMEDIO: "<<timepromR<<" min"<<endl<<endl;

}
