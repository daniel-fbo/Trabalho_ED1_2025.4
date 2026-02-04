#include "backend.h"

void adicionar_carrinho(cliente *head_c, produto *head_p, char *id, int qtd){
    
    produto *achar_produto = head_p;

    if(qtd <= 0 ) return;
    
    while(achar_produto != NULL && strcmp(achar_produto->id, id) != 0 ){
        achar_produto = achar_produto->prox;

    }

    if(achar_produto == NULL) return;

    if(achar_produto->qtd < qtd){

        printf(VERMELHO"Quantidade nao suficiente no estoque.\n"BRANCO);
        printf("Disponivel: %d\n", achar_produto->qtd);
        enter();
        return;

    }

    itemcarrinho *item_ja_existe = head_c->carrinho->itens;

    while(item_ja_existe != NULL){

        if(item_ja_existe->produto == achar_produto){

            item_ja_existe->qtd += qtd;
            achar_produto->qtd -= qtd;
            return;

        }
        item_ja_existe = item_ja_existe->prox;
    }

    itemcarrinho *novo_item = malloc(sizeof(itemcarrinho));

    novo_item->produto = achar_produto;
    novo_item->qtd = qtd;

    novo_item->prox = head_c->carrinho->itens;
    head_c->carrinho->itens = novo_item;

    achar_produto->qtd -= qtd;
}

void listar_itens_carrinho(cliente *head_c, produto *head_p){
    
    itemcarrinho *item = head_c->carrinho->itens;

    if(item == NULL){
        printf(VERMELHO"Carrinho vazio. Adicione um item. \n"BRANCO);
        enter();
        return;
    }
    while(item != NULL){
        printf("- COD: %s | Qtd: %hd | Produto: %s | preco: %.2lf\n", item->produto->id, item->qtd , item->produto->nome , item->produto->preco);

        item = item->prox;
    }
    
    enter();
    return;
}

void retirar_carrinho(cliente *head_c, produto *head_p, char *id, int qtd){
    
    itemcarrinho *item = head_c->carrinho->itens;

    if(qtd <= 0 ) return;

    if(item == NULL){
        printf(VERMELHO"Carrinho vazio. Adicione um item. \n"BRANCO);
        enter();
    }

    produto *achar_produto = head_p;

    while(achar_produto != NULL && strcmp(achar_produto->id, id) != 0 ){
        achar_produto = achar_produto->prox;

    }

    if(achar_produto == NULL) return;

    itemcarrinho *anterior = NULL;
    itemcarrinho *atual = head_c->carrinho->itens;

    while(atual != NULL){

        if(atual->produto == achar_produto){

            if(atual->qtd > qtd){
                atual->qtd -= qtd;
                achar_produto->qtd += qtd;
            } else {
                if(anterior == NULL){
                    head_c->carrinho->itens = atual->prox;
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