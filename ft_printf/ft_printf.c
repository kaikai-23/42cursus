/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:14:29 by hkai              #+#    #+#             */
/*   Updated: 2023/10/26 16:20:18 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

typedef struct s_format
{
	int		flag_minus;//-が指定された際(1とする)、左揃えになる。デフォ(0とする)では右揃え
	int		flag_zero;//左側の空白部分を0で埋める
	int		width;//指定された幅に合わせて空白を入れる
	int		precision;//精度の設定
	char	type;
}	t_fromat;


int	ft_printf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);//可変リストの初期化

	//可変リストの処理
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			// ここでフラグやフィールド幅、精度を解析し、対応する処理を行なう
			//%cの処理
			if (*format == 'c')
			{
				char c;
				c = va_arg(ap, int);
				write(1, &c, 1);
			}
			else if (*format == 's')
				//%sの処理
			else if (*format == 'p')
				//%pの処理
			else if (*format == 'd')
				//%dの処理
			else if (*format == 'i')
				//iの処理
			else if (*format == 'u')
				//uの処理
			else if (*format == 'x')
				//xの処理
			else if (*format == 'X')
				//Xの処理
			else if (*format == '%')
				write(1, "%", 1);
			else
				//無効なフォーマット指定子
		}
		else
			write(1, format, 1);
		format++;
	}

	va_end(ap);//可変リストの終了処理
	
	return (0);//書き込んだ文字数を返す
}