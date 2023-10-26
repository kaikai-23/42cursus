/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:14:29 by hkai              #+#    #+#             */
/*   Updated: 2023/10/26 15:36:41 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

typedef struct s_format
{
	int		flag_minus;//-が指定された際(1とする)、左揃えになる。デフォ(0とする)では右揃え
	int		flag_zero;//左側の空白部分を0で埋める
	int		width;//指定された幅に合わせて空白を入れる
	int		precision;//制度の設定
	char	type;
}	t_fromat;


int	ft_printf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);//可変リストの初期化
	//可変リストの処理
	va_end(ap);//可変リストの終了処理
	
	return (0);//書き込んだ文字数を返す
}