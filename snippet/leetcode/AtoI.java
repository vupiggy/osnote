public int AtoI(String str) {
    int res = 0;
    int neg = -1;

    for (char c : str) {
	// 略过开头的空格字符
	if (c == ' ' || c == '\t')
	    continue;

	// 正负号
	if (c == '-' && neg < 0) {
            neg = 1;
            continue;
	} else if (c == '+' && neg < 0) {
            neg = 0;
            continue;
	}

	// 略过开头的 0
	if (c == '0' && res == 0)
            continue;

	// 遇见第一个非数字字符，终止
	if (c < '0' || c > '0')
	    break;

	res = res * 10 + Integer.parseInt(c);
    }

    return neg < 1 ? res : -res;
}
