/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:14:29 by hkai              #+#    #+#             */
/*   Updated: 2023/11/13 15:20:03 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	is_invalid_format(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (0);
	else
		return (1);
}

int	judge_format(const char *format, va_list *ap)
{
	if (*format == 'c')
		return (print_char(ap));
	else if (*format == 's')
		return (print_string(ap));
	else if (*format == 'p')
		return (print_pointer(ap));
	else if (*format == 'd' || *format == 'i')
		return (print_decimal(ap));
	else if (*format == 'u')
		return (print_unsigned(ap));
	else if (*format == 'x')
		return (print_lower_hex(ap));
	else if (*format == 'X')
		return (print_upper_hex(ap));
	else
		return (write(1, "%", 1));
}

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
			while (*format && is_invalid_format(*format))
				format++;
			count += judge_format(format, &ap);
		}
		else
			count += write(1, format, 1);//普通にライトする
		format++;
	}
	va_end(ap);//可変リストの終了処理
	return (count);//書き込んだ文字数を返す
}


//全般的なテスト
#include <stdio.h>
int main()
{
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

	/*無効なフォーマット指定子の場合・有効な指定子を探し出力*/
	// int k = printf("aa%zzzzd%s\n", 1, "bbb");
	// printf("%d\n", k);
	// k = ft_printf("aa%zzzzd%s\n", 1, "bbb");
	// printf("%d\n", k);

	// ft_printf("aa%zhh%s", "aaa", "bbb");
	// ft_printf(" %z %s", "aaa", "bbb");
	// printf("aaaa\n");
	// ft_printf("aaaa\n");
	// printf("%c %c %c\n", '1', '2', '3');
	// ft_printf("%c %c %c\n", '1', '2', '3');
	// printf("%saaaa\n", "str");
	// ft_printf("%saaaa\n", "str");
	// printf("%p\n", "str");
	// ft_printf("%p\n", "str");
	// printf("%d\n", -2147483647);
	// ft_printf("%d\n", -2147483647);
	// printf("%i\n", -12345);
	// ft_printf("%i\n", -12345);
	// printf("%u\n", 12345);
	// ft_printf("%u\n", 12345);
	// printf("%x\n", 255);
	// ft_printf("%x\n", 255);
	// printf("%x\n", 15);
	// ft_printf("%x\n", 15);
	// printf("%x\n", -15);
	// ft_printf("%x\n", -15);
	// printf("%X\n", 255);
	// ft_printf("%X\n", 255);
	// printf("%%\n", 255);
	// ft_printf("%%\n", 255);
	// printf("aa%z\n", 255);
	// ft_printf("aa%z\n", 255);
}

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
// #include <stdio.h>
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
// #include <stdio.h>
// int main()
// {
	// printf(" %d \n", 0);
	// ft_printf(" %d \n", 0);
	// printf(" %d \n", -1);
	// ft_printf(" %d \n", -1);
	// printf(" %d \n", 9);
	// ft_printf(" %d \n", 9);
	// printf(" %d \n", 10);
	// ft_printf(" %d \n", 10);
	// printf(" %d \n", 19);
	// ft_printf(" %d \n", 19);
	// printf(" %d \n", 109);
	// ft_printf(" %d \n", 109);
	// printf(" %d \n", -109);
	// ft_printf(" %d \n", -109);
	// printf(" %d \n", INT_MAX);
	// ft_printf(" %d \n", INT_MAX);
	// printf(" %d \n", INT_MIN);
	// ft_printf(" %d \n", INT_MIN);
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
	// printf(" %d \n", 'a');
	// ft_printf(" %d \n", 'a');
	// printf(" %d \n",  +-003);
	// ft_printf(" %d \n", +-003);
	// printf(" %d \n",  0xFF);
	// ft_printf(" %d \n", 0xFF);
// }

