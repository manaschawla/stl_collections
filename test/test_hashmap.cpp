#include "../include/HashMap/hash_map.h"
#include <iostream>

using namespace std;

class Student
{
public:
    int rollNo;

    bool operator==(const Student& other) const
    {
        return rollNo == other.rollNo;
    }
};

int main()
{
    HashMap<Student,int> map;

    for(int i = 0; i < 100; i++)
    {
        Student s;
        s.rollNo = i;

        map.put(s,i);
    }

    Student s;
    s.rollNo = 57;

    cout << map.get(s) << endl;
    map.remove(s);
    cout<<map.containsKey(s)<<endl;
    s.rollNo = 500;

    HashMap<int,int> maps;

    cout << maps.isEmpty();
    return 0;
}