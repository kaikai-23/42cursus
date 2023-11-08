#include <stdarg.h>
#include "include/libft.h"

static int print_num(unsigned int num)
{
	unsigned int	c;
	unsigned int	count;

	count = 0;
	if (num < 10)
	{
		c = '0' + num;
		count += write(1, &c, 1);
		return count;
	}
	count += print_num((num / 10));
	c = '0' + (num % 10);
	count += write(1, &c, 1);
	return (count);
}

int print_decimal(va_list ap)
{
	int num;
	int count;
	unsigned int unum;

	unum = 0;
	num = va_arg(ap, int); // int型の数値を引数リストから取得
	count = 0;
	// 負の数値の場合の処理
	if (num < 0)
	{
		count += write(1, "-", 1);
		if (num == INT_MIN)
		{
			//一度INT_MAXにする
			unum = (unsigned)((-1) * (num + 1));
			unum += 1;//絶対値をINT_MINと揃える
		}
		else
		unum = (unsigned)(-num);
	}
	else
		unum = (unsigned)num;
	count += (int)print_num(unum);
	return (count);
}

