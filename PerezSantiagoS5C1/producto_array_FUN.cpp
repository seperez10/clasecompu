#include <iostream>
using namespace std;

int producto(int arr1[],int arr2[]){
    int Arrn[5];
    int *p;
    p= Arrn;
    for(int i=0; i<5; i++){
        Arrn[i]=arr1[i]*arr2[i];
    cout << *p <<endl;
    *p++;}
    return 0;
}

int productopunto(int arr1[], int arr2[]){
   int propun=0;
   int lista[5];
   
    for(int i=0; i<5; i++){
        lista[i]= arr1[i]*arr2[i];
        propun = propun + lista[i];
    }cout << propun << endl;}
        


int main(){
   int Arr1[]={1,2,3,4,5};
   int Arr2[]={10,20,30,40,50};
   //cout << Arr1<<endl;
   producto(Arr1,Arr2);
   productopunto(Arr1,Arr2);
   return 0;
}


