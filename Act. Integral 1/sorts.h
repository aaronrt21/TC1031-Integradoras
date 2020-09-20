/*

Autor: Aarón Gonzalo Ramírez Tafolla - A01351621

Clase sorts usada para ordenar un vector de menor a mayor a través de varios métodos.

*/
#ifndef SORTS_H_
#define SORTS_H_

#include <vector>
#include <list>

template <class T>																					//Se crea la clase con un template para poder usar distintos tipos de datos.
class Sorts {
private:
	void swap(std::vector<T>&, int, int);															//Función para cambiar dos números de posición.
	void copyArray(std::vector<T>&, std::vector<T>&, int, int);										//Función para copiar un arreglo.
	void mergeArray(std::vector<T>&, std::vector<T>&, int, int, int);								//Función para juntar un pedazo del arreglo final de manera ordenada.
	void mergeSplit(std::vector<T>&, std::vector<T>&, int, int);									//Función para separar un pedazo del arreglo por la mitad.
	int auxBinaria(std::vector<T> src, const int val, int low, int high);							//Función auxiliar para la búsqueda binaria.
public:
	std::vector<T> ordenaMerge(std::vector<T>& v1);													//Función de ordenamiento por el método Merge que llama el usuario.
	int busqBinaria(std::vector<T>, const int);														//Función de búsqueda binaria que llama el usuario.
};

template <class T>																					//Swap toma dos elementos en un arreglo y los intercambia.
void Sorts<T>::swap(std::vector<T> &v, int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

template <class T>
void Sorts<T>::copyArray(std::vector<T> &A, std::vector<T> &B, int low, int high) {					//CopyArray hace una copia del vector para usarla en el ordenaMerge.
	for (int i = low; i <= high; i++) {																//El valor de B[0] se guardará en el de A[0] y así sucesivamente.
		A[i] = B[i];
	}
}

template <class T>
void Sorts<T>::mergeArray(std::vector<T> &A, std::vector<T> &B, int low, int mid, int high) {		
	int i, j, k;																					//Se crean variables para manejar los valores y límites de los arreglos.

	i = low;
	j = mid + 1;
	k = low;

	while (i <= mid && j <= high) {																	//Ciclo que, en base a su condicional, ajusta los límites del arreglo a manejar.
		if (A[i] < A[j]) {
			B[k] = A[i];																			
			i++;
		} else {
			B[k] = A[j];
			j++;
		}
		k++;
	}
	if (i > mid) {
		for (; j <= high; j++) {
			B[k++] = A[j];
		}
	} else {
		for (; i <= mid; i++) {
			B[k++] = A[i];
		}
	}
}

template <class T>
void Sorts<T>::mergeSplit(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	int mid;

	if ( (high - low) < 1 ) {																		//Caso base.
		return;
	}
	mid = (high + low) / 2;
	mergeSplit(A, B, low, mid);																		//Recursividad.
	mergeSplit(A, B, mid + 1, high);
	mergeArray(A, B, low, mid, high);																//Se manda a llamar la función anterior.
	copyArray(A, B, low, high);
}

template <class T>
std::vector<T> Sorts<T>::ordenaMerge(std::vector<T>& vector1) {//Función simplificada para el usuario.
	std::vector<T> v(vector1);
	std::vector<T> aux(v.size());																	//Arreglo auxiliar en donde se almacenarán los valores conforme se vayan juntando por medio de MergeArray para
																									//después pasarlos al vector v.
	mergeSplit(v, aux, 0, v.size() - 1);
	for(int i = 0; i < v.size();i++){
		vector1[i] = v[i];
	}
	return vector1;
}

template <class T>
int Sorts<T>::auxBinaria(std::vector<T> source, const int val, int low, int high) {					//Función que hace todo el trabajo para evitar que el usuario deba usar más de 2 valores de entrada.
    if (high >= low) { 																				//Comprobar que el arreglo tenga más de 1 elemento.
        int mid = (low + high) / 2; 																//Encontrar el valor medio para dividir el arreglo en dos.

        if (source[mid] == val){ 																	//Caso base. Si el valor del arreglo en mid es igual al valor buscado se regresa mid (el índice en donde se
            return mid;																				//encuentra ubicado).
		}

        if (source[mid] > val){																		//Compara el valor del arreglo en mid con el valor para saber en qué lado del arreglo se debe enfocar.
            return auxBinaria(source, val, low, mid - 1);											//Si source[mid] es más grande que val, quiere decir que val se encuentra en la mitad izquierda del arreglo (o no existe).
		}																							//Por esto, al llamarse la nueva función (recursividad) se le cambia el límite superior a mid-1.
  
        return auxBinaria(source, val, mid + 1, high); 												//Mismo razonamiento anterior, pero se cambia el límite inferior porque el valor se encuentra del lado derecho (o no existe).
    } 
	
	else {
		for(int i = 0; i < source.size();){															//Algoritmo que busca la posición en la que se debe de encontrar el valor después de encontrar que no existe en el arreglo.
			if (val > source[i]){
				i++;
			}
			else if (val < source[i]){
				i--;
				return i;
			}
		}
	}

} 

template < class T>
int Sorts<T>::busqBinaria(std::vector<T> source, const int valor){									//Función para el usuario. Recibe el vector y el valor que busca.
	return auxBinaria(source, valor, 0, source.size()-1);											//Se llama la función anterior.
}
#endif
