# Descripción.

Cansado Buddy de comer solo croquetas, decidió cambiar su dieta alimenticia por una más rica en proteinas. Fue así como decidió comer únicamente chicharrones por el resto de su vida. Sin embargo, al llegar a la tienda a comprar chicharrones el vendedor le dijo:

<i>Si chicharrones quieres, resolver mi ecuación debes</i>

Como Buddy no tiene pulgares el solo sabe contar en un sistema de numeración en base 8, por lo que te ha pedido tu ayuda para resolver la ecuación del vendedor para que pueda comprar su chicharrón.

# Entrada.

La entrada consiste en una única línea con la ecuación en el formato <i>(x+$a$)(x+$b$)=$c$</i> en donde $a, b $ y $c$ son 3 números enteros.

# Salida.

Como es una ecuación cuadrática entonces tiene 2 soluciones. Deberás imprimir una sola línea con el resultado en el formato <i>x1= $i$ x2= $j$</i> donde $i$ y $j$ es el resultado de los valores de $x$ que resuelven la ecuación. Deberás imprimir el resultado con 5 valores después del punto decimal. La salida será correcta si la diferencia entre el resultado correcto y tu salida es menor a $10^{-5}$.

# Ejemplo.

||input
(x+3)(x+4)=0
||output
x1= -3.00000 x2= -4.00000
||input
(x+5)(x+4)=3
||output
x1= -2.69722 x2= -6.30278
||end

# Consideraciones.

* $1 \leq a, b, c \leq 100$

#Buddy te recuerda.
Buddy te recuerda usar tipos de datos precisos (double en lugar de float).
