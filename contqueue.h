#ifndef CONTQUEUE_H
#define CONTQUEUE_H
#include "matrix2d.h"

// Узел односвязного списка
typedef struct Node {
    matrix2d* mat;       // Указатель на матрицу
    struct Node* next;   // Указатель на следующий узел
} Node;

// Сама структура очереди
typedef struct {
    Node* head;  // Начало (отсюда забираем)
    Node* tail;  // Конец (сюда добавляем)
    int count;   // Количество элементов
} queue;

queue* create_queue();
void enqueue(queue* q, matrix2d* m);
matrix2d* dequeue(queue* q);
void free_queue(queue* q);

#endif
