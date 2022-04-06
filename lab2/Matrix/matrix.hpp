#pragma once
#ifndef matrix_hpp
#define matrix_hpp
#include <iostream>

using namespace std;
// шаблонный класс Матрица
template <class T>
class matrix{
private:
    T** M = nullptr; // матрица
    int rows = 0; // количество строк
    int columns = 0; // количество столбцов
public:
    //КОНСТРУКТОР
    matrix(){
        columns = rows = 0;
        M = nullptr; // необязательно
    }
    matrix(int x, int y){
        rows = x;
        columns = y;
        M = (T**) new T*[rows]; // количество строк, количество указателей
        for (int i = 0; i < rows; i++){
            M[i] = (T*)new T[columns];
            for (int j = 0; j < columns; j++){
                M[i][j] = rand()%10 + 1;
            }
        }
    }
    matrix(const matrix &NM){
        // Создается новый объект для которого выделяется память
        // Копирование данных *this <= NM
        rows = NM.m;
        columns = NM.n;

        // Выделить память для M
        M = (T**) new T*[rows]; // количество строк, количество указателей

        for (int i = 0; i < rows; i++)
          M[i] = (T*) new T[columns];

        // заполнить значениями
        for (int i = 0; i < rows; i++)
          for (int j = 0; j < columns; j++)
            M[i][j] = NM.M[i][j];
    }
    // методы доступа
    int GetMij(int i, int j){
        if ((rows > 0) && (columns > 0))
          return M[i][j];
        else
          return 0;
    }
    void SetMij(int i, int j, T value){
        if ((i < 0) || (i >= rows))
          return;
        if ((j < 0) || (j >= columns))
          return ;
        M[i][j] = value;

    }
    // метод, выводящий матрицу
    void Print(){
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < columns; j++){
                cout << M[i][j] << "\t";
            }
            cout << endl;
        }
    }
    // Деструктор - освобождает память, выделенную для матрицы
    ~matrix(){
        if (columns > 0)
        {
          // освободить выделенную память для каждой строки
          for (int i = 0; i < rows; i++)
            delete[] M[i];
        }
        if (rows > 0)
          delete[] M;
    }
};
#endif /* matrix_hpp */
