#include <cstring>
#include <iostream>
#include "Matrix/matrix.hpp"
#include "DynamicArray/DynamicArray.hpp"
#include "LinkedList/LinkedList.hpp"
#include "Sequence/ArraySequence/ArraySequence.hpp"
#include "Sequence/ListSequence/ListSequence.hpp"
#include "Sequence/Sequence.hpp"

using namespace std;

int main(){
    int input = 0;
    
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
    cout<<"listD"<<'\n';
    listD.Print();
    cout<<endl;
    
    cout<<"Pop Front <listD>"<<'\n';
    listD.PopFront();
    listD.Print();
    cout<<endl;
    
    cout<<"Copy array constructor <listIm>"<<'\n';
    LinkedList<int> listIm(arri,5);
    listIm.Print();
    cout<<endl;
    
    //
    cout<<"Copy LinkedList constructor <listLC>"<<'\n';
    LinkedList<int> listLC(listIm);
    listLC.Print();
    cout<<endl;
    //
    
    //
    cout<<"First value <listIm>"<<'\n';
    listIm.GetFirstValue();
    cout<<"Last value <listIm>"<<'\n';
    listIm.GetLastValue();
    
    listIm.GetElmntByIndex(2);
    cout<<endl;

    cout<<"Push Front <listIm>"<<'\n';
    listIm.Append(9);
    listIm.Print();
    cout<<endl;
    
    cout<<"Push Back <listIm>"<<'\n';
    listIm.Prepend(9);
    listIm.Print();
    cout<<endl;
    
    cout<<"Pop Front <listIm>"<<'\n';
    listIm.PopFront();
    listIm.Print();
    cout<<endl;
    
    cout<<"Pop Back <listIm>"<<'\n';
    listIm.PopBack();
    listIm.Print();
    cout<<endl;

    cout<<"Add element to LinkedList <listIm>"<<'\n';
    listIm.InsertAt(123, 3);
    listIm.Print();
    cout<<endl;
    
    cout<<"Concat 2 lists <listLC> <listIm>"<<'\n';
    LinkedList<int> list2 = listLC.Concat(&listIm);
    list2.Print();
    cout<<endl;
    
    switch (input){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        default:
            break;
    }
    
    return 0;
}
