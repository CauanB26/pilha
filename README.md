# pilha

Objetivo: 
Incluir e excluir 10 elementos em uma fila e em uma pilha, exibindo a estrutura a cada inclusão/exclusão. Implementar a estrutura de pilha usando listas encadeadas.


Estrutura:
Não utilizamos módulos nesse programa, utilizamos apenas um arquivo do tipo 'c' 
Pilha *criaPilha(void) - cria a pilha com os valores nulos.
void pilhaPush(Pilha *p, float v) - insere o valor na pilha
float pilhaPop (Pilha* p) - exclui o ultimo valor que entrou na pilha
void exibePilha(Pilha *p) - exibe os valores que estão presentes na pilha
void liberapilha(Pilha* p) - libera toda memória utlizada para criar a pilha


Explicação:
1:
Inclusão das bibliotecas - Incluímos as bibliotecas "stdio.h" para entrada e saída padrão de dados e a "stdlib.h" para manipularmos a memória.

Declaração das estruturas - Declaramos nossas duas structs: a struct "Elem" ("Elem" = Elementos), que contém uma variável "valor" do tipo float (responsável por armazenar o valor do elemento) e possui um ponteiro "prox" que aponta para o próximo elemento na pilha. Também declaramos a struct pilha, que contém um único campo chamado "topo" (um ponteiro para o elemento do topo da pilha).

Declaração das funções auxiliares - Neste código, iremos utilizar 5 funções auxiliares:

"Pilha *criaPilha(void)" - função que retorna um ponteiro do tipo "Pilha" e recebe "void". A função também é responsável por criar a estrutura que iremos utilizar durante todo o código. Para criar a estrutura, utilizou-se a função "malloc" e é feito o tratamento de erro logo depois. Após isso, apontamos o topo da estrutura para NULL (pois ainda não inserimos nenhum elemento). Por fim, retornamos a estrutura que acabamos de criar.

"void pilhaPush(Pilha *p, float v)" - essa função recebe a nossa estrutura criada na função "criaPilha" e um valor float (no código referenciado como "v") para inserirmos na pilha. Essa função primeiro aloca dinamicamente o espaço para o novo elemento que será inserido e faz o tratamento de erro logo depois. Depois de alocar o espaço para nosso novo elemento, definimos o valor do novo elemento como "v" e depois atualizamos o ponteiro "prox" do novo elemento para apontar para o elemento que estava no topo da pilha antes da inserção. Por último, atualizamos o ponteiro do topo da pilha para apontar para o novo elemento, tornando-o o novo topo da pilha (para assim, respeitarmos a estrutura de pilha).

"void exibePilha(Pilha* p)" - função que recebe apenas a estrutura com o objetivo de exibir ela a cada interação que fizermos (como pedido no enunciado, por isso, teremos uma saída muito grande). No início da função, criamos um ponteiro do tipo Elem auxiliar (nomeado no código de "aux") que apontará para o topo da nossa estrutura. Logo após, utilizaremos um "while(aux != NULL)", ou seja, esse loop ocorrerá até o aux chegar ao fim da pilha (visto que o último elemento aponta para NULL). Dentro do "while", iremos imprimir o valor atual de "aux" e ainda dentro do while iremos apontar o aux para o próximo elemento. Colocamos alguns "printf("\n")" apenas por questões de organização.

"void pilhaPop(Pilha *p)" - essa função recebe a estrutura e remove o elemento do topo dela (afinal, a estrutura é uma pilha). Para nos ajudar, criamos um ponteiro auxiliar (referenciado como "aux") do tipo Elem e inicializamos ele com o valor do topo da pilha. Logo após, verificamos se a pilha está vazia. Caso esteja, apenas retornamos da função (poderia também colocar o "exit(1)", porém, para fins de testes, coloquei apenas o "return" e um "printf" indicando que a pilha está vazia). Caso a estrutura não esteja vazia, atualizamos o ponteiro do topo da pilha para apontar para o próximo elemento na pilha, isso remove o elemento do topo da pilha. E depois, utilizamos a função "free()" para liberar a memória alocada para o elemento removido e evitar problemas de vazamento de memória.

"void liberaPilha(Pilha *p)" - função que recebe a estrutura e é responsável por liberar toda a memória alocada para a estrutura da pilha. Primeiro, criamos um ponteiro auxiliar (referenciado como "aux") do tipo Elem e inicializamos ele com o topo da pilha. Criamos um loop utilizando "while(aux != NULL)", ou seja, rodará até percorrer todos elementos da pilha. Neste loop, criamos um ponteiro temporário e o inicializamos com o valor atual de "aux". Depois, atualizamos o ponteiro aux para apontar para o próximo elemento, isso faz com que mova o ponteiro da pilha para o elemento "debaixo" (imaginando uma pilha de pratos). E depois chamamos a função "free(temp)" para liberar a memória alocada para o elemento removido. Após liberarmos todos os elementos da estrutura e sairmos do loop, utilizamos um "free(p)" ("p" = estrutura) e liberamos a memória da estrutura. (Primeiro temos que liberar a memória dos elementos e depois da estrutura). Para finalizar essa função, utilizamos um "printf" para garantir que ela ocorreu corretamente.

"int main(void)" - utilizamos a main para testar todas as funções auxiliares que criamos. Primeiro, criamos a "estruturaPilha" (sendo um ponteiro do tipo "Pilha") e atribuímos a ela a função "criaPilha()", que faz com que tenhamos uma estrutura vazia, cujo primeiro elemento aponta para NULL. Após criarmos a estrutura, utilizamos um "for (int i = 0; i < 10; i++)" para colocarmos 10 elementos na estrutura (como pedido no enunciado). Dentro do for, utilizamos a função "pilhaPush(estruturaPilha, i + 1.0)" para colocarmos o novo elemento, e logo depois utilizamos "exibePilha(estruturaPilha)" para exibir nossa estrutura após cada iteração (como pedido no enunciado). Depois desse for, temos outro "for (int i = 0; i < 10; i++)", dessa vez, responsável por retirar os 10 elementos da estrutura. Dentro do for, utilizamos a função "pilhaPop(estruturaPilha)" para retirarmos o elemento do topo da pilha, e depois, utilizamos "exibePilha(estruturaPilha)" para exibir nossa estrutura após cada iteração. Por fim, fora do for, utilizamos a função "liberaPilha(estruturaPilha)" para liberarmos toda memória utilizada para fazer o programa.
