#include <stdlib.h>
#include <stdio.h>

#include "./Fila/fila.h"
#include "./Pilha/pilha.h"

int contador = 0, senha = 1;

void menuCaixa(Fila* prio, Fila* norm, Pilha* chamadas){
    char opcao;

    do{
        printf("\n\nCAIXA \n 1 - Chamar o proximo \n 2 - Visualizar filas \n 3 - Ultimas chamadas \n 4 - Voltar ao menu anterior\n");
        scanf(" %c", &opcao);
        fflush(stdin);
        

        switch (opcao)
        {
        case '1':
            printf("");
            int proximo = 0;

            if(!filaVazia(prio) && !filaVazia(norm)){

                if(contador == 0){

                    proximo = desenfileirar(prio);
                    empilhar(chamadas, proximo, 'p');
                    contador++;

                }else{

                    proximo = desenfileirar(norm);
                    empilhar(chamadas, proximo, 'n');
                    contador++;

                    if (contador > 2){
                        contador = 0;
                    }

                }

            }else if(!filaVazia(prio)){
                proximo = desenfileirar(prio);
                empilhar(chamadas, proximo, 'p');

            }else if(!filaVazia(norm)){
                proximo = desenfileirar(norm);
                empilhar(chamadas, proximo, 'n');

            }else{
                printf("\nAs filas estao vazias!");
                break;
            }
            
            printf("\nChamando %d!", proximo);

            break;
        case '2':
            printf("\n");

            printf("Prioritaria:\n");
            visualizarFila(prio);

            printf("Normal:\n");
            visualizarFila(norm);

            break;
        case '3':
            printf("\n");
            visualizarPilha(chamadas);

            break;
        case '4':
            printf("\nSaindo do menu caixa...");
            opcao = 0;

            break;
        default:
            printf("\nOpcao invalida!");

            break;
        }
        
    }while (opcao != 0);
}

void menuCliente(Fila* prio, Fila* norm){
    char opcao;

    do{
        printf("\n\nRETIRAR SENHA \n 1 - Normal \n 2 - Prioritaria \n 3 - Voltar ao menu anterior\n");
        scanf(" %c", &opcao);
        fflush(stdin);

        switch (opcao)
        {
        case '1':
            if (!filaCheia(norm))
            {
                enfileirar(norm, senha);
                printf("\nSenha normal: %d, gerada!", senha);

                senha++;
            }else
            {
                printf("\nNao e possivel retirar a senha, fila normal cheia!");
            }
            break;
        case '2':
            if (!filaCheia(prio))
            {
                enfileirar(prio, senha);
                printf("\nSenha prioritaria: %d, gerada!", senha);

                senha++;
            }else
            {
                printf("\nNao e possivel retirar a senha, fila prioritaria cheia!");
            }

            break;
        case '3':
            printf("\nSaindo do menu cliente...");
            opcao = 0;

            break;
        default:
            printf("\nOpcao invalida!");
            
            break;
        }
        
    }while (opcao != 0);
}

int main(){
    char opcao;
    Fila* normal = criarFila();
    Fila* prioritaria = criarFila();
    Pilha* chamadas = criarPilha();

    do{
        printf("\n\nMENU DE CONTROLE \n 1 - Menu caixa \n 2 - Menu cliente \n 3 - Encerrar\n");
        scanf(" %c", &opcao);
        fflush(stdin);

        switch (opcao)
        {
        case '1':
            menuCaixa(prioritaria, normal, chamadas);
            system("cls");

            break;
        case '2':
            menuCliente(prioritaria, normal);
            system("cls");

            break;
        case '3':
            printf("\nAte logo!\n Encerrando...");
            opcao = 0;

            break;
        default:
            printf("\nOpcao invalida!");
            break;
        }
        
    }while (opcao != 0);
    
    liberaFila(normal);
    liberaFila(prioritaria);
    liberaPilha(chamadas);

    return 0;

    exit(1);
}
