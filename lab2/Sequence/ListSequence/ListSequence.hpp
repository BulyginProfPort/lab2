//
//  ListSequence.hpp
//  lab2
//
//  Created by Фёдор Булыгин on 12.04.2022.
//
#pragma once
#ifndef ListSequence_hpp
#define ListSequence_hpp

#include <stdio.h>
#include "/Users/fedorbulygin/Desktop/Labs2/lab2/lab2/LinkedList/LinkedList.hpp"
template <typename L>
class ListSequence{
private:
    LinkedList<L>* listM;
public:
    int GetLength(){
        //Print
        cout<<listM->GetLength()<<endl;
        return listM->GetLength();
    }
    void PushFront(L value){
        listM->Prepend(value);
    }
    void PushBack(L value){
        listM->Append(value);
    }
};

#endif /* ListSequence_hpp */
