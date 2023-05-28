#include <stdio.h>
#include <stdlib.h>  //Підключення необхідних для роботи бібліотек

#define SIZE 3

//Функція для обчислення скалярного добутку двох векторів
int dot_product(int vector1[SIZE], int vector2[SIZE]) {
    int product = 0;
    for (int i = 0; i < SIZE; i++) {
        product += vector1[i] * vector2[i];
    }
    return product;
}

//Функція для перевірки, чи є матриця ортонормованою
int is_orthonormal(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i != j && dot_product(matrix[i], matrix[j]) != 0) {
                return 0;  //Знайдено ненульовий скалярний добуток рядків
            }
            if (i == j && dot_product(matrix[i], matrix[j]) != 1) {
                return 0;  //Знайдено скалярний добуток рядка на себе, що не дорівнює 1
            }
        }
    }
    return 1;//Матриця є ортонормованою
}

//Функція для виведення матриці на екран
void print_matrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[SIZE][SIZE];

    printf("Введіть елементи матриці розміром %dx%d:\n", SIZE, SIZE);//введеня необхідної для обчислення інформації з клавіатури
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("Елемент [%d][%d]: ", i, j);
            scanf_s("%d", &matrix[i][j]);
        }
    }

    printf("Введена матриця:\n");
    print_matrix(matrix);

    if (is_orthonormal(matrix)) {//Виведення результатів на екран юзера
        printf("Матриця є ортонормованою.\n");
    }
    else {
        printf("Матриця не є ортонормованою.\n");
    }

    return 0;//кінець програми
}



