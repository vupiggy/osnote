char *numbers[] = {
	"0",
	" 0.1 ",
	"abc",
	"1 a",
	"2e10",
	"2.1e10",
	"e",
	".",
	" ",
	"e9",
	"1.",
	"-1.",
	"--2",
	"3-2",
	".-4",
	"e.-4",
	" 005047e+6",
	" -.7e+0435"
};

static int
is_valid_number(const char *s)
{
	const char *cur = s;
        int num_seen = 0;
    	int sci_notation = 0;
    	int floating_point = 0;
    	int hex_num = 0;
    	int sign = 0;
    
    	while (*cur == ' ') cur++;
        if (*cur == '\0') return 0;
        
    	for (; *cur != '\0'; cur++) {
    		if ((*cur == 'e' || *cur == 'E') && !sci_notation && num_seen) {
    			sci_notation = 1;
    			floating_point = 0;
    			sign = 0;
    			num_seen = 0;
    		} else if (*cur == '.' && !floating_point && !sci_notation) {
    			floating_point = 1;
    		} else if ((*cur == '0' && (*(cur + 1) == 'x' || *(cur + 1) == 'X'))
    			 && !hex_num) {
    			hex_num = 1;
    			num_seen = 0;
    		} else if (isspace(*cur)) {
    			while (isspace(*cur)) cur++;
    			if (*cur == '\0' && num_seen) return 1;
    			else return 0;
    		} else if ((*cur == '-' || *cur == '+') && !sign && !num_seen &&
			           !floating_point && !hex_num) {
    		    sign = 1;
    		} else if (*cur < '0' || *cur > '9'){
    			if (hex_num && ((*cur < 'f' && *cur > 'a') ||
    					(*cur < 'F' && *cur > 'A')))
    				continue;
    
    			return 0;
    		} else {
    			num_seen = 1;
    		}
    	}
        if (!num_seen)
		    return 0;
		    
    	return 1;
}

int
main(void)
{
	int i;
	for (i = 0; i < sizeof(numbers) / sizeof(char *); i++) {
		printf("%s is %s a number\n", numbers[i],
		       is_valid_number(numbers[i]) ? "\b" : "not");
	}
}

/* 有限状态机解法：
 *
 * 先枚举一下所有合法的输入情况：
 * 1.空格 + 数字 + 空格
 * 2.空格 + 点 + 数字 + 空格
 * 3.空格 + 符号 + 数字 + 空格
 * 4.空格 + 符号 + 点 + 数字 + 空格
 * 5.空格 + (1, 2, 3, 4） + e +　(1, 2, 3, 4) + 空格
 *
 * 组合后合法的字符可以是：
 *
 * 1.数字
 * 2.空格
 *
 * 有限状态机的状态转移过程：

 * 初始状态 0
 * 当输入空格时，状态仍为 0
 * 输入符号时，状态转为 3 ，3 的转换和 0 是一样的，除了不能再接受符号，
 * 于是在 0 状态基础上，把接受符号置为 -1；
 *
 * 当输入为数字时，状态转为 1, 状态1的转换在于无法再接受符号，可以接受空
 * 格、数字、点、指数；状态 1 为合法的结束状态；
 *
 * 当输入为点时，状态转为2， 状态 2 必须再接受数字，接受其他均为非法；
 * 当输入为指数时，非法；
 *
 * 状态1:
 * 接受数字时仍转为状态1，
 * 接受点时，转为状态4， 可以接受空格，数字，指数，状态4为合法的结束状态，
 * 接受指数时，转为状态5，  可以接受符号、数字，不能再接受点，因为指数必
 * 须为整数，而且必须再接受数字；
 *
 * 状态2：
 * 接受数字转为状态4；
 *
 * 状态3：
 * 和 0 一样，只是不能接受符号；
 *
 * 状态4：
 * 接受空格，合法接受；
 * 接受数字，仍为状态4；
 * 接受指数，转为状态5，
 *
 * 状态5：
 * 接受符号，转为状态6，状态6和状态5一样，只是不能再接受符号，
 * 接受数字，转为状态7，状态7只能接受空格或数字；状态7为合法的结束状态；
 *
 * 状态6：
 * 只能接受数字，转为状态7；
 *
 * 状态7：
 * 接受空格，转为状态8，状态7为合法的结束状态；
 * 接受数字，仍为状态7；
 *
 * 状态8：
 * 接受空格，转为状态8，状态8为合法的结束状态；
 */
