**Actividad Integral 6**

**Aarón Gonzalo Ramírez Tafolla - A01351621**

**Fecha de entrega: 03/12/2020**

Proyecto para la Unidad Formativa TC1031. En el proyecto se implementa una estructura Skip List. 

**Archivos necesarios:**

main.cpp

skiplist.h

**Análisis de complejidad**

La complejidad general de 'main.cpp' es O(n) ya que sólo usa las funciones skiplist, cuya complejidad es lineal.

El programa 'skiplist.h' tiene complejidad O(n). Si bien la naturaleza aleatoria de la estructura abre la posibilidad de generar una complejidad
O(logn), en el peor de los casos, todos los valores se agregarían a los niveles superiores, lo cual no traería ningún beneficio al realizar inserciones, búsquedas
ni eliminaciones porque se tendría que pasar por cada valor 1 a 1.

**Casos de prueba**

Debido a que la estructura maneja valores aleatorios para los niveles superiores al 0, no se puede manejar un caso de prueba específico. Cada vez que se ejecute el
programa, los valores dentro de los niveles superiores al 0 serán distintos.

**¿Para qué sirve la estructura?**

La estructura Skip List sirve un propósito similar a la lista ligada simple, con la diferencia de que esta cuenta con varios niveles para saltarse
elementos al momento de insertar, eliminar o buscar elementos de la lista. Esto permite ahorrar tiempo cuando se tiene una lista de muchos datos, pues en lugar
de tener que realizar una búsqueda 1 a 1, puedes brincarte muchos de los valores usando los de niveles superiores y continuar la búsqueda 1 a 1 a partir de un valor
más cercano al que necesita el usuario.

**Aplicaciones**

La estructura Skip List funge como alternativa probabilística a un árbol. En un árbol, si no se aplican las condicionales adecuadas, se puede dar un árbol degenerado
si se insertan elementos ordenados (1, 2, 3, 4, 5, etc.), lo cual hace que la complejidad sea lineal. Sin embargo, en una Skip List, aunque la lista esté en orden,
los niveles superiores darán valores que permitan dividirla y reducir el tiempo de inserción, eliminación y búsqueda a O(logn) en el caso promedio.

**Fuentes**

*https://en.wikipedia.org/wiki/Skip_list
*https://homepage.cs.uiowa.edu/~ghosh/skip.pdf
*https://www.javatpoint.com/skip-list-in-data-structure
*https://brilliant.org/wiki/skip-lists/
*https://www.youtube.com/watch?v=ypod5jeYzAU
