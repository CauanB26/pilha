#include <stdio.h>
#include <stdlib.h>

struct elem {
  float valor;
  struct elem *prox;
};
typedef struct elem Elem;

struct pilha {
  Elem *topo;
};
typedef struct pilha Pilha;

Pilha *criaPilha(void);
void pilhaPush(Pilha *p, float v);
void pilhaPop(Pilha *p);
void exibePilha(Pilha *p);
void liberaPilha(Pilha *p);

int main(void) {
  Pilha *estruturaPilha = criaPilha();

  printf("Inserindo elementos:\n");
  for (int i = 0; i < 10; i++) {
    pilhaPush(estruturaPilha, i + 1.0);
    exibePilha(estruturaPilha);
  }

  printf("\nRetirando elementos:\n");
  for (int i = 0; i < 10; i++) {
    pilhaPop(estruturaPilha);
    exibePilha(estruturaPilha);
  }

  liberaPilha(estruturaPilha);
  return 0;
}

Pilha *criaPilha(void) {

  Pilha *estrutura = (Pilha *)malloc(sizeof(Pilha));
  if (estrutura == NULL) {
    printf("Erro ao alocar memoria para estrutura\n");
    exit(1);
  }

  estrutura->topo = NULL;

  return estrutura;
}

void pilhaPush(Pilha *p, float v) {
  Elem *novo = (Elem *)malloc(sizeof(Elem));
  if (novo == NULL) {
    printf("Erro ao alocar memoria para novo elemento\n");
    exit(1);
  }
  novo->valor = v;
  novo->prox = p->topo;
  p->topo = novo;
}

void exibePilha(Pilha *p) {
  Elem *aux = p->topo;
  while (aux != NULL) {
    printf("%.2f ", aux->valor);
    aux = aux->prox;
  }
  printf("\n");
}

void pilhaPop(Pilha *p) {
  Elem *aux = p->topo;
  if (aux == NULL) {
    printf("Pilha vazia\n");
    return;
  }
  p->topo = aux->prox;
  free(aux);
}

void liberaPilha(Pilha *p) {
  Elem *aux = p->topo;
  while (aux != NULL) {
    Elem *temp = aux;
    aux = aux->prox;
    free(temp);
  }
  free(p);
  printf("Memoria liberada com sucesso\n");
}
