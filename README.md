# push_swap

## Descripción del proyecto

La finalidad del proyecto push_swap de 42 es la siguiente: dado un conjunto de enteros pasados por línea de comandos, construir una pila A y generar por stdout una secuencia de operaciones válidas (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr) que, aplicadas en el orden producido, dejen la pila ordenada ascendentemente. El programa implementa soluciones especializadas para entradas pequeñas (2–5 elementos) y una estrategia por "chunks" (k_sort) para entradas más grandes.

Aquí podéis ver una explicación del proyecto que yo he desarrollado.

## Explicación por fichero y funciones principales

Ficheros principales con sus funciones más relevantes y una breve explicación.

- includes/push_swap.h  
  - Define las estructuras `t_content` (value, sorted_pos) y `t_list` (nodo de lista enlazada).  
  - Declara los prototipos usados en el programa.

- src/main.c  
  - `init_stack(argc, argv)`: construye la pila A desde argv (llama a `load_stack`) y asigna `sorted_pos` a cada nodo (`load_sorted_positions`). Devuelve NULL en caso de error.  
  - `sort_stack(&A, &B, size)`: selecciona el algoritmo según el tamaño: 2 → swap, 3 → `three_sort`, ≤5 → `mini_sort`, >5 → `k_sort`.  
  - `main`: control del flujo: inicialización, comprobación `is_sorted`, llamada a `sort_stack`, liberación final.

- src/ps_list_utils.c  
  - `create_node(value)`: crea nodo con `t_content` y `sorted_pos = -1`.  
  - `add_node_back(&stack, node)`: añade nodo al final de la lista.  
  - `free_stack(&stack)`, `stack_size(stack)`, `is_sorted(stack)`.

- src/ps_input_utils.c  
  - `is_valid_number(str)`: valida formato de entero.  
  - `atoi_safe(str, &result)`: conversión segura con comprobación de overflow.  
  - `has_duplicates(stack)`: detecta duplicados (doble bucle).  
  - `load_stack(argc, argv)`: construye la pila A validando entrada y creando nodos.

- src/ps_array_utils.c  
  - `create_array(stack, size)`: copia valores a un array.  
  - `sort_array(array, size)`: ordena (bubble sort en esta implementación).  
  - `get_value_pos(array, value, size)`: devuelve índice en array.  
  - `load_sorted_positions(stack, size)`: asigna `sorted_pos` a cada nodo (ranking).

- src/ps_swap.c  
  - `swap_a(&A)`, `swap_b(&B)`: intercambian los dos primeros valores y escriben `sa\n`/`sb\n`.  
  - `swap_a_b(&A,&B)`: llama a `swap_a` y `swap_b` y escribe `ss\n`.

- src/ps_push.c  
  - `push_a(&B,&A)`, `push_b(&A,&B)`: mueven el tope entre pilas e imprimen `pa\n`/`pb\n`.

- src/ps_rotate.c / src/ps_rev_rotate.c  
  - `rotate_a`, `rotate_b`, `rev_rotate_a`, `rev_rotate_b` y las versiones `_a_b`. Rotaciones suben/bajan elementos y escriben `ra/rb/rra/rrb` (operaciones con coste O(n) por recorrido).

- src/ps_stack_utils.c  
  - `get_min_value_pos(stack)`, `get_max_value_pos(stack)`: devuelven índice de min/máx.  
  - `get_rotate_cost(&stack, pos)`: calcula si conviene rotar hacia arriba o hacia abajo (usa `stack_size`).

- src/ps_sort.c  
  - `three_sort(&A)`: caso fijo para 3 elementos (comparaciones y operaciones).  
  - `mini_sort(&A,&B,size)`: gestiona 2–5 elementos (extrae mínimos a B si hace falta y reconstruye).

- src/ps_k_sort.c  
  - `send_chunks(&A,&B,start,end)`: desplaza a B los elementos cuyo `sorted_pos` está en el chunk.  
  - `reinsert_sorted(&A,&B)`: reinserta elementos de B a A eligiendo máximos y rotando eficientemente.  
  - `k_sort(&A,&B)`: estrategia de chunks (chunk_size = 15 si size ≤ 100, sino 30) y reconstrucción.

## Call‑graph

```
main
 ├─ init_stack
 │   ├─ load_stack
 │   │   ├─ is_valid_number
 │   │   ├─ atoi_safe
 │   │   ├─ create_node
 │   │   └─ add_node_back
 │   └─ load_sorted_positions
 │       ├─ create_array
 │       ├─ sort_array
 │       └─ get_value_pos
 ├─ is_sorted
 └─ sort_stack
     ├─ swap_a
     ├─ three_sort
     │   ├─ swap_a
     │   ├─ rotate_a
     │   └─ rev_rotate_a
     ├─ mini_sort
     │   ├─ minis_two_three -> three_sort
     │   └─ minis_four_five
     │       ├─ get_min_value_pos
     │       ├─ get_rotate_cost
     │       ├─ rotate_a / rev_rotate_a
     │       ├─ push_b
     │       └─ push_a
     └─ k_sort
         ├─ send_chunks -> push_b / rotate_a
         └─ reinsert_sorted -> get_max_value_pos / get_rotate_cost / rotate_b / rev_rotate_b / push_a
```
