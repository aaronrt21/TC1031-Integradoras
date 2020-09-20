#ifndef SORTS_H_
#define SORTS_H_

#include <vector>
#include <list>

template <class T>																					//Se crea la clase con un template para poder usar distintos tipos de datos.
class Sorts {
private:
	void swap(std::vector<T>&, int, int);															//Función para cambiar dos números de posición.								
	int auxBinaria(std::vector<T> src, const int val, int low, int high);							//Función auxiliar para la búsqueda binaria.
public:
	std::vector<T> ordenaBurbuja(std::vector<T>& source1, std::vector <T>& source2);													//Función de ordenamiento por el método Burbuja que llama el usuario.
	int busqBinaria(std::vector<T>, const int);														//Función de búsqueda binaria que llama el usuario.
};

template <class T>																					//Swap toma dos elementos en un arreglo y los intercambia.
void Sorts<T>::swap(std::vector<T> &v, int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

template <class T>																					//OrdenaBurbuja organiza un vector moviendo dos índices juntos a lo largo de él y moviendo el valor más
std::vector<T> Sorts<T>::ordenaBurbuja(std::vector<T>& source1, std::vector <T>& source2) {									//pequeño a la izquierda por medio de un swap.
	std::vector<T> v(source1);
	std::vector <T> v2(source2);
	
	for (int i = v.size() - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (v[j] > v[j + 1]) {
				swap(v, j, j + 1);
				swap(v2, j, j + 1);
			}
		}
	}
	
	for (int i=0; i < v.size(); i++){
		source2[i]=v2[i];
	}
	
	return source2;
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
		return -1;
	}

} 

template < class T>
int Sorts<T>::busqBinaria(std::vector<T> source, const int valor){									//Función para el usuario. Recibe el vector y el valor que busca.
	return auxBinaria(source, valor, 0, source.size()-1);											//Se llama la función anterior.
}
#endif
