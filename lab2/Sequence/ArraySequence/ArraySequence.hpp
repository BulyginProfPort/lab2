//
//  ArraySequence.hpp
//  lab2
//
//  Created by Фёдор Булыгин on 12.04.2022.
//
#pragma once
#ifndef ArraySequence_hpp
#define ArraySequence_hpp

#include <stdio.h>
#include "/Users/fedorbulygin/Desktop/Labs2/lab2/lab2/DynamicArray/DynamicArray.hpp"
template <typename A>
class ArraySequence{
private:
    DynamicArray<A>* arrM;
public:
    int GetLength(){
        //Print
        
        cout<<"Size: "<<this->arrM->getSize<<endl;
        return arrM->getSize;
    }
    void Append(A value){
        arrM->ReSize(this->arrM->getSize() + 1);
        arrM->Set(value, this->arrM->getSize() - 1);
    }
    
};
#endif /* ArraySequence_hpp */
