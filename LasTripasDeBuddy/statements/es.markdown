# Descripción.

Buddy y su entrañable amigo perruno CJ, están jugando al famoso juego <i>el juego del gato</i>. A ambos les gustan los juegos largos, por lo que juegan en un tablero de $n\times n$ hasta que todos los cuadros del tablero contengan una <i>X</i> o una <i>O</i>, incluso si en algún momento ya hay un ganador. 

Como Buddy quiere evitar la fatiga, y CJ odia a los gatos, te han pedido tu ayuda para saber si al final del juego existe un ganador o si hay un empate.

Existe un ganador si una misma fila, columna o diagonal consta únicamente de símbolos de un mismo tipo (únicamente <i>X</i> u <i>O</i>), de lo contrario, ambos perros habrán empatado.

# Entrada.

La primera línea de entrada contiene un único número $n$: las dimensiones del tablero.

Las siguientes $n^2$ líneas describen el siguiente movimiento de cada perro: cada una contiene dos números $x_i, y_i$ ($1\leq x_i,y_i\leq n$) que representan la fila y la columna respectivamente donde pondrán su próxima figura. 

El primer turno siempre será de Buddy, el siguiente turno luego de cada movimiento de Buddy es de CJ, y el siguiente turno luego de cada movimiento de CJ es de Buddy.

# Salida.

Deberás imprimir en una sola línea el resultado del juego:

* <i>"Empate!"</i> (sin las comillas) si ningún perro ganó el juego.
* <i>"El ganador es Buddy!"</i> si Buddy ganó el juego.
* <i>"El ganador es CJ!</i> si CJ ganó el juego.

# Ejemplo

||input
3
1 1
2 2
3 3
2 3
2 1
3 1
1 3
1 2
3 2


||output
Empate!
||description
El tablero queda al final:
XOX

XOO

OXX

No hay forma válida de que haya un ganador, por lo tanto es un empate.
||end

# Consideraciones.

* $3\leq n\leq 101$
* $n$ siempre es un número impar.
* No hay tablero en el que ganen ambos perros.

#Buddy te recuerda.
Que CJ odia a los gatos.
