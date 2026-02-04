#include "backend.h"

void cadastrar_produto(produto **head_p, char *nome, char *id, double preco, short qtd){
    produto *produto_novo;
    produto_novo = malloc (sizeof(produto)); 

    produto_novo->nome = malloc(strlen(nome) + 1);
    produto_novo->id = malloc(strlen(id) + 1);
    strcpy(produto_novo->nome,nome);
    strcpy(produto_novo->id,id);
    produto_novo->preco = preco;
    produto_novo->qtd = qtd;

    produto_novo -> prox = *head_p;
    *head_p = produto_novo;

    system("cls");
    printf(VERDE "Produto cadastrado com sucesso!\n\n" BRANCO);
    printf("Tecle Enter para voltar...\n");
    while (getchar() != '\n');
    getchar();
    system("cls");
    return;
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
    printf("Tecle ENTER para voltar...\n");
    while (getchar() != '\n');
    getchar();
    system("cls");
}

void listar_produtos (produto *head_p){

    system("cls");
    printf(ROXO "- - - - - - Lista de Produtos - - - - - -\n\n" BRANCO);

    if (head_p == NULL)
    {
        system("cls");
        printf(VERMELHO "Erro: Nao ha produtos cadastrados\n\n" BRANCO);
        printf("Tecle ENTER para voltar...\n");
        while (getchar() != '\n');
        getchar();
        system("cls");
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

    printf("Tecle ENTER para voltar...\n");
    while (getchar() != '\n');
    system("cls");
}

produto *buscar_produto(produto *head_p, char *id){

    if (head_p == NULL) return NULL;

    produto *temp_produto = head_p;

    while (temp_produto != NULL){

        if(temp_produto->id != NULL && strcmp(temp_produto -> id, id) == 0) return temp_produto;
        
        temp_produto = temp_produto -> prox;        
    } 
    printf(VERMELHO"\033[4;31mProduto não encontrado.\033[0m Tecle Enter para voltar."BRANCO);
    getchar();
    system("cls");
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


