#include <iostream>
#include <stdexcept>
#include <limits>
#include <cmath>
#include <algorithm>
#include "vector.hpp"
using namespace std;

Vector::Vector(){
    fill(vec.begin(),vec.end(),0);
}

Vector::Vector(double k){
    fill(vec.begin(),vec.end(),k);
}

Vector::Vector(const Vector& p){
    copy(p.vec.begin(),p.vec.end(),vec.begin());
}

Vector& Vector::operator=(const Vector& p){
    if(this != &p){
            copy(p.vec.begin(),p.vec.end(),vec.begin());
    }
    return *this;
}

double Vector::operator[](unsigned long i) const{
    if(i > (n-1)){
            throw out_of_range("out of range");
    }
    return vec[i];
}

double& Vector::operator[](unsigned long i){
    if(i > (n-1)){
            throw out_of_range("out of range");
    }
    return vec[i];
}

Vector& Vector::operator+=(const Vector& p){
    copy(p.vec.begin(),p.vec.end(),vec.begin());
    return *this;
}

Vector& Vector::operator-=(const Vector& p){
    for(size_t i = 0; i < n; ++i){
        vec[i] -= p.vec[i];
    }
    return *this;
}

Vector& Vector::operator*=(double k){
    for_each(vec.begin(),vec.end(),[k](double& i){return i *= k;});
    return *this;
}

Vector& Vector::operator/=(double k){
    if(k){
            for_each(vec.begin(),vec.end(),[k](double& i){return i /= k;});
    }
    else{
            throw invalid_argument("divison by zero");
    }
    return *this;
}

bool operator==(const Vector& p1, const Vector& p2){
    for(size_t i = 0; i < Vector::n; ++i){
            if(abs(p1.vec[i] - p2.vec[i]) > numeric_limits<double>::epsilon()){
                return false;
            }
    }
    return true;
}

ostream& operator<<(ostream& os,const Vector& p){
    for(size_t i = 0; i < Vector::n; ++i){
        os<<p.vec[i]<<' ';
    }
    return os;
}

Vector operator+(const Vector& p1, const Vector& p2){
    return Vector(p1) += p2;
}

Vector operator-(const Vector& p1, const Vector& p2){
    return Vector(p1) -= p2;
}

Vector operator*(const Vector& p, double k){
    return Vector(p) *= k;
}

Vector operator*(double k, const Vector& p){
    return Vector(p) *= k;
}

Vector operator/(const Vector& p, double k){
    if(k){
            return Vector(p) /= k;
    }
    else{
        throw invalid_argument("divison by zero");
    }
}

double operator^(const Vector& p1, const Vector& p2){
    double sum = 0;
    for(size_t i = 0; i < Vector::n; ++i){
            sum += p1.vec[i]*p2.vec[i];
    }
    return sum;
}

bool operator!=(const Vector& p1, const Vector& p2){
    return !(p1 == p2);
}

Vector Vector::operator-()const{
    return Vector(*this) *= -1;
}
