**Actividad Integral 4**

**Aarón Gonzalo Ramírez Tafolla - A01351621**

**Fecha de entrega: 19/11/2020**

Proyecto para la Unidad Formativa TC1031. El programa recibe un archivo con los ID's registrados en una base de datos y los guarda en un **árbol heap**.
El usuario puede decidir si quiere **ordenar** el registro, realizar una **búsqueda** por ID específico, recibir todos los ID's existentes dentro
de un rango o desplegar los amigos de cada usuario por medio de un **grafo**. Se utiliza el **algoritmo Burbuja** para el ordenamiento porque facilita la
manipulación de los vectores con la función swap. El proyecto también manipula archivos .txt, tanto para lectura como para escritura.
El programa incluye una opción para que el usuario ejecute los **casos de prueba**.

El programa incluye comentarios sobre el funcionamiento del mismo en cada etapa importante.

**Archivos necesarios:**

main.cpp

sorts.h

heap.h

graph.h

ids.txt

lista_amigos.txt

*Se incluye un archivo de texto con los datos ordenados como referencia para identificar cada ID de manera ordenada (indices_id.txt).

**Análisis de complejidad**

La complejidad general de 'main.cpp' es cuadrática. Aunque los condicionales if y ciclos while tienen complejidad constante (pues se rigen por valores de selección establecidos
por el usuario), el ordenamiento de los ID's hace que la complejidad general del progama sea O(n^2).

El programa 'sorts.h' tiene complejidad O(n^2) debido al manejo de los índices en el algoritmo de ordenamiento Burbuja.

El programa 'heap.h' tiene complejidad O(log(n)) debido a la naturaleza binaria de la estructura de datos.

El programa 'graph.h' tiene complejidad O(n) debido a que tiene que recorrer el documento 'lista_amigos' línea por línea para crear la estructura. También debe
avanzar de uno en uno dentro de un límite para desplegar la estructura usando la representación por lista de adyacencia.

**Casos de prueba**

El usuario puede ejecutar y visualizar cada caso de prueba dentro de la aplicación si corre el programa 'main.cpp' e introduce un '4' en el primer input.

Es importante que el usuario sólo introduzca números enteros. De lo contrario, el programa entrará en un bucle infinito y el usuario deberá reiniciarlo manualmente.
Para la búsqueda de ID's por rango, el usuario debe introducir el límite inferior del rango que desea buscar antes que el superior. De lo contrario no se generará
ningún resultado aunque los ID's sí existan en el archivo "ids.txt".

Si el usuario mete un valor que se encuentra fuera del rango especificado en las impresiones de los menús ("[1/2/3/4]" y "[1/2]") el programa le pedirá que
introduzca un valor nuevamente, pues el que introdujo no es válido.
