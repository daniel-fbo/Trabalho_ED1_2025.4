#include "frontend.h"

void menu_modo_compra(cliente *head_c, produto *head_p){
    system("cls");
    printf(ROXO"- - - MODO COMPRA - - -\n\n"BRANCO);

    if(head_c == NULL) {
        printf(VERMELHO"Erro: Nao ha clientes cadastrados no momento!\n\n"BRANCO);
        enter();
        return;
    }

    cliente *encontrado = head_c; 
    char cpf_digitado[12];
    printf("Digite o CPF para comprar:\n");
    scanf(" %[^\n]",cpf_digitado);
    
    encontrado = buscar_cliente(head_c,cpf_digitado); 
    system("cls");
    
    if(encontrado != NULL){
        int opcao;
        while(SIM){
            system("cls"); 
            printf(ROXO"\n- - - MODO COMPRA - - > Perfil (%s) < - -\n"BRANCO, encontrado->nome);
            printf(" 1 - Adicionar produto no carrinho\n");
            printf(" 2 - Mostrar carrinho\n");
            printf(" 3 - Remover produto do carrinho\n");
            printf(" 4 - Finalizar/Voltar\n");
            printf("Digite uma opcao: \n");
            scanf(" %d", &opcao);
            while(getchar() != '\n');
    
            switch (opcao)
            {
            case 1:
                system("cls");
                menu_adicionar_carrinho(encontrado, head_p);
                break;
            case 2:
                system("cls");
                menu_mostrar_carrinho(encontrado, head_p);
                break;
            case 3:
                system("cls");
                menu_retirar_carrinho(encontrado, head_p);
                break;
            case 4:
                system("cls");
                return;
            default:
                system("cls");
                printf(VERMELHO"Opcao Invalida! Digite novamente!\n\n"BRANCO);
                enter();
                break;
            }
        }
    } else{
        printf(VERMELHO"Cliente nao encontrado\n"BRANCO);
        enter();
        return;
    } 
}

void menu_adicionar_carrinho(cliente *cliente_atual, produto *head_p){
    char op = 'S', id[20];
    int qtd = 0;

    system("cls");
    
    while(op == 'S' || op == 's'){
        system("cls");
        printf(ROXO" - - - ADICIONAR AO CARRINHO DE %s - - - \n\n"BRANCO, cliente_atual->nome);
        
        printf(VERDE" - - PRODUTOS DISPONIVEIS - - \n"BRANCO);
        listar_produtos(head_p); 
        printf("\n------------------------------------------------\n");
        printf(VERDE" - - SEU CARRINHO ATUAL - - \n"BRANCO);
        listar_itens_carrinho(cliente_atual, head_p);
        printf("------------------------------------------------\n\n");

        printf("Digite o CODIGO do produto para adicionar:\n");
        scanf(" %s", id);

        printf("Digite a QUANTIDADE:\n");
        scanf("%d", &qtd);

        adicionar_carrinho(cliente_atual, head_p, id, qtd);

        while(getchar() != '\n');
        printf("\nDeseja adicionar outro produto? (S/N)\n");
        scanf("%c", &op);
    }
    
    system("cls");
    return;
}

void menu_mostrar_carrinho(cliente *cliente_atual, produto *head_p){
    printf(ROXO" - - - - - CARRINHO DE COMPRAS - - - - - \n\n"BRANCO);
    printf("Cliente: %s\n\n", cliente_atual->nome);

    listar_itens_carrinho(cliente_atual, head_p);
    
    printf("\n");
    enter(); 
    return;
}

void menu_retirar_carrinho(cliente *cliente_atual, produto *head_p){
    char op = 'S', id[20];
    int qtd = 0;

    while(op == 'S' || op == 's'){
        system("cls");
        printf(ROXO" - - - RETIRAR DO CARRINHO DE %s - - - \n\n"BRANCO, cliente_atual->nome);
        
        if (cliente_atual->carrinho->itens == NULL) {
            printf(VERMELHO "Carrinho vazio. Nao ha nada para retirar.\n" BRANCO);
            enter(); 
            return;  
        }
        listar_itens_carrinho(cliente_atual, head_p);
        printf("\n------------------------------------------------\n");

        printf("Digite o CODIGO do produto para remover:\n");
        scanf(" %s", id);

        printf("Digite a QUANTIDADE para retirar:\n");
        scanf("%d", &qtd);

        retirar_carrinho(cliente_atual, head_p, id, qtd);

        while(getchar() != '\n');
        printf("\nDeseja retirar outro produto? (S/N)\n");
        scanf("%c", &op);
    }
    
    system("cls");
    return;
}