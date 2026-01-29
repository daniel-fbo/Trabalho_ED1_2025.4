#pragma once

#include "backend.h"
#include "persistencia.h"
  
void menu_modo_compra(cliente *head_c, produto *head_p);
void menu_adicionar_carrinho(cliente *head_c, produto *head_p);
void menu_retirar_carrinho(cliente *head_c, produto *head_p);
void menu_mostrar_carrinho(cliente *head_c, produto *head_p);

void menu_gerenciamento_produtos(cliente *head_c, produto *head_p);
void menu_cadastro_produto(cliente *head_c, produto *head_p);
void menu_buscar_produto(cliente *head_c, produto *head_p);
void menu_remover_produto(cliente *head_c, produto *head_p);
void menu_editar_produto(cliente *head_c, produto *head_p);

void menu_gerenciamento_clientes(cliente *head_c, produto *head_p);
void menu_cadastro_cliente(cliente *head_c, produto *head_p);
void menu_buscar_cliente(cliente *head_c, produto *head_p);
void menu_remover_cliente(cliente *head_c, produto *head_p);
void menu_editar_cliente(cliente *head_c, produto *head_p);

void menu_principal(cliente *head_c, produto *head_p);
