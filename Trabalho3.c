#include <stdio.h>
#include <stdlib.h>
#include <time.h>

    char entrada_valida() {
        char c, enter;
        int c1 = 0, c2 = 0;
        while (!(c1 == 1 && ((c == 'w') || (c == 'a') || (c == 's') || (c == 'd') || (c == 'm') ||
        (c == 'W') || (c == 'A') || (c == 'S') || (c == 'D') || (c == 'M')))) {
            if (c2 == 0)
                printf("Digite uma entrada:\n");
            else
                printf("Entrada inválida, tente novamente:\n");
            c1 = 0;
            scanf(" %c",&c);
            c2 ++;
            do {
            scanf("%c", &enter);
            c1 ++;
            }
            while (enter != '\n');
        }
    return c;
    }

    int menu() {
        int resposta;
        printf("\n Menu do Jogo\n\n Você deseja:\n\n\t1) Retornar ao jogo\n\t2) Sair do jogo\n\n Escolha: ");
        scanf("%d", &resposta);
        while (resposta != 1 && resposta != 2) {
            printf("Entrada inválida, tente novamente:\n");
            scanf("%d", &resposta);
        }
        return resposta;
    }

    void mapa_inteiro(const int I,const int J, char mapa[I][J]) {
        int i, j;
        for(j = 0; j < J; j++){
            for(i = 0; i < I; i++) {
                if(i == 0 || i == I - 1 || j == 0 || j == J - 1)
                    mapa[i][j] = '#';
                else if(i == 60 && (j >= 14 && j <= 16))
                     mapa[i][j] = '!';
                else if(i == 67 && j == 15)
                    mapa[i][j] = 'W';
                else if(i == 58 && j == 15)
                    mapa[i][j] = 'C';
                /* Desafio 1   */
                else if (i == 36 && j == 5)
                    mapa[i][j] = '?';
                else if (i == 34 && j == 5)
                    mapa[i][j] = '!';
                else if (i == 31 && j == 5)
                    mapa[i][j] = '*';
                 /* Desafio 2 */
                else if (j == 22 && i == 11 )
                    mapa[i][j] = '?';
                else if (j == 24 && i == 11 )
                    mapa[i][j] = '!';
                else if (j == 26 && i == 11)
                    mapa[i][j] = '*';
                /* Desafio 3 */
                else if (j == 27 && i == 59)
                    mapa[i][j] = '?';
                else if (j == 27 && i == 61)
                    mapa[i][j] = '!';
                else if (j == 27 && i == 64)
                    mapa[i][j] = '*';
                /*  */ 
                else if(i >= 61 && j >= 8 && j <= 22)
                    mapa[i][j] = ' ';
                else if(i >= 25 && j <= 16 && j >= 14)
                    mapa[i][j] = ' ';
                else if ((i == 40 || i == 41) && j <= 14 && j >= 5)
                    mapa[i][j] = ' ';
                else if ((j == 5 && i <= 40 && i >= 34))
                    mapa[i][j] = ' ';
                else if ((j >= 4 && j <= 6 && i <= 33 && i >= 29))
                    mapa[i][j] = ' ';
                else if (j == 14 && i >= 5 && i <= 25)
                    mapa[i][j] = ' ';
                else if (j <= 13 && j >= 1 && (i == 5 ||i == 6))
                    mapa[i][j] = ' ';
                else if (j == 1 && i >= 5 && i <= 69)
                    mapa[i][j] = ' ';
                else if (j <= 1 && j >= 4 && i == 69)
                    mapa[i][j] = ' ';
                else if (j <= 4 && j >= 1 && i >= 67 && i <= 71)
                    mapa[i][j] = ' ';
                else if ((i == 34 || i == 33) && j >= 17 && j <= 26)
                    mapa[i][j] = ' ';
                else if (j == 21 && ((i <= 33 && i >= 11) || (i >= 34 && i <= 53)))
                    mapa[i][j] = ' ';
                else if (i == 11  && j <= 25 && j >= 21)
                    mapa[i][j] = ' ';
                else if (i >= 9 && i <= 13 && j <= 27 && j >= 25)
                    mapa[i][j] = ' ';
                else if (j >= 26 && j <= 28 && i >= 30 && i <= 37)
                    mapa[i][j] = ' ';
                else if ((i == 53 || i == 52) && j >= 21 && j <= 27)
                    mapa[i][j] = ' ';
                else if (j == 27 && i >= 53 && i <= 62)
                    mapa[i][j] = ' ';
                else if (j >= 26 && j <= 28 && i >= 62 && i <= 66)
                    mapa[i][j] = ' ';
                else
                    mapa[i][j]= '#'; 
                }
            }        
        }

    void mostra_mapa (const int I, const int J, char mapa[I][J], int vidas) {
        int i, j;
        printf("\nVidas: %d\n", vidas);
        for(j = 0; j < J; j++) {
            for(i = 0; i < I; i++) {
                putchar(mapa[i][j]);
            }
            putchar('\n');
        }
        putchar('\n');
    }



    void atualiza_mapa(const int I,const int J, char mapa[I][J], int d1, int d2, int d3) {     /* Função que atualiza de acordo com os resultados dos desafios, abrindo as portas e etc */
        if (d1 == 0) {
            mapa[36][5] = ' ';
            mapa[34][5] = ' ';
        }
        if (d2 == 0) {
            mapa[11][22] = ' ';
            mapa[11][24] = ' ';
        }
        if (d3 == 0) {
            mapa[59][27] = ' ';
            mapa[61][27] = ' ';
        }
    }


    void atualiza_iluminacao(const int I,const int J, char mapa[I][J], int posicao_i, int posicao_j) {
        int i, j;
        for(j = 0; j < J; j++) {
            for(i = 0; i < I; i++) {  
                if(i == 0 || i == I - 1 || j == 0 || j == J - 1)
                    mapa[i][j] = '#';
                else if(abs(posicao_i - i) > 3 || abs(posicao_j - j) > 2)
                    mapa[i][j] = ' ';
                }
            }
        }

    int desafio1() {
        int n, resposta, tentativa = 20;
        char enter;
        srand(time(NULL));
        n = rand() % 1001;
        printf("\n Neste desafio, será escolhido aleatoriamente um número entre 0 e 1000, e você terá %d tentativas para acertar\n\n", tentativa);
        for(; tentativa > 0; tentativa--) {
            printf("\n Tentativa %d\n\n\t Digite o número: ", tentativa);
            scanf("%d%*c", &resposta);
            system("clear");
            if (resposta == n) {
                printf("\n Você acertou o número!\n\n\t Aperte ENTER para continuar ");
                do {scanf("%c", &enter);}
                while (enter != '\n');
                return 0;
            }
            else if (resposta > n) 
                printf("\n O número é menor que %d\n", resposta);
            else if (resposta < n)
                printf("\n O número é maior que %d\n", resposta);
        }

        return 1;

            }

