# Remove commnets on print statements to get results
import numpy as np
A = np.zeros((3,1))
B = np.ones((3,1))

C = np.concatenate((A,B))
Shape = np.shape(C)
#print("The shape of the new array is ",C)
# Question 1 end ---------

#Question 2 start
D = np.array([2,5,33,4,55,6])
E = D.reshape((2,3))
e = E[:,0]
#print(e)

#Question 2 end-------

#Question 3 start
P = np.array([1,3,4,2,4,5])
Q = P.reshape((2,3))
W = np.transpose(Q)

#print(W)

#Question 3 end-------

#Question 4 strat
U = np.array([1,5,66,22,4,0])
Y = U.reshape((2,3))
O = Y.reshape((3,2))

#print(O)
#Question 4 end----

#Question 5 start
F = np.array([33.8,2.4,7.9,88.7,9.9,0])
R = F.reshape((2,3))
G = np.round(R)

#print(G)

#Question 5 end-

#Question 6 Start
Array = np.random.randn(99,1)
stnd_dev = np.std(Array)
min_ = np.min(Array)
max_ = np.max(Array)
Mean = np.mean(Array)

#print ("The Min value is ",min_,"The Max value is ",max_,"The Mean value is ",Mean," The Standard Deviation is ",stnd_dev)
#Question 6 end----

#Question 7 start
arry= np.array([1,4,55,6,77,8,9,33,2])
Arry_1 = arry.reshape((3,3))


arry_2 = np.array([12,2,33,4,55,6,4,1,0])
Array2 = arry_2.reshape((3,3))


Result = np.multiply(Arry_1,Array2)
#print(Result)
#Question 7 end ---

#question 8 start
arrayA = np.array([1,22,3,15,33,5])
Array_A = arrayA.reshape((2,3))

arrayB = np.array([1,44,5,77,8,9,0,1,8,99,4,5])
Array_B = arrayB.reshape((3,4))

Answer = np.matmul(Array_A, Array_B)

#print(Answer)
#Question 8 end ----

#Question 9 start
Number = 1000
infinity = np.Infinity
if (infinity > Number):
    #print(True)
    pass
else:
   # print(False)
   pass
#Question 9 end --

#Question 10 start
New = np.array([[2,3,4],[1,2,3]])
#NewArray = New.reshape((2,3))

second = np.array([[2,3,4],[1,1,1]])
#NextArray = second.reshape((2,3))

NewResult = np.concatenate((New, second))

uni = np.unique(NewResult, axis=0)
print(uni)

#Question 10 end ----
