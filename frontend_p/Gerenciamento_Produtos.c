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

void menu_remover_produto(cliente *head_c, produto **head_p){
    printf("- - - - - - Remover Produto - - - - - -\n\n");
    printf("Digite o codigo unico do produto:\n");
    char id[12];
    scanf(" %[^\n]", id);
    produto *produto_removido = buscar_produto(*head_p, id);
    remover_produtos(head_p, produto_removido);

    return;
}

void menu_editar_produto(cliente *head_c, produto *head_p){
    printf("- - - - - - Editar Produto - - - - - -\n\n");
    printf("Digite o codigo unico do produto a ser editado:\n");
    char id[6];
    scanf(" %[^\n]", id);

    produto *temp_produto = buscar_produto(head_p, id);

    printf("\n\nNome do produto: %s\n", temp_produto -> nome);
    printf("Codigo unico: %s\n", temp_produto -> id);
    printf("Preco por unidade do produto: %.2lf\n", temp_produto -> preco);
    printf("Quantidade de itens em estoque: %hd\n", temp_produto -> qtd);
    printf("Pressione qualquer tecla para voltar...");
  
    int opcao;
    while (SIM){
        printf ("1- Editar nome.\n");
        printf ("2- Editar codigo unico.\n");
        printf ("3- Editar preco.\n");
        printf ("4- Editar quantidade de itens em estoque.\n");
        printf("Digite a opcao desejada:\n");
        scanf(" %d", &opcao);

        switch(opcao){
            case 1:
                printf("Qual o novo nome?\n");
                scanf("%[^\n]", temp_produto -> nome);
                break;
            case 2:
                printf("Qual o novo codigo unico do produto?\n");
                scanf("%[^\n]", temp_produto -> id);
                break;
            case 3:
                printf("Qual o novo preco?\n");
                scanf("%.2lf", temp_produto -> preco);
                break;
            case 4:
                printf("Qual a nova quantidade de itens em estoque?\n");
                scanf("%hd", temp_produto ->qtd);
                break;

            default:
                system("cls");
                printf(VERDE"Opcao invalida! Digite novamente.\n\n"BRANCO);
                break;
        } 
    }

    editar_produto(temp_produto, temp_produto -> nome, temp_produto -> id, temp_produto -> preco, temp_produto -> qtd, opcao);
    return;  
}