//%iのテスト
// #include <stdio.h>
// int main()
// {
// 	printf(" %i \n", 0);
// 	ft_printf(" %i \n", 0);
// 	printf(" %i \n", -1);
// 	ft_printf(" %i \n", -1);
// 	printf(" %i \n", 9);
// 	ft_printf(" %i \n", 9);
// 	printf(" %i \n", 10);
// 	ft_printf(" %i \n", 10);
// 	printf(" %i \n", 19);
// 	ft_printf(" %i \n", 19);
// 	printf(" %i \n", 109);
// 	ft_printf(" %i \n", 109);
// 	printf(" %i \n", -109);
// 	ft_printf(" %i \n", -109);
// 	printf(" %i \n", INT_MAX);
// 	ft_printf(" %i \n", INT_MAX);
// 	printf(" %i \n", INT_MIN);
// 	ft_printf(" %i \n", INT_MIN);
	// printf(" %i \n", LONG_MAX);
	// ft_printf(" %i \n", LONG_MAX);
	// printf(" %i \n", LONG_MIN);
	// ft_printf(" %i \n", LONG_MIN);
	// printf(" %i \n", UINT_MAX);
	// ft_printf(" %i \n", UINT_MAX);
	// printf(" %i \n", ULONG_MAX);
	// ft_printf(" %i \n", ULONG_MAX);
	// printf(" %i \n", 9223372036854775807LL);
	// ft_printf(" %i \n", 9223372036854775807LL);
	// int i = printf("%i\n", INT_MIN + 1);
	// int j = printf("%i\n", INT_MIN + 1);
	// printf("printf: %i ft_printf: %i", i, j);
	// int i = printf("%i\n", 0);
	// int j = printf("%i\n", 0);
	// printf("printf: %i ft_printf: %i", NULL, NULL);
	// int i = printf("%i\n", NULL);
	// int j = printf("%i\n", NULL);
	// printf("printf: %i ft_printf: %i", i, j);
	// int i = printf("%i\n", '\0');
	// int j = printf("%i\n", '\0');
	// printf("printf: %i ft_printf: %i", i, j);
// 	printf(" %i \n", 'a');
// 	ft_printf(" %i \n", 'a');
// 	printf(" %i \n",  +-003);
// 	ft_printf(" %i \n", +-003);
// 	printf(" %i \n",  0xFF);
// 	ft_printf(" %i \n", 0xFF);
// }

//%uのテスト
// #include <stdio.h>
// int main()
// {
// 	printf(" %u \n", 0);
// 	ft_printf(" %u \n", 0);
// 	printf(" %u \n", -1);
// 	ft_printf(" %u \n", -1);
// 	printf(" %u \n", 9);
// 	ft_printf(" %u \n", 9);
// 	printf(" %u \n", 10);
// 	ft_printf(" %u \n", 10);
// 	printf(" %u \n", 19);
// 	ft_printf(" %u \n", 19);
// 	printf(" %u \n", 109);
// 	ft_printf(" %u \n", 109);
// 	printf(" %u \n", -109);
// 	ft_printf(" %u \n", -109);
// 	printf(" %u \n", INT_MAX);
// 	ft_printf(" %u \n", INT_MAX);
// 	printf(" %u \n", INT_MIN);
// 	ft_printf(" %u \n", INT_MIN);
// 	// printf(" %u \n", LONG_MAX);
// 	// ft_printf(" %u \n", LONG_MAX);
// 	// printf(" %u \n", LONG_MIN);
// 	// ft_printf(" %u \n", LONG_MIN);
// 	// printf(" %u \n", UINT_MAX);
// 	// ft_printf(" %u \n", UINT_MAX);
// 	// printf(" %u \n", ULONG_MAX);
// 	// ft_printf(" %u \n", ULONG_MAX);
// 	// printf(" %u \n", 9223372036854775807LL);
// 	// ft_printf(" %u \n", 9223372036854775807LL);
// 	// int i = printf("%u\n", INT_MIN + 1);
// 	// int j = printf("%u\n", INT_MIN + 1);
// 	// printf("printf: %u ft_printf: %u", i, j);
// 	// int i = printf("%u\n", 0);
// 	// int j = printf("%u\n", 0);
// 	// printf("printf: %u ft_printf: %u", NULL, NULL);
// 	// int i = printf("%u\n", NULL);
// 	// int j = printf("%u\n", NULL);
// 	// printf("printf: %u ft_printf: %u", i, j);
// 	// int i = printf("%u\n", '\0');
// 	// int j = printf("%u\n", '\0');
// 	// printf("printf: %u ft_printf: %u", i, j);
// 	printf(" %u \n", 'a');
// 	ft_printf(" %u \n", 'a');
// 	printf(" %u \n",  +-003);
// 	ft_printf(" %u \n", +-003);
// 	printf(" %u \n",  0xFF);
// 	ft_printf(" %u \n", 0xFF);
// }

//%xのテスト
// int main()
// {
// 	printf("%x\n", 255);
// 	ft_printf("%x\n", 255);
// 	printf("%x\n", 15);
// 	ft_printf("%x\n", 15);
// 	printf("%x\n", -15);
// 	ft_printf("%x\n", -15);
// }

//%Xのテスト
// int main()
// {
// 	printf("%X\n", 255);
// 	ft_printf("%X\n", 255);
// 	printf("%X\n", 15);
// 	ft_printf("%X\n", 15);
// 	printf("%X\n", -15);
// 	ft_printf("%X\n", -15);
// }
