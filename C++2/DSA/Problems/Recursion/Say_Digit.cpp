// Q.Convert the number to digit 
//   Ex- 412 = four one two

/*Solve- for getting each digit of a number we will calculate modulus of number with 10 till we get zero
EX- 412%10 = 2(first digit) 
    Now number is quiteint of 412/10 = 41
EX- 41%10 = 1(second digit)
    41/10 = 4
EX- 4%10 = 4(third digit)
Base case = if number = 0 stop 
we will continue this process till number becomes 0.*/

#include<iostream>

using namespace std;

void say_digit(int number){
    //Base Case
    if (number == 0)
    {
        return;
    }
    string array[10] ={"zero","one","two","three","four","five","six","seven","eight","nine"};
    int digit = number%10;
    say_digit(number/10);
    cout<<array[digit]<<" ";
}
int main()

{
int number = 412;
say_digit(number);

return 0;
}