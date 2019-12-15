#include <stdio.h>
#include <math.h>
#include <string.h>
// ------------------ Construir o tabuleiro -----------------
    /* O tabuleiro vai ser uma matrix 9x9
    Primeira linha vai ter os numero das colunas
    Primeira coluna (primeira posição de cada linha) vai ter a letre que representa a linha
    Vamos iterar por cada linha (9 vezes) e iterar por cada posição (9 vezes)
    */
    //para as linhas
    calculaTabuleiro(int max){
        int i, j, value, MAX;
        MAX = max;
        int board[max][max];
        for (i = 0; i < MAX; i++){
            for (j = 0; j < MAX; j++){
                // se linha 0 -> vou colocar os numeros das colunas
                if(i == 0){
                    value = j;
                } else {
                    if (j == 0 ) {
                        value = i;
                    }
                    if (j > 0) {
                        if ((j + i) % 2 == 0){
                            value = 2;
                        } else {
                            value = 1;
                        }

                    }
                }
                board[i][j] = value;
            }
        }
        return board;
    }

    calculaPecasIniciais (int max){
        int i, j, MAX, value;
        MAX = max;
        int pieces[max][max];
        for(i = 0; i < MAX; i++){
            for(j = 0; j < MAX; j++){
                value = 0;
                if(i > 0 && j > 0 && i < 4){
                    if(i % 2 != 0 && j % 2 != 0){
                       value = 10;
                        }
                    if(i % 2 == 0 && j % 2 == 0){
                        value = 10;
                    }
                }
                if(j > 0 && i > 5){
                    if(i % 2 != 0 && j % 2 != 0){
                       value = 20;
                        }
                    if(i % 2 == 0 && j % 2 == 0){
                        value = 20;
                    }
                }
                pieces[i][j] = value;
            }
        }
        return pieces;
    }
    //desenhar o tabuleiro
    desenhaTabuleiro(int max, int *pieces, int *board){
        int i, j, MAX, pieces;
        MAX = max;
        int boardPlace[max][max];
        for (i = 0; i < MAX; i++){
            for (j = 0; j < MAX; j++){
                if(pieces[i][j] != 0) {
                    boardPlace = pieces[i][j];
                } else {
                    boardPlace = board[i][j];
                }
                if (i == 0) {
                    switch (boardPlace){
                        case 0:
                            strcpy(toPrint, "   ");
                            break;
                        case 1:
                            strcpy(toPrint, " 1 ");
                            break;
                        case 2:
                            strcpy(toPrint, " 2 ");
                            break;
                        case 3:
                            strcpy(toPrint, " 3 ");
                            break;
                        case 4:
                            strcpy(toPrint, " 4 ");
                            break;
                        case 5:
                            strcpy(toPrint, " 5 ");
                            break;
                       case 6:
                            strcpy(toPrint, " 6 ");
                            break;
                       case 7:
                            strcpy(toPrint, " 7 ");
                            break;
                       case 8:
                            strcpy(toPrint, " 8 ");
                            break;
                    }
                }
                if (i > 0 && j == 0){
                    switch (boardPlace){
                        case 0:
                            strcpy(toPrint, "   ");
                            break;
                        case 1:
                            strcpy(toPrint, " A ");
                            break;
                        case 2:
                            strcpy(toPrint, " B ");
                            break;
                        case 3:
                            strcpy(toPrint, " C ");
                            break;
                        case 4:
                            strcpy(toPrint, " D ");
                            break;
                        case 5:
                            strcpy(toPrint, " E ");
                            break;
                       case 6:
                            strcpy(toPrint, " F ");
                            break;
                       case 7:
                            strcpy(toPrint, " G ");
                            break;
                       case 8:
                            strcpy(toPrint, " H ");
                            break;
                    }
                }

                if (i > 0 && j > 0) {
                    switch (boardPlace){
                        case 20:
                            strcpy(toPrint, "<b>");
                            break;
                        case 10:
                            strcpy(toPrint, "<p>");
                            break;
                        case 2:
                            strcpy(toPrint, "|||");
                            break;
                        case 1:
                            strcpy(toPrint, "   ");
                            break;
                    }
                }

                printf("%s", toPrint);
            }
            printf("\n");
        }
    }

int main(void){

    int MAX = 9;
    int board[MAX][MAX];
    int i, j, value, boardPlace;
    char rows[] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    char columns[] = {' ', '1', '2', '3', '4', '5', '6', '7', '8'};
    char toPrint[4];
    int pieces[MAX][MAX];

    board = calculaTabuleiro(MAX);
}



/*
#include <stdio.h>
#include <math.h>

int main(void)
{
    int MAX = 64;
    int cenas[MAX], i, value;
    char black[] = "\xB2\xB2";
    char white[] = "  ";

    for (i = 0; i < MAX; i++){
        if (i % 2 == 0){
            value = 1;
        }
        else{
            value = 2;
        }
        if (i > 7){
            if (cenas[i - 8] == 1){
                value = 2;
            }
            else{
                value = 1;
            }
        }
        cenas[i] = value;
    }
    for (i = 0; i < MAX; i++){
        if ((i) % 8 == 0){
            printf(" \n");
        }
        if (cenas[i] == 1) {
            printf("%s", black);
        }
        else {
            printf("%s", white);
        }
    }
}
*/
