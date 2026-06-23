#include <iostream>
#include "../src/Linked List/Linked_list.h"

using namespace std;

int main()
{
    try
    {
        LinkedList<int> list;

        cout << "Initial State" << endl;
        cout << "Size: "
             << list.size()
             << endl;

        cout << "Is Empty: "
             << list.isEmpty()
             << endl;

        cout << "\nTesting pushFront" << endl;

        list.pushFront(20);
        list.pushFront(10);

        cout << "Size: "
             << list.size()
             << endl;

        cout << "First Element: "
             << list.get(0)
             << endl;

        cout << "\nTesting pushBack" << endl;

        list.pushBack(30);
        list.pushBack(40);

        cout << "Size: "
             << list.size()
             << endl;

        cout << "Elements:" << endl;

        for(int i = 0; i < list.size(); i++)
        {
            cout << list.get(i)
                 << " ";
        }

        cout << endl;

        cout << "\nTesting contains" << endl;

        cout << "Contains 20: "
             << list.contains(20)
             << endl;

        cout << "Contains 100: "
             << list.contains(100)
             << endl;

        cout << "\nTesting Exception" << endl;

        try
        {
            cout << list.get(100)
                 << endl;
        }
        catch(const out_of_range& e)
        {
            cout << "Invalid index exception caught"
                 << endl;
        }
    }
    catch(const exception& e)
    {
        cout << "Exception: "
             << e.what()
             << endl;
    }

    return 0;
}