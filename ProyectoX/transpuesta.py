# coding=utf-8
# @faustinoaq, 2016

print("Matriz transpuesta")
m = int(input("Tamaño M: "))
n = int(input("Tamaño N: "))

matriz = [list(range(0,m)) for j in range(m)]
tran = [list(range(0,n)) for j in range(n)]

for i in range(m):
    for j in range(n):
        el = int(input("(%i,%i): " % (i,j)))
        matriz[i][j] = el
    print()

for i in range(m):
    for j in range(n):
        tran[j][i] = matriz[i][j]

for r in matriz:
    print(r)
print()
for r in tran:
    print(r)
