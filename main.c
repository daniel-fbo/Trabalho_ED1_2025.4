#include "backend_p/backend.h"
#include "persistencia_p/persistencia.h"
#include "frontend_p/frontend.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    cliente *head_c = NULL;
    produto *head_p = NULL;

    menu_principal(head_c, head_p);

    //limpar_memoria();
    return 0;
}