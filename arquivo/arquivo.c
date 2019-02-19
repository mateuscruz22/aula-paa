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
        printf("Nome: %s\n", nomeAux);
        printf("Matricula: %d\n", matriculaAux);
        printf("Data de nascimento: %02d/%02d/%04d\n", diaAux, mesAux, anoAux);
        printf("----------------------------------\n");
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
                printf(" --- Cadastrando novo aluno --- \n\n");
                printf("Digite o nome do aluno: ");
                scanf("%[^\n]s", &(aux->nome));
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
                system("cls");
                printf(" --- Lista de alunos cadastrados --- \n\n");
                pArquivo = fopen("registro.txt", "r");
                if(pArquivo != NULL){
                    fseek(pArquivo, 0, SEEK_END);
                    tamArq = ftell(pArquivo);
                    fseek(pArquivo, 0, SEEK_SET);
                    if(tamArq != 0){
                        mostrarAlunos(pArquivo);
                    }else{
                        printf("A lista de alunos esta vazia!\n");
                    }
                }else{
                    printf("Erro ao ler o arquivo!\n");
                }
                fclose(pArquivo);
                system("pause");
                break;
            case 3:
                system("cls");
                pArquivo = fopen("registro.txt", "w");
                fclose(pArquivo);
                printf("Todos os registros foram apagados!\n");
                system("pause");
                break;
            default:
                printf("Opcao invalida! Digite um dos numeros listados no menu.\n");
                system("pause");
                break;
        }

    }while(op != 0);

    return 0;
}