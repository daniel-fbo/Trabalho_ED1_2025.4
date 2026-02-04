#include "frontend.h"

void menu_gerenciamento_clientes(cliente **head_c, produto **head_p){
    int opcao;
    while (SIM){
        printf (ROXO"- - - - - - Gerenciamento de Clientes - - - - - -\n\n"BRANCO);
        printf ("1- Cadastrar cliente.\n");
        printf ("2- Remover cliente.\n");
        printf ("3- Listar clientes.\n");
        printf ("4- Buscar cliente pelo CPF.\n");
        printf ("5- Editar dados de um cliente.\n");
        printf ("6- Voltar ao menu principal.\n\n");
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

    printf(ROXO"- - - - - - Cadastro de Cliente - - - - - -\n\n"BRANCO);
    printf("Digite o nome do cliente:\n");
    scanf(" %[^\n]", nome);
    printf("Digite o CPF do cliente (apenas numeros):\n");
    scanf(" %[^\n]", cpf);  
    printf("Digite o telefone do cliente:\n");
    scanf(" %[^\n]", telefone);
    printf("Digite o email do cliente:\n");
    scanf(" %[^\n]", email); 
    printf("Digite a data de nascimento do cliente (formato DD/MM/AAAA):\n");

    scanf("%hd/%hd/%d", &dia, &mes, &ano);

    data *data_nascimento = malloc(sizeof(data));
    if (data_nascimento == NULL) {
        printf(VERMELHO "Erro de memória!\n" BRANCO);
        return;
    }

    data_nascimento->dia = dia;
    data_nascimento->mes = mes;
    data_nascimento->ano = ano;

    cadastrar_cliente(head_c, nome, cpf, telefone, email, data_nascimento);

    return;
}

void menu_remover_cliente(cliente **head_c, produto *head_p){
    printf(ROXO"- - - - - - Remover Cliente - - - - - -\n\n"BRANCO);
    printf("Digite o cpf do cliente:\n");

    char cpf[12];
    scanf(" %[^\n]", cpf);
    cliente *cliente_removido = buscar_cliente(*head_c, cpf);
    remover_clientes(head_c, cliente_removido);
    
    return; 
}

void menu_buscar_cliente(cliente *head_c, produto *head_p){
    printf(ROXO"- - - - - - Buscar Cliente - - - - - -\n\n"BRANCO);
    printf("Digite o cpf do cliente:\n");

    char cpf[12];
    scanf(" %[^\n]", cpf);

    cliente *temp_cliente = buscar_cliente(head_c, cpf);
    if (temp_cliente == NULL) {
        printf(VERMELHO "Cliente nao encontrado. Tecle Enter para voltar." BRANCO);
        while (getchar() != '\n');
        getchar();
        system("cls");
        return;
    }

    system("cls");
    printf("\n\nNome do cliente: %s\n", temp_cliente -> nome);
    printf("CPF: %s\n", temp_cliente -> cpf);
    printf("Telefone: %s\n", temp_cliente -> telefone);
    printf("Email: %s\n", temp_cliente -> email);
    printf("Data de nascimento: %hd/%hd/%d\n", temp_cliente -> data_nascimento -> dia, temp_cliente -> data_nascimento -> mes, temp_cliente -> data_nascimento -> ano);

    printf("\nTecle Enter para voltar...");
    while (getchar() != '\n'); getchar();
    system("cls");
    return;  
}

void menu_editar_cliente(cliente *head_c, produto *head_p){
    printf(ROXO"- - - - - - Editar Cliente - - - - - -\n\n"BRANCO);
    printf("Digite o cpf do cliente a ser editado:\n");

    char cpf[12];
    scanf(" %[^\n]", cpf);
    cliente *temp_cliente = buscar_cliente(head_c, cpf);

    if (temp_cliente == NULL) {
        printf(VERMELHO "Cliente nao encontrado. Tecle Enter para voltar." BRANCO);
        while (getchar() != '\n');
        getchar();
        system("cls");
        return;
    }
    system("cls");
    printf("\n\nNome do cliente: %s\n", temp_cliente -> nome);
    printf("CPF: %s\n", temp_cliente -> cpf);
    printf("Telefone: %s\n", temp_cliente -> telefone);
    printf("Email: %s\n", temp_cliente -> email);
    printf("Data de nascimento: %02hd/%02hd/%04d\n\n", temp_cliente -> data_nascimento -> dia, temp_cliente -> data_nascimento -> mes, temp_cliente -> data_nascimento -> ano);


    int opcao=0;
    while (SIM){
        printf ("1- Editar nome.\n");
        printf ("2- Editar cpf.\n");
        printf ("3- Editar telefone.\n");
        printf ("4- Editar email.\n");
        printf ("5- Editar data de nascimento.\n");
        printf ("6- Sair/Finalizar.\n");
        printf("Digite a opcao desejada:\n");
        scanf(" %d", &opcao);
        while(getchar() != '\n');

        switch(opcao){
            case 1:
                printf("Qual o novo nome?\n");
                scanf("%[^\n]", temp_cliente ->nome);
                system("cls");
                break;
            case 2:
                printf("Qual o novo cpf?\n");
                scanf("%[^\n]", temp_cliente -> cpf);
                system("cls");
                break;
            case 3:
                printf("Qual o novo telefone?\n");
                scanf("%[^\n]", temp_cliente -> telefone);
                system("cls");
                break;
            case 4:
                printf("Qual o novo email?\n");
                scanf("%[^\n]", temp_cliente -> email);
                system("cls");
                break;
            case 5:
                printf("Digite a data de nascimento do cliente (formato DD/MM/AAAA):\n");
                short dia, mes;
                int ano;
                scanf("%hd/%hd/%d", &dia, &mes, &ano);

                temp_cliente -> data_nascimento-> dia = dia;
                temp_cliente -> data_nascimento-> mes = mes;
                temp_cliente -> data_nascimento-> ano = ano;
                system("cls");
                break;
            case 6:
                system("cls");
                return;
            default:
                system("cls");
                printf(VERMELHO"Opcao invalida! Digite novamente.\n\n"BRANCO);
                break;
        } 
    }

    editar_cliente(temp_cliente, temp_cliente -> nome, temp_cliente -> cpf, temp_cliente -> telefone, temp_cliente -> email, temp_cliente -> data_nascimento, opcao);
    system("cls");
    printf(VERDE "Cliente editado com sucesso!\n\n" BRANCO);
    printf("Tecle Enter para voltar...\n");
    while (getchar() != '\n');
    getchar();
    return;  
}


