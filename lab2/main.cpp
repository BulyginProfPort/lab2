#include <cstring>
#include <iostream>
#include "Matrix/matrix.hpp"
#include "DynamicArray/DynamicArray.hpp"
#include "LinkedList/LinkedList.hpp"
using namespace std;

int main(){
    int n = 3, m = 3;
    
    //DynamicArray Int
    int arri[9] = {0,1,2,3,4,5,6,7,8};
    cout<<"DynamicArray Int"<<'\n';
    DynamicArray<int> arrIm(arri, 9);
    arrIm.Print();
    
    DynamicArray<int> arraI(arrIm);
    arraI.Print();
    
    DynamicArray<int> arrI(arrIm,4,9);
    arrI.Print();
    arrI.ReSize(20);
    arrI.Print();
    
    DynamicArray<int> arrNI(arri,5);
    arrNI.Print();
    
    arrNI.ReSize(10);
    arrNI.Print();
    cout<<'\n';
    
    //DynamicArray Float
    cout<<"DynamicArray Float"<<'\n';
    float arrf[9] = {0.5,1.5,2.5,3.5,4.5,5.5,6.5,7.5,8.5};
    
    DynamicArray<float> arrFm(arrf, 9);
    arrFm.Print();
    
    DynamicArray<float> arraF(arrFm);
    arraF.Print();
    
    DynamicArray<float> arrF(arrFm,4,9);
    arrF.Print();
    arrF.ReSize(20);
    arrF.Print();
    
    DynamicArray<float> arrNF(arrf,5);
    arrNF.Print();
    
    arrNF.ReSize(10);
    arrNF.Print();
    cout<<'\n';

    //LinkedList
    LinkedList<int> listD;
    listD.Print();
    listD.PopFront();
    listD.Print();
    
    
    LinkedList<int> listIm(arri,5);
    listIm.Print();
    listIm.GetElmntByIndex(0);
    
    listIm.InsertAt(123, 3);
    listIm.Print();
    
    listIm.Append(9);
    listIm.Print();
    
    listIm.Prepend(9);
    listIm.Print();

    return 0;
}
