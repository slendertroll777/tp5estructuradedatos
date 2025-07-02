#include<bits/stdc++.h>
using namespace std;

typedef struct tnodo *pnodo;

typedef struct tnodo{
int dato;
pnodo siguiente;
};

void crearnodo(pnodo &nuevo){
nuevo = new tnodo;
if(nuevo != NULL){
cout << "ingrese valor: ";
cin >> nuevo->dato;
nuevo->siguiente = NULL;
} else {
cout << "memoria insuficiente" << endl;
}
}

void iniciarlista(pnodo &lista){
lista = NULL;
}

void agregarinicio(pnodo &lista, pnodo nuevo){
nuevo->siguiente = lista;
lista = nuevo;
}

void agregarfinal(pnodo &lista, pnodo nuevo){
pnodo aux;
if(lista == NULL){
lista = nuevo;
} else {
for(aux = lista; aux->siguiente != NULL; aux = aux->siguiente);
aux->siguiente = nuevo;
}
}

void agregarordenado(pnodo &lista, pnodo nuevo){
pnodo act;
if(lista == NULL || nuevo->dato < lista->dato){
nuevo->siguiente = lista;
lista = nuevo;
} else {
for(act = lista; act->siguiente != NULL && nuevo->dato > act->siguiente->dato; act = act->siguiente);
nuevo->siguiente = act->siguiente;
act->siguiente = nuevo;
}
}

pnodo eliminarinicio(pnodo &lista){
pnodo extraido = NULL;
if(lista != NULL){
extraido = lista;
lista = lista->siguiente;
extraido->siguiente = NULL;
}
return extraido;
}

pnodo eliminarfinal(pnodo &lista){
pnodo aux = lista, previo = NULL;
if(lista == NULL){
return NULL;
}
if(lista->siguiente == NULL){
lista = NULL;
return aux;
}
while(aux->siguiente->siguiente != NULL){
aux = aux->siguiente;
}
pnodo fin = aux->siguiente;
aux->siguiente = NULL;
return fin;
}

pnodo eliminarnodo(pnodo &lista, int valor){
pnodo aux = lista, previo = NULL, borrado = NULL;
if(lista != NULL){
if(lista->dato == valor){
borrado = lista;
lista = lista->siguiente;
borrado->siguiente = NULL;
} else {
while(aux->siguiente != NULL && aux->siguiente->dato != valor){
aux = aux->siguiente;
}
if(aux->siguiente != NULL){
borrado = aux->siguiente;
aux->siguiente = borrado->siguiente;
borrado->siguiente = NULL;
}
}
}
return borrado;
}

void mostrar(pnodo lista){
pnodo aux = lista;
if(aux == NULL){
cout << "lista vacia";
} else {
while(aux != NULL){
cout << "nodo: " << aux->dato << endl;
aux = aux->siguiente;
}
}
}

bool buscarnodo(pnodo lista, int valor){
pnodo aux = lista;
while(aux != NULL){
if(aux->dato == valor){
return true;
}
aux = aux->siguiente;
}
return false;
}

pnodo extraerMinimo(pnodo &lista){
if(lista == NULL){
cout << "la lista esta vacia" << endl;
return NULL;
}
pnodo min = lista, ant = NULL, aux = lista, prev = NULL;
while(aux != NULL){
if(aux->dato < min->dato){
min = aux;
ant = prev;
}
prev = aux;
aux = aux->siguiente;
}
if(ant == NULL){
lista = min->siguiente;
} else {
ant->siguiente = min->siguiente;
}
min->siguiente = NULL;
return min;
}

int main(){
pnodo lista;
iniciarlista(lista);
pnodo nuevo;
int total;
cout << "ingrese la cantidad de nodos" << endl;
cin >> total;
for(int j = 0; j < total; j++){
crearnodo(nuevo);
agregarinicio(lista, nuevo);
}
cout << "primera lista:" << endl;
mostrar(lista);
pnodo minextraido = extraerMinimo(lista);
if(minextraido != NULL){
cout << "minimo = " << minextraido->dato << endl;
delete minextraido;
}
return 0;
}
