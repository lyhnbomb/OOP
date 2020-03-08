//
//  set.hpp
//  Assignment1
//
//  Created by Lyhn Bo on 2020. 02. 23..
//  Copyright © 2020. Lyhn Bo. All rights reserved.
//

#ifndef Set_hpp
#define Set_hpp
#include <iostream>
#include <stdio.h>
#include <vector>
class Set{
private:
    std::vector<int> v;
    int sz;
    int getter(int a){return v[a];}
public:
    Set(){
        std::cout<<"Many many years ago, a Set was borned..."<<std::endl;
    };
    enum Exce{IS_EMPTY,NOT_EXIST};
    void insertElem(int a);
    void removeElem(int a)throw(Exce);
    void SetSz(int a){sz = a;}
    bool isEmpty()const;
    bool isContain(int a)const;
    int randomRet()const throw(Exce);
    int maxElem()const tEhrow(Exce);
    void print()const;
    unsigned long size(){return v.size();}
    friend std::istream& operator>> (std::istream& s, Set& a);
    friend std::ostream& operator<< (std::ostream& s, Set& a);
};
#endif /* Set_hpp */
