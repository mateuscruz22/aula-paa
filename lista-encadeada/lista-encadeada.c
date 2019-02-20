#include <stdio.h>
#include <stdlib.h>

struct tipoAluno{
    char nome[255];
    int matricula, dia, mes, ano;
    struct tipoAluno *proximo;
};

struct tipoLista{
    struct tipoAluno *cabeca, *cauda;
};

void criarLista(struct tipoLista *l){
    l->cabeca = NULL;
    l->cauda = l->cabeca;
}

void inserirLista(struct tipoLista *l, struct tipoAluno *aux){
    if(l->cabeca == NULL){
        l->cabeca = malloc(sizeof(struct tipoAluno));
        l->cabeca = aux;
        l->cauda = l->cabeca;
        l->cauda->proximo = NULL;
        printf("Inserido na lista com sucesso!\n");
    }else{
        l->cauda->proximo = malloc(sizeof(struct tipoAluno));
        l->cauda->proximo = aux;
        l->cauda = l->cauda->proximo;
        l->cauda->proximo = NULL;
        printf("Inserido na lista com sucesso!\n");
    }
}

void mostrarLista(struct tipoLista *l){
    struct tipoAluno *aux = malloc(sizeof(struct tipoAluno));
    
    if (l->cabeca == NULL) {
        printf("Nao existem alunos cadastrados!\n");
        free(aux);
    }else{

        printf(" --- Lista de alunos --- \n\n");
        for(aux = l->cabeca; aux != NULL; aux = aux->proximo){
            printf("Nome: %s\n", (aux->nome));
            printf("Matricula: %d\n", (aux->matricula));
            printf("Data de Nascimento: %02d/%02d/%04d\n", (aux->dia), (aux->mes), (aux->ano));
            printf("----------------------------------\n");
        }
        free(aux);
    }
    
}

int main(int argc, char *argv[]){
    
   struct tipoLista *lista = malloc(sizeof(struct tipoLista));
   struct tipoAluno *aux;
   int op;

   criarLista(lista);

   do{
        system("cls");
        printf(" --- Bem vindo ao gerenciador de alunos --- \n\n");
        printf(" 1) Cadastrar novo aluno\n");
        printf(" 2) Mostrar alunos cadastrados\n");
        printf(" 3) Apagar todos os registros\n");
        printf(" 0) Sair\n\n");
        printf(" Escolha uma opcao: ");
        scanf("%d", &op);

        switch (op){

            case 0:
                system("cls");
                printf("Saindo do sistema...\n");
                system("pause");
                break;
            case 1:
                system("cls");
                setbuf(stdin, NULL);
                aux = malloc(sizeof(struct tipoAluno));
                
                printf("Digite o nome do aluno: ");
                scanf("%[^\n]s", &(aux->nome));
                printf("Digite a matricula: ");
                scanf("%d", &(aux->matricula));
                printf("Digite a data de nascimento (DD MM AAAA): ");
                scanf("%d %d %d", &(aux->dia), &(aux->mes), &(aux->ano));

                inserirLista(lista, aux);

                system("pause");
                break;
            case 2:
                system("cls");
                mostrarLista(lista);
                system("pause");
                break;
            case 3:
                system("cls");
                free(lista);
                struct tipoLista *lista = malloc(sizeof(struct tipoLista));
                criarLista(lista);
                printf("Todos os registros foram apagados!\n");
                system("pause");
                break;
            default:
                printf("Opcao invalida! Digite um dos numeros listados no menu.\n");
                system("pause");
                break;
}

   } while(op != 0);

    return 0;
}