#include "frontend.h"

void menu_modo_compra(cliente *head_c,produto *head_p){
    system("cls");
    printf(ROXO"- - - MODO COMPRA - - -\n\n"BRANCO);

    if(head_c == NULL) {
        printf(VERMELHO"Erro: Nao ha clientes cadastrados no momento!\n\n"BRANCO);
        printf("Tecle ENTER para voltar ao menu principal.\n");
        while (getchar() != '\n'); getchar();
        system("cls");
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
        while(1){
            printf(ROXO"\n- - - MODO COMPRA - - > Perfil (%s) < - -\n"BRANCO, encontrado->nome);
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
        }
    } else{
        system("cls");
        printf(VERMELHO"Cliente nao encontrado\n"BRANCO);
        printf("Tecle ENTER para voltar...");
        while (getchar() != '\n'); getchar();
        return;
    } 
}


void menu_adicionar_carrinho(cliente *head_c, produto *head_p){
    system("cls");
    printf(ROXO" - - - - - MENU ADICIONAR PRODUTOS NO CARRINHO - - - - - \n"BRANCO);
    char op = 'S', id[20];
    int qtd = 0;

    printf(VERDE" - - - - - LISTA DE PRODUTOS  - - - - - \n"BRANCO);

    if (head_p == NULL)
    {
        system("cls");
        printf(VERMELHO "Erro: Nao ha produtos cadastrados\n\n" BRANCO);
        printf("Tecle ENTER para voltar...\n");
        while (getchar() != '\n');
        getchar();
        system("cls");
        return;
    }

    produto *temp_produto = head_p;
    while (temp_produto != NULL){
        printf("Nome do produto: %s\n", temp_produto -> nome);
        printf("Codigo unico: %s\n", temp_produto -> id);
        printf("Unidades do produto em estoque: %d\n", temp_produto -> qtd);
        printf("Preco: %.2lf\n\n", temp_produto -> preco);
        temp_produto = temp_produto -> prox;        
    }
    
    while(op == 'S'){

        printf("Digite o Codigo do produto:\n");
        scanf(" %s", id);

        printf("Digite a Quantidade desse produto:\n");
        scanf("%d", &qtd);

        adicionar_carrinho(head_c,head_p, id, qtd);

        while(getchar() != '\n');
        printf("Deseja adicionar outro produto? (S/N)\n");
        scanf("%c", &op);

        printf(VERDE"\n - No seu carrinho - "BRANCO);
        listar_itens_carrinho(head_c,head_p);
    }
    
    system("cls");
    return;
}

void menu_mostrar_carrinho(cliente *head_c, produto *head_p){
    system("cls");
    printf(ROXO" - - - - - MENU MOSTRAR PRODUTOS DO CARRINHO - - - - - \n"BRANCO);

    printf(VERDE"Carrindo de %s\n" BRANCO, head_c->nome);

    listar_itens_carrinho(head_c,head_p);

    printf("\nTecle ENTER para voltar...\n");
    while (getchar() != '\n');
    getchar();
    system("cls");
    return;

}

void menu_retirar_carrinho(cliente *head_c, produto *head_p){
    system("cls");
    char op = 'S', id[20];
    int qtd = 0;

    printf(ROXO" - - - - - MENU RETIRAR PRODUTOS DO CARRINHO - - - - - \n"BRANCO);

    printf("Carrindo de %s\n", head_c->nome);

    while(op == 'S'){

        listar_itens_carrinho(head_c, head_p);

        printf("Digite o Codigo do produto:\n");
        scanf(" %s", id);

        printf("Digite a Quantidade de retirada desse produto:\n");
        scanf("%d", &qtd);

        retirar_carrinho(head_c, head_p, id, qtd);

        while(getchar() != '\n');
        printf("Deseja retirar outro produto? (S/N)\n");
        scanf("%c", &op);
    }
    
    system("cls");
    printf(VERDE" - - Carrinho atualizado - - \n\n"BRANCO);

    listar_itens_carrinho(head_c,head_p);

    printf("Tecle ENTER para voltar...\n");
    while (getchar() != '\n');
    getchar();
    system("cls");
    return;
}