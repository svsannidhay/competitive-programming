#problem statement:- https://www.codechef.com/BIT22019/problems/MATHL
# PARTIALLY SOLVED  TLE IN SUBTASK 2

#Needed a better DP approach

#tags - easy-medium
#PYTHON 
from sys import stdin, stdout  
#t = int(input())
 
import math  
a = [0]
#for i in range(1,7000):
    #x = math.factorial(i)
    #x = x%1000000007
    #a.append(x)
factorial = 1;
for i in range(1,5000000):
    factorial = factorial * i;
    factorial = factorial % 1000000007
    a.append(factorial)

   
        
t = int(stdin.readline()) 
for i in range(0,t):
    #n = int(input())
    n = int(stdin.readline()) 
    product = 1
    #k = n-1;
    for i in range(1,n+1):
        #product = product * power(i,k)
        #k = k-1
        #product = product%1000000007
        product = product * a[i];
        product = product%1000000007
        
    stdout.write(str(product))
    stdout.write("\n")
