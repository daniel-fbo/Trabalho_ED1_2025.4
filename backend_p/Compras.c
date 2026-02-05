#include "backend.h"

#include "backend.h"

void adicionar_carrinho(cliente *cliente_atual, produto *head_p, char *id, int qtd){
    produto *achar_produto = head_p;
    if(qtd <= 0 ) return;
    
    while(achar_produto != NULL && strcmp(achar_produto->id, id) != 0 ){
        achar_produto = achar_produto->prox;
    }

    if(achar_produto == NULL) {
        printf(VERMELHO"Produto nao encontrado.\n"BRANCO);
        return;
    }

    if(achar_produto->qtd < qtd){
        printf(VERMELHO"Quantidade nao suficiente no estoque.\n"BRANCO);
        printf("Disponivel: %d\n", achar_produto->qtd);
        return;
    }

    itemcarrinho *item_ja_existe = cliente_atual->carrinho->itens;

    while(item_ja_existe != NULL){
        if(item_ja_existe->produto == achar_produto){
            item_ja_existe->qtd += qtd;
            achar_produto->qtd -= qtd;
            printf(VERDE "Produto adicionado ao carrinho com sucesso!\n" BRANCO);
            return;
        }
        item_ja_existe = item_ja_existe->prox;
    }

    itemcarrinho *novo_item = malloc(sizeof(itemcarrinho));
    novo_item->produto = achar_produto;
    novo_item->qtd = qtd;

    novo_item->prox = cliente_atual->carrinho->itens;
    cliente_atual->carrinho->itens = novo_item;

    achar_produto->qtd -= qtd;
    printf(VERDE "Produto adicionado ao carrinho com sucesso!\n" BRANCO);
}

void listar_itens_carrinho(cliente *cliente_atual, produto *head_p){
    itemcarrinho *item = cliente_atual->carrinho->itens;

    if(item == NULL){
        printf(VERMELHO"Carrinho vazio.\n"BRANCO);
        return;
    }
    while(item != NULL){
        printf("- COD: %s | Qtd: %hd | Produto: %s | Preco un: %.2lf | Total: %.2lf\n", 
            item->produto->id, item->qtd , item->produto->nome , item->produto->preco, (item->produto->preco * item->qtd));
        item = item->prox;
    }
    return;
}

void retirar_carrinho(cliente *cliente_atual, produto *head_p, char *id, int qtd){
    itemcarrinho *item = cliente_atual->carrinho->itens;

    if(qtd <= 0 ) return;

    if(item == NULL){
        printf(VERMELHO"Carrinho vazio. Nada a retirar. \n"BRANCO);
        return; 
    }

    produto *achar_produto = head_p;
    while(achar_produto != NULL && strcmp(achar_produto->id, id) != 0 ){
        achar_produto = achar_produto->prox;
    }
    if(achar_produto == NULL) return;

    itemcarrinho *anterior = NULL;
    itemcarrinho *atual = cliente_atual->carrinho->itens;

    while(atual != NULL){
        if(atual->produto == achar_produto){
            if(atual->qtd > qtd){
                atual->qtd -= qtd;
                achar_produto->qtd += qtd;
            } else {
                achar_produto->qtd += atual->qtd; 
                if(anterior == NULL){
                    cliente_atual->carrinho->itens = atual->prox;
                } else {
                    anterior->prox = atual->prox;
                }
                free(atual);
            }
            return; 
        }
        anterior = atual;
        atual = atual->prox;
    }
}