#include <iostream>
#include "vector.h"
#include <cmath>
#include <limits>
using namespace std;

Vector::Vector()
{
     for(unsigned int i = 0; i < n; i++){
         vec[i]=0;
    }
}

Vector::Vector(double k)
{
     for(unsigned int i = 0; i < n; i++){
         vec[i]=k;
     }   
}

Vector::Vector(const Vector& p)
{
     for(unsigned int i = 0; i < n; i++){
         vec[i]=p.vec[i];
     }  
}

Vector& Vector::operator=(const Vector& p)
{
     if(this!=&p){
         for(unsigned int i = 0; i < n; i++){
             vec[i]=p.vec[i];
         }
     }    
     return *this;
}

double Vector::operator[](unsigned long i) const
{
     if(i > (n-1)){ 
        throw "out of range";
     }   
     return vec[i];
}

double& Vector::operator[](unsigned long i)
{
     if(i > (n-1)){ 
         throw "out_of range";
     }   
     return vec[i];
}

Vector& Vector::operator+=(const Vector& p)
{
     for(unsigned int i = 0; i < n; i++){
         vec[i]+=p.vec[i];
     }    
     return *this;
}

Vector& Vector::operator-=(const Vector& p)
{
     for(unsigned int i = 0; i < n; i++){
         vec[i]-=p.vec[i];
     }    
     return *this;
}

Vector& Vector::operator*=(double k)
{
     for(unsigned int i = 0; i < n; i++){
         vec[i]*=k;
     }    
     return *this;
}

Vector& Vector::operator/=(double k)
{
     if(k){
         for(unsigned int i = 0; i < n; i++){
            vec[i]/=k;
        }
     }
     
     else{ 
         throw "division by zero";
     }   
    return *this;
}

bool operator==(const Vector& p1, const Vector& p2)
{
     for(unsigned int i = 0; i < p1.n; i++){ 
         if(abs(p1.vec[i]-p2.vec[i])>numeric_limits<double>::epsilon())
            return false;
     }        
     return true;
}

ostream& operator<<(ostream& os,const Vector& p)
{
     for(unsigned int i = 0; i < p.n; i++){
         os<<p.vec[i]<<' ';
     }   
     return os;
}

Vector operator+(const Vector& p1, const Vector& p2)
{
     return Vector(p1)+=p2;
}

Vector operator-(const Vector& p1, const Vector& p2)
{
     return Vector(p1)-=p2;
}

Vector operator*(const Vector& p, double k)
{
     return Vector(p)*=k;
}

Vector operator*(double k, const Vector& p)
{
     return Vector(p)*=k;
}

Vector operator/(const Vector &p, double k)
{
     if(k)
     {
        return Vector(p)/=k;
     }
     else{
        throw "division by zero";
     }   
}

double operator^(const Vector& p1, const Vector& p2)
{
     double sum=0;
     for(unsigned int i = 0;i < p1.n; i++){
         sum+=p1.vec[i]*p2.vec[i];
     }    
     return sum;
}

bool operator!=(const Vector& p1, const Vector& p2)
{
     return !(p1==p2);
}

Vector Vector::operator-()const
{
     return Vector(*this)*=-1;
} 
