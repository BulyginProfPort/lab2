//
//  Sequence.hpp
//  lab2
//
//  Created by Фёдор Булыгин on 03.04.2022.
//
#pragma once
#ifndef Sequence_hpp
#define Sequence_hpp

#include <iostream>
using namespace std;

template <class T>
class Sequence{
private:
    
public:
    virtual const T GetFirst() = 0;
    virtual const T GetLast() = 0;
    virtual const T Get(int index) = 0;
    virtual const int GetLength() = 0;
    virtual  void Append(T value) = 0;
    virtual  void Prepend(T value) = 0;
    virtual  void InsertAt(T value, int index) = 0;
    virtual const void Print() = 0;

};
#endif /* Sequence_hpp */
