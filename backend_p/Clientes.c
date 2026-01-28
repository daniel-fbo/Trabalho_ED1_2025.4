#include "backend.h"

#include <stdlib.h> 
#include <stdio.h>
#include <string.h>

void cadastrar_cliente(cliente *head_c, char *nome, char *cpf, char *telefone, char *email, data *data_nascimento){
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
    strcpy(cliente_novo->email,email);
    cliente_novo->data_nascimento = data_nascimento;

    cliente_novo -> prox = head_c -> prox;
    head_c -> prox = cliente_novo;
}

void listar_clientes(cliente *head_c){
    cliente *temp_cliente = head_c;
    while (temp_cliente != NULL){
        printf("Nome do cliente: %s\n", temp_cliente -> nome);
        printf("CPF: %s\n", temp_cliente -> cpf);
        printf("Telefone: %s\n\n\n\n", temp_cliente -> telefone);
        printf("Email: %s\n\n\n\n", temp_cliente -> email);
        printf("Data de nascimento: %hd/%hd/%d\n\n\n\n", temp_cliente -> data_nascimento -> dia, temp_cliente -> data_nascimento -> mes, temp_cliente -> data_nascimento -> ano);
        temp_cliente = temp_cliente -> prox;        
    } 
}



cliente *buscar_cliente(cliente *head_c, char *cpf){
    cliente *temp_cliente = head_c;
    while (temp_cliente != NULL){
        if (!(strcmp(temp_cliente -> cpf,cpf))){
        printf("Nome do cliente: %s\n", temp_cliente -> nome);
        printf("CPF: %s\n", temp_cliente -> cpf);
        printf("Telefone: %s\n\n\n\n", temp_cliente -> telefone);
        printf("Email: %s\n\n\n\n", temp_cliente -> email);
        printf("Data de nascimento: %hd/%hd/%d\n\n\n\n", temp_cliente -> data_nascimento -> dia, temp_cliente -> data_nascimento -> mes, temp_cliente -> data_nascimento -> ano);
            return temp_cliente;
        }
        temp_cliente = temp_cliente -> prox;        
    } 
    printf("\033[4;31mCliente não encontrado.\033[0m Tecle Enter para voltar.");
    getchar();
    return NULL;
}


void editar_cliente(cliente *cliente_editado, char *novo_nome, char *novo_cpf, char *novo_telefone, char *novo_email, data *nova_data_nascimento, short opcao){
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
    if (opcao == 4){
        strcopy(cliente_editado -> email, novo_email);
        return;
    }
    if (opcao == 5){
        cliente_editado -> data_nascimento = nova_data_nascimento;
        return;
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
