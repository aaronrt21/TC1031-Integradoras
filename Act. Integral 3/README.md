**Actividad Integral 3**

**Aarón Gonzalo Ramírez Tafolla - A01351621**

**Fecha de entrega: 02/11/2020**

Proyecto para la Unidad Formativa TC1031. El proyecto busca comprobar la existencia de un ID dentro de una base de datos, sin importar los datos asociados a este.
Recibe un archivo con los ID's registrados en una base de datos y los guarda en un árbol heap.
El usuario puede decidir si quiere organizar el registro, realizar una búsqueda por ID específico o recibir todos los ID's existentes dentro
de un rango. Se utiliza el algoritmo Burbuja porque facilita la manipulación de los vectores con la función swap. El proyecto también manipula
archivos .txt, tanto para lectura como para escritura. El programa incluye una opción para que el usuario ejecute los casos de prueba.

El programa incluye comentarios sobre el funcionamiento del mismo en cada etapa importante.

**Análisis de complejidad**

La complejidad general de main.cpp es cuadrática. Aunque los condicionales if y ciclos while tienen complejidad constante (pues se rigen por valores establecidos
por el usuario), el ordenamiento de los ID's hace que la complejidad general del progama sea O(n^2).

El programa 'sorts.h' tiene complejidad O(n^2) debido al manejo de los índices en el algoritmo de ordenamiento Burbuja.

El programa 'heap.h' tiene complejidad O(log(n)) debido a la naturaleza binaria de la estructura de datos.

**Archivos necesarios:**

main.cpp

sorts.h

heap.h

exception.h

ids.txt

*La autoría del documento exception.h es del profesor Pedro Óscar Pérez Murrieta

**Se incluye un archivo de texto con los datos ordenados como referencia para identificar cada ID con sus respectivos atributos de manera ordenada (ids_ans.txt).

**Casos de prueba**
El usuario puede ejecutar y visualizar cada caso de prueba dentro de la aplicación si introduce un '3' en el primer input.

Es importante que el usuario sólo introduzca números enteros. De lo contrario, el programa entrará en un bucle infinito y el usuario deberá reiniciarlo manualmente.
Para la búsqueda de ID's por rango, el usuario debe introducir el límite inferior del rango que desea buscar antes que el superior. De lo contrario no se generará
ningún resultado aunque los ID's sí existan en el archivo "ids.txt".

Si el usuario mete un valor que se encuentra fuera del rango especificado en las impresiones de los menús ("[1/2/3]" y "[1/2/3/4]") el programa le pedirá que
introduzca un valor nuevamente, pues el que introdujo no es válido.
