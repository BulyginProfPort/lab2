#pragma once
#ifndef matrix_hpp
#define matrix_hpp
#include <iostream>
#include <time.h>
#include "../Sequence/LinkedListSequence/LinkedListSequence.hpp"
#include "../Sequence/ArraySequence/ArraySequence.hpp"
using namespace std;
// шаблонный класс Матрица
template <class T>
class Matrix{
private:
    //LinkedListSequence<T> *LM = nullptr;
    ArraySequence<T> *AM = nullptr;
    int rows = 0; // количество строк
    int columns = 0; // количество столбцов
public:
    //КОНСТРУКТОР
    Matrix(){
        columns = rows = 0;
        AM = nullptr; // необязательно
    }
    Matrix(int x, int y){
        rows = x;
        columns = y;
        AM = new ArraySequence<T> [rows]; // количество строк, количество указателей еа строки
        for (int i = 0; i < rows; i++){
            AM[i] = ArraySequence<T>(columns);
            for (int j = 0; j < columns; j++){
                AM[i].Set(rand()%10,j);
            }
        }
    }
    Matrix(const Matrix<T> &NM){
        // Создается новый объект для которого выделяется память
        // Копирование данных *this <= NM
        rows = NM.rows;
        columns = NM.columns;
        AM  = NM.AM;
    }

    // методы доступа
    T const GetMij(int i, int j){
        if (i < 0 || j < 0 || i >= rows || j >=columns){
            throw "IndexOutOfRange";
        }
        if ((rows > 0) && (columns > 0) ){
          return AM[i].Get(j);
        }
        else{
          return 0;
        }
    }
    int GetRows(){
        return rows;
    }
    int GetColumns(){
        return columns;
    }
    void SetRows(int n){
        rows = n;
    }
    void SetColumns(int n){
        columns = n;
    }
    void SetMij(int i, int j, T value){
        if ( (i < 0) || (i >= rows) ){
            throw "IndexOutOfRange";
        }
        if ( (j < 0) || (j >= columns) ){
            throw "IndexOutOfRange";
        }
        AM[i].Set(value,j);
    }
    
    // метод, выводящий матрицу
    void const Print(){
        for (int i = 0; i < rows; i++){
                AM[i].Print();
                cout << endl;
        }
    }
    Matrix operator+(Matrix<T> const matrix2){
        if ( rows == matrix2.rows && columns == matrix2.columns ){
            Matrix<T> tmp(rows,columns);
            ;tmp.AM = new ArraySequence<T>[rows];
            for (int i = 0; i < rows; i++){
                tmp.AM[i] = ArraySequence<T>(columns);
                tmp.AM[i] = AM[i].operator+(matrix2.AM[i]);
                
            }
            return tmp;
        }
        else{
            throw "ERROR: Two matrix ";
        }
    }
    Matrix operator-(Matrix<T> const matrix2){
        if ( rows == matrix2.rows && columns == matrix2.columns ){
            Matrix<T> tmp(rows,columns);
            tmp.AM = new ArraySequence<T>[rows];
            for (int i = 0; i < rows; i++){
                tmp.AM[i] = ArraySequence<T>(columns);
                tmp.AM[i] = AM[i].operator-(matrix2.AM[i]);
                
            }
            return tmp;
        }
        else{
            throw "ERROR: Two matrix ";
        }
    
    }
    Matrix operator*(Matrix<T> const matrix2){
        if (rows == matrix2.columns){
            Matrix<T> tmp(rows,columns);
            tmp.AM = new ArraySequence<T>[rows];
            for (int i = 0; i < rows; i++){
                tmp.AM[i] = ArraySequence<T>(columns); //выделил место под строку класса AS
                for (int j = 0; j < columns; j++){
                    for (int k = 0; k < columns ; k++){
                        tmp.AM[i].Set( tmp.GetMij(i, j) + ( AM[i].Get(k) * matrix2.AM[k].Get(j) ), j);
                    }
                }
            }
            return tmp;
        }
        throw "ERROR";
    }

    // Деструктор - освобождает память, выделенную для матрицы
    ~Matrix(){
    }
};
#endif /* matrix_hpp */
