/*
-Lista y sus usos generales.
*/
#include <iostream>

using namespace std;

struct nodo{
    int dato;
    nodo *sig;
};

//Las funciones se ponen en publico y los datos en privado para que no se pueda acceder a ellos
class ListaSimple{
private:
    nodo *pInicio;

public:
    ListaSimple(void){
        cout << "Inicializando el objeto" << endl;
        //Para iniciar la lista se pone NULL para limpiar pInicio y que no tenga basura
        pInicio = NULL;
    }

    void EliminarLista()
    {
        nodo *s=pInicio;
        while(pInicio!=NULL)
        {
            s=pInicio;
            pInicio=pInicio->sig;
            delete(s);
        }
    }

    void EliminarListaRec(nodo *s)
    {
        if(s!=NULL)
        {
            EliminarListaRec(s->sig);
            delete (s);
        }
    }

    void EliminarListaRec()
    {
        EliminarListaRec(pInicio);
        pInicio=NULL;
    }


    void EliminarNodo(int dato)
    {
        nodo *p=pInicio, *q=NULL;

        while(p!=NULL&&p->dato!=dato)
        {
            q=p;
            p=p->sig;
        }

        if(p!=NULL)
        {
            if(q!=NULL) //El nodo esta a mitad o final de lista.
                {
                q->sig=p->sig;
                delete p;
                }

        else //El nodo esta al principio de lista
            {
            pInicio=p->sig;
            delete p;
            }
        }

        else //p fue nulo, significa que no encontro el nodo
        {
            cout<<"Dato a borrar NO esta en la lista"<<endl;
        }

    }


    void Busqueda(int dato) //El dato es el elemento que se va a buscar
    {
        nodo *s=pInicio; //se declara el puntero s y se inicializa donde pInicio empieza

        while(s!=NULL&&s->dato!=dato) //Si el puntero no es igual a null es que la lista tiene elementos, entonces seguira buscando.
            //&&si el dato de s no es igual al dato de la busqueda seguira buscando
            s=s->sig;

         if (s!=NULL) //Si s no es igual a null, es que encontro el dato
            cout<<"Elemento ENCONTRADO"<<endl;


        else// si s es igual a NULL significa que no encontro el dato en la lista, entonces el puntero senalo al final de la lista (NULL)
            cout<<"Elemento NO encontrado"<<endl;

    }

    void insAntes_1(int dato, int datoRef)
    {
        nodo *nuevo, *p, *q;
        nuevo=new nodo;
        nuevo->dato=dato;
        p=pInicio;
        q=NULL;
        while(p!=NULL&&p->dato!=datoRef) //Mientras p sea nulo o p no sea igual al dato que se busca.
        {
            q=p;
            p=p->sig;
        }

        if(q==NULL) //Si q apunta a nulo quiere decir que la lista esta vacia o que el elemento de referencia este al inicio
        {
            if(p==NULL)
            {
                cout<<"Insertaste el primero"<<endl;
                pInicio=nuevo;
                pInicio->sig=NULL;
            }

            else
            {
                cout<<"Dato de referencia al principio"<<endl;
                pInicio=nuevo;
                pInicio->sig=p;
            }
        }
            else
            {
                if(p==NULL)
                {
                    cout<<"Dato de referencia no encontrado"<<endl;
                    q->sig=nuevo;
                    nuevo->sig=NULL;
                }

                else
                {
                    cout<<"Dato insertado a mitad de la lista"<<endl;
                    q->sig=nuevo;
                    nuevo->sig=p;
                }
            }

    }

    void insertarInicioLista(int dato){
        nodo *nuevo;

        //new crea un espacio en memoria de lo que se le pone a la derecha
        nuevo = new nodo;
        //Al campo de dato donde apunta nuevo se agrega dato
        nuevo -> dato = dato;
        //Al campo siguiente donde nuevo apunta se le agrega lo que pInicio tiene
        nuevo -> sig = pInicio;
        //A pInicio se le cambia el valor y se le da lo que tiene nuevo
        pInicio = nuevo;
    }

    //Para desplegar los datos de la lista se tiene que tener un puntero, con nombre flecha dato
    //No se le pone puntero porque esta en clase y los niveles de puntero se reducen a uno
    void mostrarLista(void){

        //Ya que pInicio es de tipo modo saltarin tiene que serlo tambien
        nodo *s = pInicio;
        //Mientras saltarin no este en nulo que desplegue los datos
        cout << "Los elementos de la lista son: " << endl;
        while(s!=NULL){
          cout << s -> dato << " ";
        //Para la siguiente iteracion hay que hacer que saltarin apunte al siguiente dato
        //Lo unico que puede ayudar a que apunte al siguiente es sig ya que esta dentro
          s = s -> sig;
        }
    }

    void mostrarListaRec(void){
        mostrarListaRec(pInicio);
    }

    //Para mostrar los datos en orden que se ingresan por medio de recursion
    void mostrarListaRec(nodo *s){
        if(s!=NULL){
          mostrarListaRec(s -> sig);
          cout << s -> dato << " ";
        }
    }

    void mostrarListaRecD (void){
        mostrarListaRecD(pInicio);
    }

    void mostrarListaRecD (nodo *s){
        if(s!=NULL){
          cout << s -> dato << " ";
          mostrarListaRecD(s -> sig);
        }
    }

    void insFinal(int dato){
        nodo *p, *q;

        nodo *nuevo = new nodo;
        nuevo -> dato = dato;
        nuevo -> sig = NULL;

        if(pInicio == NULL){
            pInicio = nuevo;
        }
        else{
            p = pInicio;
            q = NULL;

            while(p!=NULL){
                q = p;
                p = p -> sig;
            }

            q -> sig = nuevo;

        }
    }
};

int main(void){

    ListaSimple miLista;
    char resp;
    int dato, datoRef;

    cout << "¿Desea meter un dato(s/n)?";
    cin >> resp;
    while(resp == 's'){
        cout << "Digite el dato: ";
        cin >> dato;
        cout<< "Antes de cual vas a insertarlo?";
        cin>>datoRef;
        miLista.insAntes_1(dato, datoRef);
        //miLista.insFinal(datoRef); //insertarInicioLista(dato);
        cout << "¿Desea meter un dato (s/n)?";
        cin >> resp;
    }

    cout << "\nMostrar lista iterativa (sentido directo): " << endl;
    miLista.mostrarListaRecD();
    cout << "\nMostrar lista recursiva (sentido inverso): " << endl;
    miLista.mostrarListaRec();
    cout << "\nMostrar lista recursiva (sentido directo): " << endl;
    miLista.mostrarListaRecD();

    cout<<endl;
    cout<<"Que dato quiere buscar?"<<endl;
    cin>>dato;
    miLista.Busqueda(dato);

    cout<<"Que dato quiere eliminar?"<<endl;
    cin>>dato;
    miLista.EliminarNodo(dato);

    cout<<"Desea eliminar lista?"<<endl;
    cin >> resp;
    if(resp == 's')
    {
        miLista.EliminarLista();
        cout<<"La lista quedo: "<<endl;
        miLista.mostrarListaRecD();
    }

        else
        cout<<"La lista quedo: "<<endl;
        miLista.mostrarListaRecD();


    return 0;

}



