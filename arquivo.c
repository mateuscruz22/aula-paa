#include <stdlib.h>
#include <stdio.h>

struct alunos{
  char nome[255];
  int matricula, dia, mes, ano;
};

void inserirLista(FILE *r, struct alunos *aux){

  if (r != NULL){
    fprintf(r, "%s %d %d/%d/%d\n", aux->nome, aux->matricula, aux->dia, aux->mes, aux->ano);
  }else{
    printf("Erro ao ler o arquivo.\n\n");
  }

}

void mostrarLista(FILE *r){

  char nomeAux[255];
  int matAux, diaAux, mesAux, anoAux;

  while (!feof(r)){
    fscanf(r, "%s %d %d/%d/%d\n", &nomeAux, &matAux, &diaAux, &mesAux, &anoAux);
    printf("\tNome: %s\n", nomeAux);
    printf("\tMatricula: %d\n", matAux);
    printf("\tData de nascimento: %02d/%02d/%04d\n", diaAux, mesAux, anoAux);
    printf("\t----------------------------------\n", nomeAux);
  }
}

int main(int argc, char *argv[]){

  int op;
  long tamArq;
  struct alunos *aux;
  FILE *r;

  do{

    system("cls");
    printf("Bem vindo ao gerenciador de alunos \n\n");
    printf("\t 1). Cadastrar novo aluno\n");
    printf("\t 2). Mostrar alunos cadastrados\n");
    printf("\t 3). Apagar todos os registros\n");
    printf("\t 0). Sair\n");
    scanf("%d", &op);

  switch (op){
    case 0:
      printf("Saindo do sistema...\n");
      system("pause");
      break;
    case 1:
      setbuf(stdin, NULL);
      aux = malloc(sizeof(struct alunos));
      system("cls");
      printf("Digite o nome do aluno:\n");
      scanf("%[^\n]s", &(aux->nome));
      printf("Digite a matricula:\n");
      scanf("%d", &(aux->matricula));
      printf("Digite a data de nascimento (DD MM AAAA):\n");
      scanf("%d %d %d", &(aux->dia), &(aux->mes), &(aux->ano));
      r = fopen("registro.txt", "a");
      inserirLista(r, aux);
      fclose(r);
      system("pause");
      break;
    case 2:
      system("cls");
      printf("Listando alunos cadastrados:\n\n");
      r = fopen("registro.txt", "r");
      if (r != NULL){
        fseek(r, 0, SEEK_END);
        tamArq = ftell(r);
        fseek(r, 0, SEEK_SET);
        if (tamArq != 0){
          mostrarLista(r);
        }else{
          printf("Nao existem alunos cadastrados.\n\n");
        }
      }else{
        printf("Erro ao ler o arquivo.");
      }
      fclose(r);
      system("pause");
      break;
    case 3:
      system("cls");
      r = fopen("registro.txt", "w");
      fclose(r);
      printf("Todos os registros foram apagados.\n\n");
      system("pause");
      break;
    case 4:
      r = fopen("registro.txt", "a");
      fclose(r);
      break;
    default:
        printf("Opcao invalida! Digite um dos numeros listados no menu.\n");
        system("pause");
        break;
    }
  } while (op != 0);

  free(aux);
  system("cls");
  
  return 0;
}