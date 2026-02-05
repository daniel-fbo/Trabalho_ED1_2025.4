#include "backend.h"
void free_carrinho(carrinho *carrinho) {
    if (carrinho == NULL){
        return;
    }
    itemcarrinho *atual = carrinho->itens; 
    
    while (atual != NULL) {
        itemcarrinho *temp = atual;
        atual = atual->prox;
        free(temp); 
    }

    free(carrinho); 
}

void limpar_memoria(cliente **head_c, produto **head_p) {
    
    cliente *atual_c = *head_c;
    while (atual_c != NULL) {
        cliente *temp_c = atual_c;
        atual_c = atual_c->prox;
        free(temp_c->nome);
        free(temp_c->cpf);
        free(temp_c->telefone);
        free(temp_c->email);
        free(temp_c->data_nascimento);
        free_carrinho(temp_c->carrinho);
        free(temp_c);
    }
    *head_c = NULL;

    produto *atual_p = *head_p;
    while (atual_p != NULL) {
        produto *temp_p = atual_p;
        atual_p = atual_p->prox;
        free(temp_p->nome);
        free(temp_p->id);
        free(temp_p);
    }
    *head_p = NULL; 
}