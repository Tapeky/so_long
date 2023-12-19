/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 22:14:11 by tsadouk           #+#    #+#             */
/*   Updated: 2023/12/19 13:54:55 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>
#include <stdbool.h>
#define MAX_ROWS 5
#define MAX_COLS 13

struct Position {
    int row;
    int col;
};

// Fonction pour vérifier si une position est valide dans la carte
bool estPositionValide(int row, int col) {
    return (row >= 0 && row < MAX_ROWS && col >= 0 && col < MAX_COLS);
}

// Fonction pour vérifier l'accessibilité des positions C et E depuis la position P
bool sontCEAccessibles(char carte[MAX_ROWS][MAX_COLS], struct Position positionP) {
    bool visited[MAX_ROWS][MAX_COLS] = {{false}};
    int queue[MAX_ROWS * MAX_COLS];
    int front = -1, rear = -1;

    // Enfiler la position de départ P
    queue[++rear] = positionP.row;
    queue[++rear] = positionP.col;
    visited[positionP.row][positionP.col] = true;

    while (front != rear) {
        // Défiler une position
        int currentRow = queue[++front];
        int currentCol = queue[++front];

        // Vérifier les positions adjacentes
        struct Position adjacents[] = {{currentRow - 1, currentCol},
                                        {currentRow + 1, currentCol},
                                        {currentRow, currentCol - 1},
                                        {currentRow, currentCol + 1}};

        for (int i = 0; i < 4; ++i) {
            int adjRow = adjacents[i].row;
            int adjCol = adjacents[i].col;

            if (estPositionValide(adjRow, adjCol) &&
                carte[adjRow][adjCol] != '1' && // Ne pas traverser les murs
                !visited[adjRow][adjCol]) {
                // Enfiler la position adjacente
                queue[++rear] = adjRow;
                queue[++rear] = adjCol;
                visited[adjRow][adjCol] = true;

                // Si la position adjacente est C ou E, la marquer comme accessible
                if (carte[adjRow][adjCol] == 'C' || carte[adjRow][adjCol] == 'E') {
                    visited[adjRow][adjCol] = true;
                }
            }
        }
    }

    // Vérifier si toutes les positions C et E ont été marquées comme accessibles
    for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = 0; j < MAX_COLS; ++j) {
            if ((carte[i][j] == 'C' || carte[i][j] == 'E') && !visited[i][j]) {
                return false; // Une position C ou E n'est pas accessible
            }
        }
    }

    return true; // Toutes les positions C et E sont accessibles
}

// Fonction pour vérifier la validité de la carte
bool estCarteValide(char carte[MAX_ROWS][MAX_COLS], struct Position positionP) {
    // Vérifier l'accessibilité des positions C et E
    if (!sontCEAccessibles(carte, positionP)) {
        return false;
    }
    return true; // La carte est considérée comme valide
}

int main() {
    char carte[MAX_ROWS][MAX_COLS] = {
        "1111111111111",
        "10000000001C1",
        "1000111110011",
        "1P0011E000001",
        "1111111111111"
    };

    // Trouver la position du joueur P
    struct Position positionP;
    for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = 0; j < MAX_COLS; ++j) {
            if (carte[i][j] == 'P') {
                positionP.row = i;
                positionP.col = j;
                break;
            }
        }
    }
    // Vérifier la validité de la carte
    if (estCarteValide(carte, positionP)) {
        printf("La carte est valide.\n");
    } else {
        printf("La carte est invalide.\n");
    }
    return 0;
}
