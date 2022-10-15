import numpy as np

def inputGraph(G,v, e):
    for i in range(0,e):
        x,y = [int(x) for x in input().split()]
        G[x - 1][y - 1] = 1

def process(G,v,n):
    for i in range(0,n):
        g = input().split()
        y = 0
        z = 0
        if g[0] == "1":
            x,y,z = [int(x) for x in g]
            if G[y - 1][z - 1] == 1:
                print("TRUE\n")
            else:
                print("FALSE\n")
        else:
            flag = 0
            z,y = [int(x) for x in g]
            for i in range(0,v):
                if G[y - 1][i] == 1:
                    flag = 1
                    print(i+1,end=" ")
            if flag != 0:
                print("\n")
            if flag == 0:
                print("NONE\n")
def main():
    v,e,n = [int(x) for x in input().split()]
    G = np.zeros((v,v))
    inputGraph(G,v,e)
    process(G,v,n)
if __name__ == '__main__':
    main()