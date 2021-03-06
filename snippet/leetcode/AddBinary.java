public String addBinary(String a, String b)
{
    if(a == null || a.length() == 0)
	return b;    
    if(b == null || b.length() == 0)
	return a;
    
    int i = a.length()-1;
    int j = b.length()-1;
    int carry = 0;
    StringBuilder res = new StringBuilder();
    
    while (i >= 0 && j >= 0) {
	int digit = (int)(a.charAt(i) - '0' +
			  b.charAt(j) - '0') + carry;
	carry = digit/2;
	digit %= 2;
	res.append(digit);
	i--;
	j--;
    }
    
    if (i < 0) {
	a = b;
	i = j;
    }
    
    while (i >= 0) {
	int digit = (int)(a.charAt(i) - '0') + carry;
	carry = digit / 2;
	digit %= 2;
	res.append(digit);
	i--;
    }   
    if (carry > 0)
            res.append(carry);
    
    return res.reverse().toString();
}
