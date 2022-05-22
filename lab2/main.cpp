#include <cstring>
#include <iostream>
#include "Matrix/matrix.hpp"
#include "DynamicArray/DynamicArray.hpp"
#include "LinkedList/LinkedList.hpp"
#include "Sequence/ArraySequence/ArraySequence.hpp"
#include "Sequence/LinkedListSequence/LinkedListSequence.hpp"
#include "Sequence/Sequence.hpp"
#include "tests/test.hpp"
using namespace std;

void menu(){
    printf(
           " ______________________________________________ \n"
           " ---------------------------------------------- \n"
           "||                  LAB 2                     ||\n"
           "||MENU:                                       ||\n"
           "||                                            ||\n"
           "\n"
           "||  General:                                  ||\n"
           "||    m = print this menu                     ||\n"
           "||    q = stop this program                   ||\n"
           "\n"
           "||  ArraySequence:                            ||\n"
           "||    s = go to ArraySequence menu            ||\n"
           "\n"
           "||  LinkedListSequence:                       ||\n"
           "||    l = go to LinkedLIstSequence menu       ||\n"
           "\n"
           "||  Matrix:                                   ||\n"
           "||    M = go to Matrix                        ||\n"
           "\n"
           "||  Tests:                                    ||\n"
           "||    t = test menu                           ||\n"
           "||                                            ||\n"
           " ______________________________________________ \n"
           " ---------------------------------------------- \n"
           );

}

void TestsMenu(){
    printf(
           " ______________________________________________ \n"
           " ---------------------------------------------- \n"
           "||                  TEST'S MENU               ||\n"
           "||MENU:                                       ||\n"
           "||    General:                                ||\n"
           "||      m = print this menu                   ||\n"
           "||      a = start all tests                   ||\n"
           "||      q = menu exit                         ||\n"
           "\n"
           "||    DynamicArray tests:                     ||\n"
           "||      d = start all DynamicArray tests      ||\n"
           "\n"
           "||    LinkedList tests:                       ||\n"
           "||      l = start all LinkedList tests        ||\n"
           "\n"
           "||    ArraySequence tests:                    ||\n"
           "||      s = start all ArraySequence tests     ||\n"
           "\n"
           "||    LinkedListSequence tests:               ||\n"
           "||      i = start all LinkedListSequence tests||\n"
           " ______________________________________________ \n"
           " ---------------------------------------------- \n"

           );
}
void LinkedListSequenceMenu(){
    printf(" ________________________________________________ \n"
           " ------------------------------------------------ \n"
           "||              LinkedListSequence              ||\n"
           "||MENU:                                         ||\n"
           "||    General:                                  ||\n"
           "||      i = insert new element                  ||\n"
           "||      p = print                               ||\n"
           "||      g = get element by index                ||\n"
           "||      d = delete range of elements            ||\n"
           "||      s = get slice of                        ||\n"
           "||      c = concatenate                         ||\n"
           "\n"
           "||    LinkedListSequence tests:                 ||\n"
           "||      t = start all LinkedListSequence tests  ||\n"
           " ________________________________________________ \n"
           " ------------------------------------------------ \n"

           );
}
void ArraySequenceMenu(){
    printf(
           " ____________________________________________________ \n"
           " ---------------------------------------------------- \n"
           "||              ArraySequence                       ||\n"
           "||MENU:                                             ||\n"
           "||    General:                                      ||\n"
           
           "||      i = insert new element                      ||\n"
           "||      p = print                                   ||\n"
           "||      g = get element by index                    ||\n"
           "||      d = delete range of ArraySequence elements  ||\n"
           "||      s = get slice                               ||\n"
           "||      c = concatenate                             ||\n"
           "||      q = menu exit                               ||\n"
           "\n"
           "||    ArraySequence tests:                          ||\n"
           "||      t = start all ArraySequence tests           ||\n"
           " ____________________________________________________ \n"
           " ---------------------------------------------------- \n"
           );
}
void MatrixMenu(){
    printf(
           " ____________________________________________________ \n"
           " ---------------------------------------------------- \n"
           "||                     Matrix                       ||\n"
           "||MENU:                                             ||\n"
           "||    General:                                      ||\n"
           "||      m = print Matrix menu                       ||\n"
           "||      p = print                                   ||\n"
           "||      s = Set Menu                                ||\n"
           "||      g = Get Menu                                ||\n"
           "||      S = Sum of 2 matrix                         ||\n"
           "||      M = Mult of 2 matrix                        ||\n"
           "||      q = menu exit                               ||\n"
           "\n"
           "||    Matrix tests:                                 ||\n"
           "||      t = start all Matrix tests                  ||\n"
           " ____________________________________________________ \n"
           " ---------------------------------------------------- \n"
           );
}
void SetMenu(){
    printf(
            " ____________________________________________________ \n"
            " ---------------------------------------------------- \n"
            "||                     Set Menu                     ||\n"
            "||MENU:                                             ||\n"
            "||    General:                                      ||\n"
            "||      1 = Set element by index                    ||\n"
            "||      2 = Set number of rows                      ||\n"
            "||      3 = Set number of columns                   ||\n"
            "||      4 = menu exit                               ||\n"

            " ____________________________________________________ \n"
            " ---------------------------------------------------- \n"
            );
}

