
def verify_ham_cycle(G, cert):
    if (G == [[0]] and cert == [0,0]) or (G == [[1]] and cert == [0,0]):
        return True
    
    if len(set(cert[0:len(cert)-1])) != len(cert[0:len(cert)-1]) or cert[0]!=cert[-1]:
        return False

    for i in range(len(cert)-1):
        if(G[cert[i]][cert[i+1]] == 0):
            return False

    return True

G = [[0, 1, 1, 1], [1, 0, 0, 1], [1, 0, 0, 1], [1, 1, 1, 0]]
cert = [1, 2, 0, 3, 1]
print(verify_ham_cycle(G,cert))