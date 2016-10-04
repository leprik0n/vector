#include <iostream>
#include "vector.h"
using namespace std;

int main()
{
try
{
  Vector buf(1);
  cout<<"Create V(1)="<<' '<<buf<<endl;
  cout<<endl;
  Vector str(5);
  cout<<"Create V(5)="<<' '<<str<<endl;
  cout<<endl;
  buf+=str;
  cout<<"V(1)+=V(5)"<<' '<<buf<<endl;
  cout<<endl;
  buf-=str;
  cout<<"V(6)-=V(5)"<<' '<<buf<<endl;
  cout<<endl;
  buf*=(-2);
  cout<<"V(1)*=(-2)"<<' '<<buf<<endl;
  cout<<endl;
  cout<<"V(-2)="<<' '<<buf[0]<<' '<<buf[1]<<' '<<buf[2]<<' '<<endl;
  buf/=4;
  cout<<endl;
  cout<<"V(-2)/=4"<<' '<<buf<<endl;
  cout<<endl;
  Vector p1=str-buf;
  cout<<"V()=V(5)-V(-0,5)"<<' '<<p1<<endl;
  Vector p2=p1+str;
  cout<<endl;
  cout<<"V()=V(5,5)+V(5)"<<' '<<p2<<endl;
  cout<<endl;
  Vector p3=p2*12;
  cout<<"V()=V(10,5)*12"<<' '<<p3<<endl;
  cout<<endl;
  Vector p4=p3/4;
  cout<<"V()=V(126)/4"<<' '<<p4<<endl;
  Vector p5=p4;
  cout<<endl;
  cout<<"V()=V(31,5)"<<' '<<p5<<endl;
  double sum=p5^p5;
  cout<<endl;
  cout<<"V(31,5)^V(31,5)"<<' '<<sum<<endl;
  cout<<endl;
  p1=Vector(0);
  p2=Vector(0);
  bool b=false;
  b=(p1==p2);
  cout<<"V(0)==V(0)"<<' '<<b<<endl;
  b=(p1!=p2);
  cout<<endl;
  cout<<"V(0)!=V(0)"<<' '<<b<<endl;
}



catch(const char*exp)
{
    cout<<"exception:"<<exp<<endl;
    cout<<"sorry can't continue!"<<endl;
}


    return 0;
}
