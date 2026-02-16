Torres_de_Hanoi
Diseño de Clases – Problema de las Torres de Hanoi

Este proyecto implementa el problema clásico de las Torres de Hanoi mediante programación orientada a objetos en C++. La solución se basa en una estructura compuesta por tres clases principales: Disco, Torre y Hanoi.

La clase Disco representa cada uno de los discos del problema. Cada disco posee un tamaño determinado que permite comprobar que no se coloque un disco grande encima de uno más pequeño, respetando así las reglas del juego. Dispone de un atributo entero que indica su tamaño, donde el valor 1 representa el disco más pequeño y el valor N el más grande. Incluye un constructor para inicializar el tamaño y un método getTamano() que devuelve dicho valor.

La clase Torre representa cada uno de los tres palos del problema, identificados como A, B y C. Internamente utiliza una estructura de datos tipo pila (stack), ya que solo puede accederse al disco superior en cada momento. Esta elección permite modelar correctamente las restricciones del problema. La clase contiene un atributo de tipo carácter que identifica la torre y una pila de discos que almacena los elementos siguiendo el comportamiento LIFO (Last In, First Out). Entre sus métodos se encuentran el constructor que inicializa el nombre de la torre, apilar() para añadir un disco en la parte superior, desapilar() para eliminar y devolver el disco superior, cima() para consultar el disco superior sin eliminarlo, vacia() para comprobar si la torre está vacía y getNombre() para obtener su identificador.

La clase Hanoi contiene la lógica recursiva necesaria para resolver el problema. Dispone de un atributo entero N que indica el número total de discos, tres objetos de tipo Torre que representan la torre de origen, la torre auxiliar y la torre de destino, y un contador que registra el número total de movimientos realizados. El constructor inicializa las tres torres y coloca los N discos en la torre de origen. El método resolver() inicia el proceso llamando a la función recursiva. La función hanoiRec() implementa el algoritmo clásico: si el número de discos es uno, se mueve directamente el disco al destino; en caso contrario, se trasladan primero los n-1 discos a la torre auxiliar, luego se mueve el disco restante al destino y finalmente se trasladan los n-1 discos desde la torre auxiliar al destino. El método moverDisco() realiza físicamente el movimiento entre torres y muestra por pantalla cada paso realizado.

El archivo principal main se encarga de solicitar al usuario el número de discos, crear un objeto de la clase Hanoi y llamar al método resolver() para ejecutar el algoritmo completo.

Estructura del proyecto

El proyecto se organiza en carpetas separadas para mantener una estructura clara y profesional. Los archivos de cabecera se encuentran en la carpeta include, mientras que los archivos de implementación y el archivo principal se ubican en la carpeta src. Además, se incluye la carpeta .vscode con la configuración necesaria para compilar y depurar el programa.

Justificación del diseño

La utilización de la estructura de datos tipo pila en la clase Torre es adecuada porque solo se puede mover un disco cada vez, únicamente es accesible el disco situado en la parte superior y se respeta el principio LIFO. De esta forma, la implementación refleja fielmente las reglas originales del problema y facilita la aplicación del algoritmo recursivo.
