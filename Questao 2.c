#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 3

struct dados
{
    char nome[250];
    char data[250];
    float nota[2];
    float media;
    char situacao[250];
};

void a(){
    printf("================================\n");
}

void limpatudo(){
    system("cls || clear");
    fflush(stdin);
}

void calcularMedia(struct dados aluno[]){
    
int soma=0;
int i,q;

    for(i=0;i<TAM;i++){
        soma=0;
        for(q=0;q<2;q++){
            soma+=aluno[i].nota[q];
        }
       aluno[i].media=soma/q;
    }
}

void situacaoAluno(struct dados aluno[]){
int i;
    for(i=0;i<TAM;i++){
        if(aluno[i].media >= 7){
            strcpy(aluno[i].situacao,"Aluno Aprovado");
        }else if(aluno[i].media >= 5 && aluno[i].media < 7){
            strcpy(aluno[i].situacao,"Aluno esta em Recuperacao");
        }else{
            strcpy(aluno[i].situacao,"Aluno esta Reprovado");
        }
    }
}

void imprimir(struct dados aluno[]){
int i;

    for(i=0;i<TAM;i++){
        a();
        printf("\nNome:%s",aluno[i].nome);
        printf("Data de Nascimento:%s",aluno[i].data);
        printf("Media:%.2f\n",aluno[i].media);
        printf("Situacao:%s\n",aluno[i].situacao);
        a();
    }

}

int main()
{
    int i, q;
    struct dados aluno[TAM];

    for (i = 0; i < TAM; i++)
    {
        printf("Nome:");
        fgets(aluno[i].nome, sizeof(aluno[i].nome), stdin);

        printf("Data de Nascimento:");
        fgets(aluno[i].data, sizeof(aluno[i].data), stdin);

        for (q = 0; q < 2; q++)
        {
            printf("%d Nota:", q + 1);
            scanf("%f", &aluno[i].nota[q]);
        }
        limpatudo();
    }

    calcularMedia(aluno);
    situacaoAluno(aluno);
    printf("\n");
    imprimir(aluno);
  /*
   for (i = 0; i < TAM; i++)
    {
        printf("Media:%f", aluno[i].media);
    }
  */
    return 0;
}