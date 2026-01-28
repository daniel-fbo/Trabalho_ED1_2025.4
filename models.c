#include "models.h"

#include <stdlib.h> 
#include <stdio.h>
#include <string.h>

void cadastrar_cliente(cliente *head_c, char *nome, char *cpf, char *telefone){
    cliente *cliente_novo;
    cliente_novo = malloc (sizeof(cliente)); 
    if (cliente_novo == NULL){
        printf("\033[4;31mCadastro não pode ser concluído.\033[0m Tecle Enter para voltar.!");
        getchar();
        return;
    }

    strcpy(cliente_novo->nome,nome);
    strcpy(cliente_novo->cpf,cpf);
    strcpy(cliente_novo->telefone,telefone);

    cliente_novo -> prox = head_c -> prox;
    head_c -> prox = cliente_novo;
}

void cadastrar_produto(produto *head_p, char *nome, char *id, double preco){
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

    produto_novo -> prox = head_p -> prox;
    head_p -> prox = produto_novo;
}

void listar_clientes(cliente *head_c){
    cliente *temp_cliente = head_c;
    while (temp_cliente != NULL){
        printf("Nome do cliente: %s\n", temp_cliente -> nome);
        printf("CPF: %s\n", temp_cliente -> cpf);
        printf("Telefone: %s\n\n\n\n", temp_cliente -> telefone);
        temp_cliente = temp_cliente -> prox;        
    } 
}

void listar_produtos (produto *head_p){
    produto *temp_produto = head_p;
    while (temp_produto != NULL){
        printf("Nome do produto: %s\n", temp_produto -> nome);
        printf("Codigo unico: %s\n", temp_produto -> id);
        printf("Preco: %.2lf\n\n\n\n", temp_produto -> preco);
        temp_produto = temp_produto -> prox;        
    } 
}

cliente *buscar_cliente(cliente *head_c, char *cpf){
    cliente *temp_cliente = head_c;
    while (temp_cliente != NULL){
        if (!(strcmp(temp_cliente -> cpf,cpf))){
            printf("Nome do cliente: %s\n", temp_cliente -> nome);
            printf("CPF: %s\n", temp_cliente -> cpf);
            printf("Telefone: %s\n\n\n\n", temp_cliente -> telefone);
            return temp_cliente;
        }
        temp_cliente = temp_cliente -> prox;        
    } 
    printf("\033[4;31mCliente não encontrado.\033[0m Tecle Enter para voltar.");
    getchar();
    return NULL;
}

produto *buscar_produto(produto *head_p, char *id){
    produto *temp_produto = head_p;
    while (temp_produto != NULL){
        if (!(strcmp(temp_produto -> id,id))){
            printf("Nome do produto: %s\n", temp_produto -> nome);
            printf("Codigo unico: %s\n", temp_produto -> id);
            printf("Preco: %.2lf\n\n\n\n", temp_produto -> preco);
            return temp_produto;
        }
        temp_produto = temp_produto -> prox;        
    } 
    printf("\033[4;31mProduto não encontrado.\033[0m Tecle Enter para voltar.");
    getchar();
    return NULL;
}

void editar_cliente(cliente *cliente_editado, char *novo_nome, char *novo_cpf, char *novo_telefone, short opcao){
    if (opcao == 1){
        strcopy(cliente_editado -> nome, novo_nome);
        return;
    }
    if (opcao == 2){
        strcopy(cliente_editado -> cpf, novo_cpf);
        return;
    }  
    if (opcao == 3){
        strcopy(cliente_editado -> telefone, novo_telefone);
        return;
    }
}
void editar_produto(produto *produto_editado, char *novo_nome, char *novo_id, double novo_preco, short opcao){
    if (opcao == 1){
        strcopy(produto_editado -> nome, novo_nome);
        return;
    }
    if (opcao == 2){
        strcopy(produto_editado -> id, novo_id);
        return;
    }
    if (opcao == 3){
        produto_editado -> preco = novo_preco;
    }
}

void remover_clientes(cliente *head_c, cliente *cliente_removido){
    cliente *cliente_anterior = head_c;
    while (cliente_anterior->prox != NULL && cliente_anterior -> prox != cliente_removido){
        cliente_anterior = cliente_anterior -> prox;
    }
    cliente_anterior -> prox = cliente_removido -> prox;
    free (cliente_removido);
}
void remover_produtos (produto *head_p, produto *produto_removido){
    produto *produto_anterior = head_p;
    while (produto_anterior->prox != NULL && produto_anterior -> prox != produto_removido){
        produto_anterior = produto_anterior -> prox;
    }
    produto_anterior -> prox = produto_removido -> prox;
    free (produto_removido);
}