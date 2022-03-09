/* Yitian Huang, System Programming, CS 2600
   03/07/2022
   Lo Shu Magic Square
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void part1();
void part2();
bool magicValidity(const int square[3][3], int size);
void squarePrinter(const int square[3][3], int size);
void generateSquare(int square[3][3], const int size);

    int main()
{
    // random generator
    time_t t;
    srand((unsigned)time(&t));

    part1();
    part2();
}

void part1() {
    /**
     * @brief part 1, Manually test a lo shu magic square and a 
     * non magic square 
     */
    printf("part 1:\n");
    int magicSquare[3][3] = {
        {8, 1, 6},
        {3, 5, 7},
        {4, 9, 2}
    };
    int nonMagicSquare[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    squarePrinter(magicSquare, 3);
    if (magicValidity(magicSquare, 3)) {
        printf("This is a magic square\n");
    } else {
        printf("This is not a magic square\n");
    }

    squarePrinter(nonMagicSquare, 3);
    if (magicValidity(nonMagicSquare, 3)) {
        printf("This is a magic square\n");
    } else {
        printf("This is not a magic square\n");
    }
}

void part2() {
    /**
     * @brief part 2, Randomly generate numbers until a valid lo shu magic square
     *  keep track of the number of generations until success and then print the square
     */
    printf("\nPart 2:\n");

    int rounds = 0;
    int square3[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 1}
    };

    while (!magicValidity(square3, 3)) {
        rounds++;
        generateSquare(square3, 3);
        // squarePrinter(square3, 3);
    }

    // print output
    printf("%d rounds to generate a magic square\n", rounds);
    squarePrinter(square3, 3);

}

bool magicValidity(const int square[3][3], int size) {
    bool result = true;
    int a = square[0][0];
    int b = square[0][1];
    int c = square[0][2];
    int d = square[1][0];
    int e = square[1][1];
    int f = square[1][2];
    int g = square[2][0];
    int h = square[2][1];
    int i = square[2][2];

    int sum = a + b + c;
    if (d + e + f != sum) {
        result = false;
    } else if (g + h + i != sum) {
        result = false;
    } else if (a + d + g != sum) {
        result = false;
    } else if (b + e + h != sum) {
        result = false;
    } else if (c + f + i != sum) {
        result = false;
    } else if (a + e + i != sum) {
        result = false;
    } else if (c + e + g != sum) {
        result = false;
    }

    return result;
}

void squarePrinter(const int square[3][3], int size) {
    printf("\n");
    for (int i = 0; i < size; ++i) {
        printf("[");
        for (int j = 0; j < size; ++j) {
            if (j == size - 1) {
                printf("%d", square[i][j]);
            } else {
                printf("%d ", square[i][j]);
            }
        }
        printf("]\n");
    }
}

void generateSquare(int square[3][3], const int size) {
    // track which number used
    int used[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int num = rand() % 9 + 1;
            while (used[num - 1] == 1) {
                num = rand() % 9 + 1;
            }
            used[num - 1] = 1;
            square[i][j] = num;
        }
    }


}