int main() {
    const int I = 75 , J = 31;
    int posicao_i = 37, posicao_j = 15, vidas = 5, resp_menu, resultado_desafio1 = 1, resultado_desafio2 = 1, resultado_desafio3 = 1;
    char mapa[I][J], entrada;
    system("clear");
    mapa_inteiro(I, J, mapa);
    mapa[posicao_i][posicao_j] = '@';
    atualiza_iluminacao(I, J, mapa, posicao_i, posicao_j);
    mostra_mapa(I, J, mapa, vidas);
    while(vidas>0) {
        entrada = entrada_valida();
        system("clear");
        if (entrada == 'm' || entrada == 'M')
        resp_menu = menu();
            if (resp_menu == 2)
            break;
        else if (posicao_i == 37 && posicao_j == 5 && (entrada == 'a' || entrada == 'A') && resultado_desafio1 != 0) {
            resultado_desafio1 = desafio1();
            if (resultado_desafio1 == 1) {
                printf("\n Você não adivinhou o número, portanto, perdeu uma vida!\n");
                vidas --;    
            }
                mapa_inteiro(I, J, mapa);
                atualiza_mapa(I, J, mapa, resultado_desafio1, resultado_desafio2, resultado_desafio3);
                mapa[posicao_i][posicao_j] = '@';
                atualiza_iluminacao(I, J, mapa, posicao_i, posicao_j);
                mostra_mapa(I, J, mapa, vidas);

        }

        else {
            if ((entrada == 'a' || entrada == 'A') && mapa[posicao_i - 1][posicao_j] == ' ')
                posicao_i--;
            else if ((entrada == 'd' || entrada == 'D') && mapa[posicao_i + 1][posicao_j] == ' ')
                posicao_i++;
            else if ((entrada == 'w' || entrada == 'W') && mapa[posicao_i][posicao_j - 1] == ' ')
                posicao_j--;
            else if ((entrada == 's' || entrada == 'S') && mapa[posicao_i][posicao_j + 1] == ' ')
                posicao_j++;
            mapa_inteiro(I, J, mapa);
            atualiza_mapa(I, J, mapa, resultado_desafio1, resultado_desafio2, resultado_desafio3);
            mapa[posicao_i][posicao_j] = '@';
            atualiza_iluminacao(I, J, mapa, posicao_i, posicao_j);
            mostra_mapa(I, J, mapa, vidas);
    }
}


    return 0;
}