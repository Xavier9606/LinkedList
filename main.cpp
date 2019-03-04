#include <iostream>
#include <string>
#include <vector>
#include "List.h"


using namespace std;


/*

void add(E MyNode); - додати елемент в кінець

E get(int index); - отримати по індексу

boolean contains(E MyNode); - чи є MyNode в лісті?

boolean delete(E MyNode); - видалити по силкі

E delete(int index); - видалити по індексу

boolean isEmpty(); - перевірка, чи він пустий

int size(); - отримати скільки елементів

int clear(); - очистити ліст


*/

int main() {
//lvalue
//rvalue

    List<string> myList;


    myList.add("Nulevoi");


    string value1 = "Odin";
    myList.add(value1);


   string value = "Dva";
    myList.add(value);


    myList.add("Tri");

    for (int i = 0; i < myList.size(); i++) {
        cout << myList[i] << endl;
    }

    cout << "------------------------------------" << endl;


    for (int i = 0; i < myList.size(); i++) {
        cout << myList[i] << endl;
    }



    cout << "Size: " << myList.size() << endl;



    cout << "Contains: " << myList.contains("Nulevoi") << endl;

    cout << myList[0] << endl;
    myList.removeID(0);
    cout << myList[0] << endl;
    cout << "Contains: " << myList.contains("Nulevoi") << endl;
    cout<< myList.clear()<<endl;

    cout << "Size: " << myList.size() << endl;
    cout << "Empty: " << myList.isEmpty() << endl;





    cin.ignore();
    return 0;
}