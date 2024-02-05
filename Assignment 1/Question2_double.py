import cProfile
import random
import timeit
import time

profiler = cProfile.Profile()
profiler.enable()
start_overall_system = timeit.default_timer()
time_process_start = time.time()

N = 512
A = [[0]*N]*N
for i in range(N):
  for j in range(N):
    A[i][j] = random.uniform(1,100)

B = [[0]*N]*N
for m in range(N):
  for n in range(N):
    B[m][n] = random.uniform(1,100)

C = [[0]*N]*N

start_meat_system = timeit.default_timer()
for p in range(N):
  for q in range(N):
    for r in range(N):
      C[p][q] = A[p][r]*B[r][q]
end_meat_system = timeit.default_timer()
end_overall_system = timeit.default_timer()

time_taken_meat = end_meat_system -  start_meat_system
time_taken_overall = end_overall_system -  start_overall_system
time_process = time.process_time()
profiler.disable()
profiler.print_stats()

print('Time taken by meat portion of the program is: ', time_taken_meat)  
print('Time taken by overall program is: ', time_taken_overall)  
print('Process time taken by overall program is: ', time_process) 

file = open("Assignment 1\Outputs_2_double_python.txt","a+")
file.write("Time taken by Question 2 (int) meat portion of program for N = " + str(N) + ": " + str(time_taken_meat) + " seconds \n")
file.write("Time taken by Question 2 (int) overall python program for N = " + str(N) + ": " + str(time_taken_overall) + " seconds \n")
file.write("Process time taken by Question 2 (int) python program for N = " + str(N) + ": " +str(time_process) + " seconds \n")
# profiler.dump_stats("Assignment 1\Outputs_2.txt")
file.close()