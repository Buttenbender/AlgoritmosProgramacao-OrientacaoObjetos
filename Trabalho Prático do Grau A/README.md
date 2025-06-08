# Trabalho Prático do Grau A: Interactive Ebook
## Autor
- João Pedro Büttenbender da Silva
## Objetivo
```
O objetivo desta atividade é integrar os conhecimentos avançados de programação e orientação a
objetos. É uma atividade que requer dedicação e estudo, mas certamente é um desafio que irá incrementar
suas habilidades de programador!
```
## Descrição Geral
```
Nos anos 90 a editora Marques Saraiva lançou uma série de livros-jogos chamada Aventuras Fantásticas,
uma tradução dos livros da série Fighting Fantasy. Atualmente alguns títulos estão sendo relançados pela
Editora Jambô. Basicamente os leitores criavam um personagem usando um sistema de regras bem
simplificado e executava a leitura de trechos de textos que indicavam quais os próximos trechos deveriam ser
lidos conforme as escolhas dos jogadores. Algumas vezes, algum trecho descrevia que o personagem havia
encontrado algum item que deveria ser anotado em seu inventário ou descrevia um encontro com alguma
criatura. Caso fosse bem-sucedido no combate deveria ir até determinado trecho.
```
## Telas
```
O jogo possui quatro telas descritas abaixo:

a) Tela de abertura: Esta tela apresenta as seguintes opções novo jogo, carregar jogo, exibir créditos e
encerrar a aplicação. Em novo jogo cria uma nova partida e carregar jogo carrega uma partida salva
anteriormente. Veja seção Salvar/Carregar. Em exibir créditos deve apresentar os nomes dos programadores;

b) Tela de inventário do jogo: essa tela é onde devem ser feitas as “configurações” iniciais do
personagem, ou seja, HABILIDADE, ENERGIA e SORTE. A mesma pode ser acionada sempre que o jogador
quiser ter acesso ao inventário do personagem.

c) Tela padrão do jogo: Nessa tela é apresentado o texto da aventura e são disponibilizadas as
possibilidades de decisão do jogador.

d) Tela de batalha: Tela em que deve ser apresentado o inimigo bem como sua Energia. Também é
nessa tela que o jogador pode escolher qual opção irá usar: Atacar, Usar Magia (dependendo de quais magias
tem em seu inventario, ou se algum item no inventário o permite usar alguma) ou Fugir;
```
## Criação de Personagem
```
Os desenvolvedores decidem como o jogador poderá atribuir os pontos de HABILIDADE, ENERGIA e
SORTE. O jogador terá 12 pontos disponíveis para distribuir entre os atributos.

A HABILIDADE terá o valor mínimo igual a 6 e valor máximo igual a 12;

A ENERGIA terá o valor mínimo igual a 12 e valor máximo igual a 24;

A SORTE terá o valor mínimo igual a 6 e valor máximo igual a 12;
```
## Uso da Sorte
```
Nos combates ou em certas situações de jogo o jogador pode optar ou ser solicitado a Testar Sorte. É
sorteado um valor aleatório e comparado com valor da sorte do personagem. Esse resultado define se ouve
falha ou sucesso no teste. Quando usar sorte em combate o usuário pode ampliar o dano causado ao inimigo
ou reduzir o dano causado pelo inimigo no personagem. Cada vez que a sorte for usada deve ser
decrementado em um o valor atual de SORTE.
```
## Resumo do Controle dos Atributos do Personagem/Inventário
```
Habilidade: Representa a destreza em combate. O valor influência diretamente nos resultados dos
combates.
Energia: Representa sua constituição, ou seja, pontos de vida.
Sorte: Como descrito sua sorte pode ser testada em determinados eventos e também pode mudar
valores do dano recebido ou causado.
Magias: Se o personagem for mago terá um numero de magias no inicio do jogo e no decorrer do
mesmo deve/pode adquirir outras, que influenciaram direto nos seus combates. Já personagens não magos
podem utilizar algumas magias desde que de posse de algum item magico.
Equipamentos: No inicio do jogo o personagem deve possuir alguns itens básicos, além desses o
programador pode definir onde e quando o personagem pode adquirir novos itens, que vão para inventário do
mesmo. Quando quiser o jogador pode acessar a tela de inventário e modificar o que o personagem está
equipado.
Tesouro: Materiais valiosos que o personagem adquire no decorrer da aventura.
Provisões: Alimentos que permitem ao personagem recuperar Energia. Só podem ser usadas fora de
combate. Uma provisão recupera sempre 4 pontos de vida.
```
