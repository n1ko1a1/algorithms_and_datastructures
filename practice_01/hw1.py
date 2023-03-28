n = int(input("Введите число n \n"))
a = [True] * n
i = 2
j = i ** 2

for i in range(2, n - 1):
    if i ** 2 >= n:
        break
    if a[i]:
        for j in range(i ** 2, n - 1, i):
            a[j] = False

print('Простые числа: ')
for i in range(2, n - 1):
    if a[i]:
        print(i)
