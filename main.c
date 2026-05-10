#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Подключаем модули проекта
#include "bitrgbled.h"
#include "matrix2d.h"
#include "contqueue.h"
#include "fiostruct.h"

// =================================================================
// СТРУКТУРА ДЛЯ ЛАБЫ 1: Чистая матрица на int (для демонстрации)
// =================================================================
typedef struct {
    int rows;
    int cols;
    int **data;
} simple_matrix;

// Конструктор для простой матрицы
simple_matrix* create_simple(int r, int c) {
    simple_matrix* m = (simple_matrix*)malloc(sizeof(simple_matrix));
    m->rows = r; 
    m->cols = c;
    m->data = (int**)malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++) {
        m->data[i] = (int*)malloc(c * sizeof(int));
    }
    return m;
}

// Деструктор для простой матрицы
void free_simple(simple_matrix* m) {
    if (m == NULL) return;
    for (int i = 0; i < m->rows; i++) free(m->data[i]);
    free(m->data);
    free(m);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("=== МЕНЮ ТЕСТИРОВАНИЯ ЛАБОРАТОРНЫХ РАБОТ ===\n");
        printf(" ./main lab1   - Тест Лабы 1 (Чистая Матрица на int + scanf)\n");
        printf(" ./main lab2   - Тест Лабы 2 (Матрица с RGB пикселями + scanf)\n");
        printf(" ./main lab3   - Тест Лабы 3 (Очередь на 1 000 000 элементов)\n");
        printf(" ./main lab4 save <файл> - Тест Лабы 4 (Сохранение в файл)\n");
        printf(" ./main lab4 list <файл> - Тест Лабы 4 (Количество в файле)\n");
        printf(" ./main lab4 get <индекс> <файл> - Тест Лабы 4 (Чтение элемента)\n");
        return 0;
    }

    const char* command = argv[1];

    // --- ЛАБОРАТОРНАЯ 1: МАТРИЦА НА INT ---
    if (strcmp(command, "lab1") == 0) {
        printf("\n--- ЛАБ 1: РУЧНОЙ ВВОД МАТРИЦЫ (INT) ---\n");
        simple_matrix* m = create_simple(2, 2);
        
        printf("Введите %d целых чисел для матрицы %dx%d:\n", m->rows * m->cols, m->rows, m->cols);
        for (int i = 0; i < m->rows; i++) {
            for (int j = 0; j < m->cols; j++) {
                printf("Элемент [%d][%d]: ", i, j);
                scanf("%d", &m->data[i][j]); // Ручной ввод
            }
        }
        
        printf("\nРезультат ввода:\n");
        for (int i = 0; i < m->rows; i++) {
            for (int j = 0; j < m->cols; j++) printf("%d\t", m->data[i][j]);
            printf("\n");
        }
        free_simple(m);
    }
    
    // --- ЛАБОРАТОРНАЯ 2: БИТОВЫЕ ПОЛЯ (RGB) ---
    else if (strcmp(command, "lab2") == 0) {
        printf("\n--- ЛАБ 2: ВВОД ПИКСЕЛЕЙ (БИТОВЫЕ ПОЛЯ) ---\n");
        matrix2d* screen = create_matrix(2, 2);
        
        printf("Введите данные R G B и Mode(0-2) для каждого пикселя:\n");
        for (int i = 0; i < screen->rows; i++) {
            for (int j = 0; j < screen->cols; j++) {
                int r, g, b, mode;
                printf("Пиксель [%d][%d]: ", i, j);
                scanf("%d %d %d %d", &r, &g, &b, &mode);
                // Присваиваем значения битовым полям
                screen->data[i][j].red = r;
                screen->data[i][j].green = g;
                screen->data[i][j].blue = b;
                screen->data[i][j].mode = mode;
            }
        }
        
        printf("\nВывод матрицы пикселей:\n");
        print_matrix(screen);
        free_matrix(screen);
    }
    
    // --- ЛАБОРАТОРНАЯ 3: ОЧЕРЕДЬ 1 000 000 ЭЛЕМЕНТОВ ---
    else if (strcmp(command, "lab3") == 0) {
        printf("\n--- ЛАБ 3: ТЕСТ ОЧЕРЕДИ (1 МИЛЛИОН ОБЪЕКТОВ) ---\n");
        queue* q = create_queue();
        int count = 1000000;
        
        printf("Добавление %d элементов в очередь (FIFO)...\n", count);
        for (int i = 0; i < count; i++) {
            matrix2d* m = create_matrix(1, 1);
            m->data[0][0].red = i % 256;
            enqueue(q, m);
        }
        
        printf("Успешно! Элементов в контейнере: %d\n", q->count);
        
        matrix2d* first = dequeue(q);
        printf("Первый элемент извлечен. Цвет RED: %d\n", first->data[0][0].red);
        
        free_matrix(first);
        free_queue(q); // Очистка памяти
        printf("Память очищена.\n");
    }
    
    // --- ЛАБОРАТОРНАЯ 4: ФАЙЛЫ ---
    else if (strcmp(command, "lab4") == 0) {
        if (argc < 3) return 0;
        const char* subcmd = argv[2];
        
        if (strcmp(subcmd, "save") == 0 && argc == 4) {
            int n = 10000;
            matrix2d** arr = rand_gen_struct(n);
            save_text(argv[3], arr, n);
            printf("Сохранено %d элементов в %s\n", n, argv[3]);
            for(int i = 0; i < n; i++) free_matrix(arr[i]);
            free(arr);
        }
        else if (strcmp(subcmd, "list") == 0 && argc == 4) {
            list_file(argv[3]);
        }
        else if (strcmp(subcmd, "get") == 0 && argc == 5) {
            int idx = atoi(argv[3]);
            matrix2d* m = get_element_from_text_file(argv[4], idx);
            if (m) {
                print_matrix(m);
                free_matrix(m);
            }
        }
    }

    return 0;
}
