for(int i = 1; i <= n; i++) suf[i] = i, pos[i] = S[i];
    for(int k = 1; k <= n; k <<= 1) {
        auto chk = [&](int a, int b) {
            if(pos[a] != pos[b]) return pos[a] < pos[b];
            if(a + k <= n && b + k <= n) return pos[a + k] < pos[b + k];
            else return a > b;
        };
        sort(suf + 1, suf + n + 1, chk);
        int tmp[N]; tmp[1] = 1;
        for(int i = 1; i < n; i++) tmp[i + 1] = tmp[i] + chk(suf[i], suf[i + 1]);
        for(int i = 1; i <= n; i++) pos[suf[i]] = tmp[i];
    }
    for(int i = 1, k = 0; i <= n; i++) if(pos[i] != n) {
        for(int j = suf[pos[i] + 1]; S[i + k] == S[j + k]; k++);
        lcp[pos[i]] = k;
        if(k) --k;
    }