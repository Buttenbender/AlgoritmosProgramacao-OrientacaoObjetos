# Pilhas: Atividade 2
## Autor
- João Pedro Büttenbender da Silva
## Descrição
```
Utilizando uma estrutura de pilha, escreva um programa que lê uma linha qualquer digitada
pelo usuário. O programa deve receber a linha digitada e indicar se a ela apresenta um
número de parêntesis, colchetes e chaves balanceados; portanto, para cada parêntesis,
colchete ou chave aberto existe um fechado. Por exemplo, a linha abaixo:
( a + b * { c / [d-e]) + (d + e)
Caso a expressão não esteja balanceada, mostre o erro (qual caractere não está balanceado).
Caso a linha não apresente nenhum parêntesis, colchete ou chave ela estará por definição
balanceada (número de elementos igual a zero). O seu programa deve ficar executando até
que o usuário não deseja mais continuar.
Exemplos de situações de erro:
Expressão tem parênteses aberto e não fechou
Expressão apresenta um colchete de fechamento e não possui um de abertura.
Dica:
Cada caractere de abertura (“(“, “[“ ou “{”) implica em uma inserção na pilha (push) e cada
caractere de fechamento (“)“, “]“ ou “}”) implica uma retirada da pilha (pop). No momento
do pop, caso o caractere do topo da pilha não faça par com o caractere que está sendo
avaliado, ocorre um erro; segunda situação de erro apontada anteriormente.
Curiosidade: este programa poderia ser parte, por exemplo, de um compilador, na avaliação
de expressões aritméticas.
```
