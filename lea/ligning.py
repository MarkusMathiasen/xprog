import math

a=int(input("Hvad er a? "))
b=int(input("Hvad er b? "))
c=int(input("Hvad er c? "))
d=b*b-4*a*c
if d<0:
	print("Der er ingen løsninger")
if d==0:
	x=-b/(2*a)
	print("x= ",x)
if d>0:
	xa=(-b+math.sqrt(d))/(2*a)
	xb=(-b-math.sqrt(d))/(2*a)
	print("x=",xa,"V x=",xb)
	
