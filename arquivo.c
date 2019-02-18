#include <stdio.h>
#include <stdlib.h>

typedef struct tipoAluno{
    char nome[255];
    int matricula, dia, mes, ano;
} aluno;

void inserirNoArquivo(FILE *pArquivo, aluno *aux){
    if(pArquivo != NULL){
        fprintf(pArquivo, "%s %d %d/%d/%d\n", aux->nome, aux->matricula, aux->dia, aux->mes, aux->ano);
    }else{
        printf("Erro ao ler o arquivo!\n");
    }
}

int main(int argc, char *argv[]){

    aluno a;

    return 0;
}