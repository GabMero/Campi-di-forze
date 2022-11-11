#include "CampoVettoriale.h"
#include "PuntoMateriale.h"

#include "TH1F.h"
#include "TApplication.h"
#include "TGraph.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TMultiGraph.h"
#include "TStyle.h"

#include <iostream>
#include <cstdlib>
#include <cmath>

#define N 900

using namespace std;

double funzione(double, PuntoMateriale, PuntoMateriale);

int main (int argc, char** argv) { // esempio di main.cpp per verificare la funzionalità delle classi CampoVettoriale & PuntoMateriale

  if(argc < 4) {
        cerr << "Using Program ./" << argv[0] << " <x> <y> <z> " << endl;
        exit(-1);
  }

  double x = atof(argv[1]);
  double y = atof(argv[2]);
  double z = atof(argv[3]);

  Posizione r(x,y,z);
  

  const double e  = 1.60217653E-19;
  const double me = 9.1093826E-31;
  const double mp = 1.67262171E-27;
  const double d  = 1.E-10;

  PuntoMateriale elettrone (me, -e, 0., 0., 0+d/2.);
  PuntoMateriale protone (me, e, 0., 0., 0-d/2.);

  CampoVettoriale C_el=elettrone.CampoElettrico(r);
  CampoVettoriale C_pr=protone.CampoElettrico(r);

  CampoVettoriale E =C_el+C_pr; // sommate nella Posizione r il contributo del CampoElettrico di elettrone e protone

  // Stampate su termianle le tre componenti del CampoVettoriale risultante nella Posizione r
  cout<<"Campo in r(elettrone)"<<endl<<"x: "<<C_el.getFx()<<endl<<"y: "<<C_el.getFy()<<endl<<"z: "<<C_el.getFz()<<endl;
  cout<<"Campo in r(protone)"<<endl<<"x: "<<C_pr.getFx()<<endl<<"y: "<<C_pr.getFy()<<endl<<"z: "<<C_pr.getFz()<<endl;
  cout<<"Campo in r"<<endl<<"x: "<<E.getFx()<<endl<<"y: "<<E.getFy()<<endl<<"z: "<<E.getFz()<<endl;

  TApplication Myapp("app",0,0);
  
  TCanvas mycanvas("grafico 1","Campo in funzione della distanza");

  double *p1_x=new double[N];
  double *p1_y=new double[N];
  double *p2_x=new double[N];
  double *p2_y=new double[N];
  int a=0;
  int b=0;

  for(int i=1000; i>100; i--){
    p1_x[a]=-i*d;
    p1_y[a]=funzione(-i*d,protone,elettrone);
    //cout<<p1_x[a]<<" "<<p1_y[a]<<endl;
    a++;
  }

  for(int i=100; i<1000; i++){
    p2_x[b]=i*d;
    p2_y[b]=funzione(i*d,protone,elettrone);
    //cout<<p2_x[b]<<" "<<p2_y[b]<<endl;
    b++;
  }
  
  


  auto gr1=new TGraph (N,p1_x,p1_y);
  auto gr2=new TGraph (N,p2_x,p2_y);
 
  
  TMultiGraph *mg = new TMultiGraph();
//  mg->Add(gr1);
  mg->Add(gr2);
  mg->SetTitle("Campo elettrico in funzione della distanza sull'asse z");
  mg->GetXaxis()->SetTitle("Distanza");
  mg->GetYaxis()->SetTitle("Campo elettrico");
  

  mg->Draw("ALP");
  
  

  Myapp.Run();

  return 0;
}

double funzione(double z, PuntoMateriale protone, PuntoMateriale elettrone){

  CampoVettoriale Comp_el=elettrone.CampoElettrico(0,0,z);
  CampoVettoriale Comp_pr=protone.CampoElettrico(0,0,z);
  CampoVettoriale El =Comp_el+Comp_pr;
  return El.getFz();
}