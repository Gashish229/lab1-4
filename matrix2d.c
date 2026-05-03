#include "matrix2d.h"

// Конструктор матрицы
matrix2d* create_matrix(int r, int c) {
    matrix2d* m = (matrix2d*)malloc(sizeof(matrix2d)); // Память под структуру
    m->rows = r;
    m->cols = c;
    
    // Память под массив строк
    m->data = (rgbled**)malloc(r * sizeof(rgbled*));
    
    // Память под каждую строку (столбцы)
    for (int i = 0; i < r; i++) {
        m->data[i] = (rgbled*)malloc(c * sizeof(rgbled));
        for (int j = 0; j < c; j++) {
            m->data[i][j].red = 0;
            m->data[i][j].green = 0;
            m->data[i][j].blue = 0;
            m->data[i][j].mode = 0;
        }
    }
    return m;
}

// Деструктор (очистка памяти в обратном порядке)
void free_matrix(matrix2d* m) {
    if (m == NULL) return;
    for (int i = 0; i < m->rows; i++) {
        free(m->data[i]); // Сначала удаляем столбцы
    }
    free(m->data); // Потом строки
    free(m);       // Потом саму структуру
}

// Заполняем матрицу случайными цветами
void fill_random(matrix2d* m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            m->data[i][j].red = rand() % 256;
            m->data[i][j].green = rand() % 256;
            m->data[i][j].blue = rand() % 256;
            m->data[i][j].mode = rand() % 3;
        }
    }
}

// Вывод на экран
void print_matrix(matrix2d* m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("[R:%3d G:%3d B:%3d]\t", m->data[i][j].red, m->data[i][j].green, m->data[i][j].blue);
        }
        printf("\n");
    }
}
