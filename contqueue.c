#include "contqueue.h"

queue* create_queue() {
    queue* q = (queue*)malloc(sizeof(queue));
    q->head = NULL; 
    q->tail = NULL; 
    q->count = 0;
    return q;
}

// Добавление в конец очереди
void enqueue(queue* q, matrix2d* m) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->mat = m; 
    n->next = NULL;
    
    if (q->tail == NULL) {
        q->head = n; 
        q->tail = n;
    } else {
        q->tail->next = n; 
        q->tail = n;
    }
    q->count++;
}

// Извлечение из начала
matrix2d* dequeue(queue* q) {
    if (q->head == NULL) return NULL;
    
    Node* temp = q->head;
    matrix2d* m = temp->mat; // Сохраняем матрицу перед удалением узла
    
    q->head = q->head->next; // Сдвигаем голову
    if (q->head == NULL) q->tail = NULL;
    
    free(temp); // Удаляем узел
    q->count--;
    return m;
}

// Удаление очереди вместе со всеми матрицами внутри
void free_queue(queue* q) {
    while (q->count > 0) {
        matrix2d* m = dequeue(q);
        free_matrix(m);
    }
    free(q);
}
