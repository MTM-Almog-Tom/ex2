//
// Created by tomgu on 08/06/2021.
//

#include <iostream>
#include "sortedList.h"
#define TEST(num) cout << endl << "TEST " << (num) << endl;

using std::cout;
using std::endl;
using std::string;
using namespace mtm;

template<class T>
void printList(SortedList<T> list);

int main()
{
    TEST("1.5")
    SortedList<string> lst1 = SortedList<string>();
    lst1.insert("Charlie");
    lst1.insert("Bob");
    lst1.insert("Alice");
    lst1.insert("Donald");

    printList(lst1);

}

template<class T>
void printList(SortedList<T> list) {
    for (auto it = list.begin(); it != list.end(); ++it) {
        cout << *it << endl;
    }
    cout << endl;
}
