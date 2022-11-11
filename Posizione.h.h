#ifndef __Posizione_h__
#define __Posizione_h__

#include <cmath>

class Posizione {

public:

  	// costruttori
	Posizione();

	Posizione(const Posizione&);

	Posizione(double x, double y, double z);
  // distruttore
	~Posizione();
    
  // metodi

  void setX(double a){m_x=a;};
  void setY(double a){m_y=a;};
  void setZ(double a){m_z=a;};

  	//coordinate cartesiane
  	double GetX() const;
  	double GetY() const;
  	double GetZ() const;

  	//coordinate polari
  	double GetR() const;
  	double GetPhi() const;
		double GetTeta() const;

	//coordinate cilindriche
	double GetRho() const;
	
	//distanza
	double Distanza(const Posizione&) const;
	double Distanza(double x,double y,double z);

private:
    double m_x, m_y, m_z;

};

Posizione::Posizione(){
	m_x=0;
	m_y=0;
	m_z=0;
}

Posizione::Posizione(const Posizione& pos){
	m_x=pos.GetX();
	m_y=pos.GetY();
	m_z=pos.GetZ();
}

//costruttore con argomento
Posizione::Posizione(double x, double y, double z){
	m_x=x;
	m_y=y;
	m_z=z;
}

//distruttore
Posizione::~Posizione(){};

double Posizione::GetX() const {
	return m_x;
}

double Posizione::GetY() const {
	return m_y;
}

double Posizione::GetZ() const {
	return m_z;
}

double Posizione::GetR() const{
	return sqrt(m_x*m_x+m_y*m_y+m_z*m_z);
}

double Posizione::GetPhi() const{
	return atan2(m_y, m_x);
}

double Posizione::GetTeta() const{
	return acos(m_z/GetR());
}

double Posizione::GetRho() const{
	return sqrt(m_x*m_x+m_y*m_y);
}

double Posizione::Distanza(const Posizione& b) const {
	return sqrt(pow(GetX()-b.GetX(),2)+pow(GetY()-b.GetY(),2)+pow(GetZ()-b.GetZ(),2));
}

double Posizione::Distanza(double x,double y,double z)  {
	return sqrt(pow(GetX()-x,2)+pow(GetY()-y,2)+pow(GetZ()-z,2));
}

#endif // __Posizione_h__
