#pragma once
#ifndef DynamicArray_hpp
#define DynamicArray_hpp
#include <iostream>
using namespace std;

template<class D>
class DynamicArray{
private:
    D* arr = nullptr;
    int size = 0;
public:
    //Default constructor
    DynamicArray(){
        size = 1;
        arr = (D*) new D[1];
        memset(arr, 0, sizeof(D) );
    }
    
    //K array's elements constructor
    DynamicArray(int k){
        if (k < 0){
            throw "Array size < 0";
        }
        size = k;
        arr = (D*) new D[k];
        memset(arr, 0, k * sizeof(D) );
    }
    
    //K array's elements constructor
    DynamicArray(D* arrIn, int k){
        if (k < 0){
            throw "Array size < 0";
        }
        size = k;
        arr = (D*) new D[k];
        copy(arrIn, arrIn+k, arr);
    }
    
    //Copy constructor
    DynamicArray(DynamicArray<D> const &arrIn ){
        size = arrIn.size;
        arr = (D*) new D[arrIn.size];
        memset( arr, 0, size * sizeof(D) );
        copy(arrIn.arr, arrIn.arr + min(size,arrIn.size), arr);
    }
    
    //Copy constructor by interval
    DynamicArray(D* arrIn,int start, int end){
        start -= 1;
        size = end - start; //Set result array size
        arr = (D*) new D[size];
        copy(arrIn + start, arrIn + end, arr);//Copy array's interval in new array
    }
    
    //Copy constructor by interval
    DynamicArray(const DynamicArray<D> &arrIn,int start, int end){
        start -= 1;
        if (arrIn.size < end){
            throw "Array size < choosed interval";
        }
        size = end - start; //Set result array size
        arr = (D*) new D[size];
        copy(arrIn.arr + start, arrIn.arr + end, arr);//Copy array's interval in new array
    }
    //Print Array
    void Print(){
        if (size < 0){
            throw "Array size < 0";
        }
        for (int i = 0; i < size; i++){
            cout<<arr[i]<<'\t';
        }
        cout<<endl;
    }
    
    //Get array element
    D Get(int index){
        if ( index > size ){
            throw "Index out of range";
        }
        //Print
        cout<<arr[index]<<endl;
        return arr[index];
    }

    //Set array element by index
    void Set(D value, int index){
        if (index < 0){
            throw "Index < 0";
        }
        //Print
        cout<<arr[index]<<endl;
        arr[index] = value;
        cout<<arr[index]<<endl;
        
    }
    
    int getSize(){
        return size;
    }
    
    //Realization realloc() (change size array with saving elements)
    void ReSize(int nSize){
        if (nSize < 0){
            throw "New size of array < 0";
        }
        D* tmp = arr;
        arr = (D*) new D[nSize];
        memset(arr,0,nSize * sizeof(D) );
        copy(tmp,tmp + min(size, nSize), arr);
        size = nSize;
        delete[] tmp;
    }
    
    //Distructor
    ~DynamicArray(){
        delete[] arr;
    }
    
};
#endif /* DynamicArray_hpp */
