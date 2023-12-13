#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 2

struct dados{
char nome[250];
char  numero[250];
char email[250];
};


void limpatudo(){
    system("cls || clear");
    fflush(stdin);
}

void validarNumero(struct dados pessoa[],char* nome){

    int i;
    for(i=0;i<TAM;i++){
        if(strcmp(pessoa[i].nome,nome) == 0){
            printf("Nome:%s",pessoa[i].nome);
            printf("Numero:%s",pessoa[i].numero);
            printf("Email:%s",pessoa[i].email);
            break;
        }
    }
   // return  printf("Contato nao encondrado\n");       
}

int main(){

struct dados pessoa[TAM];
char nome[250];
int i;

    for(i=0;i<TAM;i++){
        printf("Nome:");
        fgets(pessoa[i].nome,sizeof(pessoa[i].nome),stdin);
        fflush(stdin);

        printf("Numero:");
        fgets(pessoa[i].numero,sizeof(pessoa[i].numero),stdin);
        fflush(stdin);

        printf("Email:");
        fgets(pessoa[i].email,sizeof(pessoa[i].email),stdin);
        limpatudo();
    }
    printf("Digite nome para mostrar o numero:");
    fgets(nome,sizeof(nome),stdin);
    validarNumero(pessoa,nome);

    return 0;
}