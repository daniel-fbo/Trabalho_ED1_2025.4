#include "frontend.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu_gerenciamento_produtos(cliente *head_c, produto *head_p){
    int opcao=-1;
    while (opcao<1 || opcao>4){
        printf ("- - - - - - Gerenciamento de Produtos - - - - - -\n\n");
        printf ("1- Cadastrar produto.\n");
        printf ("2- Listar produtos.\n");
        printf ("3- Buscar produto pelo codigo unico.\n");
        printf ("4- Editar dados de um produto.\n");
        printf ("5- Remover produto.\n");
        printf ("6- Voltar ao menu principal.\n");
        printf("Digite a opcao desejada:\n");
        scanf(" %d\n", &opcao);
        if (opcao==6){
            menu_principal(head_c, head_p);
        }
        if (opcao<1 || opcao>6){
            system("cls");
            printf("\033[4;31mOPCAO INVALIDA. DIGITE NOVAMENTE.\033[0m\n\n\n");
        }
    }
    system("cls");
    if (opcao==1){menu_cadastro_produto(head_c, head_p);};
    if (opcao==2){listar_produtos(head_p);};
    if (opcao==3){menu_buscar_produto(head_c, head_p);};
    //if (opcao==4){menu_editar_produto(head_c, head_p);};
    if (opcao==5){menu_remover_produto(head_c, head_p);};
}

void menu_cadastro_produto(cliente *head_c, produto *head_p){
    printf("- - - - - - Cadastro de Produto - - - - - -\n\n");
    printf("Digite o nome do produto:\n");
    char nome[100];
    scanf("%[^\n]", nome);
    printf("Digite o codigo unico do produto:\n");
    char id[12];
    scanf("%[^\n]", id);  
    printf("Digite o preco do produto:\n");
    double preco;
    scanf("%.2lf", &preco);
    printf("Digite a quantidade de itens em estoque do produto:\n");
    short qtd;
    scanf("%hd", &qtd); 

    cadastrar_produto(head_p, nome, id, preco, qtd);
    menu_principal(head_c, head_p);
}

void menu_buscar_produto(cliente *head_c, produto *head_p){
    printf("- - - - - - Buscar Produto - - - - - -\n\n");
    printf("Digite o codigo unico do produto:\n");
    char id[12];
    scanf("%%[^\n]", id);
    buscar_produto(head_p, id);
    menu_principal(head_c, head_p);    
}

void menu_remover_produto(cliente *head_c, produto *head_p){
    printf("- - - - - - Remover Produto - - - - - -\n\n");
    printf("Digite o cpf do produto:\n");
    char id[12];
    scanf("%%[^\n]", id);
    produto *produto_removido = buscar_produto(head_p, id);
    remover_produtos(head_p, produto_removido);
    menu_principal(head_c, head_p);    
}