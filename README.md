# ALGORITMO PUSH SWAP
Algoritmo para el proyecto Push_swap de 42 Málaga.

Este algoritmo consiste en ordenar una secuencia de números (no repetidos) que se introducen en la pila A.

## Estructura

Dos pilas A y B con las siguiente operaciones:
 - Push A (PA): Coloca el primer elemento de la pila B en la pila A
 - Push B (PB): Coloca el primer elemento de la pila A en la pila B
 - Swap A (SA): Intercambia los 2 primeros elementos de la pila A
 - Swap B (SB): Intercambia los 2 primeros elementos de la pila B
 - Swap Both (SS): Intercambia los 2 primeros elementos de las dos pilas
 - Rotate A (RA): Coloca el primer elemento de la pila A al final
 - Rotate B (RB): Coloca el primer elemento de la pila B al final
 - Rotate Both (RR): Coloca el primer elemento de la pila A y B al final de cada una respectivamente 
 - Rotate Reverse A (RRA): Coloca el último elemento de la pila A al principio
 - Rotate Reverse B (RRB): Coloca el último elemento de la pila B al principio
 - Rotate Reverse Both (RRR): Coloca el último elemento de la pila A y B al principio de cada una respectivamente

## Algoritmo
### 3 o menos elementos
Miro cada caso uno a uno, ya que son pocos.
### 5 o menos elementos
Me llevo tantos elementos como pueda a B hasta que en A haya 3, aplico el algoritmo de 3, y luego inserto cada elemento de B en A colocándolo en su sitio correspondiente.
### Más de 5 elementos
Aplico un algoritmo greedy (codicioso) que utiliza como función heurística (de coste) que calcula cuántos movimientos requiere un elemento de la pila B
para colocarlo en A ordenadamente (suponiendo que A esté ordenada).

El algoritmo greedy aplica a cada elemento de B el heurísitco, coge el que menor coste tenga y aplica esos movimientos a la pila.
Repetimos este algoritmo hasta que B esté vacío.

Para que este algorimo funcione, tenemos que dejar en A un conjunto de números ya ordenados, e interesa dejar los máximos elementos posibles en A
para minimizar los movimientos necesarios, por ellos hago uso del algoritmo LIS (Longest Increasing Subsequence) que me calcula, dado una lista de
elementos, el subconjunto más grande posible de elementos creciente no necesariamente seguidos en la lista original. De esta forma, maximizamos
el número de elementos que conservamos en A y nos aseguramos de que estén ordenados crecientemente.
