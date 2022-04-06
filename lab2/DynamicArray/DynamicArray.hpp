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
    DynamicArray(int k){
        if (k < 0){
            cout<<"Error: array size < 0";
        }
        size = k;
        data = (D*) new D[k];
        memset(data, 0, k * sizeof(D) );
    }
    
    //Массив из k элементов массива arrIn
    DynamicArray(D* arrIn, int k){
        if (k < 0){
            cout<<"Error: array size < 0";
        }
        size = k;
        data = (D*) new D[k];
        copy(arrIn, arrIn+k, data);
    }
    
    //Копирующий массив конструктор
    DynamicArray(DynamicArray<D> const &arrIn ){
        if (arrIn.size < 0){
            cout<<"Error: array size < 0";
        }
        size = arrIn.size;
        data = (D*) new D[arrIn.size];
        memset( data, 0, arrIn.size * sizeof(D) );
        copy(arrIn.data, arrIn.data + arrIn.size, data);
    }
    
    //Копирующий массив констрктор на заданном интервале
    DynamicArray(DynamicArray<D> arrIn,int Start, int End){
        if (arrIn.size < End){
            throw "Error: array size < choosed interval";
        }
        size = End - Start; //Задаем размер итогового массива
        data = (D*) new D[size];
        
        copy(arrIn.data + Start, arrIn.data + End, data);//Копируем интервал массива arrIn в новый массив
    }
    
    void Print(){
        if (size < 0){
            throw "Error: array ≤ 0";
        }
        for (int i = 0; i < size; i++){
            cout<<data[i]<<'\t';
        }
        cout<<endl;
    }
    
    //Получение элемента массива по индексу
    D Get(int index){
        if ( index > size ){
            throw "IndexOutOfRange";
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
    
    //Реалиация realloc() (изменения размера массива с сохранием элементов в нем)
    void ReSize(int nSize){
        DynamicArray<D> dataT( *this );
        
        delete [] data;
        
        size = nSize;
        data = (D*) new D[nSize];
        memset(data, 0, nSize * sizeof(D) );
        
        copy(dataT.data,dataT.data+nSize, data);
    }
};
#endif /* DynamicArray_hpp */
