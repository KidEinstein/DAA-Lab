//============================================================================
// Name        : Stable.cpp
// Author      : Anirudh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define SIZE 2
class Person {
    string name;
    Person* partner;
    bool engaged;
    Person** prefList;
    int prefPosition;
    int prefEnd;
    
public:
    Person() {
        name = "";
        partner = NULL;
        engaged = false;
        prefList = new Person*[SIZE];
        prefPosition = -1;
        prefEnd = -1;
    }
    bool isEngaged();
    bool prefers(Person *p);
    void engage(Person *p);
    void disengage();
    Person* getNextPref();
    int rank(Person p);
    string getName();
    void setName(string name);
    void addToPrefList(Person *p);
    Person* getPartner();
};

bool Person::isEngaged() {
    return engaged;
}

bool Person::prefers(Person *p) {
    for (int i = 0; i < SIZE; i++) {
        if (prefList[i]->getName() == p->getName())
            return true;
        if (prefList[i]->getName() == partner->getName())
            return false;
        
    }
    return false;
}

void Person::engage(Person *p) {
    partner = p;
    p->partner = this;
}

void Person::disengage() {
    partner = NULL;
    engaged = false;
}

Person* Person::getNextPref() {
    return prefList[++prefPosition];
}

string Person::getName() {
    return name;
}

void Person::setName(string n) {
    name = n;
}
int Person::rank(Person p) {
    for(int i = 0; i < SIZE; i++) {
        if(prefList[i]->getName() == p.getName()) {
            return i;
        }
    }
    return -1;
}

void Person::addToPrefList(Person* p) {
    prefList[++prefEnd] = p;
}

Person* Person::getPartner() {
    return partner;
}

void displayArray(Person* p[]) {
    for(int i = 0; i < SIZE; i++) {
        cout<<i<<" : "<<p[i]->getName()<<endl;
    }
}

bool singleMenLeft(Person* p[]) {
    for (int i = 0; i < SIZE; i++) {
        if(!p[i]->isEngaged())
            return true;
    }
    return false;
}

int main() {
    Person *m[SIZE];
    Person *w[SIZE];
    for (int i = 0; i < SIZE; i++) {
        m[i] = new Person();
        w[i] = new Person();
    }
    string name;
    cout<<"Enter the names of "<<SIZE<<" men"<<endl;
    for (int i = 0; i < SIZE; i++) {
        cin>>name;
        m[i]->setName(name);
    }
    cout<<"Enter the names of "<<SIZE<<" women"<<endl;
    for (int i = 0; i < SIZE; i++) {
        cin>>name;
        w[i]->setName(name);
    }
    
    for (int i = 0; i < SIZE; i++) {
        cout<<"Enter the preference list for "<<m[i]->getName()<<endl;
        displayArray(w);
        for (int j = 0; j < SIZE; j++) {
            int n;
            cin>>n;
            m[i]->addToPrefList(w[n]);
        }
    }
    for (int i = 0; i < SIZE; i++) {
        cout<<"Enter the preference list for "<<w[i]->getName()<<endl;
        displayArray(m);
        for (int j = 0; j < SIZE; j++) {
            int n;
            cin>>n;
            w[i]->addToPrefList(m[n]);
        }
    }
    while (singleMenLeft(m)) {
        for (int i = 0; i < SIZE; i++) {
            if (m[i]->isEngaged())
                break;
            Person *woman = m[i]->getNextPref();
            if (!woman->isEngaged()) {
                m[i]->engage(woman);
            }
            else {
                if(woman->prefers(m[i])) {
                    woman->getPartner()->disengage();
                    m[i]->engage(woman);
                }
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        cout<<m[i]->getName()<<" : "<<m[i]->getPartner()->getName();
    }
    
}




