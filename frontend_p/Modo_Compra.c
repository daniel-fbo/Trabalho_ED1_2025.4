#include "frontend.h"
#include "backend_p/backend.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu_modo_compra(cliente *head_c,produto *head_p){
    system("cls");
    printf("--- MODO COMPRA ---\n");

    if(head_c == NULL) {
        printf("Erro: Nao ha clientes cadastrados!\n");
        printf("Pressione qualquer tecla para voltar...");
        while (getchar() != '\n'); getchar();
        return;
    }

    cliente *encontrado; 
    char cpf_digitado[12];
    printf("Digite o CPF para comprar:\n");
    scanf(" %[^\n]",cpf_digitado);
    while (getchar() != '\n');

    encontrado = buscar_cliente(head_c,cpf_digitado);

    if(encontrado != NULL){
        printf("Cliente encontrado: %s\n", encontrado->nome);

        printf("\n\n-------- LISTA DOS PRODUTOS --------\n\n");
        listar_produtos(head_p);

    } else printf("Cliente nao cadastrado\n");

    printf("\n\nPressione Enter para voltar ao menu...");
    getchar();
}