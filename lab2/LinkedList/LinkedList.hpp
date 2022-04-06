#pragma once
#ifndef LinkedList_hpp
#define LinkedList_hpp
#include <iostream>
using namespace std;

template <class L>
struct List {
    L value;
    int size;
    struct List* next = nullptr;
    struct List* prev = nullptr;
};

template <class L>
class LinkedList{
private:
    List<L>* list;
public:
    LinkedList(){
        list = (struct List<L>*) new struct List<L>;
        list->value = 0;
        list->size = 0;
    }
    LinkedList(L* items,int count){
        list = (struct List<L>*) new struct List<L>;
        list->next = (struct List<L>*) new struct List<L>;
        for (int i = 0; i < count; i++){
             
        }
    }
    LinkedList(LinkedList<L> const &list){
        
    }
    L GetFirst(){
        
    }
    L GetLast(){
        
    }
    L GetIndex(int index){
        
    }
    LinkedList <L>* GetSubList(int startIndex,int endlIndex){
        
    }
    int GetLength(){
        
    }
    void Append(L item){
        
    }
    void Prepend(L item){
        
    }
    void InsertAt(L item,int index){
        
    }
    LinkedList <L>* Concat(LinkedList<L> *list){
        
    }
    void Print(){
        for ( int i = 0; i < list->size; i++){
            cout<<list->value<<'\t';
        }
        cout<<endl;
    }

};
#endif /* LinkedList_hpp */
