# Trabalho-2-Algoritmos

# Listas

Por conta de certas características da lista ordenada e da lista não ordenada serem iguais, optamos por criar uma "listaBase" para possuir tais características e depois criar as classes "listaOrdenada" e "listaDesordenada" com herança dessa "listaBase".

# Pilha e Fila

Tanto a Pilha quanto a Fila não utilizam uma organização crescente/decrescente, então foi optado que elas herdassem as características da "listaDesordenada", para que elas tivessem, principalmente, o inserir no inicio e no final.

O maior problema da Fila é que ou a inserção ou a sua remoção terá complexidade O(n) por conta de estarmos utilizando uma alocação sequencial. Para resolver esse problema poderíamos utilizar uma alocação dinâmica, como a lista duplamente encadeada circular, assim podendo produzir uma inserção e remoção com complexidade O(1).


# Complexidade
| Tipo de estrutura | Inserção | Remoção | Busca |
| ---- | ---- | ---- | ---- |
| Lista Ordenada  | O(n) | O(n) | O(log(n)) |
| Lista Não Ordenada  | O(1) | O(n) | O(n) |
| Pilha | O(1) | O(1) | - |
| Fila | O(1) | O(n) | - |


# Integrantes

Eduarda Alves

Lucas Sancho
