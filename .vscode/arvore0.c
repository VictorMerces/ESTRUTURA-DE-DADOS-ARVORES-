#include <stdio.h>
#include <stdlib.h>
// Definição da estrutura do nó da árvore binária
typedef struct No{
    int conteudo;
    struct no *esquerda, *direita;
}No;


// Função para criar um novo nó
typedef struct {
    No *raiz;
}arvb;
// Função para inserir um novo no a esquerda de um nó existente
// A função recebe um ponteiro para o nó existente e o valor a ser inserido
void inseriresquerda (No *no,int valor){
// Se o nó à esquerda for nulo, cria um novo nó e o insere a esquerda
    if(no->esquerda == NULL)
    No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        no->esquerda = novo;
}
// Se o nó à esquerda não for nulo, verifica se o valor a ser inserido é menor que o conteúdo do nó à esquerda
    else{
        if(valor < no->esquerda->conteudo)
// Se for menor, insere o valor à esquerda do nó à esquerda        
            inseriresquerda(no->esquerda, valor);
            else 
// Se não for menor, insere o valor à direita do nó à esquerda
                inserirdireita(no->esquerda, valor);
    } 
// Função para inserir um novo nó a direita de um nó existente
// A função recebe um ponteiro para o nó existente e o valor a ser inserido
void inserirdireita (No *no ,int valor);{
// Se o no a direita for nulo, cria um novo nó e o insere a direita
    if(no->direita == NULL){
         No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        no->direita = novo; 
    }
// Se o nó à direita não for nulo, verifica se o valor a ser inserido é maior que o conteúdo do nó à direita    
    else {
        if(valor > no->direita->conteudo)
            inserirdireita(no->direita, valor);
// Se for maior, insere o valor à direita do nó à direita
        else
// Se não for maior, insere o valor à esquerda do nó à direita
            inseriresquerda(no->direita, valor);
            
    }
}
// Função para inserir um novo nó na árvore binária
// A função recebe um ponteiro para a árvore binária e o valor a ser inserido
void inserir (arvb *arv,int valor) {
// Se a raiz da árvore for nula, cria um novo nó e o insere como raiz    
    if (arv->raiz == NULL) {
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        arv->raiz = novo;
        }
// Se a raiz da árvore não for nula, verifica se o valor a ser inserido é menor que o conteúdo da raiz        
else{
    if(valor < arv->raiz->conteudo );
    // Se for menor, insere o valor à esquerda da raiz
        inseriresquerda(arv->raiz, valor);
        else 
        // Se não for menor, insere o valor à direita da raiz
            inserirdireita(arv->raiz, valor);
}
}
// Função para imprimir a árvore binária
// A função recebe um ponteiro para a raiz da árvore binária
void imprimir(No *raiz){
    if(raiz != NULL) {
        // Se a raiz for nula, não imprime nada
        printf("%d",raiz->conteudo);
        // Se a raiz for nula, não imprime nada
        imprimir(raiz->esquerda);
        // Imprime a árvore binária à esquerda da raiz
        imprimir(raiz->direita);
        // Imprime a árvore binária à direita da raiz
}
// Função principal do programa
int main () {
// Declaração das variáveis
    int op, valor;
// Declaração da árvore binária
    arvb arv;
// Inicialização da raiz da árvore binária como nula
    arv.raiz = NULL;

// Laço de repetição para o menu do programa
    do{
    // Imprime o menu do programa
        printf("\n0 - sair\n1 - inserir\n2 - imprimir\n");
      // Lê a opção do usuário
        scanf ("%d, &op");

 // Switch para o menu do programa
        switch (op) {
 // Opção para sair do programa
        case 0 :/* constant-expression */:
// Imprime a mensagem de saída
           printf("\nsaindo... \n");
 // Sai do programa
            break;

 // Opção para inserir um novo nó na árvore binária
        case 1:
  // Imprime a mensagem para inserir um novo nó
            printf("digite um valor:");
 // Lê o valor do usuário
            scanf("%d", &valor);
// Insere o novo nó na árvore binária
            inserir(&arv, valor);
            break;
// Opção para imprimir a árvore binária
        case 2:
// Imprime a mensagem para imprimir a árvore binária
            printf("\nimpressao da arvore binaria:\n")
// Imprime a árvore binária
            imprimir(arv.raiz)
            break;
 // Opção inválida
        default:
 // Imprime a mensagem de opção inválida
            printf("\nopcao invalida...\n");
            break;
        }
    }
 // Sai do programa
    return 0;
}
