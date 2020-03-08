//
//  main.cpp
//  Assignment1
//
//  Created by Lyhn Bo on 2020. 02. 22..
//  Copyright © 2020. Lyhn Bo. All rights reserved.
//

#include <iostream>
#include "set.hpp"
using namespace std;

//#define NORMAL_MODE
#ifdef NORMAL_MODE
class menu{
public:
    menu(){}
    void run();q
private:
    Set s;
    void menuWrite();
    void add();
    void write();
    void removeElem();
    void isContain();
    void random();
    void maxElem();
};
void menu::run(){
    menuWrite();
}
void menu::menuWrite(){
    int n = 7;
    do{
    cout << endl << endl;
    cout << " 0. - Quit" << endl;
    cout << " 1. - Get a random element from Set" << endl;
    cout << " 2. - Does it contain such element?" << endl;
    cout << " 3. - Remove an element" << endl;
    cout << " 4. - Print Set" << endl;
    cout << " 5. - Insert to Set" << endl;
    cout << " 6. - Get the maximum element" << endl;
        cin >> n;
    switch (n) {
        case 1:
            random();
            break;
        case 2:
            isContain();
            break;
        case 3:
            removeElem();
            break;
        case 4:
            write();
            break;
        case 5:
            add();
            break;
        case 6:
            maxElem();
            break;
        case 0:
            break;
        default:
            cout<<"Command not found"<<endl;
            break;
    }
    }while(n!=0);
}
void menu::add(){
    cout<<"How many elements?"<<endl;
    int a;
    cin >> a; cout << endl;
    s.SetSz(a);
    cin >> s;
    write();
}
void menu::write(){
    try{
        cout<<s<<endl;}
    catch(Set::Exce e){
        cout<<"Oops, Set is empty"<<endl;
    }
}
void menu::removeElem(){
    int a;
    cout << "What number would you remove?"<<endl;
    cin >> a;
    try{
        s.removeElem(a);
        write();}
    catch(Set::Exce e){
        if(e==Set::IS_EMPTY)
        cout<<"Oops, Set is empty"<<endl;
        else{cout<<"Such element not exist"<<endl;}
    }
}
void menu::isContain(){
    int a;
    cout << "What number maybe contained?"<<endl;
    cin >> a;
    if(s.isContain(a)){
        cout << "Yes"<<endl;
    }
        else{cout << "No"<<endl;}
}
void menu::random(){
    try{
        cout << "We will show you a random number: "<<s.randomRet()<<endl;}
    catch(Set::Exce e){
        cout<<"Oops, Set is empty"<<endl;
    }
}
void menu::maxElem(){
    try{
        cout<<"The maximum number is: "<<s.maxElem()<<endl;}
    catch(Set::Exce e){
        cout<<"Oops, Set is empty"<<endl;
    }
}
int main(int argc, const char * argv[]) {
    menu m;
    m.run();
    return 0;
}
#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "set.hpp"
TEST_CASE("Check isEmpty(), insertElement(), removeElem(), contains() methods","[Set]")
{
    SECTION("IsEmpty")
    {
        Set S1;
        CHECK( S1.isEmpty() == true );
        S1.insertElem(5);
        CHECK( S1.isEmpty() == false );
        S1.removeElem(5);
        CHECK( S1.isEmpty() == true );
    }
    SECTION("insertElem")
    {
        Set s1;
        s1.insertElem(1);
        CHECK(s1.isContain(1) == true);
        Set s2;
        CHECK(s2.size() == 0);
        s2.insertElem(1);
        CHECK(s2.size() == 1);
        s2.insertElem(2);
        CHECK(s2.size() == 2);
        s2.insertElem(1);
        CHECK(s2.size() == 2);
        s2.removeElem(1);
        CHECK(s2.size() == 1);
    }
    SECTION("removeElem")
    {
        Set s1;
        s1.insertElem(1);
        s1.insertElem(2);
        s1.insertElem(3);
        CHECK(s1.isContain(2) == true);
        s1.removeElem(2);
        CHECK(s1.size() == 2);
        CHECK(s1.isContain(2) == false);
    }
    SECTION("contains")
    {
        Set s2;
        s2.insertElem(1);
        s2.insertElem(2);
        CHECK(s2.isContain(1) == true);
        CHECK(s2.isContain(33) == false);
        s2.insertElem(3);
        CHECK(s2.isContain(3) == true);
    }
}
TEST_CASE("insert already existing element", "[Set]")
{
    Set s1;
    s1.insertElem(1);
    s1.insertElem(2);
    s1.insertElem(3);
    s1.insertElem(4);
    s1.insertElem(5);
    s1.insertElem(5);
    CHECK(s1.size() == 5);
    s1.insertElem(1);
    CHECK(s1.size() == 5);
    s1.insertElem(3);
    CHECK(s1.size() == 5);
}
TEST_CASE("remove not existing element", "[Set]")
{
    Set s1;
    CHECK_THROWS(s1.removeElem(1));
    s1.insertElem(1);
    s1.insertElem(2);
    s1.insertElem(3);
    s1.insertElem(4);
    CHECK_THROWS(s1.removeElem(5));
}

TEST_CASE("random element","[Set]")
{
    Set s1;
    CHECK_THROWS(s1.randomRet());
    s1.insertElem(1);
    for (int i = 0; i < 100; ++i){
        CHECK(s1.randomRet() == 1);
    }
    s1.insertElem(2);
    s1.insertElem(3);
    s1.insertElem(4);
    s1.insertElem(5);
    for (int i = 0; i < 100; ++i){
        CHECK(s1.isContain(s1.randomRet()));
    }
}

#endif
