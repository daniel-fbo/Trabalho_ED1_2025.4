#pragma once

#include "backend_p/backend.h"
#include "persistencia_p/persistencia.h"

// Editar/buscar um elemento de uma lista = ponteiro simples
// Cadastrar/remover em uma lista um elemento = ponteiro duplo

void menu_principal(cliente *head_c, produto *head_p);

void menu_gerenciamento_produtos(cliente **head_c, produto **head_p);
void menu_cadastro_produto(cliente *head_c, produto **head_p);
void menu_remover_produto(cliente *head_c, produto **head_p);
void menu_buscar_produto(cliente *head_c, produto *head_p);
void menu_editar_produto(cliente *head_c, produto *head_p);

void menu_gerenciamento_clientes(cliente **head_c, produto **head_p);
void menu_cadastro_cliente(cliente **head_c, produto *head_p);
void menu_remover_cliente(cliente **head_c, produto *head_p);
void menu_buscar_cliente(cliente *head_c, produto *head_p);
void menu_editar_cliente(cliente *head_c, produto *head_p);

void menu_modo_compra(cliente *head_c, produto *head_p);
void menu_adicionar_carrinho(cliente *head_c, produto *head_p);
void menu_retirar_carrinho(cliente *head_c, produto *head_p);
void menu_mostrar_carrinho(cliente *head_c, produto *head_p);
void adicionar_carrinho(cliente *head_c, produto *head_p, char *id, int qtd);
void listar_itens_carrinho(cliente *head_c, produto *head_p);
void retirar_carrinho(cliente *head_c, produto *head_p, char *id, int qtd);

static inline void enter() {
    printf("Tecle ENTER para voltar...\n");
    while (getchar() != '\n');
    getchar();
    system("cls");
}