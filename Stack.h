#pragma once
#include <iostream>
#include <iomanip>
#include <type_traits>

using namespace std;

template <class T>
struct item
{
    int ind;
    T i;
    item<T>* next;
};

template <class T>
class Stack
{
public:
    item<T>* head;
    Stack();
    Stack(const Stack<T>&);
    ~Stack();

    int count();
    void empty();
    void show();
    void push(T i);
    void popInd(int ind);
    void pop();

    item<T>* find(int ind);
    T* getValue(int ind);
};


template <class T>
Stack<T>::Stack() {
    head = nullptr;
}
template <class T>
Stack<T>::~Stack() {
    empty();
}

//Stack<T>::Stack(const Stack<T>& s) {
//    head = nullptr;
//    T value;
//    item<T>* p = s.head;
//
//    //добавление значений в новый стек начиная с начала копируемого стека
//    for (int i = 1; i <= s.head->ind; i++) {
//        while (i != p->ind) {
//            p = p->next;
//        }
//        push(p->i);
//        p = s.head;
//    };
//}
template <class T>
int Stack<T>::count() {
    return head->ind;
}

template <class T>
void Stack<T>::empty() {
    item<T>* p;

    while (head != nullptr)
    {
        p = head;
        head = head->next;
        delete p;
    }
}

template <class T>
void Stack<T>::show() {
    if (head == nullptr)
        std::cout << "пусто" << endl;
    else
    {
        item<T>* p;
        p = head;
        p->i.header();
        while (p != nullptr)
        {
            std::cout << p->ind << p->i << endl;
            p = p->next;
        }
        std::cout << endl;
    }
}
template <class T>
void Stack<T>::push(T i) {
    if (head == nullptr) {
        head = new item<T>;
        head->i = i;
        head->ind = 1;
        head->next = 0;
    }
    else {
        item<T>* p = new item<T>;

        p->i = i;
        p->ind = head->ind + 1;
        p->next = head;
        head = p;
    }
}

template <class T>
void Stack<T>::popInd(int ind) {
    if (head->ind == ind) {
        pop();
        return;
    }

    item<T>* p1 = find(ind + 1);
    item<T>* p2 = p1->next;

    p1->next = p2->next;

    delete p2;

    p1 = head;

    if (ind != 1) {
        while (p1->ind > ind) {
            p1->ind--;
            p1 = p1->next;
        }
    }
    else {
        while (p1 != 0)
        {
            p1->ind--;
            p1 = p1->next;
        }
    }
}
template <class T>
void Stack<T>::pop() {
    if (head == nullptr)
        return;

    item<T>* p = head;
    head = head->next;
    delete p;
}

template <class T>
item<T>* Stack<T>::find(int ind) {
    item<T>* p = head;
    while (ind != p->ind) {
        p = p->next;
    }
    return p;
}
template <class T>
T* Stack<T>::getValue(int ind) {
    return &find(ind)->i;
}