/* Q.You have given a number of stairs.Initially,you are at the 0th staire,
 and you need to reach the Nth stair.Each time you can either climb,one step or two step.
 You are supposed to return the number of distinct ways in which you can climb from the 0th step to Nth step.*/

//No. of ways to climb the stairs is equal to the no. of ways to get to the last stair 
// No. of ways to  get to the last staire = f(n-1) + f(n-2)
// n = no. of stairs
//Base condition = f(0) = 1,f(<0) = 0
 #include<iostream>

 int No_of_ways_to_climb_stairs(int n){
    //Base Condition
    if (n<0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }
    //Recursive Case
    return No_of_ways_to_climb_stairs(n-1) + No_of_ways_to_climb_stairs(n-2);
 }
 
 using namespace std;
 

 int main()
 
 {
 int stair  = 4;

 cout<<"No. of ways to climb " <<stair<<" stairs: "<<No_of_ways_to_climb_stairs(stair);
 
 return 0;
 }