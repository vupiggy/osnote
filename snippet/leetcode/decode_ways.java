public int numDecodings(String s) {
	if(s == null || s.length() == 0 ||
	   s.charAt(0) <= '0' || s.charAt(0) > '9')
		return 0;
        
	int	num1 = 1;
	int	num2 = 1;
	int	num3 = 1;
	
	for (int i = 1; i < s.length(); i++) {
		if (s.charAt(i) < '0' || s.charAt(i) > '9')
			return 0;
		
		if (s.charAt(i) == '0') {
			if(s.charAt(i - 1) == '1' || s.charAt(i - 1) == '2')
				num3 = num1;
			else
				return 0; /* 是数字，但无法解码 */
		} else {
			if (s.charAt(i-1) == '0' || s.charAt(i-1) > '2' ||
			    (s.charAt(i-1) == '2' && s.charAt(i) > '6'))
				num3 = num2;
			else 
				num3 = num1 + num2;
		}
		num1 = num2;
		num2 = num3;
	}
	
	return num2;
}
