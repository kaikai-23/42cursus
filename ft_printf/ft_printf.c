/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaramonkai <takaramonkai@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:14:29 by hkai              #+#    #+#             */
/*   Updated: 2023/10/31 10:59:53 by takaramonka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "include/libft.h"

typedef struct s_format
{
	int		flag_minus;//-が指定された際(1とする)、左揃えになる。デフォ(0とする)では右揃え
	int		flag_zero;//左側の空白部分を0で埋める
	int		width;//指定された幅に合わせて空白を入れる
	int		precision;//精度の設定
	char	type;
}	t_fromat;

void	print_char(va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	write(1, &c, 1);
}

void	print_str(va_list ap)
{
	char	*str;

	str = va_arg(ap, char*);
	if (str == NULL)
	{
		//NULLの処理
	}
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	print_pointer(va_list ap)
{
	void 				*ptr;
	unsigned long long address;
	char				buffer[20];
	int					i;

	i = 0;
	ptr = va_arg(ap, void*);
	if (ptr == NULL)
		buffer[i++] = '0';
	else
	{
		address = (unsigned long long)ptr;
		while (address)
		{
			unsigned char hex_digit = address % 16;
			if (hex_digit < 10)
				buffer[i++] = '0' + hex_digit;
			else
				buffer[i++] = 'a' + (hex_digit - 10);
			address /= 16;
		}
	}
	write(1, "0x", 2); // 16進数を表す接頭辞
	while (i > 0) // バッファの内容を逆順に出力
	{
		write(1, &buffer[--i], 1);
	}
}

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
				print_char(ap);
			else if (*format == 's')
				print_str(ap);
			else if (*format == 'p')
				print_pointer(ap);
			else if (*format == 'd')
			{
				int num;
				int is_negative = 0;
				char buffer[12]; // int型の最大桁数(10) + 負の記号 + null終端
				int i = 0;

				num = va_arg(ap, int); // int型の数値を引数リストから取得

				// 負の数値の場合の処理
				if (num < 0)
				{
					is_negative = 1;
					num = -num;
				}

				if (num == 0) // 0の場合の処理
				{
					buffer[i++] = '0';
				}
				else
				{
					while (num)
					{
						buffer[i++] = '0' + (num % 10);
						num /= 10;
					}
				}

				if (is_negative)
				{
					buffer[i++] = '-';
				}

				// バッファの内容を逆順に出力
				while (i > 0)
				{
					write(1, &buffer[--i], 1);
				}
			}
			else if (*format == 'i')
			{
				int num;
				int is_negative = 0;
				char buffer[12]; // int型の最大桁数(10) + 負の記号 + null終端
				int i = 0;

				num = va_arg(ap, int); // int型の数値を引数リストから取得

				// 負の数値の場合の処理
				if (num < 0)
				{
					is_negative = 1;
					num = -num;
				}

				if (num == 0) // 0の場合の処理
				{
					buffer[i++] = '0';
				}
				else
				{
					while (num)
					{
						buffer[i++] = '0' + (num % 10);
						num /= 10;
					}
				}

				if (is_negative)
				{
					buffer[i++] = '-';
				}

				// バッファの内容を逆順に出力
				while (i > 0)
				{
					write(1, &buffer[--i], 1);
				}
			}
			else if (*format == 'u')
			{
				unsigned int num;
				char buffer[12]; // unsigned int型の最大桁数(10) + null終端
				int i = 0;

				num = va_arg(ap, unsigned int); // unsigned int型の数値を引数リストから取得

				if (num == 0) // 0の場合の処理
				{
					buffer[i++] = '0';
				}
				else
				{
					while (num)
					{
						buffer[i++] = '0' + (num % 10);
						num /= 10;
					}
				}

				// バッファの内容を逆順に出力
				while (i > 0)
				{
					write(1, &buffer[--i], 1);
				}
			}
			else if (*format == 'x')
			{
				unsigned int num;
				char buffer[9]; // unsigned int型の最大16進数桁数(8) + null終端
				int i = 0;

				num = va_arg(ap, unsigned int); // unsigned int型の数値を引数リストから取得

				if (num == 0) // 0の場合の処理
				{
					buffer[i++] = '0';
				}
				else
				{
					while (num)
					{
						unsigned char hex_digit = num % 16;
						if (hex_digit < 10)
							buffer[i++] = '0' + hex_digit;
						else
							buffer[i++] = 'a' + (hex_digit - 10);
						num /= 16;
					}
				}

				// バッファの内容を逆順に出力
				while (i > 0)
				{
					write(1, &buffer[--i], 1);
				}
			}
			else if (*format == 'X')
			{
				unsigned int num;
				char buffer[9]; // unsigned int型の最大16進数桁数(8) + null終端
				int i = 0;

				num = va_arg(ap, unsigned int); // unsigned int型の数値を引数リストから取得

				if (num == 0) // 0の場合の処理
				{
					buffer[i++] = '0';
				}
				else
				{
					while (num)
					{
						unsigned char hex_digit = num % 16;
						if (hex_digit < 10)
							buffer[i++] = '0' + hex_digit;
						else
							buffer[i++] = 'A' + (hex_digit - 10); // 大文字で出力
						num /= 16;
					}
				}
				// バッファの内容を逆順に出力
				while (i > 0)
				{
					write(1, &buffer[--i], 1);
				}
			}
			else if (*format == '%')
			{
				write(1, "%", 1);
			}
			else
			{
				// 無効なフォーマットのケース
				// 記述なしで大丈夫そう
			}
		}
		else
			write(1, format, 1);
		format++;
	}

	va_end(ap);//可変リストの終了処理
	
	return (0);//書き込んだ文字数を返す
}

#include <stdio.h>
int main()
{
	printf("aaaa\n");
	ft_printf("aaaa\n");
	printf("%caaaa\n", 'c');
	ft_printf("%caaaa\n", 'c');
	printf("%saaaa\n", "str");
	ft_printf("%saaaa\n", "str");
	printf("%p\n", "str");
	ft_printf("%p\n", "str");
	printf("%d\n", -12345);
	ft_printf("%d\n", -12345);
	printf("%i\n", -12345);
	ft_printf("%i\n", -12345);
	printf("%u\n", 12345);
	ft_printf("%u\n", 12345);
	printf("%x\n", 255);
	ft_printf("%x\n", 255);
	printf("%X\n", 255);
	ft_printf("%X\n", 255);
	printf("%%\n", 255);
	ft_printf("%%\n", 255);
	printf("aa%z\n", 255);
	ft_printf("aa%z\n", 255);
}
