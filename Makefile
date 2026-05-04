# --- Настройки компилятора ---
CC = gcc
CFLAGS = -Wall -std=c99

# --- Главная цель (вызывается при простом 'make') ---
all: main

# --- Сборка итоговой программы ---
main: main.o matrix2d.o bitrgbled.o contqueue.o fiostruct.o
	$(CC) $(CFLAGS) -o main main.o matrix2d.o bitrgbled.o contqueue.o fiostruct.o

# --- Компиляция отдельных файлов ---
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

matrix2d.o: matrix2d.c matrix2d.h bitrgbled.h
	$(CC) $(CFLAGS) -c matrix2d.c

bitrgbled.o: bitrgbled.c bitrgbled.h
	$(CC) $(CFLAGS) -c bitrgbled.c

contqueue.o: contqueue.c contqueue.h matrix2d.h
	$(CC) $(CFLAGS) -c contqueue.c

fiostruct.o: fiostruct.c fiostruct.h matrix2d.h
	$(CC) $(CFLAGS) -c fiostruct.c

# --- Запуск программы (make run) ---
# Эта команда сначала проверит, собран ли main, и если да — запустит тест
run: main
	./main test

# --- Очистка (make clean) ---
clean:
	rm -f *.o main
