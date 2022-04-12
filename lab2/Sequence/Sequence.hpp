//
//  Sequence.hpp
//  lab2
//
//  Created by Фёдор Булыгин on 03.04.2022.
//
#pragma once
#ifndef Sequence_hpp
#define Sequence_hpp
#include <stdio.h>
#include "ArraySequence/ArraySequence.hpp"
#include "ListSequence/ListSequence.hpp"
template <class S>
class Sequence{
private:
    ArraySequence<S> arrM();
    ListSequence<S> listM();
public:
    
};
#endif /* Sequence_hpp */
