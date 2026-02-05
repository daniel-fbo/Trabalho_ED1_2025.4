# Trabalho Prático — Listas Encadeadas em C

**CRUD de Clientes e Produtos**

## Descrição

Uma empresa de pequeno porte deseja informatizar o controle básico de **clientes** e **produtos** por meio de uma aplicação simples executada no **terminal**.

O objetivo deste trabalho é desenvolver um sistema na linguagem **C** que utilize **listas simplesmente encadeadas** para armazenar e manipular os dados dinamicamente, implementando operações completas de **CRUD**.

---

## Funcionalidades

O sistema deve possui um **menu principal** com três opções:

- Gerenciamento de Clientes
- Gerenciamento de Produtos
- Modo Compra

---

## Clientes

O sistema permite:

- Cadastrar um cliente (CPF, data de nascimento, email, nome e telefone);
- Listar todos os clientes;
- Buscar um cliente pelo seu CPF;
- Editar dados de um cliente;
- Remover um cliente;

---

## Produtos

O sistema permite:

- Cadastrar um produto (código único, nome, quantidade e preço);
- Listar todos os produtos;
- Buscar produto pelo código;
- Editar dados de um produto;
- Remover um produto;

---

## Modo Compra

O sistema permite:

- Um cliente incluir produtos que deseja comprar no carrinho;
- Listar os produtos do carrinho de um cliente;
- Retirar os produtos do carrinho de um cliente;

---

## Requisitos Técnicos

- Implementação **exclusiva em C**;
- Uso de **listas simplesmente encadeadas**;
- Uso de **alocação dinâmica de memória** (`malloc`, `calloc`, `realloc` e `free`);
- **Sem** o uso de variáveis globais;
- Manipulação das listas por **passagem de parâmetros**;
- Menu funcional via terminal;

