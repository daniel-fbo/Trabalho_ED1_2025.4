#pragma once

typedef struct {
    short mes;
    short dia;
    int ano;
} data;

typedef struct{
    double P1;
    double P2;
    double P3;
    double NE[10];
} nota;

typedef struct Turma {
    char nome[20];
    short qtdAlunos;
    int id;
    struct Aluno *primeiroAluno;
} turma;

typedef struct Aluno {
    char nome[100];
    char cpf[12];
    data nascimento; 
    nota *notas;
    struct Turma *turma; 
    struct Aluno *anterior;
    struct Aluno *proximo;
} aluno;



double calcular_media_final(nota *notas);
double calcular_media_NE(double *NE);


void cadastrar_turma(turma *lista_turmas, short *qtd_turmas, char *nome, int codigo);
void cadastrar_aluno(turma *lista_turmas, short *qtd_turmas, char *nome, char *cpf);
void mostrar_aluno (aluno *aluno);
void acessar_notas (aluno *aluno);


aluno *buscar_aluno(turma *lista_turmas, char *cpf_buscado);
turma *buscar_turma(turma *lista_turmas, short *qtd_turmas, int id);
turma *buscar_turma_menos_alunos(turma *lista_turmas, short *qtd_turmas);

void inserir_aluno(aluno *aluno, turma *turma);

