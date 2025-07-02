#include <bits/stdc++.h>
using namespace std;

typedef struct nodo_elemento *puntero_nodo;
typedef struct nodo_elemento {
	int valor_dato;
	puntero_nodo siguiente_elemento;
} nodo_elemento;

void crearnodo(puntero_nodo &nuevo_elemento) {
	nuevo_elemento = new nodo_elemento;
	if (nuevo_elemento != NULL) {
		cout << "Ingrese valor: ";
		cin >> nuevo_elemento->valor_dato;
		nuevo_elemento->siguiente_elemento = NULL;}
	else {
		cout << "Memoria insuficiente" << endl;}}

void iniciarlista(puntero_nodo &cabeza_lista) {
	cabeza_lista = NULL;}

void agregarinicio(puntero_nodo &cabeza_lista, puntero_nodo nuevo_elemento) {
	nuevo_elemento->siguiente_elemento = cabeza_lista;
	cabeza_lista = nuevo_elemento;}

void mostrar(puntero_nodo cabeza_lista) {
	puntero_nodo iterador_lista;
	if (cabeza_lista != NULL) {
		for (iterador_lista = cabeza_lista; iterador_lista != NULL; iterador_lista = iterador_lista->siguiente_elemento) {
			cout << "Nodo: " << iterador_lista->valor_dato << endl;}}
	else {
		cout << "Lista vacia" << endl;}}

void seleccion(puntero_nodo &cabeza_lista) {
	if (cabeza_lista == NULL) return;
	puntero_nodo actual_iterador = cabeza_lista;
	puntero_nodo nodo_minimo;
	
	while (actual_iterador != NULL) {
		nodo_minimo = actual_iterador;
		for (puntero_nodo temp_iterador = actual_iterador->siguiente_elemento; temp_iterador != NULL; temp_iterador = temp_iterador->siguiente_elemento) {
			if (temp_iterador->valor_dato < nodo_minimo->valor_dato) {
				nodo_minimo = temp_iterador;}}
		if (nodo_minimo != actual_iterador) {
			int temp_dato = actual_iterador->valor_dato;
			actual_iterador->valor_dato = nodo_minimo->valor_dato;
			nodo_minimo->valor_dato = temp_dato;}
		actual_iterador = actual_iterador->siguiente_elemento;}}

void combinarSinOrden(puntero_nodo &lista_destino, puntero_nodo &lista_origen) {
	if (lista_destino == NULL) {
		lista_destino = lista_origen;
		return;}
	puntero_nodo ultimo_elemento = lista_destino;
	while (ultimo_elemento->siguiente_elemento != NULL) {
		ultimo_elemento = ultimo_elemento->siguiente_elemento;}
	ultimo_elemento->siguiente_elemento = lista_origen;
	lista_origen = nullptr; 
}

void combinarConOrden(puntero_nodo &lista_ordenada, puntero_nodo &lista_a_insertar) {
	puntero_nodo nuevo_nodo;
	while (lista_a_insertar != nullptr) {
		nuevo_nodo = lista_a_insertar;
		lista_a_insertar = lista_a_insertar->siguiente_elemento;
		if (lista_ordenada == nullptr || nuevo_nodo->valor_dato < lista_ordenada->valor_dato) {
			nuevo_nodo->siguiente_elemento = lista_ordenada;
			lista_ordenada = nuevo_nodo;}
		else {
			puntero_nodo actual_posicion = lista_ordenada;
			while (actual_posicion->siguiente_elemento != nullptr && nuevo_nodo->valor_dato > actual_posicion->siguiente_elemento->valor_dato) {
				actual_posicion = actual_posicion->siguiente_elemento;}
			nuevo_nodo->siguiente_elemento = actual_posicion->siguiente_elemento;
			actual_posicion->siguiente_elemento = nuevo_nodo;}}
}

void liberarLista(puntero_nodo &cabeza_lista) {
	puntero_nodo elemento_actual = cabeza_lista;
	while (elemento_actual != nullptr) {
		puntero_nodo temp_borrado = elemento_actual;
		elemento_actual = elemento_actual->siguiente_elemento;
		delete temp_borrado;}
	cabeza_lista = nullptr;}

