
#ifndef __CampoVettoriale_h__
#define __CampoVettoriale_h__

#include "Posizione.h"
#include <cmath>
#include <iostream>
using namespace std;

class CampoVettoriale : public Posizione {

public:

  CampoVettoriale();
  CampoVettoriale(const Posizione&);
  CampoVettoriale(const Posizione&, double Fx, double Fy, double Fz);
  CampoVettoriale(double x, double y, double z, double Fx, double Fy, double Fz);
  ~CampoVettoriale();

  CampoVettoriale & operator+=( const CampoVettoriale & ) ;
  CampoVettoriale operator+( const CampoVettoriale & ) const;
  
  

  double getFx() const {return m_Fx;}
  double getFy() const {return m_Fy;}
  double getFz() const {return m_Fz;}

  double Modulo();

private:

  double m_Fx, m_Fy, m_Fz;

};



CampoVettoriale::CampoVettoriale():Posizione(){
  m_Fx=0;
  m_Fy=0;
  m_Fz=0;
}

CampoVettoriale::CampoVettoriale(const Posizione& pos):Posizione(pos){
  m_Fx=0;
  m_Fy=0;
  m_Fz=0;
}

CampoVettoriale::CampoVettoriale(const Posizione& pos, double Fx, double Fy, double Fz):Posizione(pos){
  m_Fx=Fx;
  m_Fy=Fy;
  m_Fz=Fz;
}


CampoVettoriale::CampoVettoriale(double x, double y, double z, double Fx, double Fy, double Fz):Posizione(x, y, z){
  m_Fx=Fx;
  m_Fy=Fy;
  m_Fz=Fz;
}

CampoVettoriale::~CampoVettoriale(){
  //cout<<"destructor";
};

CampoVettoriale CampoVettoriale::operator+(const CampoVettoriale & v) const {
  CampoVettoriale sum(v.GetX(), v.GetY(), v.GetZ(), 0, 0, 0);
  sum.m_Fx=v.m_Fx+m_Fx;
  sum.m_Fy=v.m_Fy+m_Fy;
  sum.m_Fz=v.m_Fz+m_Fz;
  return sum;
}


CampoVettoriale & CampoVettoriale::operator+=(const CampoVettoriale & v){
  return (*this)=(*this)+v;
}

double CampoVettoriale::Modulo(){
  double mod=sqrt(pow(m_Fx,2)+(m_Fy,2)+(m_Fz,2));
  return mod;
}

#endif // __CampoVettoriale_h__ 