void GetMenu(){
    printf(
            " ____________________________________________________ \n"
            " ---------------------------------------------------- \n"
            "||                    Get Menu                      ||\n"
            "||MENU:                                             ||\n"
            "||    General:                                      ||\n"
            "||      1 = Get element by index                    ||\n"
            "||      2 = Get row                                 ||\n"
            "||      3 = Get column                              ||\n"
            "||      4 = menu exit                               ||\n"
            " ____________________________________________________ \n"
            " ---------------------------------------------------- \n"
            );
}

void ChecknNumSize(char *arr, int &s, int size){
    s = 0;
    for (int i = 0; i < size; i++){
        if (arr[i] != '\0'){
            s++;
        }
    }
}

int StrToInt(char *s){
    int temp = 0; // число
    int i = 0;
    int sign = 0; // знак числа 0 - положительное, 1 — отрицательное
    if (s[i] == '-'){
        sign = 1;
        i++;
    }
    while (s[i] >= 0x30 && s[i] <= 0x39){
        temp = temp + (s[i] & 0x0F);
        temp = temp * 10;
        i++;
    }
    temp = temp / 10;
    if (sign == 1){
        temp = -temp;
    }
    return(temp);
}

void InputNumCheckInt(char* arr, int size, int &num){
    bool m = 0;
    int s = 0;
    char a[11] = {"2147483647"};
    printf("Enter the number: ");
    getchar();
    cin.getline(arr, size);
    ChecknNumSize(arr, s, size);
    while (s > 10){
        printf("\nERROR: Number is too big number for data type.\n"
               "Try enter the number again: ");
        memset(arr,'\0',20);
        cin.getline(arr, size);
        ChecknNumSize(arr,s,size);
    }
    if (s < 10){
        m = 1;
    }
    else if (s == 10){
        int i = 0;
        if (arr[i] > 2){
            throw "ERROR: Number is too big number for data type int";
        }
        else if (arr[i] < 2){
            m = 1;
        }
        else if (arr[i] == 2){
            for (int i = 0; i < 11; i++){
                if ( arr[i] <= int(a[i]) ){
                    m = 1;
                }
                else{
                    throw "ERROR: Number is too big number for data type int";
                }
            }
        }
    }
    if (m){
        num = StrToInt(arr);
    }
}

