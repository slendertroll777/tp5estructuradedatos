void enigma(Nodo* nodo) 
{ 
	if(nodo!=nullptr) 
		if(nodo->getSiguiente() == nullptr) 
		cout << nodo->getDato() << endl; 
		else{ 
		enigma(nodo->getSiguiente()); 
		cout << nodo->getDato() << endl; 
		} 
}
//Enigma: muestra la lista de manera inversa

int misterio (Nodo* nodo) 
{ 
	if(nodo == nullptr) 
		return 0; 
	else 
		return misterio(nodo->getSiguiente()) + 1; 
} 

//Misterio devuelve la cantidad de elementos de la lista
Nodo* desconocido(Nodo* nodo) 
{ 
	if(nodo == nullptr || nodo ->getSiguiente() == 
	   nullptr) 
		return nodo; 
	else 
		return desconocido(nodo->getSiguiente()); 
} 
//desconocido devuelve el último nodo de la lista
