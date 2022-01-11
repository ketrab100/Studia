import matplotlib.pyplot as plt

xsa = [6,10,12,13,14,15,17,21,22,39,43,70,101,127,152,198,323]
ysa = [4.15,4.24,4.71,4.9,4.63,4.81,4.78,5.08,5.36,6.29,6.58,8.08,9.38,10.4,24.6,13,19.9]
xbf = [6,10,12,13,14,15]
ybf = [0.0000026,0.00584,0.851,10.6,134,1990]
xhk = [6,10,12,13,14,15,17,21,24]
yhk = [0.0000062,0.000177,0.000776,0.00167,0.00358,0.00885,0.0407,1.05,8.95]
xbb = [6,10,12,13,14,15,17,21]
ybb = [0.0000094,0.000433,0.00201,0.00504,0.0257,0.0159,12.7,9.55]


plt.plot(xsa,ysa,'o-', linestyle = 'dotted' ,color='green',label='SA')
plt.plot(xhk,yhk,'o-', linestyle = 'dotted' ,color='blue',label='Held-Karp')
plt.plot(xbf,ybf,'o-', linestyle = 'dotted' ,color='red',label='Brute force')
plt.plot(xbb,ybb,'o-', linestyle = 'dotted' ,color='orange',label='B&B')

plt.ylim(-0.5,25)
plt.xticks((6,10,14,22,39,43,70,101,127,152,198,323),('6','10','14','22','39','43','70','101','127','152','198','323'))
plt.ylabel('Czas[s]', fontsize=13)
plt.xlabel('Wielkosc instancji', fontsize=13)
plt.legend(loc = 'best')




plt.show()