**Aarón Gonzalo Ramírez Tafolla - A01351621**

**Fecha de entrega: 21/09/2020**

Proyecto para la Unidad Formativa TC1031. El programa recibe un archivo con los registros de varios jugadores. Cada jugador tiene registrado un ID, su edad y las horas jugadas.
El usuario puede decidir si quiere organizar alguno de los registros mencionados anteriormente o realizar una búsqueda por ID específico o recibir todos los ID's existentes dentro
de un rango. El proyecto utiliza el arlgoritmo de ordenamiento por burbuja porque, aunque Merge es más eficiente con valores aleatorios, Burbuja maneja una complejidad lineal (o(n))
en el mejor de los casos (a diferencia de Merge, que maneja una complejidad nlog(n)). Además, facilita la manipulación de los vectores con la función swap. AEl proyecto también manipula
archivos .txt, tanto para lectura como para escritura.

El programa incluye comentarios sobre el funcionamiento del mismo en cada etapa importante.

**Archivos necesarios:**

main.cpp

sorts.h

datos.txt

*Se incluye un archivo de texto con los datos ordenados como referencia para identificar cada ID con sus respectivos atributos de manera ordenada.

**Funciones del usuario y casos de prueba**

Todos las entradas del usuario tienen que ser números enteros, de lo contrario el programa entra en un bucle infinito y el usuario deberá reiniciarlo.

**Búsqueda por rangos de ID's**

Para que la función de búsqueda por rangos de ID's funcione de manera esperada, se recomienda al usuario introducir el límite más pequeño primero y el más
grande después. De lo contrario regresará una búsqueda vacía.
