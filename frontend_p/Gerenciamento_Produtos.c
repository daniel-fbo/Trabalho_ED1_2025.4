#include "frontend.h"

void menu_gerenciamento_produtos(cliente **head_c, produto **head_p){
    int opcao;
    while (SIM){
        printf (ROXO"- - - - - - Gerenciamento de Produtos - - - - - -\n\n"BRANCO);
        printf ("1- Cadastrar produto.\n");
        printf ("2- Remover produto.\n");
        printf ("3- Listar produtos.\n");
        printf ("4- Buscar produto pelo codigo unico.\n");
        printf ("5- Editar dados de um produto.\n");
        printf ("6- Voltar ao menu principal.\n");
        printf("Digite a opcao desejada:\n");
        scanf(" %d", &opcao);
        while(getchar() != '\n');

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

    printf(ROXO"- - - - - - Cadastro de Produto - - - - - -\n\n"BRANCO);
    printf("Digite o nome do produto:\n");
    scanf(" %[^\n]", nome);
    printf("Digite o codigo unico do produto:\n");
    scanf(" %[^\n]", id);  
    printf("Digite o preco do produto:\n");
    scanf(" %lf", &preco); 
    printf("Digite a quantidade de itens em estoque:\n");
    scanf(" %hd", &qtd);

    cadastrar_produto(head_p, nome, id, preco, qtd);
    enter();
    return;
}

void menu_remover_produto(cliente *head_c, produto **head_p){
    printf(ROXO"- - - - - - Remover Produto - - - - - -\n\n"BRANCO);
    printf("Digite o codigo unico do produto:\n");
    char id[12];
    scanf(" %[^\n]", id);
    produto *produto_removido = buscar_produto(*head_p, id);
    remover_produtos(head_p, produto_removido);
    enter();

    return;
}

void menu_buscar_produto(cliente *head_c, produto *head_p){
    printf(ROXO"- - - - - - Buscar Produto - - - - - -\n\n"BRANCO);
    printf("Digite o codigo unico do produto:\n");

    char id[6];
    scanf(" %[^\n]", id);

    produto *temp_produto = buscar_produto(head_p, id);
    if (temp_produto == NULL){
        printf(VERMELHO"Produto não encontrado.\n"BRANCO);
        enter();
        return;
    }

    system("cls");
    printf("\n\nNome do produto: %s\n", temp_produto -> nome);
    printf("Codigo unico: %s\n", temp_produto -> id);
    printf("Preco por unidade do produto: %.2lf\n", temp_produto -> preco);
    printf("Quantidade de itens em estoque: %hd\n\n", temp_produto -> qtd);
    
    enter();
    return;  
}

void menu_editar_produto(cliente *head_c, produto *head_p){
    printf(ROXO"- - - - - - Editar Produto - - - - - -\n\n"BRANCO);
    printf("Digite o codigo unico do produto a ser editado:\n");
    char id[6];
    scanf(" %[^\n]", id);

    produto *temp_produto = buscar_produto(head_p, id);
    if (temp_produto == NULL){
        printf(VERMELHO"Produto não encontrado."BRANCO);
        enter();
        return;
    }

    system("cls");
    printf("\n\nNome do produto: %s\n", temp_produto -> nome);
    printf("Codigo unico: %s\n", temp_produto -> id);
    printf("Preco por unidade do produto: %.2lf\n", temp_produto -> preco);
    printf("Quantidade de itens em estoque: %hd\n\n", temp_produto -> qtd);

    int opcao;
    while (SIM){
        printf ("1- Editar nome.\n");
        printf ("2- Editar codigo unico.\n");
        printf ("3- Editar preco.\n");
        printf ("4- Editar quantidade de itens em estoque.\n");
        printf ("5- Sair/Finalizar.\n");
        printf("Digite a opcao desejada:\n");
        scanf(" %d", &opcao);

        switch(opcao){
            case 1:
                printf("Qual o novo nome?\n");
                scanf("%[^\n]", temp_produto -> nome);
                system("cls");
                break;
            case 2:
                printf("Qual o novo codigo unico do produto?\n");
                scanf("%[^\n]", temp_produto -> id);
                system("cls");
                break;
            case 3:
                printf("Qual o novo preco?\n");
                scanf("%lf", &temp_produto -> preco);
                system("cls");
                break;
            case 4:
                printf("Qual a nova quantidade de itens em estoque?\n");
                scanf("%hd", &temp_produto ->qtd);
                system("cls");
                break;
            case 5:
                system("cls");
                return;
            default:
                system("cls");
                printf(VERDE"Opcao invalida! Digite novamente.\n\n"BRANCO);
                break;
        }
        system("cls");
    }

    editar_produto(temp_produto, temp_produto -> nome, temp_produto -> id, temp_produto -> preco, temp_produto -> qtd, opcao);
    
    system("cls");
    printf(VERDE "Produto editado com sucesso!\n\n" BRANCO);
    enter();
    return;  
}


