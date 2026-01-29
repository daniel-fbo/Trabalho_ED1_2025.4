#include "frontend.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void menu_gerenciamento_clientes(cliente *head_c, produto *head_p){
    int opcao=-1;
    while (opcao<1 || opcao>4){
        printf ("- - - - - - Gerenciamento de Clientes - - - - - -\n\n");
        printf ("1- Cadastrar cliente.\n");
        printf ("2- Listar clientes.\n");
        printf ("3- Buscar cliente pelo CPF.\n");
        printf ("4- Editar dados de um cliente.\n");
        printf ("5- Remover cliente.\n");
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
    if (opcao==1){menu_cadastro_cliente(head_c, head_p);};
    if (opcao==2){listar_clientes(head_c);};
    if (opcao==3){menu_buscar_cliente(head_c, head_p);};
    //if (opcao==4){menu_editar_cliente(head_c, head_p);};
    if (opcao==5){menu_remover_cliente(head_c, head_p);};
}


void menu_cadastro_cliente(cliente *head_c, produto *head_p){
    printf("- - - - - - Cadastro de Aluno - - - - - -\n\n");
    printf("Digite o nome do cliente:\n");
    char nome[100];
    scanf("%[^\n]", nome);
    printf("Digite o CPF do cliente:\n");
    char cpf[12];
    scanf("%[^\n]", cpf);  
    printf("Digite o telefone do clienta:\n");
    char telefone[12];
    scanf("%[^\n]", telefone);
    printf("Digite o email do cliente:\n");
    char email[50];
    scanf("%[^\n]", email); 
    printf("Digite a data de nascimento do cliente (formato DD/MM/AAAA):\n");
    short dia, mes;
    int ano;
    scanf("%hd/%hd/%d\n", &dia, &mes, &ano);
    
    data *data_nascimento;
    data_nascimento = malloc(sizeof(data));
    data_nascimento -> dia = dia;
    data_nascimento -> mes = mes;
    data_nascimento -> ano = ano;

    cadastrar_cliente(head_c, nome, cpf, telefone, email, data_nascimento);
    menu_principal(head_c, head_p);
}



void menu_buscar_cliente(cliente *head_c, produto *head_p){
    printf("- - - - - - Buscar Cliente - - - - - -\n\n");
    printf("Digite o cpf do cliente:\n");
    char cpf[12];
    scanf("%%[^\n]", cpf);
    buscar_cliente(head_c, cpf);
    menu_principal(head_c, head_p);    
}

void menu_remover_cliente(cliente *head_c, produto *head_p){
    printf("- - - - - - Remover Cliente - - - - - -\n\n");
    printf("Digite o cpf do cliente:\n");
    char cpf[12];
    scanf("%%[^\n]", cpf);
    cliente *cliente_removido = buscar_cliente(head_c, cpf);
    remover_clientes(head_c, cliente_removido);
    menu_principal(head_c, head_p);    
}

