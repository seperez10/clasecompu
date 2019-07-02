    
#include <iostream>
using namespace std;
int main(){
int x1;
int x2;
cout<<"Introduzca numero 1"<<endl;
cin>>x1;
cout<<"Introduzca numero 2"<<endl;
cin>>x2;

for (int i=x1;i<=x2;i++){
int cont=0;
for (int j=2;j<i;j++){
    if(i%j==0){cont++;}
                 
    }
 if(cont==0 && i%2!=0){cout << i << endl; 
}
}
}