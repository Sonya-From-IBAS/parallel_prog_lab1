# Описание к лабораторным работам
### Лабораторная 1
***Выполнил студент группы 6312-100503D Пахомов Леонид***
___

### Задание на *л/р*:

- [X] Написать на С++ программу, которая создает матрицы, умножает их и записывает результаты в файлы
- [X] Написать программу на Python, которая проверяет результат перемножений матриц на C++
- [X] Получить график зависимости времени вычислений от размеров матриц

### Описание файлов
+ data - папка со значениями матриц
+ results - папка с результатами вычислений
  + result_computing - папка с временем вычислений и размером для каждой матрицы
  + result-matrix - папка с результирующей матрицей (результат перемножения двух матриц)
+ main.cpp - С++ скрипт, который создает, перемножает и записывает матрицы и результаты в файл
+ calc_checking.py - Python утилита для проверки перемножения матриц на C++
+ main.py - Python скрипт для проверки результатов C++ программы, использует calc_cheking.py (Для этого используется библиотека Numpy)
+ checking calculations.txt - txt файл, куда main.py записывает, верно ли были перемножены матрицы в C++
+ graph.png - График зависимости времени перемножения матриц от их размера
___

### График зависимости:
![graph](graph.png)

:octocat: Результаты:

Были созданы матрицы размерами 100x100, 250x250, 300x300, 500x500, 750x750, 900x900, 1000x1000. Результаты их перемножения были проверены с помощью Python и библиотеки Numpy и записаны в файл checking calculations.txt, все они были верны :white_check_mark:. Так же был создан график зависимости времени перемножений матриц и их размера. По нему видно, что время растет не пропорцианально увелечению размера матриц