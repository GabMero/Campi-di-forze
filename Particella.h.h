#ifndef __Particella_h__
#define __Particella_h__

#include <string>
#include <iostream>
using namespace std;


/***********************************************************
 * Classe astratta per una generica particella
 * definisce i metodi che ogni particella 
 * deve implementare e delle funzioni di utilizzo generale.
 ***********************************************************/

class Particella {

public:

  // costruttori
	Particella();
	Particella(double massa, double carica);

  // distruttore
  ~Particella();

  // metodi
  double GetMassa() const {return m_massa;};
	double GetCarica()const {return m_carica;};
	void Print() const;

 	protected:
	double m_massa;
	double m_carica;

};

Particella::Particella(double massa,double carica){
	m_massa=massa;
	m_carica=carica;
}

Particella::~Particella(){}

void Particella::Print() const {
	cout<<"Particella: m="<<m_massa<<", q="<<m_carica<<endl;
}


/*********************************************************
 * Implementazione concreta di una particella elementare
 * in questo caso tutte le proprietà della particella 
 * sono costanti, definite nel costruttore di default.
 ***********************************************************/

class Elettrone : public Particella {
	public:
	Elettrone();
	~Elettrone();

	void Print() const;
};

Elettrone::Elettrone(): Particella(9.1093826E-31, -1.60217653E-19){}

Elettrone::~Elettrone(){}

void Elettrone::Print() const{
	cout<<"Elettrone: m="<<m_massa<<", q="<<m_carica<<endl;
}

#endif //__Particella_h__
