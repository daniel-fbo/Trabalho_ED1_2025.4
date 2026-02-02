#include "backend.h"

void cadastrar_cliente(cliente **head_c, char *nome, char *cpf, char *telefone, char *email, data *data_nascimento){
    carrinho *novo_carrinho = malloc(sizeof(carrinho));
    novo_carrinho -> prox = NULL;
    
    cliente *cliente_novo = malloc (sizeof(cliente));

    if (cliente_novo == NULL){
        printf(VERMELHO"Cadastro não pode ser concluído. Tecle Enter para voltar.!"BRANCO);
        getchar();
        return;
    }

    cliente_novo->nome = malloc(strlen(nome) + 1);
    cliente_novo->cpf = malloc(strlen(cpf) + 1);
    cliente_novo->telefone = malloc(strlen(telefone) + 1);
    cliente_novo->email = malloc(strlen(email) + 1);

    strcpy(cliente_novo->nome,nome);
    strcpy(cliente_novo->cpf,cpf);
    strcpy(cliente_novo->telefone,telefone);
    strcpy(cliente_novo->email,email);
    cliente_novo->data_nascimento = data_nascimento;
    cliente_novo->carrinho = novo_carrinho;

    cliente_novo -> prox = *head_c;
    *head_c  = cliente_novo;
}

void listar_clientes(cliente *head_c){
    
    cliente *temp_cliente = head_c;

    if(head_c == NULL){
        printf(VERDE" ==============================================\n"BRANCO);
        printf(" Nao ha clientes cadastrados\n");
        printf(" Pressione qualquer tecla para voltar...\n");
        printf(VERDE " ==============================================\n" BRANCO);
        while (getchar() != '\n'); getchar();
        return;      
    }

    while (temp_cliente != NULL){
        printf(VERDE" ==============================================\n"BRANCO);
        printf("Nome do cliente: %s\n", temp_cliente -> nome);
        printf("CPF: %s\n", temp_cliente -> cpf);
        printf("Telefone: %s\n", temp_cliente -> telefone);
        printf("Email: %s\n", temp_cliente -> email);
        printf("Data de nascimento: %hd/%hd/%d\n", temp_cliente -> data_nascimento -> dia, temp_cliente -> data_nascimento -> mes, temp_cliente -> data_nascimento -> ano);
        printf(VERDE" ==============================================\n"BRANCO);

        temp_cliente = temp_cliente -> prox;        
    } 

    printf(" Pressione qualquer tecla para voltar...\n");
    printf(VERDE" ==============================================\n"BRANCO);
    while (getchar() != '\n'); getchar();
    return;
}



cliente *buscar_cliente(cliente *head_c, char *cpf){
    /* if (head_c == NULL) return NULL;

    cliente *temp_cliente = head_c;
    while (temp_cliente != NULL){
        if (temp_cliente->cpf != NULL && strcmp(temp_cliente->cpf, cpf) == 0){
        printf("\n\nNome do cliente: %s\n", temp_cliente -> nome);
        printf("CPF: %s\n", temp_cliente -> cpf);
        printf("Telefone: %s\n", temp_cliente -> telefone);
        printf("Email: %s\n", temp_cliente -> email);
        printf("Data de nascimento: %hd/%hd/%d\n", temp_cliente -> data_nascimento -> dia, temp_cliente -> data_nascimento -> mes, temp_cliente -> data_nascimento -> ano);


            return temp_cliente;
        }
        temp_cliente = temp_cliente -> prox;        
    } 
    printf("\033[4;31mCliente não encontrado.\033[0m Tecle Enter para voltar.");
    getchar();
    return NULL; */

    //tentativa josef
    if (head_c == NULL) return NULL;

    cliente *temp_cliente = head_c;
    while (temp_cliente != NULL){
        if (temp_cliente->cpf != NULL && strcmp(temp_cliente->cpf, cpf) == 0){

            return temp_cliente;

        }
        temp_cliente = temp_cliente -> prox;        
    } 
    
    return NULL;
}


void editar_cliente(cliente *cliente_editado, char *novo_nome, char *novo_cpf, char *novo_telefone, char *novo_email, data *nova_data_nascimento, short opcao){
    if (opcao == 1){
        strcpy(cliente_editado -> nome, novo_nome);
        return;
    }
    if (opcao == 2){
        strcpy(cliente_editado -> cpf, novo_cpf);
        return;
    }  
    if (opcao == 3){
        strcpy(cliente_editado -> telefone, novo_telefone);
        return;
    }
    if (opcao == 4){
        strcpy(cliente_editado -> email, novo_email);
        return;
    }
    if (opcao == 5){
        cliente_editado -> data_nascimento = nova_data_nascimento;
        return;
    }
}


void remover_clientes(cliente **head_c, cliente *cliente_removido){

    //analisar se retiro esse
    /* cliente *cliente_anterior = head_c;
    while (cliente_anterior->prox != NULL && cliente_anterior -> prox != cliente_removido){
        cliente_anterior = cliente_anterior -> prox;
    }
    cliente_anterior -> prox = cliente_removido -> prox;
    free (cliente_removido); */

    if (*head_c == cliente_removido) {
        *head_c = cliente_removido->prox;
        free(cliente_removido);
        return;
    }

    cliente *atual = *head_c;
    while (atual->prox && atual->prox != cliente_removido)
        atual = atual->prox;

    if (atual->prox) {
        atual->prox = cliente_removido->prox;
        free(cliente_removido);
    }
}
