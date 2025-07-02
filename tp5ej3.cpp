#include<bits/stdc++.h>
using namespace std;

typedef struct nodo_elemento *puntero_nodo;
typedef struct nodo_elemento{
	int valor_dato;
	puntero_nodo siguiente_elemento;} nodo_elemento;

typedef struct lista_enlazada{
	puntero_nodo inicio_lista;
	puntero_nodo fin_lista;
	int contador_elementos;} lista_enlazada;

void crearnodo(puntero_nodo &nuevo_elemento){
	nuevo_elemento = new nodo_elemento;
	if(nuevo_elemento != NULL){
		cout << "Ingrese valor: ";
		cin >> nuevo_elemento -> valor_dato;
		nuevo_elemento -> siguiente_elemento = NULL;}
	else{
		cout << "Memoria insuficiente" << endl;}}
	
	void iniciarlista(lista_enlazada &mi_lista){
		mi_lista.inicio_lista = nullptr;
		mi_lista.fin_lista = nullptr;
		mi_lista.contador_elementos = 0;}
		
		void agregarinicio(lista_enlazada &mi_lista, puntero_nodo nuevo_elemento){
			nuevo_elemento -> siguiente_elemento = mi_lista.inicio_lista;
			mi_lista.inicio_lista = nuevo_elemento;
			if(mi_lista.fin_lista == nullptr){
				mi_lista.fin_lista = nuevo_elemento;}
			mi_lista.contador_elementos++;}
			
			void agregarfinal(lista_enlazada &mi_lista, puntero_nodo nuevo_elemento){
				if(mi_lista.inicio_lista == nullptr){
					mi_lista.inicio_lista = nuevo_elemento;
					mi_lista.fin_lista = nuevo_elemento;}
				else{
					mi_lista.fin_lista->siguiente_elemento = nuevo_elemento;
					mi_lista.fin_lista = nuevo_elemento;}
				mi_lista.contador_elementos++;}
				
				void agregarordenado(puntero_nodo &lista_actual, puntero_nodo nuevo_elemento){
					puntero_nodo iterador_lista;
					if(lista_actual == NULL){
						lista_actual = nuevo_elemento;}
					else{
						if(nuevo_elemento->valor_dato < lista_actual->valor_dato){
							nuevo_elemento->siguiente_elemento = lista_actual;
							lista_actual = nuevo_elemento;}
						else{
							for(iterador_lista = lista_actual; iterador_lista->siguiente_elemento != NULL && nuevo_elemento->valor_dato > (iterador_lista->siguiente_elemento)->valor_dato; iterador_lista = iterador_lista->siguiente_elemento);
							nuevo_elemento->siguiente_elemento = iterador_lista->siguiente_elemento;
							iterador_lista->siguiente_elemento = nuevo_elemento;}}}
					
					puntero_nodo eliminarinicio(lista_enlazada &mi_lista){
						puntero_nodo nodo_borrado;
						if(mi_lista.inicio_lista == nullptr){
							return nullptr;}
						nodo_borrado = mi_lista.inicio_lista;
						mi_lista.inicio_lista = mi_lista.inicio_lista->siguiente_elemento;
						if(mi_lista.inicio_lista == nullptr){
							mi_lista.fin_lista = nullptr;}
						nodo_borrado->siguiente_elemento = nullptr;
						mi_lista.contador_elementos--;
						return nodo_borrado;}
						
						puntero_nodo eliminarfinal(lista_enlazada &mi_lista){
							puntero_nodo nodo_borrado, iterador_lista;
							if(mi_lista.inicio_lista == nullptr){
								return nullptr;}
							if(mi_lista.inicio_lista == mi_lista.fin_lista){
								nodo_borrado = mi_lista.inicio_lista;
								mi_lista.inicio_lista = nullptr;
								mi_lista.fin_lista = nullptr;}
							else{
								for(iterador_lista = mi_lista.inicio_lista; iterador_lista->siguiente_elemento != mi_lista.fin_lista; iterador_lista = iterador_lista->siguiente_elemento);
								nodo_borrado = mi_lista.fin_lista;
								iterador_lista->siguiente_elemento = nullptr;
								mi_lista.fin_lista = iterador_lista;}
							mi_lista.contador_elementos--;
							return nodo_borrado;}
							
							puntero_nodo eliminarnodo(puntero_nodo &lista_actual, int valor_a_eliminar){
								puntero_nodo nodo_borrado, iterador_lista;
								if(lista_actual == NULL){
									nodo_borrado = NULL;}
								else{
									if(lista_actual->valor_dato == valor_a_eliminar){
										nodo_borrado = lista_actual;
										lista_actual = nodo_borrado->siguiente_elemento;
										nodo_borrado->siguiente_elemento = NULL;}
									else{
										for(iterador_lista = lista_actual; iterador_lista->siguiente_elemento != NULL && valor_a_eliminar != (iterador_lista->siguiente_elemento)->valor_dato; iterador_lista = iterador_lista->siguiente_elemento);
										if(iterador_lista->siguiente_elemento != NULL){
											nodo_borrado = iterador_lista->siguiente_elemento;
											iterador_lista->siguiente_elemento = nodo_borrado->siguiente_elemento;
											nodo_borrado->siguiente_elemento = NULL;}
										else{
											nodo_borrado = NULL;}}}
								return nodo_borrado;}
								
								void mostrar(lista_enlazada mi_lista){
									puntero_nodo iterador_lista;
									if(mi_lista.inicio_lista != NULL){
										for(iterador_lista = mi_lista.inicio_lista; iterador_lista != nullptr; iterador_lista = iterador_lista->siguiente_elemento){
											cout << "Nodo: " << iterador_lista->valor_dato << endl;}}
									else{
										cout << "Lista vacia";}}
									
									int buscar_indice(lista_enlazada mi_lista, int valor_buscado) {
										puntero_nodo elemento_actual = mi_lista.inicio_lista;
										int indice_actual = 0;
										while (elemento_actual != nullptr) {
											if (elemento_actual->valor_dato == valor_buscado) {
												return indice_actual;}
											elemento_actual = elemento_actual->siguiente_elemento;
											indice_actual++;}
										return -1;}
									
									puntero_nodo buscar_por_indice(lista_enlazada mi_lista, int indice_buscado) {
										puntero_nodo elemento_actual = mi_lista.inicio_lista;
										int contador_posicion = 0;
										while (elemento_actual != nullptr) {
											if (contador_posicion == indice_buscado) {
												return elemento_actual;}
											elemento_actual = elemento_actual->siguiente_elemento;
											contador_posicion++;}
										return nullptr;}
									
									int main() {
										lista_enlazada mi_lista_principal;
										iniciarlista(mi_lista_principal);
										puntero_nodo nuevo_elemento_creado;
										
										for (int i = 0; i < 3; ++i) {
											crearnodo(nuevo_elemento_creado);
											agregarfinal(mi_lista_principal, nuevo_elemento_creado);}
										
										cout << "Mostrando la lista:";
										mostrar(mi_lista_principal);
										
										int valor_a_buscar;
										cout << "Ingrese valor a buscar (buscar_indice): ";
										cin >> valor_a_buscar;
										
										int posicion_encontrada = buscar_indice(mi_lista_principal, valor_a_buscar);
										if (posicion_encontrada != -1)
											cout << "El valor " << valor_a_buscar << " se encuentra en la posicion logica: " << posicion_encontrada << endl;
										else
											cout << "Valor no encontrado";
										
										int indice_a_buscar;
										cout << "Ingrese indice a buscar (buscar_por_indice): ";
										cin >> indice_a_buscar;
										
										puntero_nodo nodo_encontrado_por_indice = buscar_por_indice(mi_lista_principal, indice_a_buscar);
										if (nodo_encontrado_por_indice != nullptr)
											cout << "El nodo en el indice " << indice_a_buscar << " contiene: " << nodo_encontrado_por_indice->valor_dato << endl;
										else
											cout << "Indice fuera de rango";
										
										return 0;}

