//
//  DynamicArraySequence.hpp
//  lab2
//
//  Created by Фёдор Булыгин on 12.04.2022.
//
#pragma once
#ifndef ArraySequence_hpp
#define ArraySequence_hpp
#include <stdio.h>
#include "../../Sequence/Sequence.hpp"
#include "../../DynamicArray/DynamicArray.hpp"
#include "../../LinkedList/LinkedList.hpp"

using namespace std;

template <class T>
class ArraySequence: public Sequence<T>{
private:
    DynamicArray<T> *arrM = nullptr;
public:
    //Default ArraySequence constructor
    ArraySequence(){
        arrM = new DynamicArray<T>();
    }
    
    ArraySequence(int k){
        arrM = new DynamicArray<T>(k);
    }
    
    //K array elements DynamicArraySequence constructor
    ArraySequence(T* const arr, int k){
        arrM = new DynamicArray<T> (arr,k);
    }
    
    ArraySequence(T* const arr, int firstElement, int lastElemnt){
        arrM = new DynamicArray<T> (arr, firstElement, lastElemnt);
    }
    
    ArraySequence(ArraySequence<T> const &arrIn){
        arrM = arrIn.arrM;
    }
    
    //Copy constructor
    ArraySequence(DynamicArray<T> const &arr, int k){
        arrM = new DynamicArray<T> (arr);
    }
    
    ArraySequence( DynamicArray<T> const &arrIn, int firstElement, int lastElement){
        arrM = new DynamicArray<T>(arrIn, firstElement, lastElement);
    }
    
    ArraySequence( ArraySequence<T> const &arrIn, int firstElement, int lastElement){
        arrM = new DynamicArray<T>(*arrIn.arrM, firstElement, lastElement);
    }
    
    ArraySequence( LinkedList<T> const &list ){
        arrM = new DynamicArray<T>(list.GetLength());
        for (int i = 0; i < arrM->GetSize(); i++){
            arrM->Set(list.Get(i), i);
        }
    }
    
    T const GetFirst() override{
        if(arrM->GetSize() == 0){
            throw "Index out of range";
        }
        return arrM->Get(0);
    }

    T const GetLast() override{
        if(arrM->GetSize() == 0){
            throw "Index out of range";
        }
        return arrM->Get(arrM->GetSize() - 1);
    }
    
    int const GetLength() override{
        //Print
        //cout<<"Size: "<<this->arrM->getSize<<endl;
        return arrM->GetSize();
    }
    
    void Append(T value) override{
        arrM->ReSize( arrM->GetSize() + 1);
        arrM->Set(value, arrM->GetSize() - 1);
    }
    
    void Prepend(T value) override{
        int newSize = arrM->GetSize() + 1;
        arrM->ReSize(newSize);
        for (int i = newSize - 1; i > 0; i--){
            arrM->Set(arrM->Get(i - 1), i);
        }
        arrM->Set(value, 0);
    }

    T const Get(int index) override{
        if(index + 1 > arrM->GetSize() || index < 0){
            throw "Index out of range";
        }
        return arrM->Get(index);
    }
    
    void Set(T value, int index){
        arrM->Set(value, index);
    }
    
    void InsertAt(T value, int index) override{
        if ( index + 1 > arrM->GetSize() || index < 0){
            throw "Index out of range";
        }
        arrM->ReSize(arrM->GetSize() + 1);
        T *tmp = new T[ (arrM->GetSize() - 1) - index];
        int j = 0;
        for (int i = index; i < arrM->GetSize() - 1; i++){
            tmp[j++] = arrM->Get(i);
        }
        arrM->Set(value, index);
        j = 0;
        for (int i = index + 1; i < arrM->GetSize(); i++){
            arrM->Set(tmp[j++], i);
        }
    }
    
    void const Print() override{
        arrM->Print();
    }
    
    ArraySequence operator+ (ArraySequence<T> const arrIn){
        ArraySequence<T> tmp(arrM->operator+(*arrIn.arrM), max(arrM->GetSize(), arrIn.arrM->GetSize()) );
        return tmp;
    }
    
    ArraySequence operator- (ArraySequence<T> const arrIn){
        ArraySequence<T> tmp(arrM->operator-(*arrIn.arrM), max(arrM->GetSize(), arrIn.arrM->GetSize()) );
        return tmp;
    }
    
    ArraySequence operator* (ArraySequence<T> const arrIn){
        ArraySequence tmp(arrM->operator*(*arrIn.arrM), max(arrM->GetSize(), arrIn.arrM->GetSize()) );
        return tmp;
    }
    
    ArraySequence operator/ (ArraySequence<T> const arrIn){
        ArraySequence tmp(arrM->operator/(*arrIn.arrM), max(arrM->GetSize(), arrIn.arrM->GetSize()) );
        return tmp;
    }
    
};
#endif /* DynamicArraySequence_hpp */
