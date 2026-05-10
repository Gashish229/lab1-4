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
// Функция ручного ввода матрицы с клавиатуры
void input_matrix(matrix2d* m) {
    printf("--- Ручной ввод матрицы размером %dx%d ---\n", m->rows, m->cols);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            // Временные переменные, так как scanf не умеет писать напрямую в битовые поля
            int r, g, b, mode; 
            
            printf("Пиксель [%d][%d] - Введите через пробел R, G, B и Режим (0-2): ", i, j);
            scanf("%d %d %d %d", &r, &g, &b, &mode);
            
            // Присваиваем считанные значения нашим битовым полям
            m->data[i][j].red = r;
            m->data[i][j].green = g;
            m->data[i][j].blue = b;
            m->data[i][j].mode = mode;
        }
    }
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
