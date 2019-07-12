#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
ofstream outfile;
ofstream outfileProm;

int main(){


  double Tprom = 0;
  double tmax100 = 100.0;
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
    
    
    
     while(t < tmax100){
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
    
     ///////////////////////////////////PARA CONDICIONES DE FRONTERA FIJAS 2500/////////////////////////////
    
    outfile.open("Fijas2500.dat");
    outfileProm.open("PromedioFijas.dat");
    
    double tmax2500=2500;
    while(t < tmax2500){
        
        for(i = 1;i<nlado-1;i++){
          for(j = 1;j<nlado-1;j++){
            
            Tpresente[i][j]= miu*dt*(((Tviejo[i+1][j]+Tviejo[i-1][j]-2*Tviejo[i][j])/(dx*dx)) + ((Tviejo[i][j+1]+Tviejo[i][j-1]-2*Tviejo[i][j])/(dx*dx)))+ Tviejo[i][j];
            
            Tviejo[i][j]=Tpresente[i][j];
            
      }
    }
    
    
    t += dt;
  }

double PromedioFi[nlado];
PromedioFi[0]=0;
  for(i=0;i<nlado;i++){
      for(j=0;j<nlado;j++){
        
        outfile << Tpresente[i][j] << " ";
        PromedioFi[i+1] = PromedioFi[i] + (Tpresente[i][j])/(nlado*nlado);
      }
      outfileProm << PromedioFi[nlado-1] << endl;
      outfile << "\n";
    }
    outfileProm.close();
    outfile.close();
    
    
    ///////////////////////////////////PARA CONDICIONES DE FRONTERA ABIERTAS/////////////////////////////
     ///////////////////////////////////PARA CONDICIONES DE FRONTERA ABIERTAS/////////////////////////////
     ///////////////////////////////////PARA CONDICIONES DE FRONTERA ABIERTAS/////////////////////////////
    
    
    double TfuturoA[nlado-2][nlado-2];
    double TviejoA[nlado-2][nlado-2];
    double TpresenteA[nlado-2][nlado-2];
    for(i=1;i<nlado-1;i++){
      for(j=1;j<nlado-1;j++){
          TviejoA[i][j]=50.0;
          TfuturoA[i][j]=50.0;
          TpresenteA[i][j]=TviejoA[i][j];
          if(i>=40 && i<61 && j>20 && j<41){
              TviejoA[i][j]=100.0;
              TfuturoA[i][j]=100.0;
              TpresenteA[i][j]=TviejoA[i][j];
          }
           
      }
     
  }
    
    outfile.open("Abiertas100.dat");
    double t2=0.0;
    while(t2 < tmax100){
        for(int h = 1;h<nlado-1;h++){
          for(int s = 1;s<nlado-1;s++){
              
            TfuturoA[h][s]= miu*dt*(((TviejoA[h+1][s]+TviejoA[h-1][s]-2*TviejoA[h][s])/(dx*dx)) + ((TviejoA[h][s+1]+TviejoA[h][s-1]-2*TviejoA[h][s])/(dx*dx)))+ TviejoA[h][s];
              TviejoA[h][s]=TfuturoA[h][s];
            
            
      }
    }
    t2 += dt;
  }


  for(i=1;i<=nlado-2;i++){
      for(j=1;j<=nlado-2;j++){
          if (i==j && i==0){
              TfuturoA[i][j]= TfuturoA[i+2][j+2];}
          else if(i==0 && j==nlado-2){
              TfuturoA[i][j]= TfuturoA[i+2][j-2];}
          else if(j==0 && i==nlado-2){
              TfuturoA[i][j]= TfuturoA[i-2][j+2];}
          else if(i==nlado-2 && j==nlado-2){
              TfuturoA[i][j]= TfuturoA[i-2][j-2];}
        outfile << TfuturoA[i][j] << " ";
      }
      outfile << "\n";
    } outfile.close();
    
    
    
        outfile.open("Abiertas2500.dat");
    while(t2 < tmax2500){
        for(int h = 1;h<nlado-1;h++){
          for(int s = 1;s<nlado-1;s++){
              
            TfuturoA[h][s]= miu*dt*(((TviejoA[h+1][s]+TviejoA[h-1][s]-2*TviejoA[h][s])/(dx*dx)) + ((TviejoA[h][s+1]+TviejoA[h][s-1]-2*TviejoA[h][s])/(dx*dx)))+ TviejoA[h][s];
              TviejoA[h][s]=TfuturoA[h][s];
            
            
      }
    }
    t2 += dt;
  }


  for(i=1;i<=nlado-2;i++){
      for(j=1;j<=nlado-2;j++){
          if (i==j && i==5){
              TfuturoA[i][j]= TfuturoA[i+2][j+2];}
          else if(i==0 && j>nlado-5){
              TfuturoA[i][j]= TfuturoA[i+2][j-2];}
          else if(j==0 && i>nlado-5){
              TfuturoA[i][j]= TfuturoA[i-2][j+2];}
          else if(i>nlado-5 && j>nlado-5){
              TfuturoA[i][j]= TfuturoA[i-2][j-2];}
        outfile << TfuturoA[i][j] << " ";
      }
      outfile << "\n";
    } outfile.close();
    
    
    
    
    double TfuturoP[nlado][nlado];
    double TviejoP[nlado][nlado];
    double TpresenteP[nlado][nlado];
    for(i=1;i<nlado-1;i++){
      for(j=1;j<nlado-1;j++){
          TviejoP[i][j]=50.0;
          TfuturoP[i][j]=50.0;
          TpresenteP[i][j]=TviejoP[i][j];
          if(i>=40 && i<61 && j>20 && j<41){
              TviejoP[i][j]=100.0;
              TfuturoP[i][j]=100.0;
              TpresenteP[i][j]=TviejoP[i][j];
          }
           
      }
     
  }
    
        outfile.open("Periodicas100.dat");
    double t3=0.0;
    while(t3 < tmax100){
        for(int p = 1;p<nlado-1;p++){
          for(int m = 1;m<nlado-1;m++){
              
            TfuturoP[p][m]= miu*dt*(((TviejoP[p+1][m]+TviejoP[p-1][m]-2*TviejoP[p][m])/(dx*dx)) + ((TviejoP[p][m+1]+TviejoP[p][m-1]-2*TviejoP[p][m])/(dx*dx)))+ TviejoP[p][m];
              TviejoP[p][m]=TfuturoP[p][m];
            
            
      }
    }
    t3 += dt;
  }


  for(i=0;i<=nlado-1;i++){
      for(j=0;j<=nlado-1;j++){
          if(i==0){
              TfuturoP[i][j]=TfuturoP[nlado-2][j];}
          if(j==0){
              TfuturoP[i][j]=TfuturoP[i][nlado-2];}
          if(i==nlado-1){
              TfuturoP[i][j]=TfuturoP[2][j];}
          if(j==nlado-1){
              TfuturoP[i][j]=TfuturoP[i][2];}
        outfile << TfuturoP[i][j] << " ";
      }
      outfile << "\n";
    } outfile.close();
    
    
    
    
    
     outfile.open("Periodicas2500.dat");
    while(t3 < tmax2500){
        for(int p = 1;p<nlado-1;p++){
          for(int m = 1;m<nlado-1;m++){
              
            TfuturoP[p][m]= miu*dt*(((TviejoP[p+1][m]+TviejoP[p-1][m]-2*TviejoP[p][m])/(dx*dx)) + ((TviejoP[p][m+1]+TviejoP[p][m-1]-2*TviejoP[p][m])/(dx*dx)))+ TviejoP[p][m];
              TviejoP[p][m]=TfuturoP[p][m];
            
            
      }
    }
    t3 += dt;
  }


  for(i=0;i<=nlado-1;i++){
      for(j=0;j<=nlado-1;j++){
          if(i==0){
              TfuturoP[i][j]=TfuturoP[nlado-2][j];}
          if(j==0){
              TfuturoP[i][j]=TfuturoP[i][nlado-2];}
          if(i==nlado-1){
              TfuturoP[i][j]=TfuturoP[1][j];}
          if(j==nlado-1){
              TfuturoP[i][j]=TfuturoP[i][1];}
        outfile << TfuturoP[i][j] << " ";
      }
      outfile << "\n";
    } outfile.close();
    
    
 
    
    return 0;
}