from decimal import *
a,b,c = map(int, input().split())
print(Decimal(a)*Decimal(b)/Decimal(c))
