#include "escola.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void cadastrar_turma(turma *lista_turmas, short *qtd_turmas, char *nome, int codigo){
    turma turma_nova;
    strcpy(turma_nova.nome,nome);
    turma_nova.id = codigo;
    turma_nova.qtdAlunos = 0;

    for (int i=0;i<*qtd_turmas;i++){
        if (lista_turmas[i].id == '\0'){
            (*qtd_turmas)++;
            lista_turmas[i] = turma_nova;
            printf("Turma cadastrada com sucesso. Tecle Enter para voltar ao menu principal!");
            getchar();
            return;
        }
    }
    printf("\033[4;31mCadastro não pode ser concluído.\033[4;31m Tecle Enter para voltar ao menu principal!");
    getchar();
}

void cadastrar_aluno(turma *lista_turmas, short *qtd_turmas, char *nome, char *cpf){
    aluno *aluno_novo;
    strcpy(aluno_novo->nome,nome);
    strcpy(aluno_novo->cpf,cpf);
    turma *turma_aluno = buscar_turma_menos_alunos(lista_turmas, qtd_turmas); 
    inserir_aluno(aluno_novo,turma_aluno);
    printf("Turma cadastrada com sucesso na turma %s. Tecle Enter para voltar ao menu principal!", aluno_novo->turma);
    getchar();
}