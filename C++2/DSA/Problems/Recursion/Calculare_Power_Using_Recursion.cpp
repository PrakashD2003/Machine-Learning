//Calculate A to the power B
//  for B=even A^B = A^(b/2) * A^(b/2)
//      B=odd  A^b = A * A^(b/2) * A^(b/2) 
#include<iostream>

using namespace std;

int power(int a,int b)
{
    //Base Case
    if (b==0)  return 1;
    if (b==1) return a;
    
     int anw = power(a,b/2);
    if (b%2==0)
    {
    //if b is even
    return anw*anw;   
    }
    else{
    //if b is odd
        return a*anw*anw;
    }
    
    
}
int main()

{
cout<<power(2,5);

return 0;
}