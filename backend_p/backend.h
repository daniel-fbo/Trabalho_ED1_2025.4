#pragma once

typedef struct Data{
    short dia;
    short mes;
    int ano;
} data;

typedef struct Carrinho {
    struct Cliente *cliente;
    struct Produto *prox;
} carrinho;

typedef struct Cliente { 
    char *nome;
    char *cpf;
    char *telefone;
    char *email;
    data *data_nascimento;
    struct Cliente *prox;
} cliente;

typedef struct Produto {
    char *id;
    char *nome;
    short qtd;
    double preco;
    struct Produto *prox;
} produto;


void cadastrar_cliente(cliente **head_c, char *nome, char *cpf, char *telefone, char *email, data *data_nascimento);
void cadastrar_produto(produto **head_p, char *nome, char *id, double preco, short qtd);

void listar_clientes(cliente *head_c);
void listar_produtos (produto *head_p);


cliente *buscar_cliente(cliente *head_c, char *cpf);
produto *buscar_produto(produto *head_p, char *id);

void editar_cliente(cliente *cliente_editado, char *novo_nome, char *novo_cpf, char *novo_telefone, char *novo_email, data *nova_data_nascimento, short opcao);
void editar_produto(produto *produto_editado, char *novo_nome, char *novo_id, double novo_preco, short nova_qtd, short opcao);

//acho q será necessário ponteiro duplo aq tbm
void remover_clientes(cliente **head_c, cliente *cliente_removido);
void remover_produtos (produto **head_p, produto *produto_removido);
