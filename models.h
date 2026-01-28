#pragma once
#include "models.h"

typedef struct Carrinho {
    struct Cliente *cliente;
    struct Produto *prox;
} carrinho;

typedef struct Cliente {
    char nome[50];
    char cpf[12];
    char telefone[12];
    carrinho *carrinho;
    struct Cliente *prox;
} cliente;

typedef struct Produto {
    char id[20];
    char nome[50];
    double preco;
    struct Produto *prox;
} produto;


void cadastrar_cliente(cliente *head_c, char *nome, char *cpf, char *telefone);
void cadastrar_produto(produto *head_p, char *nome, char *id, double preco);

void listar_clientes(cliente *head_c);
void listar_produtos (produto *head_p);


cliente *buscar_cliente(cliente *head_c, char *cpf);
produto *buscar_produto(produto *head_p, char *id);

void editar_cliente(cliente *cliente_editado, char *novo_nome, char *novo_cpf, char *novo_telefone, short opcao);
void editar_produto(produto *produto_editado, char *novo_nome, char *novo_id, double novo_preco, short opcao);

void remover_clientes(cliente *head_c, cliente *cliente_removido);
void remover_produtos (produto *head_p, produto *produto_removido);



