/*

Autor: Aarón Gonzalo Ramírez Tafolla - A01351621

Proyecto para la Unidad Formativa TC1031. El programa recibe un archivo con los ID's registrados en una base de datos y los guarda en un árbol heap.
El usuario puede decidir si quiere organizar el registro, realizar una búsqueda por ID específico o recibir todos los ID's existentes dentro
de un rango. Se utiliza el algoritmo Burbuja porque facilita la manipulación de los vectores con la función swap. El proyecto también manipula
archivos .txt, tanto para lectura como para escritura.

*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "sorts.h"
#include "heap.h"

using namespace std;

int main() {
	///.txt to String////////////////
	string line, idstr, edadestr, horastr, logrostr;
	//Se abre el archivo a leer.
	ifstream leer("ids.txt");
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
	
	
	///ID: STRING TO ARRAY//////////
	int idar[10] = {0};
	int j = 0, sum = 0;
	for (i = 0; idstr[i] != '\0'; i++) { 
        if (idstr[i] == ',') 
            j++; 
        else {  
            idar[j] = idar[j] * 10 + (idstr[i] - 48); 
        } 
    }
	
	///EDADES: STRING TO ARRAY//////////
	int edadar[10] = {0};
	j = 0; sum = 0;
	for (i = 0; edadestr[i] != '\0'; i++) { 
        if (edadestr[i] == ',') 
            j++; 
        else {  
            edadar[j] = edadar[j] * 10 + (edadestr[i] - 48); 
        } 
    }
	
	///HORAS: STRING TO ARRAY//////////
	int horasar[10] = {0};
	j = 0; sum = 0;
	for (i = 0; horastr[i] != '\0'; i++) { 
        if (horastr[i] == ',') 
            j++; 
        else {  
            horasar[j] = horasar[j] * 10 + (horastr[i] - 48); 
        } 
    }
	
	///LOGROS: STRING TO ARRAY//////////
	int logrosar[10] = {0};
	j = 0; sum = 0;
	for (i = 0; logrostr[i] != '\0'; i++) { 
        if (logrostr[i] == ',') 
            j++; 
        else {  
            logrosar[j] = logrosar[j] * 10 + (logrostr[i] - 48); 
        } 
    }
	
	///ID: ARRAY TO HEAP TREE///////////
	Heap<int> id(10);
	for (i = 0; i < 10; i++){
		id.push(idar[i]);
	}
    vector<int> idv;
	
	///HEAP TREE TO VECTOR//////////////
	//Se pasan los datos del árbol heap a un vector auxiliar para facilitar el ordenamiento.
	idstr = id.toString();
    stringstream ssid(idstr);
    for (i; ssid >> i;) {
        idv.push_back(i);    
        if (ssid.peek() == ',')
            ssid.ignore();
    }
	//Imprimir un menú para que el usuario escoja si quiere hacer el sort, hacer una búsqueda o salir.
	//Variables para manejar las selecciones del usuario.
	int option1 = 0, option2 = 0;
	
	//Variable de tipo Sorts<int> para manejar las búsquedas y los ordenamientos.
	Sorts<int> sorts;
	
	//Variable cont que se utiliza para indexar los valores de los archivos de salida.
	int cont = 0;
	
	while (option1 < 1 || option1 > 3){
		cout << "\n\nBienvenido.\nSeleccione lo que quiere hacer:\n";
		cout << "1. Ordenar la lista de ID's\n2. Buscar un ID\n3. Ejecutar casos de prueba\nRespuesta [1/2]: ";
		cin >> option1;
		
		///Ordenar la lista de ID's//////////
		if (option1 == 1){
			sorts.ordenaBurbuja(idv);
			//Se crea un archivo de salida.
			ofstream escribe("ordenamiento_id.txt");
			if (escribe.is_open()){
				//Ciclo for para escribir cada elemento del vector ordenado.
				escribe << "ID\n";
				for (i = 0; i < idv.size();i++){
					escribe << cont << ". " << idv[i] << "\n";
					cont++;
				}
				escribe.close();
			}
			else
				cout << "No es posible abrir el archivo.";
					
			cout << "\n\nPuede consultar el ordenamiento en el archivo ordenamiento_id.txt\n";
			return 0;
		}
		
		///Buscar por ID/////////////
		if(option1 == 2){
			//Se crea el valor1 que va a ser usado -escoja lo que escoja el usuario a partir de este punto- para realizar la búsqueda.
			int valor1;
			option2 = 0;
			sorts.ordenaBurbuja(idv);
			while(option2 < 1 || option2 > 2){
				//Menú para que el usuario escoja qué tipo de búsqueda desea realizar.
				cout << "\nBusqueda por ID: \n1. Busqueda de ID especifico\n2. Busqueda de ID dentro de un rango\n\nRespuesta [1/2]: ";
				cin >> option2;
				if(option2 == 1){
					//Búsqueda por ID específico.
					cout << "\nIntroduce el ID que desea buscar: ";
					cin >> valor1;
					//Se realiza una búsqueda binaria para encontrar el ID solicitado de manera eficiente.
					
					int i_result = sorts.busqBinaria(idv, valor1);
					if (i_result > -1){
						cout << "\n\nResultado:\nID\n";
						cout << cont << ". " << idv[i_result] << "\n";
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
					cout << "\n\nResultado:\nID\n";
					for (i = 0; i < idv.size(); i++){
							if ((idv[i] >= valor1) && (idv[i] <=valor2)){
								cout << cont << ". " << idv[i] << "\n";
								cont++;
							}
						}
					return 0;
					
					
				}
			}
		}
		if (option1 == 3){
			cout << "\n\n//////////CASOS DE PRUEBA//////////\n";
			
			cout << "---------------------------------\n"
			"Caso 1: Ordenamiento de ID's en la base de datos.\n"
				"Inputs: 1\n"
				"Output: Puede consultar el ordenamiento en el archivo ordenamiento_id.txt (Crea un archivo de salida)\n";
				sorts.ordenaBurbuja(idv);
				cont = 0;
				//Se crea un archivo de salida.
				ofstream escribe("ordenamiento_id.txt");
				if (escribe.is_open()){
					//Ciclo for para escribir cada elemento del vector ordenado.
					escribe << "ID\n";
					for (i = 0; i < idv.size();i++){
						escribe << cont << ". " << idv[i] << "\n";
						cont++;
					}
					escribe.close();
				}
				else
					cout << "No es posible abrir el archivo.";
			cout << "---------------------------------\n"
			"Caso 2: Buscar un ID especifico (cuando el ID no existe).\n"
				"Inputs: 2, 1, 13000\n"
				"Output:\n";
				int valor1 = 13000;
				int i_result = sorts.busqBinaria(idv, valor1);
				cont = 0;
					if (i_result > -1){
						cout << "\nResultado:\nID\n";
						cout << cont << ". " << idv[i_result] << "\n";
						cont++;
					}
					else {
						cout << "\nEl ID buscado no existe.\n";
					}
			cout << "---------------------------------\n"
			"Caso 3: Buscar un ID especifico (cuando el ID si existe). \n"
				"Inputs: 2, 1, 13654\n"
				"Output:\n";
				valor1 = 13654;
				cont = 0;
				i_result = sorts.busqBinaria(idv, valor1);
					if (i_result > -1){
						cout << "\nResultado:\nID\n";
						cout << cont << ". " << idv[i_result] << "\n";
						cont++;
					}
					else {
						cout << "\nEl ID buscado no existe.\n";
					}
			cout << "---------------------------------\n"
			"Caso 4: Buscar en un rango de ID's (ID's validos, input3 > input4)\n"
				"Inputs: 2, 2, 14000, 18000\n"
				"Output:\n";
				cont = 0;
				valor1 = 14000;
				int valor2 = 18000;
				cout << "\n\nResultado:\nID\n";
				for (i = 0; i < idv.size(); i++) {
					if ((idv[i] >= valor1) && (idv[i] <=valor2)){
						cout << cont << ". " << idv[i] << "\n";
						cont++;
					}
				}
			cout << "---------------------------------\n"
			"Caso 5: Buscar en un rango de ID's (ID's validos, input3 < input4)\n"
				"Inputs: 2, 2, 18000, 14000\n"
				"Output:\n";
				cont = 0;
				valor1 = 18000;
				valor2 = 14000;
				cout << "\n\nResultado:\nID\n";
				for (i = 0; i < idv.size(); i++) {
					if ((idv[i] >= valor1) && (idv[i] <=valor2)){
						cout << cont << ". " << idv[i] << "\n";
						cont++;
					}
				}
			cout << "---------------------------------\n"
			"Caso 6: Buscar en un rango de ID's (ID's no validos, sin importar el orden).\n"
				"Inputs: 2, 2, 10, 50\n"
				"Output:\n";
				cont = 0;
				valor1 = 10;
				valor2 = 50;
				cout << "\n\nResultado:\nID\n";
				for (i = 0; i < idv.size(); i++) {
					if ((idv[i] >= valor1) && (idv[i] <=valor2)){
						cout << cont << ". " << idv[i] << "\n";
						cont++;
					}
				}
				cout << "\nInputs: 2, 2, 50, 10\n"
				"Output: \n";
				cont = 0;
				valor1 = 50;
				valor2 = 10;
				cout << "\n\nResultado:\nID\n";
				for (i = 0; i < idv.size(); i++) {
					if ((idv[i] >= valor1) && (idv[i] <=valor2)){
						cout << cont << ". " << idv[i] << "\n";
						cont++;
					}
				}
			return 0;
		}
		
	}
	return 0;
}
