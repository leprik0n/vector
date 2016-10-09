#include <iostream>
#include <stdexcept>
#include "vector.h"
#include <assert.h>
using namespace std;

void ctor_novalue(){
    Vector buf{};
    for(unsigned int i = 0; i < 3; i++){
            assert(buf[i] == 0);
    }
    cout<<"1_Passed"<<endl;
}

void ctor_value(){
    Vector buf{5};
    for(unsigned int i = 0; i < 3; i++){
            assert(buf[i] == 5);
    }
    cout<<"2_Passed"<<endl;
}

void ctor_copy(){
    Vector buf;
    Vector bbf{buf};
    for(unsigned int i = 0; i < 3; i++){
            assert(bbf[i] == buf[i]);
    }
    cout<<"3_Passed"<<endl;
}

void oper_assign(){
    Vector buf;
    Vector bbf = buf;
    for(unsigned int i = 0; i < 3; i++){
            assert(bbf[i] == buf[i]);
    }
    cout<<"4_Passed"<<endl;
}

void oper_idx(){
    Vector buf{6};
    buf[2] = 9;
    assert(buf[2] == 9);
    cout<<"5_Passed"<<endl;
}

void oper_plus_equal(){
    Vector buf{9};
    Vector bbf{2};
    buf += bbf;
    for(unsigned int i = 0; i < 3; i++){
            assert(buf[i] == 11);
    }
    cout<<"6_Passed"<<endl;
}

void oper_minus_equal(){
    Vector buf{10};
    Vector bbf{-3};
    buf -= bbf;
    for(unsigned int i = 0; i < 3; i++){
            assert(buf[i] == 13);
    }
    cout<<"7_Passed"<<endl;
}

void oper_mult_equal(){
    Vector buf{2};
    buf *= 12;
    for(unsigned int i = 0; i < 3; i++){
            assert(buf[i] == 24);
    }
    cout<<"8_Passed"<<endl;
}

void oper_div_equal(){
    Vector buf{2};
    buf /= -1;
    for(unsigned int i = 0; i < 3; i++){
            assert(buf[i] == -2);
    }
    cout<<"9_Passed"<<endl;
}

void oper_equal(){
    Vector buf{};
    Vector bbf{buf};
    buf[0] = 1.020; buf[1] = 2.01; buf[2] = 3.0012;
    bbf[0] = 1.020; bbf[1] = 2.01; bbf[2] = 3.0312;
    bool k = (buf == bbf);
    assert(k == false);
    cout<<"10_Passed"<<endl;
}

void oper_plus(){
    Vector buf{2};
    Vector bbf{4};
    Vector bfs = buf+bbf;
    for(unsigned int i = 0; i < 3; i++){
            assert(bfs[i] == 6);
    }
    cout<<"11_Passed"<<endl;
}

void oper_minus(){
    Vector buf{3};
    Vector bbf{-1};
    Vector bfs = buf-bbf;
    for(unsigned int i = 0; i < 3; i++){
            assert(bfs[i] == 4);
    }
    cout<<"12_Passed"<<endl;
}

void oper_mult_right(){
    Vector buf{2};
    Vector bbf = buf*4;
    for(unsigned int i = 0; i < 3; i++){
            assert(bbf[i] == 8);
    }
    cout<<"13_Passed"<<endl;
}

void oper_mult_left(){
    Vector buf{2};
    Vector bbf = 4*buf;
    for(unsigned int i = 0; i < 3; i++){
            assert(bbf[i] == 8);
    }
    cout<<"14_Passed"<<endl;
}

void oper_div(){
    Vector buf{15};
    Vector bbf = buf/3;
    for(unsigned int i = 0; i < 3; i++){
            assert(bbf[i] == 5);
    }
    cout<<"15_Passed"<<endl;
}

void oper_scalar(){
    Vector buf{1};
    Vector bbf{buf};
    double sum = bbf^buf;
    assert(sum == 3);
    cout<<"16_Passed"<<endl;
}

void oper_not_equal(){
    Vector buf{};
    Vector bbf{buf};
    buf[0] = 1.020; buf[1] = 2.0113; buf[2] = 3.0312;
    bbf[0] = 1.020; bbf[1] = 2.01; bbf[2] = 3.0312;
    bool k = (buf != bbf);
    assert(k == true);
    cout<<"17_Passed"<<endl;
}

void oper_minus_unar(){
    Vector buf{1};
    Vector bbf = -buf;
    for(unsigned int i = 0; i < 3; i++){
            assert(bbf[i] == -1);
    }
    cout<<"18_Passed"<<endl;
}


int main()
{

try
{

ctor_novalue();
ctor_value();
ctor_copy();
oper_assign();
oper_plus_equal();
oper_minus_equal();
oper_mult_equal();
oper_div_equal();
oper_equal();
oper_plus();
oper_minus();
oper_mult_right();
oper_mult_left();
oper_div();
oper_scalar();
oper_not_equal();
oper_minus_unar();
    
}

catch(const char* op){
    cout<<"exception:"<<op<<endl;
}

catch(const std::out_of_range& oop){
    cout<<"exception:"<<oop.what()<<endl;
}

    return 0;
}
