//============================================================================
// Name        : Stable.cpp
// Author      : Anirudh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define SIZE 2
using namespace std;
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
    engaged = true;
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
                continue;
            Person *woman = m[i]->getNextPref();
            if (!woman->isEngaged()) {
                m[i]->engage(woman);
                woman->engage(m[i]);
            }
            else {
                if(woman->prefers(m[i])) {
                    woman->getPartner()->disengage();
                    woman->disengage();
                    m[i]->engage(woman);
                    woman->engage(m[i]);
                }
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        cout<<m[i]->getName()<<" : "<<m[i]->getPartner()->getName()<<endl;
    }
    
}




