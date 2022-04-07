#pragma once
#ifndef DynamicArray_hpp
#define DynamicArray_hpp
#include <iostream>
using namespace std;

template<class D>
class DynamicArray{
private:
    D* data = nullptr;
    int size = 0;
public:
    //Массив из k элементов
    DynamicArray(){
        size = 1;
        data = (D*) new D[1];
        memset(data, 0, sizeof(D) );
    }
    DynamicArray(int k){
        if (k < 0){
            throw "Array size < 0";
        }
        size = k;
        data = (D*) new D[k];
        memset(data, 0, k * sizeof(D) );
    }
    
    //Массив из k элементов массива arrIn
    DynamicArray(D* arrIn, int k){
        if (k < 0){
            throw "Array size < 0";
        }
        size = k;
        data = (D*) new D[k];
        copy(arrIn, arrIn+k, data);
    }
    
    //Копирующий конструктор
    DynamicArray(DynamicArray<D> const &arrIn ){
        size = arrIn.size;
        data = (D*) new D[arrIn.size];
        memset( data, 0, size * sizeof(D) );
        copy(arrIn.data, arrIn.data + min(size,arrIn.size), data);
    }
    
    //Копирующий констрктор на заданном интервале
    DynamicArray(const DynamicArray<D> &arrIn,int start, int end){
        start -= 1;
        if (arrIn.size < end){
            throw "Array size < choosed interval";
        }
        size = end - start; //Задаем размер итогового массива
        data = (D*) new D[size];
        copy(arrIn.data + start, arrIn.data + end, data);//Копируем интервал массива arrIn в новый массив
    }
    //Вывод в консоль массива
    void Print(){
        if (size < 0){
            throw "Array size < 0";
        }
        for (int i = 0; i < size; i++){
            cout<<data[i]<<'\t';
        }
        cout<<endl;
    }
    
    //Получение элемента массива по индексу
    D Get(int index){
        if ( index > size ){
            throw "Index out of range";
        }
        return data[index];
    }

    //Определение элемента массива по индекс
    void Set(D value, int index){
            if (index < 0){
                throw "Index < 0";
            }
            return data[index] = value;
    }
    
    int getSize(){
        return size;
    }
    
    //Реалиация realloc() (изменения размера массива с сохранием элементов в нем)
    void ReSize(int nSize){
        if (nSize < 0){
            throw "New size of array < 0";
        }
        D* tmp = data;
        data = (D*) new D[nSize];
        memset(data,0,nSize * sizeof(D) );
        copy(tmp,tmp + min(size, nSize), data);
        size = nSize;
        delete[] tmp;
    }

    ~DynamicArray(){
        delete[] data;
    }
    
};
#endif /* DynamicArray_hpp */
