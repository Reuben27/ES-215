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
  auto start_overall = Clock::now();
  ios_base::sync_with_stdio(false);

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
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      for(int k = 0; k < N; k++)
      {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  auto end = Clock::now();
  auto end_overall = Clock::now();
  auto time_taken_meat = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
  auto time_taken_overall = std::chrono::duration_cast<std::chrono::microseconds>(end_overall - start_overall).count();
  cout << "Time taken by meat program is : " << time_taken_meat << " * microseconds " << endl;
  cout << "Time taken by overall program is : " << time_taken_overall << " * microseconds " << endl;  

  string line, text;
  ifstream myfile("Outputs_2_overall.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile, line) )
    {
      text += line + "\n";
    }
    myfile.close();
  }

  ofstream myoutfile ("Outputs_2_overall.txt");
  if (myoutfile.is_open())
  {
    myoutfile << text;
    myoutfile << "Time taken by Question 2 (int) cpp meat portion of program for N = " << N << ": " << time_taken_meat << " microseconds \n" ; 
    myoutfile << "Time taken by Question 2 (int) cpp overall program for N = " << N << ": " << time_taken_overall << " microseconds \n" ; 
    myoutfile.close();
  }
  return 0;
}