#include "../include/ft_printf.h"

int print_decimal(va_list ap)
{
	int num;
	unsigned count;
	unsigned unum;

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
	count += print_positive_num(unum);
	return ((int)count);
}
