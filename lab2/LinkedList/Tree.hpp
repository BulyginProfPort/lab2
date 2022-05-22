#pragma once
#ifndef LinkedList_hpp
#define LinkedList_hpp
#include <iostream>
using namespace std;

template <class T>
class Tree{
private:
    // Private descriptions of list's structures
    struct Node {
        T value;
        struct Node *right = nullptr;
        struct Node *left = nullptr;
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
    Tree(){
        
        //Inizialization list
        list = (struct List*) new struct List;
        list->head = (struct Node*) new struct Node;
        
        //Construct list
        size = 1;
        list->head->value = 0;
        list->tail = list->head;
    }
    
    Tree(int k){
        list = (struct List*) new struct List;
        list->head = (struct Node*) new struct Node;
        
        size = k;
        
        struct Node *tmpH = list->head;
        
        for (int i = 0; i < size; i++){
            struct Node *tmp = list->head;
            list->head->value = 0;
            if (i < k - 1){
                list->head->right = (struct Node*) new struct Node;
                list->head = list->head->right;
                list->head->prev = tmp;
            }
        }
        list->tail = list->head;
        list->head = tmpH;
    }
    
    //Tree constructor by copy an array
    Tree(T* arr,int k){
        list = (struct List*) new struct List;
        list->head = (struct Node*) new struct Node;

        size = k;
        struct Node *tmpH = list->head;
        
        for (int i = 0; i < size; i++){
            struct Node *tmp = list->head;
            list->head->value = arr[i];
            if (i < k - 1){
                list->head->right = (struct Node*) new struct Node;
                list->head = list->head->right;
                list->head->prev = tmp;
            }
        }
        list->tail = list->head;
        list->head = tmpH;
    }
    
    ///В Sequence использовать конструктор LinkedList котороый принимает на вход DynamicArray
    
    //LinkedList copy constructor
    Tree<T>(Tree<T> const &listIn){
        list = (struct List*) new struct List;
        list->head = (struct Node*) new struct Node;
    
        size = listIn.size;
        struct Node *tmpH = list->head;        
        struct Node *tmpIn = listIn.list->head;

        for (int i = 0; i < size; i++){
            struct Node *tmpM = list->head;
            list->head->value = tmpIn->value;
            if (i < size - 1){
                list->head->right = (struct Node*) new struct Node;
                list->head = list->head->right;
                tmpIn = tmpIn->next;
                list->head->prev = tmpM;
            }
        }
        list->tail = list->head;
        list->head = tmpH;
    }
    
    //Get SubList of LinkedList
    Tree <T> GetSubList(int startIndex,int endIndex){
        int rSize = endIndex - startIndex + 1;
        T* arr = new T[rSize];
        int j = 0;
        struct Node* tmp = list->head;
        for (int i = 0; i < size; i++){
            if (i >= startIndex && i <= endIndex){
                arr[j] = list->head->value;
                j++;
            }
            else if(i >= endIndex){
                break;
            }
            list->head = list->head->right;
        }
        list->head = tmp;
        Tree<T> listRes(arr,rSize);
        //Print
        //listRes.Print();
        return listRes;
    }
    struct Node* Move(int index) const{
        struct Node *tmp = list->head;
        for (int i = 0; i < index; i++){
            tmp = tmp->right;
        }
        return tmp;
    }
    
    //Get the first element of LinkedList
    T GetFirstValue() const{
        if (size == 0){
            throw "IndexOutOfRange";
        }
        //Print
        //cout<<list->head->value<<'\n';
        return list->head->value;
    }
    
    //Get the last element of LinkedList
    T GetLastValue() const{
        if (size == 0){
            throw "IndexOutOfRange";
        }
        //Print
        //cout<<list->tail->value<<'\n';
        return list->tail->value;
    }
    
    //Get element of LinkedList by index
    T Get(int index) const{
        struct Node* tmp = Move(index);
        //Print
        //cout<<"Value ["<<index + 1<<"]: "<<value<<'\n';
        return tmp->value;
    }
    
    //Get length of LinkedList
    int GetLength() const{
        //Print
        //cout<<"Size:"<<size<<'\n';
        return size;
    }
    
    //Add one element to the front of LinkedList
    void Append(T value){
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
    
    //Add one element to the end of LinkedList
    void Prepend(T value){
        struct Node *tmp = (struct Node*) new struct Node;
        tmp->value = value;
        tmp->right = list->head;
        tmp->left = nullptr;

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
    
    //Delete first LinkedLists's element
    void PopFront(){
        struct Node *tmp = list->head;
        list->head = list->head->right;
        if (list->head){
            list->head->prev = nullptr;
        }
        if (tmp == list->head){
            list->head = nullptr;
        }
        delete tmp;
        size--;
    }
    
    //Delete last LinkedList's element
    void PopBack(){
        struct Node *tmp = list->tail;
        list->tail = list->tail->left;
        if (list->tail){
            list->tail->right = nullptr;
        }
        if (tmp == list->head){
            list->head = nullptr;
        }
        delete tmp;
        size--;
    }
    
    void InsertAt(T item,int index){
        if (index == size){
            this->Prepend(item);
        }
        if (index == 0){
            this->Append(item);
        }
        else{
            struct Node* tmpLeft = Move(index - 1);
            struct Node* tmp = Move(index);
            struct Node* t = (struct Node*) new struct Node;
            t->value = item;
            t->right = tmp;
            t->left = tmpLeft;
            tmpLeft->next = t;
            size++;
        }
    }
    
    //Merg 2 LinkedList
    Tree <T> Concat(Tree<T> *listIn){
        int newSize = size + listIn->size;
        T* arr = new T[newSize];
        int m = 0;
        for (int i = 0; i < size; i++){
            struct Node *tmp = Move(i);
            arr[i] = tmp->value;
            m = i;
        }
        for (int i = 0; i < listIn->size; i++){
            struct Node *tmp = listIn->Move(i);
            arr[(m+1)+i] = tmp->value;
        }
        Tree<T> arrOut(arr, newSize);
        delete[] arr;
        return arrOut;
    }
    Tree<T>& operator=(const Tree& listIn){
        list = (struct List*) new struct List;
        list->head = (struct Node*) new struct Node;
    
        size = listIn.size;
        struct Node *tmpH = list->head;
        struct Node *tmpIn = listIn.list->head;

        for (int i = 0; i < size; i++){
            struct Node *tmpM = list->head;
            list->head->value = tmpIn->value;
            if (i < size - 1){
                list->head->next = (struct Node*) new struct Node;
                list->head = list->head->right;
                tmpIn = tmpIn->right;
                list->head->left = tmpM;
            }
        }
        list->tail = list->head;
        list->head = tmpH;
        return *this;
    }
    void Print() const{
        Node *tmp = list->head;
        while (tmp){
            cout<<tmp->value<<'\t';
            tmp = tmp->next;
        }
        cout<<endl;
    }
    //LinkedList Distructor
    ~Tree(){
        if (size == 0){
            delete list;
            return;
        }
        struct Node *tmp = list->head->right;
        for (int i = 0; i < size; i++){
            delete list->head;
            list->head = tmp;
            if (tmp){
                if (tmp->next){
                    tmp->left = nullptr;
                    tmp = tmp->right;
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
