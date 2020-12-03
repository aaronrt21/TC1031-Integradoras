/*

Autor: Aarón Gonzalo Ramírez Tafolla - A01351621

Proyecto para la Unidad Formativa TC1031. en el proyecto se implementa una estructura Skip List. La estructura Skip List sirve un propósito similar a la lista ligada simple, con la diferencia de
que esta cuenta con varios niveles para saltarse elementos al momento de insertar, eliminar o buscar elementos de la lista. De esta forma, la complejidad puede reducirse a O(logn), aunque en el peor
de los casos la complejidad sigue siendo O(n). En el main se presenta la forma en la que se usa esta estructura. Deibdo a que la estructura maneja valores aleatorios para los niveles superiores al
0, no se puede manejar un caso de prueba específico.

*/

#include "skiplist.h"

int main() 
{ 
	//Se utiliza la función srand para que los elementos de niveles mayores a 0 no tengan los mismos valores la próxima vez que se ejecute el programa.
    srand((unsigned)time(0)); 
	
	//Se crean las listas. El primer número indica el nivel máximo que va a alcanzar la lista. El segundo valor indica la probabilidad de cada valor de ser agregado al siguiente nivel.
    SkipList s_lista1(1, 0.3); 
	SkipList s_lista2(3, 0.5);
	//Se insertan valores a la lista 1.
    s_lista1.insert(9); s_lista1.insert(10); s_lista1.insert(41); s_lista1.insert(2); s_lista1.insert(6); 
    s_lista1.insert(71); s_lista1.insert(62); s_lista1.insert(12); s_lista1.insert(52); s_lista1.insert(20); 
	
	//Se insertan valores a la lista 2.
	s_lista2.insert(35); s_lista2.insert(87); s_lista2.insert(2); s_lista2.insert(17); s_lista2.insert(76); 
    s_lista2.insert(14); s_lista2.insert(20); s_lista2.insert(26); s_lista2.insert(22); s_lista2.insert(19); 
	
	//Se imprime la lista 1
	cout << "\n\n--------------------Lista 1--------------------\n";
	s_lista1.printList();
	
	//Se busca un valor que no existe en la lista 1.
    s_lista1.search(18); 
	
	//Se busca un valor que sí existe en la lista 1.
	s_lista1.search(12);
  
    //Se elimina el 10 de la lista y se imprime de nuevo para demostrar que ya no existe.
    s_lista1.remove(10);
	cout << "\n\n--------------------Lista 1 (nueva)--------------------\n";
    s_lista1.printList();
	
	//Se imprime la lista 2
	cout << "\n\n--------------------Lista 2--------------------\n";
	s_lista2.printList();
	
	//Se busca un valor que no existe en la lista 2.
    s_lista2.search(21); 
	
	//Se busca un valor que sí existe en la lista 2.
	s_lista2.search(22);
  
    //Se elimina el 22 de la lista y se imprime de nuevo para demostrar que ya no existe.
    s_lista2.remove(22); 
	cout << "\n\n--------------------Lista 2 (nueva)--------------------\n";
    s_lista2.printList();
  
    
	
	return 0;
} 