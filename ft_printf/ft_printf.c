/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:14:29 by hkai              #+#    #+#             */
/*   Updated: 2023/11/07 19:42:06 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "include/libft.h"

void	print_char(va_list ap); //別ファイル
void	print_string(va_list ap);//別ファイル
void	print_pointer(va_list ap);//別ファイル

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
				print_string(ap);
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


//全般的なテスト
// #include <stdio.h>
// int main()
// {
// 	printf("aaaa\n");
// 	ft_printf("aaaa\n");
// 	printf("%caaaa\n", 'c');
// 	ft_printf("%caaaa\n", 'c');
// 	printf("%saaaa\n", "str");
// 	ft_printf("%saaaa\n", "str");
// 	printf("%p\n", "str");
// 	ft_printf("%p\n", "str");
// 	printf("%d\n", -12345);
// 	ft_printf("%d\n", -12345);
// 	printf("%i\n", -12345);
// 	ft_printf("%i\n", -12345);
// 	printf("%u\n", 12345);
// 	ft_printf("%u\n", 12345);
// 	printf("%x\n", 255);
// 	ft_printf("%x\n", 255);
// 	printf("%X\n", 255);
// 	ft_printf("%X\n", 255);
// 	printf("%%\n", 255);
// 	ft_printf("%%\n", 255);
// 	printf("aa%z\n", 255);
// 	ft_printf("aa%z\n", 255);
// }

// %cのテスト
// #include <stdio.h>
// int main()
// {
// 	int i = printf("%c\n", 'a');
// 	int j = ft_printf("%c\n", 'a');
// 	printf("   %c   \n", 'a');
// 	ft_printf("   %c   \n", 'a');
// 	printf("%c\n", 'a' - 256);
// 	ft_printf("%c\n", 'a' - 256);
// 	printf("%c\n", 'a' + 256);
// 	ft_printf("%c\n", 'a' + 256);
// 	printf(" %c %c %c \n", 'a', 0, 'b');
// 	ft_printf(" %c %c %c \n", 'a', 0, 'b');
// 	printf(" %c %c %c \n", ' ', ' ', ' ');
// 	ft_printf(" %c %c %c \n", ' ', ' ', ' ');
// 	printf(" %c %c %c \n", 'a', 'b', 'c');
// 	ft_printf(" %c %c %c \n", 'a', 'b', 'c');
// 	printf(" %c %c %c \n", 'c', 'a', 0);
// 	ft_printf(" %c %c %c \n", 'c', 'a', 0);
// 	printf(" %c %c %c \n", 0, 'a', 'b');
// 	ft_printf(" %c %c %c \n", 0, 'a', 'b');
// 	printf("printf:%d ft_printf: %d\n", i, j);
	// printf("%c\n", NULL);
	// ft_printf("%c\n", NULL);
// }

// %sのテスト
// #include <stdio.h>
// int main()
// {
	// printf("%s\n", NULL);
	// ft_printf("%s\n", NULL);
	// printf("%s\n", "");
	// ft_printf("%s\n", "");
	// printf(" %s\n", "");
	// ft_printf(" %s\n", "");
	// printf("%s \n", "");
	// ft_printf("%s \n", "");
	// printf(" %s \n", "");
	// ft_printf(" %s \n", "");
	// printf(" %s \n", "-");
	// ft_printf(" %s \n", "-");
	// printf(" %s %s \n", "", "-");
	// ft_printf(" %s %s \n", "", "-");
	// printf(" %s %s \n", " - ", "");
	// ft_printf(" %s %s \n", " - ", "");
	// // printf(" %s %s %s %s %s\n", " - ", "", "4", "", s2);
	// printf(" %s %s %s %s %s \n", " - ", "", "4", "", "2 ");
	// ft_printf(" %s %s %s %s %s \n", " - ", "", "4", "", "2 ");
	// printf(" NULL %s NULL \n", NULL);
	// ft_printf(" NULL %s NULL \n", NULL);
// }

// // %pのテスト
// int main()
// {
// 	printf(" %p \n", -1);
// 	ft_printf(" %p \n", -1);
// 	printf(" %p \n", 1);
// 	ft_printf(" %p \n", 1);
// 	printf(" %p \n", 15);
// 	ft_printf(" %p \n", 15);
// 	printf(" %p \n", 16);
// 	ft_printf(" %p \n", 16);
// 	printf(" %p \n", 17);
// 	ft_printf(" %p \n", 17);
// 	printf(" %p %p\n", LONG_MIN, LONG_MAX);
// 	ft_printf(" %p %p\n", LONG_MIN, LONG_MAX);
// 	printf(" %p %p\n", INT_MIN, INT_MAX);
// 	ft_printf(" %p %p\n", INT_MIN, INT_MAX);
// 	printf(" %p %p\n", ULONG_MAX, -ULONG_MAX);
// 	ft_printf(" %p %p\n", ULONG_MAX, -ULONG_MAX);
// 	printf(" %p \n", 0);
// 	ft_printf(" %p \n", 0);
// }

//%dのテスト
// int main()
// {
// 	printf(" %d ", 0);
// 	TEST(1, print(" %d ", 0));
// 	TEST(2, print(" %d ", -1));
// 	TEST(3, print(" %d ", 1));
// 	TEST(4, print(" %d ", 9));
// 	TEST(5, print(" %d ", 10));
// 	TEST(6, print(" %d ", 11));
// 	TEST(7, print(" %d ", 15));
// 	TEST(8, print(" %d ", 16));
// 	TEST(9, print(" %d ", 17));
// 	TEST(10, print(" %d ", 99));
// 	TEST(11, print(" %d ", 100));
// 	TEST(12, print(" %d ", 101));
// 	TEST(13, print(" %d ", -9));
// 	TEST(14, print(" %d ", -10));
// 	TEST(15, print(" %d ", -11));
// 	TEST(16, print(" %d ", -14));
// 	TEST(17, print(" %d ", -15));
// 	TEST(18, print(" %d ", -16));
// 	TEST(19, print(" %d ", -99));
// 	TEST(20, print(" %d ", -100));
// 	TEST(21, print(" %d ", -101));
// 	TEST(22, print(" %d ", INT_MAX));
// 	TEST(23, print(" %d ", INT_MIN));
// 	TEST(24, print(" %d ", LONG_MAX));
// 	TEST(25, print(" %d ", LONG_MIN));
// 	TEST(26, print(" %d ", UINT_MAX));
// 	TEST(27, print(" %d ", ULONG_MAX));
// 	TEST(28, print(" %d ", 9223372036854775807LL));
// 	TEST(29, print(" %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
// }