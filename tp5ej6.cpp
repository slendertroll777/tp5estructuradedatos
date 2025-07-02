#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct Nodo {
T dato;
Nodo<T>* siguiente;};
template <typename T>
class Lista {
private:
Nodo<T>* inicio;
public:
Lista() : inicio(nullptr) {}
void agregar(T valor) {
Nodo<T>* nuevo = new Nodo<T>;
nuevo->dato = valor;
nuevo->siguiente = nullptr;
if (inicio == nullptr) {
inicio = nuevo;}
else {
Nodo<T>* aux = inicio;
while (aux->siguiente != nullptr) {
aux = aux->siguiente;}
aux->siguiente = nuevo;}}
void mostrar() {
Nodo<T>* aux = inicio;
while (aux != nullptr) {
cout << aux->dato << " ";
aux = aux->siguiente;}
cout << endl;}
Nodo<T>* getInicio() {
return inicio;}
~Lista() {
Nodo<T>* temp;
while (inicio) {
temp = inicio;
inicio = inicio->siguiente;
delete temp;}}};
bool esPrimo(int n) {
if (n <= 1) return false;
for (int i = 2; i * i <= n; ++i)
if (n % i == 0) return false;
return true;}
int contarPrimos(Lista<int>& lista) {
int contador = 0;
Nodo<int>* actual = lista.getInicio();
while (actual) {
if (esPrimo(actual->dato)) contador++;
actual = actual->siguiente;}
return contador;}
void contarMayusMinus(Lista<char>& lista, int& mayus, int& minus) {
mayus = minus = 0;
Nodo<char>* actual = lista.getInicio();
while (actual) {
if (isupper(actual->dato)) mayus++;
else
if (islower(actual->dato)) minus++;
actual = actual->siguiente;}}
int main() {
Lista<int> listaEnteros;
int n, valor;
cout << "Cantidad de numeros enteros: ";
cin >> n;
for (int i = 0; i < n; ++i) {
cout << "Numero " << i + 1 << ": ";
cin >> valor;
listaEnteros.agregar(valor);}
cout << "Lista de enteros: ";
listaEnteros.mostrar();
int primos = contarPrimos(listaEnteros);
cout << "Cantidad de numeros primos: " << primos << endl;
Lista<char> listaCaracteres;
char c;
cout << "Cantidad de caracteres: ";
cin >> n;
for (int i = 0; i < n; ++i) {
cout << "Caracter " << i + 1 << ": ";
cin >> c;
listaCaracteres.agregar(c);}
cout << "Lista de caracteres: ";
listaCaracteres.mostrar();
int mayus, minus;
contarMayusMinus(listaCaracteres, mayus, minus);
cout << "Mayusculas: " << mayus << ", Minusculas: " << minus << endl;
return 0;}
