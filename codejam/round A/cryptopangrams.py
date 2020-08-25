

def GCD(a, b):
    if(a%b == 0):
        return b
    return GCD(b, a%b)

t = int(input())
res = list()
for x in range(t):
    n, l = [int(x) for x in input().split()]
    arr = list(map(int, input().split()))
    primes = list()
    j = -1
    for i in range(len(arr)+1):
        gcd = GCD(arr[i], arr[i+1])
        if gcd != 1:
            primes.append(gcd)
            j = i
            break
    pup = primes[0]
    pdowm = primes[0]
    k = j-1
    while(k >= 0 and j < len(arr)):
        npup = arr[j] / pup
        primes.append(pup)
        j+=1
        pup = npup
        npdown = arr[k] / pdown
        primes.append(npdown)
        k-=1
        pdown = npdown
    
    while(k>=0):
        npdown = arr[k] / pdown
        primes.append(npdown)
        k-=1
        pdown = npdown
    
    while(j < len(arr)):
        npup = arr[j] / pup
        primes.append(pup)
        j+=1
        pup = npup
    
    primes.sort()

    ans = ""
    first = arr[0]
    fletter = ""
    sletter = ""
    pr = 0
    for i in range(len(primes)):
        if(GCD(first, primes[i]) == primes[i]):
            if(arr[i] % primes[i] == 0):
                fletter = chr(ord('A') + primes.index(first / primes[i]))
                sletter = chr(ord('A') + i)
                pr = primes[i]
            else:
                fletter = chr(ord('A') + i)
                sletter = chr(ord('A') + primes.index(first/primes[i]))
                pr = first/primes[i]

    ans += fletter
    ans += sletter
    for i in range(1, len(arr)):
        ans += chr(ord('A') + primes.index(arr[i]/pr))
        pr = arr[i]/pr
    
    res.append(ans)

for i in range(t):
    out = "Case #" + i+1 + ": " + res[i]
    print(out)



