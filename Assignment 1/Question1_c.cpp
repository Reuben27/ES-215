// Reuben Devanesan
// 19110059
#include <ctime>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;
using namespace std;

unsigned long long int fibonacci(int n, unsigned long long int memo[], int check[])
{
  if(check[n] == 1)
  {
    return memo[n];
  }
  else
  {
    unsigned long long int fibo = fibonacci(n-1, memo, check) + fibonacci(n-2,memo,check);
    check[n] = 1;
    memo[n] = fibo;
    return fibo;
  }
}

int main()
{
  auto start = Clock::now();
  ios_base::sync_with_stdio(false); 

  int N = 101;
  unsigned long long int memo[N];
  int check[101] = {0};
  check[0] = 1; check[1] = 1;
  memo[0] = 0, memo[1] = 1;
  
  for(int i = 0; i<N; i++)
  {
    cout << i << " " << fibonacci(i, memo, check) << endl; 
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
    myoutfile << "Time taken by Question 1_c program to print first 100 fibonacci numbers: " << time_taken << " * 10^-6 sec \n" ; 
    myoutfile.close();
  }
  return 0;
}