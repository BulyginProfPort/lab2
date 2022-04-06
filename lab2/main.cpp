#include <iostream>
#include "matrix.hpp"
#include "DynamicArray.hpp"
using namespace std;

int main(){
    int n = 3, m = 3;
    int arr1[5] = {1,2,3,4,5};
    
    matrix<int> matrix1;
    matrix1.Print();
    
    DynamicArray<int> arr(arr1, 5);
    arr.Print();
    DynamicArray<int> arra(arr1,5);
    arra.Print();
    arra.ReSize(10);
    arra.Print();
    
    
    
    return 0;
}
