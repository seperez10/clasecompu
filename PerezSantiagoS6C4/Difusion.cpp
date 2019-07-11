#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
ofstream outfile;

int main(){


  double Tprom = 0;
  double tmax = 100.0;
    double dx = 0.01;
  double miu = 1e-4;
  double dt = (dx*dx)*0.05/miu;
  double t = 0.0;
  
  int nlado = 100;
  double Tviejo[nlado][nlado];
  double Tfuturo[nlado][nlado];
  double Tpresente[nlado][nlado];
  int i, j;
 outfile.open("iniciales.dat");
    
  for(i=0;i<nlado;i++){
      for(j=0;j<nlado;j++){
          Tviejo[i][j]=50.0;
          Tfuturo[i][j]=50.0;
          Tpresente[i][j]=Tviejo[i][j];
          if(i>=40 && i<=60 && j>=20 && j<=40){
              Tviejo[i][j]=100.0;
              Tfuturo[i][j]=100.0;
              Tpresente[i][j]=Tviejo[i][j];
              
          }
           
      }
     
  }
      for(i=0;i<nlado;i++){
          for(j=0;j<nlado;j++){
            outfile << Tfuturo[i][j] << " ";
      }
      outfile << "\n";
    } outfile.close();

    
    
    outfile.open("Fijas100.dat");
    
    
    
     while(t < tmax){
        for(i = 1;i<nlado-1;i++){
          for(j = 1;j<nlado-1;j++){
            
            Tpresente[i][j]= miu*dt*(((Tviejo[i+1][j]+Tviejo[i-1][j]-2*Tviejo[i][j])/(dx*dx)) + ((Tviejo[i][j+1]+Tviejo[i][j-1]-2*Tviejo[i][j])/(dx*dx)))+ Tviejo[i][j];
            
            Tviejo[i][j]=Tpresente[i][j];
      }
    }
    t += dt;
  }


  for(i=0;i<nlado;i++){
      for(j=0;j<nlado;j++){
        outfile << Tpresente[i][j] << " ";
      }
      outfile << "\n";
    } outfile.close();
 
    
    
    
    return 0;
}