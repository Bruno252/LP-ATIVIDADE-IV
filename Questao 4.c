#include <stdio.h>
#include <stdlib.h>

struct contaBancaria {
    char numero[250];
    char nome[250];
    float saldoCorrente;
    float saldoPoupanca;
    int tipoConta;
    int contadorSacar;
    int contadorDepositado;
    int contadorSaldo;
};

void a() {
    printf("------------------------------------------\n");
}

void limpatudo() {
    fflush(stdin);
//setbuf(stdin,NULL);
    system("cls || clear");
}

struct contaBancaria corrente(struct contaBancaria pessoa) {
    float valorSacado;
    int escolha;

    do {
        a();
        printf("Digite 1| para sacar\n");
        printf("Digite 2| para depositar\n");
        printf("Digite 3| para ver o saldo\n");
        printf("Digite 4| para voltar\n");
        a();
        scanf("%d",&escolha);

        switch(escolha) {
        case 1:
            fflush(stdin);
            limpatudo();
            a();
            printf("Valor que deseja ser sacado:\n");
            a();
            scanf("%f",&valorSacado);
            pessoa.saldoCorrente-=valorSacado;
            //pessoa.saldo=sacarCorrente(pessoa,valorSacado);
            break;

        case 2:
            fflush(stdin);
            limpatudo();
            a();
            printf("Valor que deseja ser Depositado:\n");
            a();
            scanf("%f",&valorSacado);
            pessoa.saldoCorrente+=valorSacado;

            break;

        case 3:
             limpatudo();
            a();
            printf("Saldo da Conta:%.2f\n",pessoa.saldoCorrente);
            a();
            break;

        }
    } while(escolha!=4);
    return pessoa;
}
struct contaBancaria poupanca(struct contaBancaria pessoa) {
    int contador;
    int escolha;
    float valorSacado;

    do {
        a();
        printf("Digite 1| para sacar\n");
        printf("Digite 2| para depositar\n");
        printf("Digite 3| para ver o saldo\n");
        printf("Digite 4| para voltar\n");
        a();
        scanf("%d",&escolha);

        switch(escolha) {
        case 1:
            if(pessoa.contadorSacar<2) {
                limpatudo();
                a();
                printf("Valor que deseja ser sacado:\n");
                a();
                scanf("%f",&valorSacado);
                pessoa.saldoPoupanca-=valorSacado;
                pessoa.contadorSacar++;
            } else {
                limpatudo();
                a();
                printf("Limite Excedido\n");
                a();
            }
            break;

        case 2:
            if(pessoa.contadorDepositado<2) {
                limpatudo();
                a();
                printf("Valor que deseja ser Depositado:\n");
                a();
                scanf("%f",&valorSacado);
                pessoa.saldoPoupanca+=valorSacado;
                pessoa.contadorDepositado++;
            } else {
                limpatudo();
                a();
                printf("Limite Excedido\n");
                a();
            }
            break;

        case 3:
            if(pessoa.contadorSaldo<2) {
                limpatudo();
                a();
                printf("Saldo da Conta:%.2f\n",pessoa.saldoPoupanca);
                a();
                pessoa.contadorSaldo++;
            } else {
                limpatudo();
                a();
                printf("Limite Excedido\n");
                a();
            }
            break;
        }
    } while(escolha!=4);
    return pessoa;
}


int main() {
    int escolha;
    int conta;
    float valor;
    int i;
    struct contaBancaria pessoa;

    pessoa.saldoPoupanca=0;
    pessoa.saldoCorrente=0;
    pessoa.contadorSacar=0;
    pessoa.contadorDepositado=0;
    pessoa.contadorSaldo=0;

    printf("Nome do Titular:");
    fgets(pessoa.nome,sizeof(pessoa.nome),stdin);
    printf("Numero da Conta:");
    fgets(pessoa.numero,sizeof(pessoa.numero),stdin);


    do {
        limpatudo();
        a();
        printf("Digite 1 | para conta corrente\n");
        printf("Digite 2 | para conta poupanca\n");
        printf("Digite 3 | sair e encerrar o procedimento\n");
        a();
        scanf("%d",&pessoa.tipoConta);
        conta=pessoa.tipoConta;
        limpatudo();
        switch(conta) {

        case 1:
            limpatudo();
            pessoa=corrente(pessoa);

            break;

        case 2:
            limpatudo();
            pessoa=poupanca(pessoa);

            break;

        case 3:

            break;
        default:
            printf("Escolha Invalida\n");
            break;
        }
    } while(conta!=3);
    printf("Obrigado e Volte Sempre");
    return 0;
}
