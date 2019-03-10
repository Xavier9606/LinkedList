#pragma once

#include <functional>

template<typename T>
class MyNode {
public:

    explicit MyNode(T &val, MyNode *link = nullptr) : value(std::move(val)), next(link) {}

    ~MyNode() = default;

    void setValue(T &&v) {
        value = std::move(v);
    }

    T &getValue() {
        return value;
    }

    void setLink(MyNode *L) {
        next = L;
    }

    MyNode *getLink() {
        return next;
    }


private:

    T value;
    MyNode *next;
};

template<typename T>
class List {
public:
    List() = default;

    ~List() = default;

    T &operator[](int index) { return get(index); };

    void add(T &value); // -������ ������� � �����

    void add(T &&value); // -������ ������� � �����

    T gethead() { return head->getValue(); };

    T gettail() { return tail->getValue(); };

    T &get(int index); // -�������� �� �������

    bool contains(T obj); // -�� � obj � ��� ?

    T removeID(int index); // -�������� �� �������

    bool isEmpty(); // -��������, �� �� ������

    int size(); // -�������� ������ ��������

    int clear();// -�������� ���

    void sort(std::function<bool(T &, T &)> fn);

    void swap(int a, int b);

private:

    MyNode<T> *getNode(int index);

    int length = 0;
    MyNode<T> *head = nullptr;
    MyNode<T> *tail = nullptr;

};

template<typename T>
void List<T>::add(T &value)  // -������ ������� � �����
{
    if (length == 0) {
        tail = head = new MyNode<T>(value);
        length++;
        return;
    };

    tail->setLink(new MyNode(value));
    tail = tail->getLink();
    length++;
}

template<typename T>
void List<T>::add(T &&value)  // -������ ������� � �����
{
    if (length == 0) {
        tail = head = new MyNode<T>(value);
        length++;
        return;
    };

    tail->setLink(new MyNode(value));
    tail = tail->getLink();
    length++;
}

template<typename T>
T &List<T>::get(int index) // -�������� �� �������
{


    MyNode<T> *curr = head;

    for (int i = 0; (i < index); i++) {
        if (curr->getLink() == nullptr)
            break;

        curr = curr->getLink();
    }

    return curr->getValue();
}

template<typename T>
MyNode<T> *List<T>::getNode(int index) // -�������� �� �������
{

    MyNode<T> *curr = head;

    for (int i = 0; (i < index); i++) {
        if (curr->getLink() == nullptr)
            break;

        curr = curr->getLink();
    }
    return curr;
}


template<typename T>
bool List<T>::contains(T obj) // -�� � MyNode � ��� ?
{
    MyNode<T> *curr = head;
    for (int i = 0; (i < length); i++) {
        if (curr->getValue() == obj) {
            return true;
        };
        curr = curr->getLink();
    }
    return false;

}


template<typename T>
T List<T>::removeID(int index) // -�������� �� �������
{
    MyNode<T> *curr = head;
    MyNode<T> *next = nullptr;
    MyNode<T> *prev = nullptr;
    T del = std::move(get(index));

    if (index == 0) {

        next = head->getLink();
        delete head;
        head = next;
        length--;
        return del;
    }


    for (int i = 0; (i < index); i++) {
        if (i == (index - 1)) { prev = curr; };
        curr = curr->getLink();

    }

    prev->setLink(curr->getLink());
    if (curr == tail) { tail = prev; }

    delete curr;


    length--;
    return del;
}

template<typename T>
bool List<T>::isEmpty() // -��������, �� �� ������
{
    return length == 0;
}

template<typename T>
int List<T>::size() // -�������� ������ ��������
{
    return length;
}


template<typename T>
int List<T>::clear()// -�������� ���
{
    int objectsCount = length;

    //MyNode<T> *curr = head;
    MyNode<T> *next = nullptr;
    for (int i = 0; (i < length); i++) {
        next = head->getLink();
        delete head;
        head = next;
    }
    tail = nullptr;
    length = 0;
    return objectsCount;
}

template<typename T>
void List<T>::sort(std::function<bool(T &, T &)> fn) {
    MyNode<T> *curr = head;
    while (curr->getLink() != nullptr) {
        T currVal = std::move(curr->getValue());
        T nextVal = std::move(curr->getLink()->getValue());
        bool b = fn(currVal, nextVal);
        if (b) {
            T temp = std::move(currVal);
            curr->setValue(std::move(nextVal));
            curr->getLink()->setValue(std::move(temp));
            curr = head;
            continue;
        }
        curr = curr->getLink();
    }
}

template<typename T>
void List<T>::swap(int a, int b) {

    T temp = std::move(getNode(a)->getValue());
    getNode(a)->setValue(std::move(getNode(b)->getValue()));
    getNode(b)->setValue(std::move(temp));

}
