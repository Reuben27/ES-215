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

  int N = 100;
  vector<unsigned long long int> memo;
  memo.push_back(0);
  memo.push_back(1);

  cout<< 0 << " " << memo[0] << endl;
  cout<< 1 << " " << memo[1] << endl;
  for(int i = 2; i <= N; i++){
    memo.push_back(memo[i-1] + memo[i-2]);
    cout << i << " " << memo[i] << endl;
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
    myoutfile << "Time taken by Question 1_d program to print first 100 fibonacci numbers: " << time_taken << " * 10^-6 sec \n" ; 
    myoutfile.close();
  }
  return 0;
}