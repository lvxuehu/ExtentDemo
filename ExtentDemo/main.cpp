//
//  main.cpp
//  TestExtentOverDemo
//
//  Created by lly on 14-9-12.
//  Copyright (c) 2014年 lly. All rights reserved.
//

#include <iostream>


class Base0{
public:
    Base0(){};
    ~Base0(){};
    
    virtual void f1()=0;
    
    virtual void f2()=0;
    
    virtual void f3()=0;
    
    
    
};



class Base{
public:
    Base(){
        
    }
    
    ~Base(){
        
    }
    
    void f1(){//如果基类中没有virtual申明，子类中无法覆盖整个方法，就算有一个方法名相同的方法，还是会调用基类的方法。所以如果希望子类能覆盖，就需要virtual申明
        std::cout << "Base f1 \n";
    }
    
    virtual void f2(){
        std::cout << "Base f2 \n";
    }//必须写{}，要不报错；如果子类没有覆盖这个方法，则调用基类的这个方法。这个写法比较灵活。
    
    
    virtual void f3()=0;//除非添加=0，要不都需要写方法体，哪怕方法体是空的，{}；如果写了=0，子类必须覆盖基类的这个方法。
};


class B1:public Base{
public:
    B1(){
        
    }
    
    void f1(){
        std::cout << "B1 f1 \n";
    }
    
    void f2(){//注释这个方法后，会调用基类的方法
        
        std::cout << "B1 f2 \n";
        Base::f2();//注意这种写法，在子类的覆盖virtual后可以继续调用基类的f2方法。
    }
    
    void f3(){
        std::cout << "B1 f3 \n";
    }
};


class B2:public Base0{
public:
    B2(){
        
    }
    ~B2(){
        
    }
    
    void f1(){
        std::cout << "B2 f1 \n";
    }
    
    void f2(){
        std::cout << "B2 f2 \n";
    }
    
    void f3(){
        std::cout << "B2 f3 \n";
    }
    
    
    
    
};



int main(int argc, const char * argv[])
{
    
    Base* b=new B1();
    b->f1();
    b->f2();
    b->f3();
    
    
    Base0* b2=new B2();
    //    b2->f1();
    b2->f2();
    b2->f3();
    
    
    // insert code here...
    std::cout << "----Hello, World!\n----";
    return 0;
}

