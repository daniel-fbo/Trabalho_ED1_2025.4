#include "frontend.h"

void menu_modo_compra(cliente *head_c,produto *head_p){
    system("cls");
    printf("--- MODO COMPRA ---\n");

    if(head_c == NULL) {
        printf("Erro: Nao ha clientes cadastrados!\n");
        printf("Pressione qualquer tecla para voltar...");
        while (getchar() != '\n'); getchar();
        return;
    }

    cliente *encontrado = head_c; 
    char cpf_digitado[12];
    printf("Digite o CPF para comprar:\n");
    scanf(" %[^\n]",cpf_digitado);
    while (getchar() != '\n');

    encontrado = buscar_cliente(head_c,cpf_digitado); 
    
    if(encontrado != NULL){
        system("cls");
        int opcao = 0;

        printf("\n--- MODO COMPRA --> Perfil (%s) <-----\n", encontrado->nome);
        printf(" 1 - Adicionar produto no Carrinho\n");
        printf(" 2 - Mostar carrinho\n");
        printf(" 3 - Remover produto do carrinho\n");
        printf(" 4 - Finalizar/Voltar\n");
        printf("Digite uma opcao: \n");
        scanf(" %d", &opcao);

        switch (opcao)
        {
        case 1:
            menu_adicionar_carrinho(head_c,head_p);
            break;
        case 2:
            menu_mostrar_carrinho(head_c,head_p);
            break;
        case 3:
            menu_retirar_carrinho(head_c,head_p);
            break;
        case 4:
            system("cls");
            return;
            break;
        default:
            printf("Opcao invalida");
            break;
        }
    } else{
        system("cls");
        printf("Cliente nao encontrado\n");
        printf("Pressione qualquer tecla para voltar...");
        while (getchar() != '\n'); getchar();
        return;
    } 
}


void menu_adicionar_carrinho(cliente *head_c, produto *head_p){

    printf(" - - - - - MENU ADICIONAR PRODUTOS NO CARRINHO - - - - - \n");
    char op = 'S', id[20];
    int qtd = 0;
    
    while(op == 'S'){

        listar_produtos(head_p);

        printf("Digite o Codigo do produto:\n");
        scanf(" %s", id);

        printf("Digite a Quantidade desse produto:\n");
        scanf("%d", &qtd);

        adicionar_carrinho(head_c,head_p, id, qtd);

        printf("Deseja adicionar outro produto? (S/N)\n");
        scanf("%c", &op);
    }

}

void menu_mostrar_carrinho(cliente *head_c, produto *head_p){

    printf(" - - - - - MENU MOSTRAR PRODUTOS DO CARRINHO - - - - - \n");

    printf("Carrindo de %s\n", head_c->nome);

    listar_itens_carrinho(head_c,head_p);

    printf("Pressione qualquer tecla para voltar...\n");
    while (getchar() != '\n');
    getchar();
    return;

}

void menu_retirar_carrinho(cliente *head_c, produto *head_p){
    
    char op = 'S', id[20];
    int qtd = 0;

    printf(" - - - - - MENU RETIRAR PRODUTOS DO CARRINHO - - - - - \n");

    printf("Carrindo de %s\n", head_c->nome);

    listar_itens_carrinho(head_c,head_p);

    while(op == 'S'){

        listar_itens_carrinho(head_c, head_p);

        printf("Digite o Codigo do produto:\n");
        scanf(" %s", id);

        printf("Digite a Quantidade de retirada desse produto:\n");
        scanf("%d", &qtd);

        retirar_carrinho(head_c, head_p, id, qtd);

        printf("Deseja retirar outro produto? (S/N)\n");
        scanf("%c", &op);
    }
    
    printf("Carrinho atualizado: \n\n");
    listar_itens_carrinho(head_c,head_p);
}