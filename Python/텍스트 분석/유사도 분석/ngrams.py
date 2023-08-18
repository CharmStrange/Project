def N_Grams(s, num) :
    res = []
    slen = len(s) - num + 1
    for i in range(slen) :
        ss = s[i:i+num]
        res.append(ss)
    return res
    
def diff_N_Grams(sa, sb, num) :
    a = N_Grams(sa, num)
    b = N_Grams(sb, num)
    r = []
    cnt = 0
    for i in a :
        for j in b :
            if (i == j) : cnt += 1
            r.append(i)
    return cnt / len(a), r
