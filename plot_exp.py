import numpy as np
import matplotlib.pylab as plt

def modulo(A):
    n=len(A)
    A1=np.zeros(n)
    for i in range(n):
        x=A[i]
        if(x>np.pi):
            while(x>np.pi):
                x=x-np.pi
        if(x<np.pi):
            while(x<-np.pi):
                x=x+np.pi
        A1[i]=x
    return A1

A=np.loadtxt('datos1.dat',usecols=0)
B=np.loadtxt('datos1.dat',usecols=1)
A1=modulo(A)
B1=modulo(B)
t=np.arange(1,len(A)+1)/10
plt.figure()
plt.plot(t,np.log(np.abs(A1-B1)),color='green',label='Simulation')
plt.legend()
plt.grid()
plt.savefig('Lyapunov1.png')

A=np.loadtxt('datos2.dat',usecols=0)
B=np.loadtxt('datos2.dat',usecols=1)
A1=modulo(A)
B1=modulo(B)
t=np.arange(1,len(A)+1)/10
plt.figure()
plt.plot(t,np.log(np.abs(A1-B1)),color='red',label='Simulation')
plt.legend()
plt.grid()
plt.savefig('Lyapunov2.png')