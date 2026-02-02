#include "frontend.h"

void menu_principal(cliente *head_c, produto *head_p){
    int opcao;
    while (SIM){
        printf ("- - - - - - Loja Dolphin - - - - - -\n\n");
        printf ("1- Gerenciamento de Clientes.\n");
        printf ("2- Gerenciamento de Produtos.\n");
        printf ("3- Modo Compra.\n");
        printf ("4- Sair do sistema.\n");
        printf("Digite a opcao desejada:\n");

        scanf(" %d", &opcao);

        switch (opcao)
        {
        case 1:
            menu_gerenciamento_clientes(&head_c,&head_p);
            break;
        case 2:
            menu_gerenciamento_produtos(&head_c,&head_p);
            break;
        case 3:
            menu_modo_compra(head_c, head_p);
            break;
        case 4:
            printf(VERDE "Saindo do programa...");
            exit(EXIT_SUCCESS);
        default:
            system("cls");
            printf(VERMELHO"Opcao Invalida! Digite novamente!\n\n"BRANCO);
        } 
    } 
}
