//
//  LinkedListSequence.hpp
//  lab2
//
//  Created by Фёдор Булыгин on 12.04.2022.
//
#pragma once
#ifndef ListSequence_hpp
#define ListSequence_hpp
#include <stdio.h>
#include "../../Sequence/Sequence.hpp"
#include "../../LinkedList/LinkedList.hpp"
#include "../../DynamicArray/DynamicArray.hpp"

using namespace std;

template<class T>
class LinkedListSequence: public Sequence<T>{
private:
    LinkedList<T> *listM = nullptr;
public:
    LinkedListSequence(){
        listM = new LinkedList<T>();
    }
    
    LinkedListSequence(int k){
        listM = new LinkedList<T>(k);
    }
    
    LinkedListSequence(T* arr, int k){
        listM = new LinkedList<T>(arr,k);
    }
    
    LinkedListSequence(const LinkedList<T> &list){
        listM = new LinkedList<T> (list);
    }
    
    LinkedListSequence(const DynamicArray<T> &arr){
        listM = new LinkedList<T>();
        for (int i = 0; i < arr.GetSize(); i++){
            listM->InsertAt(arr.Get(i), i);
        }
    }
    LinkedListSequence(const LinkedListSequence<T> &listIn, int firstElement, int lastElement){
        firstElement--;
        lastElement--;
        listM = new LinkedList<T> ();
        *listM = listIn.listM->GetSubList(firstElement, lastElement);
    }
    T const GetFirst() override{
        if ( listM->GetLength() == 0){
            throw "Index out of range";
        }
        return listM->GetFirstValue();
    }
    
    T const GetLast() override{
        if ( listM->GetLength() == 0){
            throw "Index out of range";
        }
        return listM->GetLastValue();
    }
    
    T const Get(int index) override{
        if ( index < 0 || index + 1 > listM->GetLength() ){
            throw "Index out of range";
        }
        return listM->Get(index);
    }
    
    int const GetLength()  override{
        //Print
        //cout<<listM->GetLength()<<endl;
        return listM->GetLength();
    }
    
    void Append(T value) override{
        listM->Append(value);
    }
    
    void Prepend(T value) override{
        listM->Prepend(value);
    }
    
    void InsertAt(T value, int index) override{
        if (index < 0 || index + 1 > listM->GetLength() ){
            throw "Index out of range";
        }
        listM->InsertAt(value, index);
    }
    
    void const Print() override{
        listM->Print();
    }
    ~LinkedListSequence(){
    }
};

#endif /* LinkedListSequence_hpp */
