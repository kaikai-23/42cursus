/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaramonkai <takaramonkai@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:14:29 by hkai              #+#    #+#             */
/*   Updated: 2023/11/08 14:36:34 by takaramonka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "include/libft.h"

int	print_char(va_list ap); //別ファイル
int	print_string(va_list ap);//別ファイル
void	print_pointer(va_list ap);//別ファイル
int	print_decimal(va_list ap);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);//可変リストの初期化
	count = 0;//数字数える用の変数
	//可変リストの処理
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			// ここでフラグやフィールド幅、精度を解析し、対応する処理を行なう
			//%cの処理
			if (*format == 'c')
				count += print_char(ap);
			else if (*format == 's')
				count += print_string(ap);
			else if (*format == 'p')
				print_pointer(ap);
			else if (*format == 'd')
				count += print_decimal(ap);
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
			count += write(1, format, 1);//普通にライトする
		format++;
	}

	va_end(ap);//可変リストの終了処理
	
	return (count);//書き込んだ文字数を返す
}


//全般的なテスト
// #include <stdio.h>
// int main()
// {
	/*
		そもそもprintfにNULLが入ってくるパターン
		セグフォでクラッシュする
		対応済み
	*/
	// printf(NULL);
	// ft_printf(NULL);
	/*
		そもそもprintfに'\0'や'a'のような文字が入ってくるパターン
		ワーニングからのセグフォになる
		対応済み
	*/
	// printf('\0');
	// ft_printf('\0');
	// printf('a');
	// ft_printf('a');
	/*
		ダブルクォーテーションで空文字が入ってくるケース
		何も出力しない
		対応済み
	*/
	// printf("\0");
	// ft_printf("\0");
	
	// printf("aaaa\n");
	// ft_printf("aaaa\n");
	// printf("%caaaa\n", 'c');
	// ft_printf("%caaaa\n", 'c');
	// printf("%saaaa\n", "str");
	// ft_printf("%saaaa\n", "str");
	// printf("%p\n", "str");
	// ft_printf("%p\n", "str");
	// printf("%d\n", -2147483648);
	// ft_printf("%d\n", -2147483648);
	// printf("%i\n", -12345);
	// ft_printf("%i\n", -12345);
	// printf("%u\n", 12345);
	// ft_printf("%u\n", 12345);
	// printf("%x\n", 255);
	// ft_printf("%x\n", 255);
	// printf("%X\n", 255);
	// ft_printf("%X\n", 255);
	// printf("%%\n", 255);
	// ft_printf("%%\n", 255);
	// printf("aa%z\n", 255);
	// ft_printf("aa%z\n", 255);
// }

// %cのテスト
// #include <stdio.h>
// int main()
// {
	// int i = printf("%c\n", 'a');
	// int j = ft_printf("%c\n", 'a');
	// printf("   %c   \n", 'a');
	// ft_printf("   %c   \n", 'a');
	// printf("%c\n", 'a' - 256);
	// ft_printf("%c\n", 'a' - 256);
	// printf("%c\n", 'a' + 256);
	// ft_printf("%c\n", 'a' + 256);
	// printf(" %c %c %c \n", 'a', 0, 'b');
	// ft_printf(" %c %c %c \n", 'a', 0, 'b');
	// printf(" %c %c %c \n", ' ', ' ', ' ');
	// ft_printf(" %c %c %c \n", ' ', ' ', ' ');
	// printf(" %c %c %c \n", 'a', 'b', 'c');
	// ft_printf(" %c %c %c \n", 'a', 'b', 'c');
	// printf(" %c %c %c \n", 'c', 'a', 0);
	// ft_printf(" %c %c %c \n", 'c', 'a', 0);
	// printf(" %c %c %c \n", 0, 'a', 'b');
	// ft_printf(" %c %c %c \n", 0, 'a', 'b');
	// printf("printf:%d ft_printf: %d\n", i, j);
	// int i = printf("%c %c %c\n", NULL, 'a', 'b');
	// int j = ft_printf("%c %c %c\n", NULL, 'a', 'b');
	// printf("printf:%d ft_printf: %d\n", i, j);
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
	// int i = printf("%s\n", (char *)NULL);
	// int j = ft_printf("%s\n", (char *)NULL);
	// printf("printf:%d ft_printf: %d\n", i, j);
// }

// %pのテスト
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
#include <stdio.h>
int main()
{
	printf(" %d \n", 0);
	ft_printf(" %d \n", 0);
	printf(" %d \n", -1);
	ft_printf(" %d \n", -1);
	printf(" %d \n", 9);
	ft_printf(" %d \n", 9);
	printf(" %d \n", 10);
	ft_printf(" %d \n", 10);
	printf(" %d \n", 19);
	ft_printf(" %d \n", 19);
	printf(" %d \n", 109);
	ft_printf(" %d \n", 109);
	printf(" %d \n", -109);
	ft_printf(" %d \n", -109);
	printf(" %d \n", INT_MAX);
	ft_printf(" %d \n", INT_MAX);
	printf(" %d \n", INT_MIN);
	ft_printf(" %d \n", INT_MIN);
	// printf(" %d \n", LONG_MAX);
	// ft_printf(" %d \n", LONG_MAX);
	// printf(" %d \n", LONG_MIN);
	// ft_printf(" %d \n", LONG_MIN);
	// printf(" %d \n", UINT_MAX);
	// ft_printf(" %d \n", UINT_MAX);
	// printf(" %d \n", ULONG_MAX);
	// ft_printf(" %d \n", ULONG_MAX);
	// printf(" %d \n", 9223372036854775807LL);
	// ft_printf(" %d \n", 9223372036854775807LL);
	// int i = printf("%d\n", INT_MIN + 1);
	// int j = printf("%d\n", INT_MIN + 1);
	// printf("printf: %d ft_printf: %d", i, j);
	// int i = printf("%d\n", 0);
	// int j = printf("%d\n", 0);
	// printf("printf: %d ft_printf: %d", NULL, NULL);
	// int i = printf("%d\n", NULL);
	// int j = printf("%d\n", NULL);
	// printf("printf: %d ft_printf: %d", i, j);
	// int i = printf("%d\n", '\0');
	// int j = printf("%d\n", '\0');
	// printf("printf: %d ft_printf: %d", i, j);
}

