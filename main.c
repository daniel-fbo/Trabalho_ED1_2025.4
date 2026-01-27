#include "menus.h"
#include "escola.h"
#include <stdio.h>

int main(){
    turma lista_turmas[10];
    short *qtd_turmas, num_turmas = 10;
    qtd_turmas = &num_turmas;
    menu_principal(lista_turmas, qtd_turmas);
    return 0;
}