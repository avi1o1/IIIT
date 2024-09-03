T = int(input())

while T:
    N, M, S, X = map(int, input().split())

    dfa = {}
    for _ in range(M):
        u, v = map(int, input().split())
        dfa[u] = v

    cycleAt = cycleLen = 0
    visited = [-1] * (N+1)
    tmp = S
    for x in range(N+1):
        if visited[tmp] >= 0:
            cycleAt = tmp
            cycleLen = x - visited[tmp]
            break

        visited[tmp] = x
        tmp = dfa[tmp]

    cnt = [0] * (N+1)
    for _ in range(N):
        if S == cycleAt:
            break
        cnt[S] += 1
        S = dfa[S]
        visited[S] = 0
        X -= 1
    
    tmp = X // cycleLen
    cnt[S] += tmp
    S = dfa[S]
    while S != cycleAt:
        cnt[S] += tmp
        S = dfa[S]
    
    X %= cycleLen
    for _ in range(X):
        cnt[S] += 1
        S = dfa[S]

    print(" ".join(map(str, cnt[1:])))
    T -= 1
