#include <iostream>
#include <iomanip>

void showbalance(double balance);
double deposit(); //儲存
double withdraw(double balance); //提款

int main() {
  double balance = 0;
  int choice = 0;
  do{
    std::cout<<"*******************\n"<<"Enter you choice:\n"<<"*******************\n";
    std::cout<<"1.Show Balance\n";
    std::cout<<"2.Deposit\n";
    std::cout<<"3.Withdraw\n";
    std::cout<<"4.Exit\n";
    std::cin>>choice;

    std::cin.clear();
    fflush(stdin);
    
    switch(choice){
      case 1:
        showbalance(balance);
        break;
      case 2:
        balance=balance+deposit();
        showbalance(balance);
        break;
      case 3:
        balance=balance-withdraw(balance);
        showbalance(balance);
        break;
      case 4:
        std::cout<<"Thanks for visiting!\n";
        break;
      default:
        std::cout<<"Invalid choice.\n"; }
  }while(choice!=4);

  return 0;
}

void showbalance(double balance){
  std::cout<<"Your balance is: $"<<std::setprecision(2)<<std::fixed<<balance<<'\n'; //取道小數點第二位後四捨五入
}
double deposit(){
  double save;
  std::cout<<"Enter amount to be deposited:";
  std::cin>>save;
  if(save<=0){
    std::cout<<"That's not an valid amount!\n";
    return 0;
  }
    return save;
}
double withdraw(double balance){
  double withdraw;
  std::cout<<"Enter amount to be withdraw:";
  std::cin>>withdraw;
  if(withdraw>balance){
    std::cout<<"Insufficient funds.\n";
    return 0;
  }
  else if(withdraw<=0){
    std::cout<<"Invalid amount.\n";
    return 0;
  }
  else{
    return withdraw;
  }
}

