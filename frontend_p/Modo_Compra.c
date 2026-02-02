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

    cliente *encontrado = head_c; 
    char cpf_digitado[12];
    printf("Digite o CPF para comprar:\n");
    scanf(" %[^\n]",cpf_digitado);
    while (getchar() != '\n');

    encontrado = buscar_cliente(head_c,cpf_digitado); 
    
    if(encontrado != NULL){
        system("cls");
        int opcao = 0;

        printf("\n--- MODO COMPRA --> Perfil (%s) <-----\n", encontrado->nome);
        printf(" 1 - Listar Produtos\n");
        printf(" 2 - Adicionar no Carrinho\n");
        printf(" 3 - Ver carrinho\n");
        printf(" 4 - Retirar do carrinho\n");
        printf(" 5 - Voltar ao Menu Principal\n");
        printf("Digite uma opcao: \n");
        scanf(" %d", &opcao);

        switch (opcao)
        {
        case 1:
            listar_produtos(head_p);
        case 2:
            menu_adicionar_carrinho(head_c,head_p);
            break;
        case 3:
            menu_mostrar_carrinho(head_c,head_p);
            break;
        case 4:
            menu_retirar_carrinho(head_c,head_p);
            break;
        case 5:
            system("cls");
            return;
            break;
        default:
            printf("Opcao invalida");
            break;
        }
    } else{
        system("cls");
        printf("Cliente nao encontrado\n");
        printf("Pressione qualquer tecla para voltar...");
        while (getchar() != '\n'); getchar();
        return;
    } 
}