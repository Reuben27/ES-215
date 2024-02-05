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
  // Initialization
  int N = 512;
  static int a[512][512], b[512][512], c[512][512];

  for(int i = 0; i<N; i++){
    for(int j = 0; j<N; j++){
      a[i][j] = (int)rand() / 100;
      b[i][j] = (int)rand() / 100;
    }
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++)
    {
      c[i][j]=0;
    }
  }

  auto start = Clock::now();
  ios_base::sync_with_stdio(false); 
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      for(int k = 0; k < N; k++)
      {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  auto end = Clock::now();
  auto time_taken = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
  cout << "Time taken by program is : " << time_taken << " * microseconds " << endl; 

  string line, text;
  ifstream myfile("Outputs_2.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile, line) )
    {
      text += line + "\n";
    }
    myfile.close();
  }

  ofstream myoutfile ("Outputs_2.txt");
  if (myoutfile.is_open())
  {
    myoutfile << text;
    myoutfile << "Time taken by Question 2 (int) cpp program for N = 512: " << time_taken << " microseconds \n" ; 
    myoutfile.close();
  }
  return 0;
}