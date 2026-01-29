#include "backend.h"
#include "persistencia.h"
#include "frontend.h"


#include <stdio.h>

int main(){
    cliente *head_c = NULL;
    produto *head_p = NULL;
    menu_principal(head_c, head_p);
    //limpar_memoria();
    return 0;
}