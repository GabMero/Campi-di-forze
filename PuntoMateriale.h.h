#ifndef __PuntoMateriale_h__
#define __PuntoMateriale_h__

#include "Particella.h"
#include "Posizione.h"
#include "CampoVettoriale.h"

class PuntoMateriale: public Particella, Posizione {

  public:
  PuntoMateriale(double massa, double carica, const Posizione&);
  PuntoMateriale(double massa, double carica, double x, double y, double z);
  ~PuntoMateriale();

  CampoVettoriale CampoElettrico(const Posizione&) const ;
  CampoVettoriale CampoElettrico(double x,double y,double z) ;
  CampoVettoriale CampoGravitazionale(const Posizione&) const;

  const double epsilon0 = 8.85418781762E-12;
  const double EConst = 1/(4*M_PI*epsilon0);
  const double GConst = 6.67428E-11;

};

PuntoMateriale::PuntoMateriale(double massa, double carica, const Posizione& p):Particella(massa,carica),Posizione(p){}

PuntoMateriale::PuntoMateriale(double massa, double carica, double x, double y, double z ):Particella(massa,carica),Posizione(x,y,z){}

PuntoMateriale::~PuntoMateriale(){}

CampoVettoriale PuntoMateriale::CampoElettrico(const Posizione & p) const{
  double r=Distanza(p);
  
  double constante=m_carica*(EConst/(pow(r,2)));
  double Fx = constante * abs((p.GetX() - GetX()));
  double Fy = constante * abs((p.GetY() - GetY()));
  double Fz = constante * abs((p.GetZ() - GetZ()));
  
 

  CampoVettoriale E(p,Fx,Fy,Fz);
  return E;
}

CampoVettoriale PuntoMateriale::CampoElettrico(double x,double y,double z) {
  double r=Distanza(x,y,z);
//  double constante=m_carica*(EConst/pow(r,2)); // LC
	double constante=m_carica*(EConst/pow(r,3)); //LC
	double Fx = constante * abs((x - GetX()));
  double Fy = constante * abs((y - GetY()));
  double Fz = constante * abs((z - GetZ()));

  CampoVettoriale E(x,y,z,Fx,Fy,Fz);
  return E;
}


CampoVettoriale PuntoMateriale::CampoGravitazionale(const Posizione & p) const{
  double r=Distanza(p);
  double constante=m_massa*(-GConst/pow(r,3));
  double Fx = constante * (p.GetX() - GetX());
  double Fy = constante * (p.GetY() - GetY());
  double Fz = constante * (p.GetZ() - GetZ());

  CampoVettoriale G(p,Fx,Fy,Fz);
  return G;
}

#endif // __PuntoMateriale_h__
