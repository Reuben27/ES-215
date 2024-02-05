// Reuben Devanesan
// 19110059
#include <ctime>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;
using namespace std;

int main()
{
  auto start = Clock::now();
  ios_base::sync_with_stdio(false); 

  unsigned long long int a = 0;
  unsigned long long int b = 1;
  for(int i = 0; i <= 100; i++)
  {
    if(i == 0 || i == 1)
    {
      cout << i << " " << i << endl;;
    }
    else
    {
      unsigned long long int temp = b;
      cout << i << " " << a + b << endl;
      b = a + b;
      a = temp;
    }
  }
  
  auto end = Clock::now();
  auto time_taken = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
  cout << "Time taken by program is : " << time_taken << " * 10^-6 sec " << endl; 

  string line, text;
  ifstream myfile("Outputs_1.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile, line) )
    {
      text += line + "\n";
    }
    myfile.close();
  }

  ofstream myoutfile ("Outputs_1.txt");
  if (myoutfile.is_open())
  {
    myoutfile << text;
    myoutfile << "Time taken by Question 1_b program to print first 100 fibonacci numbers: " << time_taken << " * 10^-6 sec \n" ; 
    myoutfile.close();
  }
  return 0;
}