def min(x, y, z):
    if x < y and x < z:
        return x
    if y < x and y < z:
        return y
    return z

def min_edit_distance(s1, s2):
    m = len(s1)
    l = len(s2)

    dp = [[0] * (l + 1) for _ in range(m + 1)]

    for i in range(m + 1):
        for j in range(l + 1):
            if i == 0:
                dp[i][j] = j
            elif j == 0:
                dp[i][j] = i
            elif s1[i - 1] == s2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]
            else:
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1])

    return dp[m][l]

if __name__ == "__main__":
    fragment_cod = "fnuc(myFuncion"
    cod_corect = "func(myFunction)"

    numar_minim_operatii = min_edit_distance(fragment_cod, cod_corect)
    print(f"Numărul minim de operații necesare: {numar_minim_operatii}")