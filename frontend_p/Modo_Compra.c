#include "frontend.h"
#include "backend_p/backend.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu_modo_compra(cliente *head_c,produto *head_p){
    cliente *encontrado; 
    char cpf_digitado[12];
    printf("Digite o CPF para comprar: ");
    scanf("%s",cpf_digitado);

    encontrado = buscar_cliente(head_c,cpf_digitado);

    if(encontrado != NULL){
        printf("Cliente encontrado: %s\n", encontrado->nome);

        printf("\n\n-------- LISTA DOS PRODUTOS --------\n\n");
        listar_produtos(head_p);

    } else printf("Cliente nao cadastrado");
}