#include<bits/stdc++.h>
using namespace std;
// Creating a Base Structure for Food Items and its Data
struct food_item{
  string name;
  int item_type;
  int manu_date[3];
  int expiry_date[3];
  int period_rem;
  int status;
};
// A Seperate Fucntion for Finding The Expiry Period
int status_val(int period_rem){
  if(period_rem<=0){
    return 0;
  }
  else if(period_rem<=10){
    return 1;
  }
  else if(period_rem<=30){
    return 2;
  }
  else return 3;
}
// Updating the Products Remaining days
int update(){
  int val;
  cout<<"Enter the number of days remaining for the product's expiry : ";
  cin>>val;
  return val;
}
// Main Function
int main(){
  int n;
  cout<<"Enter the number of food products : ";// Entering the number of Food Products
  cin>>n;
  struct food_item items[n]; //Structure Declaration
//Entering the details about the Food item
  for(int i=0;i<n;i++){
    cout<<"Enter the details about the food item "<<i+1<<" : \n";
    cout<<"Enter the food item name : "; // Food item name
    cin>>items[i].name;
    cout<<"Enter the manufacture date of the product : (in the order : date month year)";//food item manufacture date
    cin >> items[i].manu_date[0] >> items[i].manu_date[1] >> items[i].manu_date[2] ;
    cout<<"Enter the expiry date of the product : (in the order : date month year)";
    cin >> items[i].expiry_date[0] >> items[i].expiry_date[1] >> items[i].expiry_date[2] ;//food item expiry date
    cout<<"Enter the number of days remaining for the product to expire : ";
    cin>>items[i].period_rem;
    items[i].status=status_val(items[i].period_rem);
  }
  while(1){
    int choose;
    cout<<"Select the number based on the following option : \n1.Product's detail 2.Exit";
  //To Check the Product Details
    cin>>choose;
//Checking the availabale products in the storage
    if(choose==1){
      cout<<"The products that are available are : \n";
      for(int i=0;i<n;i++){
        cout<<i+1<<" . "<<items[i].name<<endl;
      }
      int index,flag;
      // Displaying the selected items
      cout<<"Select the item number whose details needs to be displayed : ";
      cin>>index;
      //updating the expiry date
      cout<<"Choose 1: if update of the remaining days available for the product's expiry date is required\nElse choose 0:";
      cin>>flag;
      if(flag){
        items[index].period_rem=update();
      }
      // The Current status of the product
      cout<<"The status of the product is : ";
      int ans=items[index].status;
      if(ans==0) cout<<"Item is expired\n";
      else if(ans==1) cout<<"10 days is available until the product gets expired\n";
      else if(ans==2) cout<<"30 days is available until the product gets expired\n";
      else cout<<"More than a month is available until the product gets expired\n";
    }
    else{
      break;
    }
  }
  return 0;
}
