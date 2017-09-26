# coding=utf-8
# @faustinoaq, 2016

print("Triangulo")
a = int(input("a: "))
b = int(input("b: "))
c = int(input("c: "))

if ((a + b) > c) and\
   ((a + c) > b) and ((b + c) > a):
   s = 0.5*(a + b + c)
   area = (s*(s-a)*(s-b)*(s-c))**0.5
   print("Area: %f" % area)
else:
    print("No es un triangulo")
