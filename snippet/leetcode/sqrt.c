/* 先任意假设一个初始解 res（设为1），然后以抛物  y = x^2-c（这里的c相当
 * 于题目中的 x）上的点  (res, res^2-c) 为切点作切线，让 res  = 切线与 x
 * 轴的交点，一直循环上面的操作直到前后两次的解相 。

 */
int sqrt(int x)
{
        double res = 1.0, tmpres = 0.0;
	
        while (int(res) - int(tmpres)) {
		tmpres = res;
		/* res / 2.0 + x /(2.0 * res)为切线与x轴的交点 */
		res =  res / 2.0 + x /(2.0 * res);
        }
        return (int)res;
}
