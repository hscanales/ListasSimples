#include <iostream>

using namespace std;


struct Nodo{
    int dato;
    Nodo *sig;
}*inicio;

void insertarInicio();
Nodo *crearElemento();
void insertarFinal(Nodo *);
void insertarFinalR(Nodo *);
void mostrar();
void menu();
void sumar();
void sumaRecursiva(Nodo *);
int sumaRecursiva2(Nodo *, int);
int main()
{
    inicio = NULL;
	bool flag = true;
	while(flag){
		menu();
		int op=0;
		cout<<"Ingrese su opcion del menu: \n";
		cin>>op;
		switch(op){
			case 1: 
				insertarInicio();
				break;
			case 2:
				insertarFinal(inicio);
				break;
			case 3:
				mostrar();
				break;
				case 4:
					sumaRecursiva(inicio);
					break;
			case 0:
				flag=false;
				break;
			default:
				cout<<"Ingreso una opcion no valida, intente denuevo \n";
				break;
		}
	}

    return 0;
}
void menu(){
	cout<<"Menu Listas Simples"<<endl;
	cout<<"1- Insertar Inicio \n";
	cout<<"2- Insertar Final \n";
	cout<<"3- Mostrar\n";
	cout<<"4- Sumar Valores \n";
	cout<<"0- salir\n";
}
void mostrar(){
    Nodo *aux = inicio;
    cout<<"Lista Simple"<<endl;
    cout<<"-------------"<<endl;
    int cont = 0;
    while(aux){
        cout<<cont<<"-"<<aux->dato<<endl;
        aux=aux->sig;
        cont++;
    }
    cout<<"\n";
    cout<<"\n";
}


void insertarInicio(){
    Nodo *nuevo = crearElemento();
    nuevo->sig = inicio;
    inicio = nuevo;
    cout<<"\n";
}


void insertarFinal(Nodo *aux)
{
    if(!aux)
    {
        insertarInicio();
    }
    else
    {
        insertarFinalR(aux);
    }
}

void insertarFinalR(Nodo *aux)
{
    //cout << "entro0" << endl;
    if(aux->sig)
    {
        insertarFinalR(aux->sig);
    }
    else
    {
        Nodo *nuevo = crearElemento();
        /*nuevo->nombre=nombre;*/

        aux->sig = nuevo;
        //nuevo->sig = NULL;
    }
  	cout<<"\n";
}

  	Nodo *	crearElemento(){
Nodo *nuevo = new Nodo;
cout<<"Usuario ingrese el dato a guardar: \n";
cin>>nuevo->dato;
nuevo->sig=NULL;
return nuevo;
}


void sumar(){
    Nodo *aux = inicio;
    int suma = 0;
    while(aux){
        suma=suma+aux->dato;
        aux=aux->sig;
    }
    cout<<"La suma es: "<<suma<<endl;
}


int sumaRecursiva2(Nodo *p,int n){
    if(p->sig){
        return sumaRecursiva2(p->sig,n+p->dato);
    }
    else{
        n=n+p->dato;
        cout<<"La suma es: "<<n<<endl;
        cout<<"\n\n\n";
        return n;
    }
}


void sumaRecursiva(Nodo *aux){
    if(!aux){
        cout<<"Su lista esta vacia!";
    }else{
        sumaRecursiva2(aux,0);
    }

}