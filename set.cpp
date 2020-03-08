//
//  set.cpp
//  Assignment1
//
//  Created by Lyhn Bo on 2020. 02. 23..
//  Copyright © 2020. Lyhn Bo. All rights reserved.
//

#include "set.hpp"
#include <stdio.h>
#include <stdlib.h>

using namespace std;
bool Set::isEmpty()const{
    return v.size()==0;
}
bool Set::isContain(int a)const{
    for(int i = 0; i < v.size(); i++){
        if(v[i]==a){return 1;}
    }
    return 0;
}
int Set::randomRet()const throw(Exce){
    if(isEmpty())throw IS_EMPTY;
    int ri = rand() % v.size();
    return v[ri];
}
void Set::insertElem(int a){
    if(!isContain(a)){
        v.push_back(a);
    }
    else{
        cout << a << " is existing in set!"<<endl;
    }
}
void Set::removeElem(int a)throw(Exce){
    bool b = false;
    if(isEmpty())throw IS_EMPTY;
    for(int i = 0; i < v.size(); i++){
        if(v[i]==a){
            b = true;
            v.erase(v.begin()+i);
            break;
        }
    }
    if(!b) throw NOT_EXIST;
}
int Set::maxElem()const throw(Exce){
    if(isEmpty())throw IS_EMPTY;
    int i = 0;
    int max = -999999;
    for(i = 0; i < v.size(); i++){
        if(v[i]>max){
            max = v[i];
        }
    }
    return max;
}
void Set::print()const{
    if(isEmpty())throw IS_EMPTY;
    int i = 0;
    
    for(i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
std::istream& operator>> (std::istream& s, Set& a){
    int b;
    for(int i = 0; i < a.sz; i++){
        s >> b;
        a.insertElem(b);
    }
    return s;
}
std::ostream& operator<< (std::ostream& s, Set& a){
    if(a.isEmpty())throw Set::IS_EMPTY;
    s << "Current Set: "<<endl;
    for(int i = 0; i < a.size(); i++){
        s << a.getter(i) << " ";
    }
    return s;
}
