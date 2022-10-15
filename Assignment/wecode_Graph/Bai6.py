import numpy as np

def inputGraph(G, v, e, ax, ay):
    k = input().split()
    for i in range(0, v):
        ax [k[i]] = i
        ay [i] = k[i]

    for i in range(0, e):
        x, y = [x for x in input().split()]
        G[ax[x]][ax[y]] = 1


def process(G, v, n, ax, ay):
    for i in range(0, n):
        g = input().split()
        y = 0
        z = 0
        if g[0] == "1":
            x, y, z = [x for x in g]
            if G[ax[y]][ax[z]] == 1:
                print("TRUE\n")
            else:
                print("FALSE\n")
        else:
            flag = 0
            z, y = [x for x in g]
            for i in range(0, v):
                if G[ax[y]][i] == 1:
                    flag = 1
                    print(ay[i],end=" ")
            if flag != 0:
                print("\n")
            if flag == 0:
                print("NONE\n")


def main():
    v, e, n = [int(x) for x in input().split()]
    G = np.zeros((v, v))
    ax = {}
    ay = {}
    inputGraph(G, v, e, ax, ay)
    process(G, v, n, ax, ay)

if __name__ == '__main__':
    main()
