/*

Autor: Aarón Gonzalo Ramírez Tafolla - A01351621

Proyecto para la Unidad Formativa TC1031. El programa recibe un archivo con los registros de varios jugadores. Cada jugador tiene registrado un ID, su edad y las horas jugadas.
El usuario puede decidir si quiere organizar alguno de los registros mencionados anteriormente o realizar una búsqueda por ID específico o recibir todos los ID's existentes dentro
de un rango. El proyecto utiliza el arlgoritmo de ordenamiento por burbuja porque, aunque Merge es más eficiente con valores aleatorios, Burbuja maneja una complejidad lineal (o(n))
en el mejor de los casos (a diferencia de Merge, que maneja una complejidad nlog(n)). Además, facilita la manipulación de los vectores con la función swap. AEl proyecto también manipula
archivos .txt, tanto para lectura como para escritura.

*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "sorts.h"
#include "dlist.h"

using namespace std;

int main() {
	///.txt to String////////////////
	string line, idstr, edadestr, horastr, logrostr;
	//Se abre el archivo a leer.
	ifstream leer("datos.txt");
	int i = 0;
	if (leer.is_open()){
		//Se asignan los caracteres de cada línea a strings específicos antes de que se sobrescriba la variable line.
		while(getline(leer, line)){		
			if (i == 0){
				idstr = line;
			}
			if (i == 1){
				edadestr = line;
			}
			
			if (i == 2){
				horastr = line;
			}
			
			if (i == 3){
				logrostr = line;
			}
			i++;
		}
		leer.close();
	}
	else
		cout << "No es posible abrir el archivo.";
	
	
	///ID: String to Vector//////////
    vector<int> ids;
    stringstream ssid(idstr);
	//Se introduce cada caracter del string. Se pasa al siguiente indice del vector cuando encuentra una coma, ignorándola en el proceso.
    for (int i; ssid >> i;) {
        ids.push_back(i);    
        if (ssid.peek() == ',')
            ssid.ignore();
    }

	///Edad: String to Vector////////
    vector<int> edades;
    stringstream ssed(edadestr);

    for (int i; ssed >> i;) {
        edades.push_back(i);    
        if (ssed.peek() == ',')
            ssed.ignore();
    }
	
	///Horas: String to Vector///////
    vector<int> horas;
    stringstream ssho(horastr);

    for (int i; ssho >> i;) {
        horas.push_back(i);    
        if (ssho.peek() == ',')
            ssho.ignore();
    }
	
	///Logros: String to Vector//////
    vector<int> logros;
    stringstream sslo(logrostr);

    for (int i; sslo >> i;) {
        logros.push_back(i);    
        if (sslo.peek() == ',')
            sslo.ignore();
    }
	
	
	///ID: Vector to DList///////////
	DList<int> ids_lista;
	for (i = 0; i < ids.size(); i++){
		ids_lista.add(ids[i]);
	}
	
	///Edades: Vector to DList///////
	DList<int> edades_lista;
	for (i = 0; i < edades.size(); i++){
		edades_lista.add(edades[i]);
	}
	
	///Horas: Vector to DList////////
	DList<int> horas_lista;
	for (i = 0; i < horas.size(); i++){
		horas_lista.add(horas[i]);
	}
	
	///Logros: Vector to DList///////
	DList<int> logros_lista;
	for (i = 0; i < logros.size(); i++){
		logros_lista.add(logros[i]);
	}
	//Se crean copias de los vectores originales para manejar sus índices con el vector temporal para el sort.
	vector<int> orig_ids = ids;
	vector<int> orig_edades = edades;
	vector<int> orig_horas = horas;
	vector<int> orig_logros = logros;
	/////////////////////////////////

	//Imprimir un menú para que el usuario escoja si quiere hacer el sort, hacer una búsqueda o salir.
	//Variables para manejar las selecciones del usuario.
	int option1 = 0, option2 = 0;
	
	//Variable de tipo Sorts<int> para manejar las búsquedas y los ordenamientos.
	Sorts<int> sorts;
	
	//Variable cont que se utiliza para indexar los valores de los archivos de salida.
	int cont = 0;
	while (option1 < 1 || option1 > 2){
		cout << "\n\nBienvenido.\nSeleccione lo que quiere hacer:\n";
		cout << "1. Ordenar la lista\n2. Buscar por ID\n\nRespuesta [1/2]: ";
		cin >> option1;
		
		///Ordenar la lista//////////
		if (option1 == 1){
			//Seleccionar el atributo a ordenar (ID, edad u horas jugadas)
			while (option2 < 1 || option2 > 4){
				cout << "\n\nSeleccione el atributo que quiere ordenar en la lista:\n1. ID\n2. Edad del jugador\n3. Horas jugadas\n4. Cantidad de Logros Desbloqueados\n\nRespuesta [1/2/3/4]: ";
				cin >> option2;
				
				//Ordenar los ID's.
				if (option2 == 1) {
					//Se hace un ordenamiendo de Burbuja con vectores auxiliares. Se ordenan los valores de la lista y se actualiza.
					sorts.ordenaBurbuja(orig_ids, ids);
					sorts.ordenaBurbuja(orig_ids, edades);
					sorts.ordenaBurbuja(orig_ids, horas);
					sorts.ordenaBurbuja(orig_ids, logros);
					//Se actualizan las listas. Ahora están ordenadas por ID de forma ascendente.
					///ID
					for (i = 0; i < ids.size(); i++){
						//Se actualiza el índice de la lista con el valor que está en ese índice en el vector auxiliar ordenado.
						ids_lista.update(i, ids[i]);
					}
					
					///Edades
					for (i = 0; i < edades.size(); i++){
						edades_lista.update(i, edades[i]);
					}
					
					///Horas
					for (i = 0; i < horas.size(); i++){
						horas_lista.update(i, horas[i]);
					}
					
					///Logros
					for (i = 0; i < logros.size(); i++){
						logros_lista.update(i, logros[i]);
					}
					//Se crea un archivo de salida.
					ofstream escribe("ordenamiento_id.txt");
					if (escribe.is_open()){
						//Ciclo for para escribir cada elemento del vector ordenado.
						escribe << "ID | Edad | Horas jugadas | Logros Desbloqueados\n";
						for (i = 0; i < ids.size();i++){
							escribe << cont << ". " << ids_lista.readVal(i) << " | " << edades_lista.readVal(i) << " | " << horas_lista.readVal(i) << " | " << logros_lista.readVal(i) << "\n";
							cont++;
						}
						escribe.close();
					}
					else
						cout << "No es posible abrir el archivo.";
					
					cout << "\n\nPuede consultar el ordenamiento en el archivo ordenamiento_id.txt\n";
					return 0;
				}
				
				//Ordenar las edades.
				else if (option2 == 2) {
					//Se hace un ordenamiento con burbuja porque, aunque Merge es más eficiente con valores aleatorios, Burbuja maneja una complejidad lineal
					//en el mejor de los casos, además de facilitar la manipulación de los vectores con la función swap.
					sorts.ordenaBurbuja(orig_edades, ids);
					sorts.ordenaBurbuja(orig_edades, edades);
					sorts.ordenaBurbuja(orig_edades, horas);
					sorts.ordenaBurbuja(orig_horas, logros);
					//Se actualizan las listas. Ahora están ordenadas por edad de forma ascendente.
					///ID
					for (i = 0; i < ids.size(); i++){
						//Se actualiza el índice de la lista con el valor que está en ese índice en el vector auxiliar ordenado.
						ids_lista.update(i, ids[i]);
					}
					
					///Edades
					for (i = 0; i < edades.size(); i++){
						edades_lista.update(i, edades[i]);
					}
					
					///Horas
					for (i = 0; i < horas.size(); i++){
						horas_lista.update(i, horas[i]);
					}
					
					///Logros
					for (i = 0; i < logros.size(); i++){
						logros_lista.update(i, logros[i]);
					}
					//Se crea un archivo de salida.
					ofstream escribe("ordenamiento_edad.txt");
					if (escribe.is_open()){
						//Ciclo for para escribir cada elemento del vector ordenado.
						escribe << "ID | Edad | Horas jugadas | Logros Desbloqueados\n";
						for (i = 0; i < ids.size();i++){
							escribe << cont << ". " << ids_lista.readVal(i) << " | " << edades_lista.readVal(i) << " | " << horas_lista.readVal(i) << " | " << logros_lista.readVal(i) << "\n";
							cont++;
						}
						escribe.close();
					}
					else
						cout << "No es posible abrir el archivo.";
					
					cout << "\n\nPuede consultar el ordenamiento en el archivo ordenamiento_edad.txt\n";
					return 0;
				}
				
				//Ordenar las horas de juego.
				else if (option2 == 3) {
					//Se hace un ordenamiento con burbuja porque, aunque Merge es más eficiente con valores aleatorios, Burbuja maneja una complejidad lineal
					//en el mejor de los casos, además de facilitar la manipulación de los vectores con la función swap.
					sorts.ordenaBurbuja(orig_horas, ids);
					sorts.ordenaBurbuja(orig_horas, edades);
					sorts.ordenaBurbuja(orig_horas, horas);
					sorts.ordenaBurbuja(orig_horas, logros);
					//Se actualizan las listas. Ahora están ordenadas por horas de forma ascendente.
					///ID
					for (i = 0; i < ids.size(); i++){
						//Se actualiza el índice de la lista con el valor que está en ese índice en el vector auxiliar ordenado.
						ids_lista.update(i, ids[i]);
					}
					
					///Edades
					for (i = 0; i < edades.size(); i++){
						edades_lista.update(i, edades[i]);
					}
					
					///Horas
					for (i = 0; i < horas.size(); i++){
						horas_lista.update(i, horas[i]);
					}
					
					///Logros
					for (i = 0; i < logros.size(); i++){
						logros_lista.update(i, logros[i]);
					}
					//Se crea un archivo de salida.
					ofstream escribe("ordenamiento_horas.txt");
					if (escribe.is_open()){
						//Ciclo for para escribir cada elemento del vector ordenado.
						escribe << "ID | Edad | Horas jugadas | Logros Desbloqueados\n";
						for (i = 0; i < ids.size();i++){
							escribe << cont << ". " << ids_lista.readVal(i) << " | " << edades_lista.readVal(i) << " | " << horas_lista.readVal(i) << " | " << logros_lista.readVal(i) << "\n";
							cont++;
						}
						escribe.close();
					}
					else
						cout << "No es posible abrir el archivo.";
					
					cout << "\n\nPuede consultar el ordenamiento en el archivo ordenamiento_horas.txt\n";
					return 0;
				}
				
				//Ordenar por cantidad de logros desbloqueados.
				else if (option2 == 4) {
					//Se hace un ordenamiento con burbuja porque, aunque Merge es más eficiente con valores aleatorios, Burbuja maneja una complejidad lineal
					//en el mejor de los casos, además de facilitar la manipulación de los vectores con la función swap.
					sorts.ordenaBurbuja(orig_logros, ids);
					sorts.ordenaBurbuja(orig_logros, edades);
					sorts.ordenaBurbuja(orig_logros, horas);
					sorts.ordenaBurbuja(orig_logros, logros);
					//Se actualizan las listas. Ahora están ordenadas por número de logros de forma ascendente.
					///ID
					for (i = 0; i < ids.size(); i++){
						//Se actualiza el índice de la lista con el valor que está en ese índice en el vector auxiliar ordenado.
						ids_lista.update(i, ids[i]);
					}
					
					///Edades
					for (i = 0; i < edades.size(); i++){
						edades_lista.update(i, edades[i]);
					}
					
					///Horas
					for (i = 0; i < horas.size(); i++){
						horas_lista.update(i, horas[i]);
					}
					
					///Logros
					for (i = 0; i < logros.size(); i++){
						logros_lista.update(i, logros[i]);
					}
					//Se crea un archivo de salida.
					ofstream escribe("ordenamiento_logros.txt");
					if (escribe.is_open()){
						//Ciclo for para escribir cada elemento del vector ordenado.
						escribe << "ID | Edad | Horas jugadas | Logros Desbloqueados\n";
						for (i = 0; i < ids.size();i++){
							escribe << cont << ". " << ids_lista.readVal(i) << " | " << edades_lista.readVal(i) << " | " << horas_lista.readVal(i) << " | " << logros_lista.readVal(i) << "\n";
							cont++;
						}
						escribe.close();
					}
					else
						cout << "No es posible abrir el archivo.";
					
					cout << "\n\nPuede consultar el ordenamiento en el archivo ordenamiento_logros.txt\n";
					return 0;
				}
			}
		}
		
		///Buscar por ID/////////////
		if(option1 == 2){
			//Se crea el valor1 que va a ser usado -escoja lo que escoja el usuario a partir de este punto- para realizar la búsqueda.
			int valor1;
			option2 = 0;
			sorts.ordenaBurbuja(orig_ids, ids);
			sorts.ordenaBurbuja(orig_ids, edades);
			sorts.ordenaBurbuja(orig_ids, horas);
			sorts.ordenaBurbuja(orig_ids, logros);
			//Se actualizan las listas. Ahora están ordenadas por horas de forma ascendente.
			///ID
			for (i = 0; i < ids.size(); i++){
				//Se actualiza el índice de la lista con el valor que está en ese índice en el vector auxiliar ordenado.
				ids_lista.update(i, ids[i]);
			}
			
			///Edades
			for (i = 0; i < edades.size(); i++){
				edades_lista.update(i, edades[i]);
			}
			
			///Horas
			for (i = 0; i < horas.size(); i++){
				horas_lista.update(i, horas[i]);
			}
					
			///Logros
			for (i = 0; i < logros.size(); i++){
				logros_lista.update(i, logros[i]);
			}
			
			while(option2 < 1 || option2 > 2){
				//Menú para que el usuario escoja qué tipo de búsqueda desea realizar.
				cout << "\nBusqueda por ID: \n1. Busqueda de ID especifico\n2. Busqueda de ID dentro de un rango\n\nRespuesta [1/2]: ";
				cin >> option2;
				if(option2 == 1){
					//Búsqueda por ID específico.
					cout << "\nIntroduce el ID que desea buscar: ";
					cin >> valor1;
					//Se realiza una búsqueda binaria para encontrar el ID solicitado de manera eficiente.
					
					int i_result = sorts.busqBinaria(ids, valor1);
					if (i_result > -1){
						cout << "\n\nResultado:\nID | Edad | Horas jugadas | Logros Desbloqueados\n";
						cout << cont << ". " << ids_lista.readVal(i_result) << " | " << edades_lista.readVal(i_result) << " | " << horas_lista.readVal(i_result) << " | " << logros_lista.readVal(i_result) << "\n";
						cont++;
					}
					else {
						cout << "\nEl ID buscado no existe.\n";
					}
				}
				if(option2 == 2){
					//Se crea un valor2 que sólo es utilizado si el usuario pide una búsqueda por rangos.
					int valor2;
					cout << "\nIntroduce el primer ID en el rango a buscar: ";
					cin >> valor1;
					cout << "\nIntroduce el segundo ID en el rango a buscar: ";
					cin >> valor2;
					
					//Verificar que el id entre en el rango solicitado por el usuario.
					cout << "\n\nResultado:\nID | Edad | Horas jugadas | Logros Desbloqueados\n";
					for (i = 0; i < ids.size(); i++){
							if ((ids[i] >= valor1) && (ids[i] <=valor2)){
								cout << cont << ". " << ids_lista.readVal(i) << " | " << edades_lista.readVal(i) << " | " << horas_lista.readVal(i) << " | " << logros_lista.readVal(i) << "\n";
								cont++;
							}
						}
					return 0;
					
					
				}
			}
		}
		
	}
	
	return 0;
}