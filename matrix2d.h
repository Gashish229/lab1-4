#ifndef MATRIX2D_H
#define MATRIX2D_H
#include <stdio.h>
#include <stdlib.h>
#include "bitrgbled.h" // Подключаем наш пиксель

// Структура двумерной матрицы
typedef struct {
    int rows;
    int cols;
    rgbled **data; // Двумерный массив (указатель на указатель) пикселей
} matrix2d;

// Базовые методы матрицы
matrix2d* create_matrix(int r, int c);
void free_matrix(matrix2d* m);
void fill_random(matrix2d* m);
void input_matrix(matrix2d* m);
void print_matrix(matrix2d* m);

#endif