int main() {
	puntero_nodo primera_lista, segunda_lista, nuevo_elemento;
	int cantidad_nodos1, cantidad_nodos2;
	
	iniciarlista(primera_lista);
	iniciarlista(segunda_lista);
	
	cout << "Ingrese la cantidad de nodos para la primera lista: ";
	cin >> cantidad_nodos1;
	for (int i = 0; i < cantidad_nodos1; i++) {
		crearnodo(nuevo_elemento);
		agregarinicio(primera_lista, nuevo_elemento);}
	
	cout << "Ingrese la cantidad de nodos para la segunda lista: ";
	cin >> cantidad_nodos2;
	for (int i = 0; i < cantidad_nodos2; i++) {
		crearnodo(nuevo_elemento);
		agregarinicio(segunda_lista, nuevo_elemento);}
	
	cout << "Primera lista original:" << endl;
	mostrar(primera_lista);
	cout << "Segunda lista original:" << endl;
	mostrar(segunda_lista);
	
	seleccion(primera_lista);
	cout << "Primera lista ordenada con seleccion:\n";
	mostrar(primera_lista);
	
	
	cout << "Combinando sin orden";
	puntero_nodo lista_sin_orden = nullptr;
	puntero_nodo aux_segunda_lista_sin_orden = nullptr;
	iniciarlista(lista_sin_orden);
	iniciarlista(aux_segunda_lista_sin_orden);
	
	puntero_nodo temp_original = primera_lista;
	while(temp_original != nullptr){
		crearnodo(nuevo_elemento);
		nuevo_elemento->valor_dato = temp_original->valor_dato;
		agregarinicio(lista_sin_orden, nuevo_elemento); 
		temp_original = temp_original->siguiente_elemento;
	}
	// Para que la copia sea correcta y luego ordenar
	liberarLista(lista_sin_orden); 
	iniciarlista(lista_sin_orden); 
	
	temp_original = primera_lista;
	puntero_nodo ultimo_copia_1 = nullptr;
	while(temp_original != nullptr){
		puntero_nodo copia_nodo = new nodo_elemento;
		copia_nodo->valor_dato = temp_original->valor_dato;
		copia_nodo->siguiente_elemento = nullptr;
		if(lista_sin_orden == nullptr){
			lista_sin_orden = copia_nodo;
		} else {
			ultimo_copia_1->siguiente_elemento = copia_nodo;
		}
		ultimo_copia_1 = copia_nodo;
		temp_original = temp_original->siguiente_elemento;
	}
	
	
	temp_original = segunda_lista;
	puntero_nodo ultimo_copia_2 = nullptr;
	while(temp_original != nullptr){
		puntero_nodo copia_nodo = new nodo_elemento;
		copia_nodo->valor_dato = temp_original->valor_dato;
		copia_nodo->siguiente_elemento = nullptr;
		if(aux_segunda_lista_sin_orden == nullptr){
			aux_segunda_lista_sin_orden = copia_nodo;
		} else {
			ultimo_copia_2->siguiente_elemento = copia_nodo;
		}
		ultimo_copia_2 = copia_nodo;
		temp_original = temp_original->siguiente_elemento;
	}
	
	cout << "Lista 1 para combinar sin orden:" << endl;
	mostrar(lista_sin_orden);
	cout << "Lista 2 para combinar sin orden:" << endl;
	mostrar(aux_segunda_lista_sin_orden);
	
	combinarSinOrden(lista_sin_orden, aux_segunda_lista_sin_orden);
	cout << "Lista combinada (sin orden, 1 + 2):" << endl;
	mostrar(lista_sin_orden);
	liberarLista(lista_sin_orden);
	liberarLista(aux_segunda_lista_sin_orden);
	
	
	cout << " Combinando con orden (usando las listas originales)";
	seleccion(primera_lista);
	seleccion(segunda_lista);
	cout << "Primera lista (ordenada para combinacion con orden):";
	mostrar(primera_lista);
	cout << "Segunda lista (ordenada para combinacion con orden): ";
	mostrar(segunda_lista);
	
	combinarConOrden(primera_lista, segunda_lista);
	cout << "Lista combinada (respetando orden, 1 + 2):" << endl;
	mostrar(primera_lista);
	
	liberarLista(primera_lista);
	liberarLista(segunda_lista); 
	
	return 0;}
