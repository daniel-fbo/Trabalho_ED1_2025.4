#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char *nome;
    struct Node *anterior;
    struct Node *prox;
} node;

void inserir(char *nome, node *head, node *tail);

int main(){
    node *head;
    head = malloc(sizeof(head));
    head -> anterior = NULL;
    node *tail;
    tail = malloc(sizeof(tail));
    tail -> prox = NULL;   

    head -> prox = tail;
    tail -> anterior = head;


    char nomes[200][100];
    int i=0;
    while(scanf("%[^\n]",nomes[i])==1){
        inserir(nomes[i], head, tail);
        i++;
    }
    for (int j=0;j<i;j++){
        printf("%s\n",nomes[j]);
    }
    free(head);
    free(tail);
    return 0;
}

void inserir (char *nome, node *head, node *tail){


}
