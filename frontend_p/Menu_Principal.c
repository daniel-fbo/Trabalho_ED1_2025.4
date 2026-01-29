#include "frontend.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void menu_principal(cliente *head_c, produto *head_p){
    int opcao=-1;
    while (opcao<1 || opcao>4){
        printf ("- - - - - - Loja Dolphin - - - - - -\n\n");
        printf ("1- Gerenciamento de Clientes.\n");
        printf ("2- Gerenciamento de Produtos.\n");
        printf ("3- Modo Compra.\n");
        printf ("4- Sair do sistema.\n");
        printf("Digite a opcao desejada:\n");
        scanf(" %d\n", &opcao);
        if (opcao==4){
            return;
        }
        if (opcao<1 || opcao>4){
            system("cls");
            printf("\033[4;31mOPCAO INVALIDA. DIGITE NOVAMENTE.\033[0m\n\n\n");
        }
    }
    system("cls");
    if (opcao==1){menu_gerenciamento_clientes(head_c, head_p);};
    if (opcao==2){menu_gerenciamento_produtos(head_c, head_p);};
    //if (opcao==3){menu_modo_compra(head_c, head_p);};
}
