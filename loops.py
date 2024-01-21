import math

u = 0.02
vi = 98
g=9.8
loop=1
d = None
r= None

print("Loop  Init Vel  Final Vel  Circumference  Radius")
for i in range(7):
    d = (0.5*vi**2)/((10/(4*math.pi)+u)*g)
    r = d/(2*math.pi)
    vf = math.sqrt((10*g*d)/(2*math.pi))

    print(str(loop) + "        " + str(round(vi,2)) + "       " + str(round(vf,2)) + "        " + str(round(d,2)) +"       " + str(round(r,2)))
    loop+=1
    vi = vf