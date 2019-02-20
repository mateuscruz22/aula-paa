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

int main(int argc, char *argv[]){
    
   struct tipoLista *lista = malloc(sizeof(struct tipoLista));
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

        switch (op)
        {
            case 0:
                printf("Saindo do sistema...\n");
                system("pause");
                break;
            case 1:
                system("cls");
                // code
                system("pause");
                break;
            case 2:
                system("cls");
                // code
                system("pause");
                break;
            case 3:
                system("cls");
                // code
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