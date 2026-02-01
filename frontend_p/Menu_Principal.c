#include "frontend_p/frontend.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* --- to achando q essa função vai ter que receber ponteiro duplo (**) para alterar na memoria o NULL do head_c---*/
void menu_principal(cliente *head_c, produto *head_p){
    int opcao = 0;
    while (1){
        printf ("- - - - - - Loja Dolphin - - - - - -\n\n");
        printf ("1- Gerenciamento de Clientes.\n");
        printf ("2- Gerenciamento de Produtos.\n");
        printf ("3- Modo Compra.\n");
        printf ("4- Sair do sistema.\n");
        printf("Digite a opcao desejada:\n");


        if (scanf(" %d", &opcao) != 1) {
            while (getchar() != '\n'); 
            system("cls");
            printf("Opcao Invalida!\n");
            continue;
        }
        system("cls");
        printf("Opcao escolhida: %d\n", opcao);
         
        switch (opcao)
        {
        case 1:
            menu_gerenciamento_clientes(&head_c,&head_p);
            break;
        case 2:
            menu_gerenciamento_produtos(head_c,head_p);
            break;
        case 3:
            menu_modo_compra(head_c, head_p);
            break;
        case 4:
            exit(0);
        default:
            printf("Opcao Invalida!\n");
        } 
    } 
}
