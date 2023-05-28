#include <stdio.h>//Підключення необхідних бібліотек
#include <stdlib.h>
#include <time.h>

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
            //Перевірка, чи вектори мають скалярний добуток 0, якщо індекси не співпадають
            if (i != j && dot_product(matrix[i], matrix[j]) != 0) {
                return 0;
            }
            //Перевірка, чи вектор має скалярний добуток 1 з собою, якщо індекси співпадають
            if (i == j && dot_product(matrix[i], matrix[j]) != 1) {
                return 0;
            }
        }
    }
    return 1;
}

//Функція для виводу матриці на екран
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

    //Ініціалізація генератора випадкових чисел
    srand(time(NULL));

    //Заповнення матриці випадковими числами
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = rand() % 201 - 100;  //Випадкове число від -100 до 100
        }
    }

    printf("Згенерована матриця:\n");//Виведеня результатів на екран юзера
    print_matrix(matrix);

    if (is_orthonormal(matrix)) {
        printf("Матриця є ортонормованою.\n");
    }
    else {
        printf("Матриця не є ортонормованою.\n");
    }

    return 0;//Кінець програми
}


