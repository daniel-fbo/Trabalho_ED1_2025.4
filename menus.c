#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "menus.h"
#include "escola.h"

void menu_cadastrar_turma(turma *lista_turmas, short *qtd_turmas){
    srand(time(NULL));
    printf("- - - - - - Cadastro de Turma - - - - - -\n\n");
    printf("Digite o nome da turma:\n");
    char nome[20];
    scanf("%[^\n]", nome);
    int codigo = (rand()%9000)+1000;   

    cadastrar_turma(lista_turmas, qtd_turmas, nome, codigo);
    menu_principal(lista_turmas,qtd_turmas);
}

void menu_cadastrar_aluno(turma *lista_turmas, short *qtd_turmas){
    printf("- - - - - - Cadastro de Aluno - - - - - -\n\n");
    printf("Digite o nome do aluno:\n");
    char nome[100];
    scanf("%[^\n]", nome);
    printf("Digite o CPF do aluno:\n");
    char cpf[12];
    scanf("%[^\n]", cpf); 
    cadastrar_aluno(lista_turmas, qtd_turmas, nome, cpf);
    menu_principal(lista_turmas,qtd_turmas);    
}

void menu_buscar_aluno(turma *lista_turmas, short *qtd_turmas){
    printf("- - - - - - Busca por Aluno - - - - - -\n\n");
    printf("Digite o codigo da turma:\n");
    int id;
    scanf("%d", &id);
    printf("Digite o cpf do aluno:\n");
    char cpf[20];
    scanf("%[^\n]", cpf);
    turma *turma_aluno = buscar_turma(lista_turmas, qtd_turmas, id);
    aluno *aluno_buscado = buscar_aluno(turma_aluno, cpf);
    mostrar_aluno(aluno_buscado);
    menu_principal(lista_turmas,qtd_turmas);    
}

void menu_registrar_notas(turma *lista_turmas, short *qtd_turmas){
    printf("- - - - - - Registrar Notas de Aluno - - - - - -\n\n");
    printf("Digite o codigo da turma:\n");
    int id;
    scanf("%d", &id);
    printf("Digite o cpf do aluno:\n");
    char cpf[20];
    scanf("%[^\n]", cpf);
    turma *turma_aluno = buscar_turma(lista_turmas, qtd_turmas, id);
    aluno *aluno_buscado = buscar_aluno(turma_aluno, cpf);
    acessar_notas(aluno_buscado);
    menu_principal(lista_turmas,qtd_turmas); 

}


void menu_principal(turma *lista_turmas, short *qtd_turmas){
    int opcao=-1;
    while (opcao<1 || opcao>4){
        printf ("- - - - - - Colegio Dolphin - - - - - -\n\n");
        printf ("1- Cadastrar aluno.\n");
        printf ("2- Cadastrar turma.\n");
        printf ("3- Buscar aluno.\n");
        printf ("4- Registrar notas do aluno.\n");
        printf ("5- Sair do sistema.\n");
        printf("Digite a opcao desejada:\n");
        scanf(" %d\n", &opcao);
        if (opcao==5){
            return;
        }
        if (opcao<1 || opcao>5){
            system("cls");
            printf("\033[4;31mOPCAO INVALIDA. DIGITE NOVAMENTE.\033[4;31m\n\n\n");
        }
    }
    system("cls");
    if (opcao==1){menu_cadastrar_turma(lista_turmas, qtd_turmas);};
    if (opcao==2){menu_cadastrar_aluno(lista_turmas, qtd_turmas);};
    if (opcao==3){menu_buscar_aluno(lista_turmas, qtd_turmas);};
    if (opcao==4){menu_registrar_notas(lista_turmas, qtd_turmas);};

}