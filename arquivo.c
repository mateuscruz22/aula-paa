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

void mostrarAlunos(FILE *pArquivo){

    char nomeAux[255];
    int matriculaAux, diaAux, mesAux, anoAux;

    while(!feof(pArquivo)){
        fscanf(pArquivo, "%s %d %d/%d/%d\n", &nomeAux, &matriculaAux, &diaAux, &mesAux, &anoAux);
        printf("\tNome: %s\n", nomeAux);
        printf("\tMatricula: %d\n", matriculaAux);
        printf("\tData de nascimento: %02d/%02d/%04d\n", diaAux, mesAux, anoAux);
        printf("\t----------------------------------\n");
    }

}

int main(int argc, char *argv[]){

    aluno a;

    return 0;
}