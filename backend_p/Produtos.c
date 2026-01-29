#include "backend.h"

#include <stdlib.h> 
#include <stdio.h>
#include <string.h>

void cadastrar_produto(produto *head_p, char *nome, char *id, double preco, short qtd){
    produto *produto_novo;
    produto_novo = malloc (sizeof(produto)); 
    if (produto_novo == NULL){
        printf("\033[4;31mCadastro não pode ser concluído.\033[0m Tecle Enter para voltar.!");
        getchar();
        return;
    }

    strcpy(produto_novo->nome,nome);
    strcpy(produto_novo->id,id);
    produto_novo->preco = preco;
    produto_novo->qtd = qtd;

    produto_novo -> prox = head_p -> prox;
    head_p -> prox = produto_novo;
}


void listar_produtos (produto *head_p){
    produto *temp_produto = head_p;
    while (temp_produto != NULL){
        printf("Nome do produto: %s\n", temp_produto -> nome);
        printf("Codigo unico: %s\n", temp_produto -> id);
        printf("Unidades do produto em estoque: %d\n", temp_produto -> qtd);
        printf("Preco: %.2lf\n\n\n\n", temp_produto -> preco);
        temp_produto = temp_produto -> prox;        
    } 
}

produto *buscar_produto(produto *head_p, char *id){
    produto *temp_produto = head_p;
    while (temp_produto != NULL){
        if (!(strcmp(temp_produto -> id,id))){
            printf("Nome do produto: %s\n", temp_produto -> nome);
            printf("Codigo unico: %s\n", temp_produto -> id);
            printf("Unidades do produto em estoque: %d\n", temp_produto -> qtd);
            printf("Preco: %.2lf\n\n\n\n", temp_produto -> preco);
            return temp_produto;
        }
        temp_produto = temp_produto -> prox;        
    } 
    printf("\033[4;31mProduto não encontrado.\033[0m Tecle Enter para voltar.");
    getchar();
    return NULL;
}


void editar_produto(produto *produto_editado, char *novo_nome, char *novo_id, double novo_preco, short nova_qtd, short opcao){
    if (opcao == 1){
        strcpy(produto_editado -> nome, novo_nome);
        return;
    }
    if (opcao == 2){
        strcpy(produto_editado -> id, novo_id);
        return;
    }
    if (opcao == 3){
        produto_editado -> preco = novo_preco;
    }
    if (opcao == 4){
        produto_editado -> qtd = nova_qtd;
    }
}


void remover_produtos (produto *head_p, produto *produto_removido){
    produto *produto_anterior = head_p;
    while (produto_anterior->prox != NULL && produto_anterior -> prox != produto_removido){
        produto_anterior = produto_anterior -> prox;
    }
    produto_anterior -> prox = produto_removido -> prox;
    free (produto_removido);
}