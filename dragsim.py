import math
import numpy as np

u=0.02
g=9.8
r=[95.6, 93.25, 90,97, 88.74, 86.56, 84.44, 82.37]
dt=0.1
cdpa=0.30699 #drag coeffecient*rho*area

#square of velocity returned
def getVel(r, start, stop):
    out=[]
    for t in np.arange(start, stop, dt):
        v=((r/10) - 0.9*r*math.cos(t))**2 + ((r*math.sin(t))**2)*(1-((t-6)/7))
        gf=round(v/g, 2)
        out.append(gf)
    return out

def gloop(r, start, stop):
    out=[]

    vels = getVel(r, start, stop)
    count = 0
    for t in np.arange(start, stop, dt):
        a=r*(math.sqrt(0.81*(math.sin(t))**2+(math.cos(t))**2)) - u*g*((1-9*(math.cos(t)))/(10*(math.sin(t)))) - (1/1000)*cdpa*vels[0]
        gf=round(a/g, 2)
        out.append(gf)
        count +=1
    avg = sum(out)/(len(out)-2)
    print(out)
    return round(avg,2)

def allLoops():
    gs=[]
    for i in r:
        gs.append(gloop(i, 3, 10))
        print(gloop(i, 3, 10))
    avg = sum(gs)/len(gs)
    return round(avg, 3)

print("Averaging " + str(allLoops()) + " pulled through all of the loops")