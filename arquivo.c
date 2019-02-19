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

    int op;
    long tamArq;
    aluno *aux;
    FILE *pArquivo;
    
    do{
        system("cls");
        printf(" --- Bem vindo ao gerenciador de alunos --- \n\n");
        printf(" 1) Cadastrar novo aluno\n");
        printf(" 2) Mostrar alunos cadastrados\n");
        printf(" 3) Apagar todos os registros\n");
        printf(" 0) Sair\n\n");
        printf(" Escolha uma opcao: ");
        scanf("%d", &op);

        switch (op)
        {
            case 0:
                printf("Saindo do sistema...\n");
                system("pause");
                break;
            case 1:
                setbuf(stdin, NULL);
                aux = malloc(sizeof(aluno));
                system("cls");
                printf("Difgite o nome do aluno: ");
                scanf("%[^/n]s", &(aux->nome));
                printf("Digite a matricula: ");
                scanf("%d", &(aux->matricula));
                printf("Digite a data de nascimento (DD MM AAAA): ");
                scanf("%d %d %d", &(aux->dia), &(aux->mes), &(aux->ano));
                pArquivo = fopen("registro.txt", "a");
                inserirNoArquivo(pArquivo, aux);
                fclose(pArquivo);
                system("pause");
                break;
            case 2:
                /* code */
                break;
            case 3:
                /* code */
                break;
            default:
                printf("Opcao invalida! Digite um dos numeros listados no menu.\n");
                system("pause");
                break;
        }

    }while(op != 0);

    return 0;
}