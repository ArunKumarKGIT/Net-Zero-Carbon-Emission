#include<bits/stdc++.h>
using namespace std;

struct sensors{
  int total_vol;
  int carbon_vol;
};

int main(){
  int n,total=0,car=0;
  cout<<"Enter the number of outlets where sensors have been placed to measure the carbon footprint (in ppm): ";
  cin>>n;
  struct sensors num[n];
  for(int i=0;i<n;i++){
    cout<<"Enter the readings for outlet "<< i+1 <<" : \n";
    cout<<"Total amount of gas : ";
    cin>>num[i].total_vol;
    cout<<"Total amount of carbon : ";
    cin>>num[i].carbon_vol;
    total+=num[i].total_vol;
    car+=num[i].carbon_vol;
  }
  cout<<"The ratio of the amount of carbon to the total gas that is being emitted is given by -> " << car <<":"<<total; 
  return 0;
}
