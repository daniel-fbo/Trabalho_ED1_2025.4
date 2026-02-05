#include "frontend.h"

void menu_principal(cliente **head_c, produto **head_p){
    system("cls");
    int opcao;
    while (SIM){
        printf (ROXO"- - - - - - Loja Dolphin - - - - - -\n\n"BRANCO);
        printf ("1- Gerenciamento de Clientes.\n");
        printf ("2- Gerenciamento de Produtos.\n");
        printf ("3- Modo Compra.\n");
        printf ("4- Sair do sistema.\n\n");
        printf("Digite a opcao desejada:\n");

        scanf(" %d", &opcao);
        while(getchar() != '\n'); 

        switch (opcao){
        case 1:
            system("cls");
            menu_gerenciamento_clientes(head_c,head_p);
            break;
        case 2:
            system("cls");
            menu_gerenciamento_produtos(head_c,head_p);
            break;
        case 3:
            system("cls");
            menu_modo_compra(*head_c, *head_p);
            break;
        case 4:
            system("cls");
            printf(VERDE "Saindo do programa..."BRANCO);
            return;
        default:
            system("cls");
            printf(VERMELHO"Opcao Invalida! Digite novamente!\n\n"BRANCO);
        } 
    } 
}
