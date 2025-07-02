#include <iostream>
using namespace std;

typedef struct nodo_elemento *puntero_nodo;
typedef struct nodo_elemento {
	int valor_dato;
	puntero_nodo siguiente_elemento;
} nodo_elemento;

struct estructura_pila {
	puntero_nodo tope_pila;
	int cantidad_elementos;
};

void iniciarPila(estructura_pila &pila_principal) {
	pila_principal.tope_pila = nullptr;
	pila_principal.cantidad_elementos = 0;}

bool pilaVacia(estructura_pila pila_principal) {
	return pila_principal.tope_pila == nullptr;}

void apilar(estructura_pila &pila_principal, puntero_nodo nuevo_elemento) {
	nuevo_elemento->siguiente_elemento = pila_principal.tope_pila;
	pila_principal.tope_pila = nuevo_elemento;
	pila_principal.cantidad_elementos++;}

puntero_nodo desapilar(estructura_pila &pila_principal) {
	if (pilaVacia(pila_principal)) return nullptr;
	puntero_nodo elemento_borrado = pila_principal.tope_pila;
	pila_principal.tope_pila = pila_principal.tope_pila->siguiente_elemento;
	elemento_borrado->siguiente_elemento = nullptr;
	pila_principal.cantidad_elementos--;
	return elemento_borrado;}

void mostrarPila(estructura_pila pila_principal) {
	puntero_nodo elemento_actual = pila_principal.tope_pila;
	cout << "Pila (tope -> fondo): ";
	while (elemento_actual != nullptr) {
		cout << elemento_actual->valor_dato << " ";
		elemento_actual = elemento_actual->siguiente_elemento;}
	cout << "Cantidad: " << pila_principal.cantidad_elementos;}

struct estructura_cola {
	puntero_nodo inicio_cola;
	puntero_nodo fin_cola;
	int cantidad_elementos;
};

void iniciarCola(estructura_cola &cola_principal) {
	cola_principal.inicio_cola = nullptr;
	cola_principal.fin_cola = nullptr;
	cola_principal.cantidad_elementos = 0;}

bool colaVacia(estructura_cola cola_principal) {
	return cola_principal.inicio_cola == nullptr;}

void encolar(estructura_cola &cola_principal, puntero_nodo nuevo_elemento) {
	nuevo_elemento->siguiente_elemento = nullptr;
	if (colaVacia(cola_principal)) {
		cola_principal.inicio_cola = cola_principal.fin_cola = nuevo_elemento;}
	else {
		cola_principal.fin_cola->siguiente_elemento = nuevo_elemento;
		cola_principal.fin_cola = nuevo_elemento;}
	cola_principal.cantidad_elementos++;}

puntero_nodo desencolar(estructura_cola &cola_principal) {
	if (colaVacia(cola_principal)) return nullptr;
	puntero_nodo elemento_borrado = cola_principal.inicio_cola;
	cola_principal.inicio_cola = cola_principal.inicio_cola->siguiente_elemento;
	if (cola_principal.inicio_cola == nullptr) {
		cola_principal.fin_cola = nullptr;}
	elemento_borrado->siguiente_elemento = nullptr;
	cola_principal.cantidad_elementos--;
	return elemento_borrado;}

void mostrarCola(estructura_cola cola_principal) {
	puntero_nodo elemento_actual = cola_principal.inicio_cola;
	cout << "Cola (inicio -> fin): ";
	while (elemento_actual != nullptr) {
		cout << elemento_actual->valor_dato << " ";
		elemento_actual = elemento_actual->siguiente_elemento;}
	cout << "\nCantidad: " << cola_principal.cantidad_elementos << "\n";}

void crearnodo(puntero_nodo &nuevo_elemento) {
	nuevo_elemento = new nodo_elemento;
	if (nuevo_elemento != nullptr) {
		cout << "Ingrese valor: ";
		cin >> nuevo_elemento->valor_dato;
		nuevo_elemento->siguiente_elemento = nullptr;}
	else {
		cout << "Memoria insuficiente" << endl;}}

int main() {
	puntero_nodo elemento_a_procesar;
	estructura_pila mi_pila;
	iniciarPila(mi_pila);
	
	cout << "CARGANDO PILA";
	for (int i = 0; i < 3; ++i) {
		crearnodo(elemento_a_procesar);
		apilar(mi_pila, elemento_a_procesar);}
	mostrarPila(mi_pila);
	
	cout << "\nDesapilando un nodo...\n";
	puntero_nodo nodo_eliminado_pila = desapilar(mi_pila);
	if (nodo_eliminado_pila) cout << "Eliminado: " << nodo_eliminado_pila->valor_dato << "\n";
	mostrarPila(mi_pila);
	
	estructura_cola mi_cola;
	iniciarCola(mi_cola);
	
	cout << "\n--- CARGANDO COLA ---\n";
	for (int i = 0; i < 3; ++i) {
		crearnodo(elemento_a_procesar);
		encolar(mi_cola, elemento_a_procesar);}
	mostrarCola(mi_cola);
	
	cout << "\nDesencolando un nodo...\n";
	puntero_nodo nodo_eliminado_cola = desencolar(mi_cola);
	if (nodo_eliminado_cola) cout << "Eliminado: " << nodo_eliminado_cola->valor_dato << "\n";
	mostrarCola(mi_cola);
	
	return 0;}
