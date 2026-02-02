#include "frontend.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
//talvez com ponteiro duplo para alterar
void menu_gerenciamento_clientes(cliente **head_c, produto **head_p){
    int opcao=0;
    while (1){
        system("cls");
        printf ("- - - - - - Gerenciamento de Clientes - - - - - -\n\n");
        printf ("1- Cadastrar cliente.\n");
        printf ("2- Listar clientes.\n");
        printf ("3- Buscar cliente pelo CPF.\n");
        printf ("4- Editar dados de um cliente.\n");
        printf ("5- Remover cliente.\n");
        printf ("6- Voltar ao menu principal.\n");
        printf("Digite a opcao desejada:\n");
        scanf(" %d", &opcao);
        
        switch (opcao)
        {
        case 1:
            menu_cadastro_cliente(head_c, *head_p);
            break;
        case 2:
            listar_clientes(*head_c);
            break;
        case 3:
            menu_buscar_cliente(*head_c, *head_p);
            break;
        /* case 4:
            menu_editar_cliente(*head_c, *head_p);
            break; */
        case 5:
            menu_remover_cliente(head_c, *head_p);
            break;
        case 6:
            return;
            break;
        default:
            printf("Opcao Invalida!\n");
            break;
        }
    }
}


void menu_cadastro_cliente(cliente **head_c, produto *head_p){
    system("cls");
    cliente *cliente = malloc(sizeof(cliente));

    cliente->nome = malloc(50);
    cliente->cpf = malloc(12);
    cliente->telefone = malloc(12);
    cliente->email = malloc(60);

    data *data_nascimento = malloc(sizeof(data));

    printf("- - - - - - Cadastro de Cliente - - - - - -\n\n");
    printf("Digite o nome do cliente:\n");
    scanf(" %[^\n]", cliente->nome);
    printf("Digite o CPF do cliente:\n");
    scanf(" %[^\n]", cliente->cpf);  
    printf("Digite o telefone do cliente:\n");
    scanf(" %[^\n]", cliente->telefone);
    printf("Digite o email do cliente:\n");
    scanf(" %[^\n]", cliente->email); 
    printf("Digite a data de nascimento do cliente (formato DD/MM/AAAA):\n");
    short dia, mes;
    int ano;
    scanf("%hd/%hd/%d", &dia, &mes, &ano);
    
    data_nascimento -> dia = dia;
    data_nascimento -> mes = mes;
    data_nascimento -> ano = ano;

    printf("\nCliente cadastrado com sucesso!\n");
    printf("Pressione uma tecla para sair");
    getchar();
    
    cadastrar_cliente(head_c, cliente->nome, cliente->cpf, cliente->telefone, cliente->email, data_nascimento);

    return;
}



void menu_buscar_cliente(cliente *head_c, produto *head_p){
    system("cls");

    printf("- - - - - - Buscar Cliente - - - - - -\n\n");
    printf("Digite o cpf do cliente:\n");

    char cpf[12];
    scanf(" %[^\n]", cpf);

    buscar_cliente(head_c, cpf);
  
    return;  
}

void menu_remover_cliente(cliente **head_c, produto *head_p){
    system("cls");


    printf("- - - - - - Remover Cliente - - - - - -\n\n");
    printf("Digite o cpf do cliente:\n");

    char cpf[12];
    scanf(" %[^\n]", cpf);

    cliente *cliente_removido = buscar_cliente(*head_c, cpf);

    remover_clientes(head_c, cliente_removido);
   
    return; 
}

//implementar a função editar cliente