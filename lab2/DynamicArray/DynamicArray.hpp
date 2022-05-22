#pragma once
#ifndef DynamicArray_hpp
#define DynamicArray_hpp
#include <iostream>
#include <cstring>
#include <time.h>


using namespace std;

template<class T>
class DynamicArray{
private:
    T* arr = nullptr;
    int size = 0;
public:
    //Default constructor
    DynamicArray(){
        size = 1;
        arr = (T*) new T[size];
        memset(arr, 0, sizeof(T) );
    }
    
    //K array elements constructor
    DynamicArray(int k){
        if (k < 0){
            throw "Array size < 0";
        }
        size = k;
        arr = (T*) new T[k];
        memset( arr, 0, size * sizeof(T) );
    }
    
    //K array's elements constructor
    DynamicArray(T* const arrIn, int k){
        if (k < 0){
            throw "Array size < 0";
        }
        size = k;
        arr = (T*) new T[k];
        memset( arr, 0, size * sizeof(T) );
        copy(arrIn, arrIn+k, arr);
    }
    
    //Copy constructor
    DynamicArray(DynamicArray<T> const &arrIn ){
        size = arrIn.size;
        arr = (T*) new T[arrIn.size];
        memset( arr, 0, size * sizeof(T) );
        copy(arrIn.arr, arrIn.arr + min(size,arrIn.size), arr);
    }
    
    //Copy constructor by interval
    DynamicArray(T* const arrIn,int start, int end){
        start -= 1;
        size = end - start; //Set result array size
        arr = (T*) new T[size];
        copy(arrIn + start, arrIn + end, arr);//Copy array's interval in new array
    }
    
    //Copy constructor by interval
    DynamicArray(DynamicArray<T> const &arrIn,int firstElement, int lastElement){
        firstElement -= 1;
        size = lastElement - firstElement; //Set result array size
        arr = (T*) new T[size];
        copy(arrIn.arr + firstElement, arrIn.arr + lastElement, arr);//Copy array's interval in new array
    }
    
    //Get array element
    T Get(int index) const{
        if ( index > size ){
            throw "Index out of range";
        }
        //Print
        cout<<arr[index]<<endl;
        return arr[index];
    }

    //Set array element by index
    void Set(T value, int index){
        if ( index < 0 || index + 1 > size ){
            throw "Index out of range";
        }
        //Print
        //cout<<arr[index]<<endl;
        arr[index] = value;
        //cout<<arr[index]<<endl;
    }
    
    int GetSize() const{
        return size;
    }
    
    //Realization realloc() (change size array with saving elements)
    void ReSize(int nSize){
        if (nSize < 0){
            throw "New size of array < 0";
        }
        T* tmp = arr;
        arr = (T*) new T[nSize];
        memset(arr,0,nSize * sizeof(T) );
        copy(tmp,tmp + min(size, nSize), arr);
        size = nSize;
        delete[] tmp;
    }
    //Print Array
    void Print() const{
        if (size < 0){
            throw "Array size < 0";
        }
        for (int i = 0; i < size; i++){
            cout<<arr[i]<<'\t';
        }
        cout<<endl;
    }
    
    DynamicArray<T> operator+ (DynamicArray<T> const arrIn){
        int ArrSize = max(size, arrIn.size);
        T* tmpArr = new T[ArrSize];

        if (size > arrIn.size){
            copy(arr, arr + ArrSize, tmpArr);
        }
        else{
            copy(arrIn.arr, arrIn.arr + ArrSize, tmpArr);
        }
        memset(tmpArr,0,min(size,arrIn.size) * sizeof(T));
        for (int i = 0; i < min(size,arrIn.size); i++){
            tmpArr[i] = arr[i] + arrIn.arr[i];
        }
        DynamicArray<T> tmp(tmpArr, ArrSize);
        return tmp;
    }
    
    DynamicArray<T> operator- (DynamicArray<T> const arrIn){
        int ArrSize = max(size, arrIn.size);
        T* tmpArr = new T[ArrSize];

        if (size > arrIn.size){
            copy(arr, arr + ArrSize, tmpArr);
        }
        else{
            copy(arrIn.arr, arrIn.arr + ArrSize, tmpArr);
        }
        memset(tmpArr,0,ArrSize * sizeof(T));
        for (int i = 0; i < min(size,arrIn.size); i++){
            tmpArr[i] = arr[i] - arrIn.arr[i];
        }
        DynamicArray<T> tmp(tmpArr, ArrSize);
        return tmp;
    }

    DynamicArray<T> operator* (DynamicArray<T> const arrIn){
        int ArrSize = max(size, arrIn.size);
        T* tmpArr = new T[ArrSize];

        if (size > arrIn.size){
            copy(arr, arr + ArrSize, tmpArr);
        }
        else{
            copy(arrIn.arr, arrIn.arr + ArrSize, tmpArr);
        }
        memset(tmpArr,0,ArrSize * sizeof(T));
        for (int i = 0; i < min(size,arrIn.size); i++){
            tmpArr[i] = arr[i] * arrIn.arr[i];
        }
        
        DynamicArray<T> tmp(tmpArr, ArrSize);
        return tmp;
    }
    
    DynamicArray<T> operator/ (DynamicArray<T> const arrIn){
        int ArrSize = max(size, arrIn.size);
        T* tmpArr = new T[ArrSize];
        if (size > arrIn.size){
            copy(arr, arr + ArrSize, tmpArr);
        }
        else{
            copy(arrIn.arr, arrIn.arr + ArrSize, tmpArr);
        }
        memset(tmpArr,0,ArrSize * sizeof(T));
        for (int i = 0; i < min(size,arrIn.size); i++){
            try{
                cout<<arr[i]<<' '<<arrIn.arr[i]<<endl;
                if (arrIn.arr[i] == 0){
                    throw "ERROR: Div by zero";
                }
                tmpArr[i] = arr[i] / arrIn.arr[i];
            }
            catch(const char* exception){
                cout<<exception<<endl;
            }
        }
        DynamicArray<T> tmp(tmpArr, ArrSize);
        return tmp;
    }
    
    //Distructor
    ~DynamicArray(){
        if (arr){
            delete[] arr;
        }
    }
    
};

#endif /* DynamicArray_hpp */
