import random
import timeit

N = 512
A = [[0]*N]*N
for i in range(N):
  for j in range(N):
    A[i][j] = random.randint(1,100)

B = [[0]*N]*N
for m in range(N):
  for n in range(N):
    B[m][n] = random.randint(1,100)

C = [[0]*N]*N

start = timeit.default_timer()
for p in range(N):
  for q in range(N):
    for r in range(N):
      C[p][q] = A[p][r]*B[r][q]
end = timeit.default_timer()
    
time_taken = end -  start
print('Time taken by program is: ', time_taken)  
file = open("Outputs_2.txt","a+")
file.write("Time taken by Question 2 (int) python program for N = 512: " + str(time_taken) + " seconds \n")
file.close()