#include "frontend.h"

void menu_gerenciamento_clientes(cliente **head_c, produto **head_p){
    int opcao;
    while (SIM){
        printf ("- - - - - - Gerenciamento de Clientes - - - - - -\n\n");
        printf ("1- Cadastrar cliente.\n");
        printf ("2- Remover cliente.\n");
        printf ("3- Listar clientes.\n");
        printf ("4- Buscar cliente pelo CPF.\n");
        printf ("5- Editar dados de um cliente.\n");
        printf ("6- Voltar ao menu principal.\n");
        printf("Digite a opcao desejada:\n");
        scanf(" %d", &opcao);
        
        switch (opcao)
        {
        case 1:
            system("cls");          
            menu_cadastro_cliente(head_c, *head_p);
            break;
        case 2:
            system("cls"); 
            menu_remover_cliente(head_c, *head_p);
            break;
        case 3:
            listar_clientes(*head_c);
            break;
        case 4:
            system("cls"); 
            menu_buscar_cliente(*head_c, *head_p);
            break;
        case 5:
            system("cls"); 
            menu_editar_cliente(*head_c, *head_p);
            break; 
        case 6:
            system("cls");
            return;
        default:
            system("cls");
            printf(VERMELHO"Opcao Invalida! Digite novamente!\n\n"BRANCO);
            break;
        }
    }
}

void menu_cadastro_cliente(cliente **head_c, produto *head_p){
    char nome[100], cpf[12], telefone[12], email[50];
    short dia, mes; int ano;

    printf("- - - - - - Cadastro de Cliente - - - - - -\n\n");
    printf("Digite o nome do cliente:\n");
    scanf(" %[^\n]", nome);
    printf("Digite o CPF do cliente:\n");
    scanf(" %[^\n]", cpf);  
    printf("Digite o telefone do cliente:\n");
    scanf(" %[^\n]", telefone);
    printf("Digite o email do cliente:\n");
    scanf(" %[^\n]", email); 
    printf("Digite a data de nascimento do cliente (formato DD/MM/AAAA):\n");
    short dia, mes;
    int ano;
    scanf("%hd/%hd/%d", &dia, &mes, &ano);

    data *data_nascimento = malloc(sizeof(data));
    data_nascimento->dia = dia;
    data_nascimento->mes = mes;
    data_nascimento->ano = ano;

    cadastrar_cliente(head_c, nome, cpf, telefone, email, data_nascimento);
    return;
}

void menu_buscar_cliente(cliente *head_c, produto *head_p){
    printf("- - - - - - Buscar Cliente - - - - - -\n\n");
    printf("Digite o cpf do cliente:\n");

    char cpf[12];
    scanf(" %[^\n]", cpf);

    cliente *temp_cliente = buscar_cliente(head_c, cpf);

    printf("\n\nNome do cliente: %s\n", temp_cliente -> nome);
    printf("CPF: %s\n", temp_cliente -> cpf);
    printf("Telefone: %s\n", temp_cliente -> telefone);
    printf("Email: %s\n", temp_cliente -> email);
    printf("Data de nascimento: %hd/%hd/%d\n", temp_cliente -> data_nascimento -> dia, temp_cliente -> data_nascimento -> mes, temp_cliente -> data_nascimento -> ano);

    printf("Pressione qualquer tecla para voltar...");
    while (getchar() != '\n'); getchar();

    return;  
}

void menu_remover_cliente(cliente **head_c, produto *head_p){
    printf("- - - - - - Remover Cliente - - - - - -\n\n");
    printf("Digite o cpf do cliente:\n");

    char cpf[12];
    scanf(" %[^\n]", cpf);
    cliente *cliente_removido = buscar_cliente(*head_c, cpf);
    remover_clientes(head_c, cliente_removido);
    return; 
}

void menu_editar_cliente(cliente *head_c, produto *head_p){

    printf("- - - - - - Editar Cliente - - - - - -\n\n");
    printf("Digite o cpf do cliente a ser editado:\n");

    char cpf[12];
    scanf(" %[^\n]", cpf);
    cliente *temp_cliente = buscar_cliente(head_c, cpf);

    printf("\n\nNome do cliente: %s\n", temp_cliente -> nome);
    printf("CPF: %s\n", temp_cliente -> cpf);
    printf("Telefone: %s\n", temp_cliente -> telefone);
    printf("Email: %s\n", temp_cliente -> email);
    printf("Data de nascimento: %hd/%hd/%d\n\n", temp_cliente -> data_nascimento -> dia, temp_cliente -> data_nascimento -> mes, temp_cliente -> data_nascimento -> ano);


    int opcao;
    while (SIM){
        printf ("1- Editar nome.\n");
        printf ("2- Editar cpf.\n");
        printf ("3- Editar telefone.\n");
        printf ("4- Editar email.\n");
        printf ("5- Editar data de nascimento.\n");
        printf("Digite a opcao desejada:\n");
        scanf(" %d", &opcao);

        switch(opcao){
            case 1:
                printf("Qual o novo nome?\n");
                scanf("%[^\n]", temp_cliente ->nome);
                break;
            case 2:
                printf("Qual o novo cpf?\n");
                scanf("%[^\n]", temp_cliente -> cpf);
                break;
            case 3:
                printf("Qual o novo telefone?\n");
                scanf("%[^\n]", temp_cliente -> telefone);
                break;
            case 4:
                printf("Qual o novo email?\n");
                scanf("%[^\n]", temp_cliente -> email);
                break;
            case 5:
                printf("Digite a data de nascimento do cliente (formato DD/MM/AAAA):\n");
                short dia, mes;
                int ano;
                scanf("%hd/%hd/%d", &dia, &mes, &ano);

                temp_cliente -> data_nascimento-> dia = dia;
                temp_cliente -> data_nascimento-> mes = mes;
                temp_cliente -> data_nascimento-> ano = ano;

            default:
                system("cls");
                printf(VERDE"Opcao invalida! Digite novamente.\n\n"BRANCO);
                break;
        } 
    }

    editar_cliente(temp_cliente, temp_cliente -> nome, temp_cliente -> cpf, temp_cliente -> telefone, temp_cliente -> email, temp_cliente -> data_nascimento, opcao);
    return;  
}


