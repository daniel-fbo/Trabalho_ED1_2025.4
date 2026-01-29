#include "backend_p/backend.h"
#include "persistencia_p/persistencia.h"
#include "frontend_p/frontend.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    cliente *head_c = NULL;
    produto *head_p = NULL;

    // ==== CRIANDO UM CLIENTE PARA TESTAR MODO COMPRA =====
    /*fazendo isso so pra debugar*/
    cliente *c1 = malloc(sizeof(cliente)); // criando o espaço para o cliente

    c1->nome = malloc(100); //alocando espaço para o nome
    strcpy(c1->nome, "Josef");

    c1->cpf = malloc(12);
    strcpy(c1->cpf, "123");

    c1->telefone = malloc(4);
    strcpy(c1->telefone,"321");

    c1->email = malloc(20);
    strcpy(c1->email, "josef@gmail.com");

    c1->data_nascimento = malloc(sizeof(data));
    c1->data_nascimento->dia = 13;
    c1->data_nascimento->mes = 8;
    c1->data_nascimento->ano = 2006;

    c1->prox = NULL; //nao tem proximo, so quero testar 1 msm

    head_c = c1;

    menu_principal(head_c, head_p);
    //limpar_memoria();
    return 0;
}