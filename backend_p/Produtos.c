#include "backend.h"

void cadastrar_produto(produto **head_p, char *nome, char *id, double preco, short qtd) {
    produto *produto_novo = malloc(sizeof(produto));
    if (produto_novo == NULL) {
        printf(VERMELHO "Erro: Cadastro não pode ser concluído.\n" BRANCO);
        enter();
        return;
    }

    produto_novo->nome = malloc(strlen(nome) + 1);
    produto_novo->id = malloc(strlen(id) + 1);

    if (!produto_novo->nome || !produto_novo->id) {
        free(produto_novo->nome);
        free(produto_novo->id);
        free(produto_novo);
        return;
    }

    strcpy(produto_novo->nome, nome);
    strcpy(produto_novo->id, id);
    produto_novo->preco = preco;
    produto_novo->qtd = qtd;

    produto_novo->prox = *head_p;
    *head_p = produto_novo;

    system("cls");
    printf(VERDE "Produto cadastrado com sucesso!\n\n" BRANCO);
    enter();
    system("cls");
}

void remover_produtos(produto **head_p, produto *produto_removido) {
    bool encontrado = NAO;

    if (*head_p == NULL || produto_removido == NULL) {
        printf(VERMELHO "Erro: Lista vazia ou produto invalido.\n" BRANCO);
    } 
    else {
        if (*head_p == produto_removido) {
            *head_p = produto_removido->prox;
            encontrado = SIM;
        } 
        else {
            produto *anterior = *head_p;
            while (anterior->prox != NULL && anterior->prox != produto_removido) {
                anterior = anterior->prox;
            }

            if (anterior->prox == produto_removido) {
                anterior->prox = produto_removido->prox;
                encontrado = SIM;
            } else {
                printf(VERMELHO "Erro: Produto nao encontrado na lista.\n" BRANCO);
            }
        }
    }

    if (encontrado == SIM) {
        free(produto_removido->nome);
        free(produto_removido->id);
        free(produto_removido);
        printf(VERDE "Produto removido com sucesso!\n" BRANCO);
    }
    return;
}

void listar_produtos (produto *head_p){

    system("cls");
    printf(ROXO "- - - - - - Lista de Produtos - - - - - -\n\n" BRANCO);

    if (head_p == NULL)
    {
        system("cls");
        printf(VERMELHO "Erro: Nao ha produtos cadastrados\n\n" BRANCO);
        enter();
        return;
    }

    produto *temp_produto = head_p;
    while (temp_produto != NULL){
        printf("Nome do produto: %s\n", temp_produto -> nome);
        printf("Codigo unico: %s\n", temp_produto -> id);
        printf("Unidades do produto em estoque: %d\n", temp_produto -> qtd);
        printf("Preco: %.2lf\n\n", temp_produto -> preco);
        temp_produto = temp_produto -> prox;        
    } 

    enter();
    return;
}

produto *buscar_produto(produto *head_p, char *id){

    if (head_p == NULL){
        return NULL;
    }
    produto *temp_produto = head_p;
    while (temp_produto != NULL){

        if(temp_produto->id != NULL && strcmp(temp_produto -> id, id) == 0) return temp_produto;
        
        temp_produto = temp_produto -> prox;        
    } 
    return NULL;
}


void editar_produto(produto *produto_editado, char *novo_nome, char *novo_id, double novo_preco, short nova_qtd, short opcao){
    char *temp;
    
    switch (opcao) {
        case 1: 
            temp = realloc(produto_editado->nome, strlen(novo_nome) + 1);
            if (temp != NULL) {
                produto_editado->nome = temp;
                strcpy(produto_editado->nome, novo_nome);
            }
            break;
        
        case 2: 
            temp = realloc(produto_editado->id, strlen(novo_id) + 1);
            if (temp != NULL) {
                produto_editado->id = temp;
                strcpy(produto_editado->id, novo_id);
            }
            break;
            
        case 3: 
            produto_editado->preco = novo_preco;
            break;
            
        case 4: 
            produto_editado->qtd = nova_qtd;
            break;
    }
}

