#pragma once
#ifndef LinkedList_hpp
#define LinkedList_hpp
#include <iostream>
using namespace std;

template <class L>
class LinkedList{
private:
    // Private descriptions of list's structures
    struct Node {
        L value;
        struct Node *next = nullptr;
        struct Node *prev = nullptr;
    };
    
    struct List{
        struct Node *head = nullptr;
        struct Node *tail = nullptr;
    };
    
    // Private fields class LinkedList
    List *list = nullptr;
    int size = 0;
    
public:
    //Default constructor 
    LinkedList(){
        
        //Inizialization list
        list = (struct List*) new struct List;
        list->head = (struct Node*) new struct Node;
        
        //Construct list
        size = 1;
        list->head->value = 0;
        list->tail = list->head;
    }

    //LinkedList constructor by copy an array
    LinkedList(L* arr,int k){
        list = (struct List*) new struct List;
        size = k;
        list->head = (struct Node*) new struct Node;
        struct Node *tmpH = list->head;
        for (int i = 0; i < size; i++){
            struct Node *tmp = list->head;
            list->head->value = arr[i];
            if (i < k - 1){
                list->head->next = (struct Node*) new struct Node;
                list->head = list->head->next;
                list->head->prev = tmp;
            }
        }
        list->tail = list->head;
        list->head = tmpH;
    }
    
    ///В Sequence использовать конструктор LinkedList котороый принимает на вход DynamicArray
    
    //LinkedList copy constructor
    LinkedList(LinkedList<L> const &listIn){
    }

    //Add one element to the front of LinkedList
    void Append(L value){
        struct Node *tmp = (struct Node*) new struct Node;
        tmp->value = value;
        tmp->next = list->head;
        tmp->prev = nullptr;

        if (size == 0){
            list->head = list->tail = tmp;
        }
        else{
            list->head = tmp;
        }
        if (list->tail == nullptr){
            list->tail = tmp;
        }
        size++;
    }
    
    //Get SubList of LinkedList
    LinkedList <L>* GetSubList(int startIndex,int endlIndex){
        int rSize = endlIndex - startIndex + 1;
        L* arr = new L[rSize];
        struct Node *tmp = list->head;
        int j = 0;
        for (int i = 0; i < size; i++){
            list->head = list->head->next;
            if (i == startIndex){
                arr[j] = list->head->value;
                j++;
            }
        }
        LinkedList<L> listRes(arr,rSize);
        
        //Print
        cout<<"listRes"<<'\n';
        listRes.Print();
        return listRes;
    }
    
    struct Node* Move(int index){
        index--;
        struct Node *tmp = list->head;
        for (int i = 0; i < index; i++){
            tmp = tmp->next;
        }
        return tmp;
    }
    
    //Get the first element of LinkedList
    L GetFirstValue(){
        if (size == 0){
            throw "IndexOutOfRange";
        }
        //Print
        cout<<list->tail->value<<'\n';
        return list->head->value;
    }
    
    //Get the last element of LinkedList
    L GetLastValue(){
        if (size == 0){
            throw "IndexOutOfRange";
        }
        //Print
        cout<<list->tail->value<<'\n';
        return list->tail->value;
    }
    
    //Get element of LinkedList by index
    L GetElmntByIndex(int index){
        index--;
        L value;
        struct Node *tmp = list->head;
        for (int i = 0; i < index; i++){
            list->head = list->head->next;
        }
        value = list->head->next->value;
        list->head = tmp;
        
        //Print
        cout<<"Value ["<<index + 1<<"]: "<<value<<'\n';
        return value;
    }
    
    //Get length of LinkedList
    int GetLength(){
        return size;
    }
    
    //Add one element to the end of LinkedList
    void Prepend(L value){
        struct Node *tmp = (struct Node*) new struct Node;
        tmp->prev = list->tail;
        tmp->value = value;

        tmp->next = nullptr;
        if (list->tail != nullptr){
            list->tail->next = tmp;
        }
        if (size == 0){
            list->head = list->tail = tmp;
        }
        else{
            list->tail = tmp;
        }
        size++;
    }
    
    //Delete first LinkedLists's element
    void PopFront(){
        struct Node *tmp = list->head->next;
        delete list->head;
        list->head = tmp;
        if (size == 1){
            size--;
        }
    }
    
    //Delete last LinkedList's element
    void PopBack(){
        struct Node *tmp = list->tail->prev;
        delete list->tail;
        list->tail = tmp;
        if (size == 1){
            delete list;
            size--;
        }
    }
    
    void InsertAt(L item,int index){
        if (index == size){
            this->Prepend(item);
        }
        if (index == 0){
            this->Append(item);
        }
        else{
            struct Node* tmpPrev = Move(index - 1);
            struct Node* tmp = Move(index);
            struct Node* t = (struct Node*) new struct Node;
            t->value = item;
            t->next = tmp;
            t->prev = tmpPrev;
            tmpPrev->next = t;
            size++;
        }
    }
    
    //Merg 2 LinkedList
    LinkedList <L>* Concat(LinkedList<L> *list){
        
    }
    
    void Print(){
        Node *tmp = list->head;
        while (tmp){
            cout<<tmp->value<<' ';
            tmp = tmp->next;
        }
        cout<<endl;
    }

    //LinkedList Distructor
    ~LinkedList(){
        if (size == 0){
            delete list;
            return;
        }
        struct Node *tmp = list->head->next;
        for (int i = 0; i < size; i++){
            delete list->head;
            list->head = tmp;
            if (tmp){
                if (tmp->next){
                    tmp->prev = nullptr;
                    tmp = tmp->next;
                }
                else{
                    tmp->prev = nullptr;
                    tmp = nullptr;
                }
            }
        }
        delete list;
        delete tmp;
    }
};
#endif /* LinkedList_hpp */
