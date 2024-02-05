// Reuben Devanesan
// 19110059
#include <ctime>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;
using namespace std;

unsigned long long int fibonacci(int n)
{
  if(n <= 1)
  {
    return n;
  }
  else
  {
    return fibonacci(n-1) + fibonacci(n-2);
  }
}

int main()
{
  auto start = Clock::now();
  ios_base::sync_with_stdio(false); 

  for(int i = 0; i <= 100; i++)
  {
    cout << i << " " << fibonacci(i) << endl;
  }

  auto end = Clock::now();
  auto time_taken = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
  cout << "Time taken by program is : " << time_taken << " * milliseconds " << endl; 

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
    myoutfile << "Time taken by Question 1_a program to print first 100 fibonacci numbers: " << time_taken << " milliseconds \n" ; 
    myoutfile.close();
  }
  return 0;
}