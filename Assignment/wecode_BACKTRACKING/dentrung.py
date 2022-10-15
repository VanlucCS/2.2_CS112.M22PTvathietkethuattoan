s = input()
n = len(s)
a = []
H = 0
while True:
    x = input()
    if x == '.':
        break
    a.append(x)
    H = H+1
C = len(a[0])
Pass = [[False for _ in range(C)] for _ in range(H)]
global flag
flag = False


def ghepchu():
    for i in range(H):
        for j in range(C):
            if a[i][j] == s[0]:
                Pass[i][j] = True
                ghepchunext(Pass, 1, i, j)
                if flag == True:
                    break
                Pass[i][j] = False
            if flag == True:
                break
    if flag == False:
        print('fasle')


def ghepchunext(Pass, i: int, x: int, y: int):
    global flag
    if flag == True:
        return
    for h in [(0, 1), (1, 0), (0, -1), (-1, 0), (1, 1), (-1, 1), (1, -1), (-1, -1)]:
        j, k = x+h[0], y+h[1]
        if j < 0 or j >= H or k < 0 or k >= C:
            continue

        if a[j][k] == s[i] and Pass[j][k] == False:
            Pass[j][k] = True
            if i == n-1:
                flag = True
                print('true')
                return
            if flag == False:
                ghepchunext(Pass, i+1, j, k)
            Pass[j][k] = False


ghepchu()
