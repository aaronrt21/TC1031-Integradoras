**Actividad Integral 2**

**Aarón Gonzalo Ramírez Tafolla - A01351621**

**Fecha de entrega: 08/10/2020**
Proyecto para la Unidad Formativa TC1031. El programa recibe un archivo con los registros de varios jugadores y los guarda en listas doblemente anidadas. 
Cada jugador tiene registrado un ID, su edad, las horas jugadas y la cantidad de logros desbloqueados. El usuario puede decidir si quiere organizar alguno de los
registros mencionados anteriormente o realizar una búsqueda por ID específico o recibir todos los ID's existentes dentro de un rango. El proyecto utiliza el arlgoritmo
de ordenamiento por burbuja porque, aunque Merge es más eficiente con valores aleatorios, Burbuja maneja una complejidad lineal (o(n)) en el mejor de los casos
(a diferencia de Merge, que maneja una complejidad nlog(n)). Además, facilita la manipulación de los vectores auxiliares con la función swap. El proyecto también
manipula archivos .txt, tanto para lectura como para escritura.

El programa incluye comentarios sobre el funcionamiento del mismo en cada etapa importante.

**Archivos necesarios:**

main.cpp

sorts.h

dlist.h

exception.h

datos.txt

*La autoría del documento exception.h es del profesor Pedro Óscar Pérez Murrieta
**Se incluye un archivo de texto con los datos ordenados como referencia para identificar cada ID con sus respectivos atributos de manera ordenada (DatosOrd.txt).

**Casos de prueba**
Es importante que el usuario sólo introduzca números enteros. De lo contrario, el programa entrará en un bucle infinito y el usuario deberá reiniciarlo manualmente.

**Primer caso: ordenamiento de la lista por ID.**
Inputs: 1 1
Output: Archivo "ordenamiento_id.txt"

**Segundo caso: ordenamiento de la lista por Edad.**
Inputs: 1 2
Output: Archivo "ordenamiento_edad.txt"

**Tercer caso: ordenamiento de la lista por Horas.**
Inputs: 1 3
Output: Archivo "ordenamiento_horas.txt"

**Cuarto caso: ordenamiento de la lista por logros.**
Inputs: 1 4
Output: Archivo "ordenamiento_logros.txt"

**Quinto caso: búsqueda de perfil por ID específico (ID sí existe).**
Inputs: 2 1 12789
Output:
Resultado:
ID | Edad | Horas jugadas | Logros Desbloqueados
0. 12789 | 31 | 23 | 17
