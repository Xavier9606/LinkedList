#include <iostream>
#include <string>
#include <vector>
#include "List.h"
#include <chrono>

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


class twofields {
public:
    explicit twofields(int a) : a(a) {}

    twofields(twofields&& obj)= default;

//    twofields(twofields&& obj) {
//        cout << "move twofields" << endl;
//        a = obj.a;
//        b = std::move(obj.b);
//    };

    twofields& operator=(twofields &&obj) = default;

    twofields(twofields const &obj) = delete;

    twofields& operator=(twofields const &obj) = delete;

    void setA(int aa) { a = aa; }

    int getA() { return a; }

    string getB() { return b; }

private:
    int a;
    string b;
};



int main() {


//    List<twofields> myList;
//    for (int i = 0; i < 10; i++) {
//        myList.add({i});
//    }
//
//    for (int i = 0; i < myList.size(); i++) {
//        cout << myList[i].getA() << endl;
//    }
//
//    cout << "---------------------" << endl;


        List<int> myList;
    for (int i = 0; i < 10; i++) {
        myList.add(i);
    }


    for (int i = 0; i < myList.size(); i++) {
        cout << myList[i] << endl;
    }


//    myList.sort([](auto &first, auto &second) {
//            return first.getA() < second.getA();
//    });


    cout << "---------------------" << endl;


//    cout << "Size: " << myList.size() << endl;
//    cout << "Empty: " << myList.isEmpty() << endl;

    cin.ignore();
    return 0;
}