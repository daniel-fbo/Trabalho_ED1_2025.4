#include "backend.h"

void cadastrar_cliente(cliente **head_c, char *nome, char *cpf, char *telefone, char *email, data *data_nascimento)
{
    cliente *cliente_novo = malloc(sizeof(cliente));
    if (cliente_novo == NULL)
    {
        printf(VERMELHO "Erro: Cadastro não pode ser concluído. Tecle ENTER para voltar...!\n" BRANCO);
        printf("Tecle ENTER para voltar...\n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    carrinho *novo_carrinho = malloc(sizeof(carrinho));
    if (novo_carrinho == NULL) {
        free(cliente_novo);
        printf(VERMELHO "Erro: Cadastro não pode ser concluído. Tecle ENTER para voltar...!\n" BRANCO);
        printf("Tecle ENTER para voltar...\n");
        while (getchar() != '\n');
        getchar();
        return;
    }


    novo_carrinho->itens = NULL;

    cliente_novo->nome = malloc(strlen(nome) + 1);
    cliente_novo->cpf = malloc(strlen(cpf) + 1);
    cliente_novo->telefone = malloc(strlen(telefone) + 1);
    cliente_novo->email = malloc(strlen(email) + 1);
    
    if (!cliente_novo->nome || !cliente_novo->cpf || !cliente_novo->telefone || !cliente_novo->email) {
        free(cliente_novo->nome);
        free(cliente_novo->cpf);
        free(cliente_novo->telefone);
        free(cliente_novo->email);
        free(novo_carrinho);
        free(cliente_novo);
        return;
    } 

    strcpy(cliente_novo->nome, nome);
    strcpy(cliente_novo->cpf, cpf);
    strcpy(cliente_novo->telefone, telefone);
    strcpy(cliente_novo->email, email);
    cliente_novo->data_nascimento = data_nascimento;
    cliente_novo->carrinho = novo_carrinho;

    cliente_novo->prox = *head_c;
    *head_c = cliente_novo;

    system("cls");
    printf(VERDE "Cliente cadastrado com sucesso!\n\n" BRANCO);
    printf("Tecle Enter para voltar...\n");
    while (getchar() != '\n');
    getchar();
    system("cls");
}

void remover_clientes(cliente **head_c, cliente *cliente_removido) {
    bool encontrado = NAO; 

    if (*head_c == NULL || cliente_removido == NULL) {
        printf(VERMELHO "Erro: Lista vazia ou cliente invalido.\n" BRANCO);
    } 
    else {
        if (*head_c == cliente_removido) {
            *head_c = cliente_removido->prox;
            encontrado = SIM;
        } 
        else {
            cliente *atual = *head_c;
            while (atual->prox != NULL && atual->prox != cliente_removido) {
                atual = atual->prox;
            }

            if (atual->prox == cliente_removido) {
                atual->prox = cliente_removido->prox;
                encontrado = SIM;
            } else {
                printf(VERMELHO "Erro: Cliente nao encontrado na lista.\n" BRANCO);
            }
        }
    }

    if (encontrado == SIM) {
        free(cliente_removido->nome); 
        free(cliente_removido->cpf); 
        free(cliente_removido->telefone);
        free(cliente_removido->email);  
        free(cliente_removido->data_nascimento); 
        //free(cliente_removido->carrinho); 
        free(cliente_removido);
        printf(VERDE "Cliente removido com sucesso!\n" BRANCO);
    }

    printf("Tecle ENTER para voltar...\n");
    while (getchar() != '\n');
    getchar();
    system("cls");
}

void listar_clientes(cliente *head_c)
{
    system("cls");
    printf(ROXO "- - - - - - Lista de Clientes - - - - - -\n\n" BRANCO);

    cliente *temp_cliente = head_c;

    if (head_c == NULL)
    {
        system("cls");
        printf(VERMELHO "Erro: Nao ha clientes cadastrados\n\n" BRANCO);
        printf("Tecle ENTER para voltar...\n");
        while (getchar() != '\n');
        getchar();
        system("cls");
        return;
    }

    while (temp_cliente != NULL)
    {
        printf("Nome do cliente: %s\n", temp_cliente->nome);
        printf("CPF: %s\n", temp_cliente->cpf);
        printf("Telefone: %s\n", temp_cliente->telefone);
        printf("Email: %s\n", temp_cliente->email);
        printf("Data de nascimento: %02hd/%02hd/%04d\n", temp_cliente->data_nascimento->dia, temp_cliente->data_nascimento->mes, temp_cliente->data_nascimento->ano);
        printf("\n\n");
        temp_cliente = temp_cliente->prox;
    }

    printf("Tecle ENTER para voltar...\n");
    while (getchar() != '\n');
    getchar();
    system("cls");
    return;
}

cliente *buscar_cliente(cliente *head_c, char *cpf)
{
    if (head_c == NULL)
        return NULL;

    cliente *temp_cliente = head_c;
    while (temp_cliente != NULL)
    {
        if (temp_cliente->cpf != NULL && strcmp(temp_cliente->cpf, cpf) == 0)
        {
            return temp_cliente;
        }
        temp_cliente = temp_cliente->prox;
    }
    return NULL;
}

void editar_cliente(cliente *cliente_editado, char *novo_nome, char *novo_cpf, char *novo_telefone, char *novo_email, data *nova_data_nascimento, short opcao)
{
    char *temp;
    switch (opcao)
    {
    case 1:
        temp = realloc(cliente_editado->nome, strlen(novo_nome) + 1);
        if (temp != NULL) {
            cliente_editado->nome = temp;
            strcpy(cliente_editado->nome, novo_nome);
        }
        break;
    case 2:
        temp = realloc(cliente_editado->cpf, strlen(novo_cpf) + 1);
        if (temp != NULL) {
            cliente_editado->cpf = temp;
            strcpy(cliente_editado->cpf, novo_cpf);
        }
        break;
    case 3:
        temp = realloc(cliente_editado->telefone, strlen(novo_telefone) + 1);
        if (temp != NULL) {
            cliente_editado->telefone = temp;
            strcpy(cliente_editado->telefone, novo_telefone);
        }
        break;
    case 4:
        temp = realloc(cliente_editado->email, strlen(novo_email) + 1);
        if (temp != NULL) {
            cliente_editado->email = temp;
            strcpy(cliente_editado->email, novo_email);
        }
        break;
    case 5:
            cliente_editado->data_nascimento->dia = nova_data_nascimento->dia;
            cliente_editado->data_nascimento->mes = nova_data_nascimento->mes;
            cliente_editado->data_nascimento->ano = nova_data_nascimento->ano;
        break;
    }
    return;
}