using namespace std;
int main(){
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    ArraySequence<int> ArrSeq(arr, 10);
    LinkedListSequence<int> LlSeq(arr, 10);
    
    Matrix<int> matrix1(4, 4);
    
    Matrix<int> matrix2(4, 4);
    char input[7];
    memset(input, '\0', 5 * sizeof(char));
    int res = 0;
    srand(time(NULL));

    while(!res && input[0] != 'q'){
        menu();
        cin>>input[0];
        switch(input[0]){
            case 'm':
                menu();
                break;
            case 's':
                while(input[1] != 'q'){
                    ArraySequenceMenu();
                    cin>>input[1];
                    switch (input[1]) {
                        case 'i':{
                            int index = 0, num = 0;
                            printf("Write index where you want to insert number: ");
                            cin>>index;
                            while (index > ArrSeq.GetLength() || index < 0){
                                printf("Oops, Index out of range! Write index where you want to insert number: ");
                                cin>>index;
                            }
                            char arr[20];
                            memset(arr, '\0', 20 * sizeof(char));
                            InputNumCheckInt(arr, 20, num);
                            while (num > 2147483647){
                                printf("ERROR: So big number");
                                cin>>num;
                            }
                            if (index == 0){
                                ArrSeq.Prepend(num);
                            }
                            else if (index == ArrSeq.GetLength() ){
                                ArrSeq.Append(num);
                            }
                            else{
                                ArrSeq.InsertAt(num, index);
                            }
                            break;
                        }
                        case 'p':
                            ArrSeq.Print();
                            break;
                        case 'g':
                            
                            break;
                        case 'd':
                            break;
                        case 's':{
                            int firstElement = 0, lastElement = 0;
                            cout<<"Write number of first element: ";
                            cin>>firstElement;
                            cout<<"Write nember of last element: ";
                            cin>>lastElement;
                            ArraySequence<int> ArrSeqInterval(ArrSeq, firstElement, lastElement);
                            cout<<"Slice of ArraySequence"<<endl;
                            ArrSeqInterval.Print();
                            break;
                        }
                        case 'c':
                            break;
                        case 't':
                            AllArraySequenceTests();
                            break;
                        case 'q':
                            break;
                        default:
                            break;
                    }
                }
                break;
            case 'l':
                LinkedListSequenceMenu();
                while(input[2] != 'q'){
                    cin>>input[2];
                    switch (input[2]) {
                        case 'i':{
                            int index = 0, num = 0;
                            printf("Write index where you want to insert number: ");
                            cin>>index;
                            while (index > ArrSeq.GetLength() || index < 0){
                                printf("Oops, Index out of range! Write index where you want to insert number: ");
                                cin>>index;
                            }
                            char arr[20];
                            memset(arr, '\0', 20* sizeof(char));
                            InputNumCheckInt(arr, 20, num);
                            while (num > 2147483647){
                                printf("ERROR: So big number");
                                cin>>num;
                            }
                            if (index == 0){
                                LlSeq.Prepend(num);
                            }
                            else if (index == ArrSeq.GetLength() ){
                                LlSeq.Append(num);
                            }
                            else{
                                LlSeq.InsertAt(num, index);
                            }
                        }
                            break;
                        case 'p':
                            LlSeq.Print();
                            break;
                        case 'g':{
                            int index = 0;
                            cout<<"Write index of element, that you want to get: ";
                            LlSeq.Get(index);
                        }
                            break;
                        case 'd':
                            
                            break;
                        case 's':{
                            int firstElement = 0, lastElement = 0;
                            cout<<"Write number of first element: ";
                            cin>>firstElement;
                            cout<<"Write nember of last element: ";
                            cin>>lastElement;
                            LinkedListSequence<int> LlSeqInterval(LlSeq, firstElement, lastElement);
                            LlSeqInterval.Print();
                        }
                            break;
                        case 'c':
                            
                            break;
                        case 't':
                            
                            break;
                    }
                }
                break;
            case'M':
                MatrixMenu();
                while (input[3] != 'q'){
                    cin>>input[3];
                    switch(input[3]){
                        case 'm':
                            MatrixMenu();
                            break;
                            
                        case 'p':
                            cout<<"<matrix1>"<<endl;
                            matrix1.Print();
                            break;
                        case 's':{
                            SetMenu();
                            while (input[4] != '4'){
                                cin>>input[4];
                                switch(input[4]){
                                    case '1':{
                                        int i = 0, j = 0, value = 0;
                                        printf("Write index what number in Matrix do you want to set:\n");
                                        cout<<"Enter [i]: ";
                                        cin>>i;
                                        cout<<"Enter [j]: ";
                                        cin>>j;
                                        while (i > matrix1.GetRows() || j > matrix1.GetColumns() || i < 0 || j < 0){
                                            printf("Oops, Index out of range! Write index where you want to insert number: ");
                                            cout<<"Enter [i]"<<endl;
                                            cin>>i;
                                            cout<<"Enter [j]"<<endl;
                                            cin>>j;
                                        }
                                        char arr[20];
                                        memset(arr, '\0', 20 * sizeof(char));
                                        InputNumCheckInt(arr, 20, value);
                                        while (value > 2147483647){
                                            printf("ERROR: So big number");
                                            cin>>value;
                                        }
                                        matrix1.SetMij(i, j, value);
                                    }
                                    case '2':
                                        
                                        break;
                                    case '3':
                                        
                                        break;
                                }
                            }

                            break;
                        }
                        case 'g':{
                            GetMenu();
                            while (input[5] != '4'){
                                cin>>input[5];
                                switch(input[5]){
                                    case'e':{
                                        int i = 0, j = 0;
                                        printf("Write index where you want to insert number in Matrix: ");
                                        cout<<"Enter [i]: "<<endl;
                                        cin>>i;
                                        cout<<"Enter [j]: "<<endl;
                                        cin>>j;
                                        while (i > matrix1.GetRows() || j > matrix1.GetColumns() || i < 0 || j < 0){
                                            printf("Oops, Index out of range! Write index where you want to insert number: ");
                                            cout<<"Enter [i]"<<endl;
                                            cin>>i;
                                            cout<<"Enter [j]"<<endl;
                                            cin>>j;
                                        }
                                        matrix1.GetMij(i, j);
                                        break;
                                    }
                                    case'r':
                                        
                                        break;
                                    case 'c':
                                        
                                        break;
                                }
                            }
                            break;
                        }
                        case 'S':{
                            cout<<"<matrix1>"<<endl;
                            matrix1.Print();
                            cout<<"<matrix2>"<<endl;
                            matrix2.Print();
                            
                            Matrix<int> matrixr = matrix1.operator+(matrix2);
                            cout<<"Result matrix <matrixr>"<<endl;
                            matrixr.Print();
                            break;
                        }
                        case 'M':{
                            cout<<"<matrix1>"<<endl;
                            matrix1.Print();
                            cout<<"<matrix2>"<<endl;
                            matrix2.Print();
                            
                            Matrix<int> matrixr = matrix1.operator*(matrix2);
                            cout<<"Result matrix <matrixr>"<<endl;
                            matrixr.Print();
                            break;
                        }
                            break;
                        case 't':
                            
                            break;
                    }
                }
                cin>>input[3];
                
            case 't':
                TestsMenu();
                while(input[6] != 'q'){
                    cin>>input[6];
                    switch(input[6]){
                        case 'm':
                            TestsMenu();
                            break;
                        case 'a':
                            AllTests();
                            break;
                        case 'd':
                            cout<<"DynamicArray tests"<<'\n'<<endl;
                            AllDynamicArrayTests();
                            break;
                        case 'l':
                            cout<<"LinkedList tests"<<'\n'<<endl;
                            AllLinkedListTests();
                            break;
                        case 's':
                            cout<<"ArraySequence tests"<<'\n'<<endl;
                            AllArraySequenceTests();
                            break;
                        case 'i':
                            cout<<"LinkedListSequence tests"<<'\n'<<endl;
                            AllLinkedListSequenceTests();
                            break;
                        case 'q':
                            break;
                        default:
                            break;
                    }
                }
                break;
            case 'q':
                res = 1;
                break;
            default:
                printf("ERROR");
                break;
        }
    }
    return 0;
}
