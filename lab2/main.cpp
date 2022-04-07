#include <cstring>
#include <iostream>
#include "Matrix/matrix.hpp"
#include "DynamicArray/DynamicArray.hpp"
#include "LinkedList/LinkedList.hpp"
using namespace std;

int main(){
    int n = 3, m = 3;
    int arr1[9] = {0,1,2,3,4,5,6,7,8};
    DynamicArray<int> arr(arr1, 9);
    arr.Print();
    
    DynamicArray<int> arra(arr);
    arra.Print();
    
    DynamicArray<int> arrI(arr,4,9);
    arrI.Print();
    arrI.ReSize(20);
    arrI.Print();
    
    DynamicArray<int> arrN(arr1,5);
    arrN.Print();
    
    arrN.ReSize(10);
    arrN.Print();
    
    return 0;
}
