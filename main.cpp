#include<iostream>


int digits(int cardNumber){
    return (cardNumber%10) + (cardNumber/10);
}

int evenDigits(std::string cardNumber){
    int sum = 0;
    for(int i=cardNumber.size()-2;i>=0;i-=2){
        sum += digits((cardNumber[i] - '0')*2);
    }
    return sum;
}

int oddDigits(std::string cardNumber){
    int sum = 0;
    for(int i=cardNumber.size()-1;i>=0;i-=2){
        sum += (cardNumber[i] - '0');
    }
    return sum;
}
int main(){
    std::cout<<"Enter a credit card number : ";
    std::string cardNumber;
    std::getline(std::cin,cardNumber);
    for(int i = 0; i < cardNumber.size(); i++){
        if(!isdigit(cardNumber[i])){
            std::cout<<"Invalid input! Only digits are allowed.\n";
            return 0;
        }
    }
    if(cardNumber.empty()){
        std::cout<<"Credit card number cannot be empty.\n";
        return 0;
    }
    int even = evenDigits(cardNumber);
    int odd =  oddDigits(cardNumber);
    int result = even +odd;
    if(result%10 == 0){
        std::cout<<"Valid credit card number.\n";
    }
    else{
        std::cout<<"Not a valid credit card number.\n";
    }
    return 0;
}