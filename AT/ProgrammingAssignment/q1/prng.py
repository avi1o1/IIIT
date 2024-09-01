T = int(input())

while T:
    N, M, S, X = map(int, input().split())

    dfa = [[] for _ in range(N+1)]
    for _ in range(M):
        u, v = map(int, input().split())
        dfa[u].append(v)
    
    cnt = [0] * (N+1)
    for _ in range(X):
        cnt[S] += 1
        S = dfa[S][0]

    print(" ".join(map(str, cnt[1:])))
    T -= 1
