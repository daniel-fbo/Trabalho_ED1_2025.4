#include "frontend.h"

void menu_gerenciamento_clientes(cliente **head_c, produto **head_p){
    int opcao;
    while (SIM){
        printf ("- - - - - - Gerenciamento de Produtos - - - - - -\n\n");
        printf ("1- Cadastrar produto.\n");
        printf ("2- Remover produto.\n");
        printf ("3- Listar produtos.\n");
        printf ("4- Buscar produto pelo codigo unico.\n");
        printf ("5- Editar dados de um produto.\n");
        printf ("6- Voltar ao menu principal.\n");
        printf("Digite a opcao desejada:\n");
        scanf(" %d", &opcao);
        
        switch (opcao)
        {
        case 1:
            system("cls");          
            menu_cadastro_produto(*head_c, head_p);
            break;
        case 2:
            system("cls"); 
            menu_remover_produto(*head_c, head_p);
            break;
        case 3:
            listar_produtos(*head_p);
            break;
        case 4:
            system("cls"); 
            menu_buscar_produto(*head_c, *head_p);
            break;
        case 5:
            system("cls"); 
            menu_editar_produto(*head_c, *head_p);
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

void menu_cadastro_produto(cliente *head_c, produto **head_p){
    char nome[100], id[6];
    short qtd;
    double preco;

    printf("- - - - - - Cadastro de Produto - - - - - -\n\n");
    printf("Digite o nome do produto:\n");
    scanf(" %[^\n]", nome);
    printf("Digite o codigo unico do produto:\n");
    scanf(" %[^\n]", id);  
    printf("Digite o preco do produto:\n");
    scanf(" %.2lf", preco); 
    printf("Digite a quantidade de itens em estoque:\n");
    scanf(" %hd", qtd);

    cadastrar_produto(head_p, nome, id, preco, qtd);
    return;
}

void menu_buscar_cliente(cliente *head_c, produto *head_p){
    printf("- - - - - - Buscar Produto - - - - - -\n\n");
    printf("Digite o codigo unico do produto:\n");

    char id[6];
    scanf(" %[^\n]", id);

    produto *temp_produto = buscar_produto(head_p, id);

    printf("\n\nNome do produto: %s\n", temp_produto -> nome);
    printf("Codigo unico: %s\n", temp_produto -> id);
    printf("Preco por unidade do produto: %.2lf\n", temp_produto -> preco);
    printf("Quantidade de itens em estoque: %hd\n", temp_produto -> qtd);
    printf("Pressione qualquer tecla para voltar...");
    while (getchar() != '\n'); getchar();

    return;  
}

void menu_remover_produto(cliente *head_p, produto **head_p){
    printf("- - - - - - Remover Produto - - - - - -\n\n");
    printf("Digite o codigo unico do produto:\n");
    char id[12];
    scanf(" %[^\n]", id);
    produto *produto_removido = buscar_produto(*head_p, id);
    remover_produtos(head_p, produto_removido);

    return;
}

void menu_editar_cliente(cliente *head_c, produto *head_p){

    printf("- - - - - - Editar Produto - - - - - -\n\n");
    printf("Digite o codigo unico do produto a ser editado:\n");

    char nome[100], id[6];
    short data()
    scanf(" %[^\n]", id);

    cliente *temp_cliente = buscar_cliente(head_c, cpf);
    strcpy (nome, temp_cliente -> nome);
    strcpy (telefone, temp_cliente -> telefone);
    strcpy (email, temp_cliente -> email);
    data *data_nascimento = temp_cliente -> data_nascimento;


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
                scanf("%[^\n]",nome);
                break;
            case 2:
                printf("Qual o novo cpf?\n");
                scanf("%[^\n]", cpf);
                break;
            case 3:
                printf("Qual o novo telefone?\n");
                scanf("%[^\n]", telefone);
                break;
            case 4:
                printf("Qual o novo email?\n");
                scanf("%[^\n]", email);
                break;
            case 5:
                printf("Digite a data de nascimento do cliente (formato DD/MM/AAAA):\n");
                short dia, mes;
                int ano;
                scanf("%hd/%hd/%d", &dia, &mes, &ano);

                data_nascimento->dia = dia;
                data_nascimento->mes = mes;
                data_nascimento->ano = ano;

            default:
                system("cls");
                printf(VERDE"Opcao invalida! Digite novamente.\n\n"BRANCO);
                break;
        } 
    }

    editar_cliente(temp_cliente, nome, cpf, telefone, email, data_nascimento, opcao);
    return;  
}


