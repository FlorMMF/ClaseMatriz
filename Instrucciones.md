# ClaseMatriz

Elabore un proyecto de aplicación de consola en C++ que implemente una clase Matriz con las siguientes especificaciones:

La clase Matriz, debe contener los siguientes atributos privados:
Un número entero (puede ser unsigned) que represente el número de renglones de la matriz
Un número entero (puede ser unsigned) que represente el número de columnas de la matriz
Un puntero a un arreglo bidimensional dinámico para almacenar las entradas de la matriz

La clase Matriz debe ofrecer al cliente lo siguiente (interfaz de la clase):
Un constructor de dos parámetros: el número de renglones y columnas de la matriz. Deberán recibirse valores por default para ambos parámetros (puede ser 1). No debe permitirse la conversión de tipos (de entero a Matriz) implícita.  
*Un destructor  
*Un constructor de copias  
*El operador =   
Operadores para:  
*Suma de dos matrices  
*Resta de dos matrices  
*Producto de dos matrices  
*Producto de una matriz por un escalar  

Un método para calcular...  
*La transpuesta de una matriz  
*La inversa de una matriz cuadrada  
*Un método de redimensionamiento de una matriz. El método debe establecer las dimensiones de una matriz y modificar el arreglo dinámico para que se ajuste a las nuevas dimensiones. Si las dimensiones son más pequeñas, que trunque la matriz; si las dimensiones son más grandes, que rellene de ceros las entradas faltantes  
*Operadores para entrada y salida para flujos de datos: inserción (<<) y extracción (>>)  
*Un operador no miembro para el producto por escalar conmutativo

Además, implemente los métodos de utilería que considere necesarios.

OJO:   
*Las dimensiones de una matriz deben ser números positivos  
*Defina los métodos como const cuando sea apropiado  
*El proyecto deberá incluir el código cliente de la clase donde se pruebe cada recurso que esta ofrece  
*No olvide documentar debidamente cada elemento en la interfaz de la clase  
*No olvide la bitácora de trabajo  
