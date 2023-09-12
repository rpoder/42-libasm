/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:51:49 by rpoder            #+#    #+#             */
/*   Updated: 2023/09/12 18:21:52 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

void test_strcpy(char *src)
{
	char	*dest = malloc(10);

	printf("strcpy = |%s|\n", strcpy(dest, src));
	memset(dest, '#', 10);
	printf("ft_strcpy = |%s|\n", ft_strcpy(dest, src));
}

void test_strlen(char *str)
{
	printf("strlen = %ld\n", strlen(str));
	printf("ft_strlen = %ld\n", ft_strlen(str));
}

void test_strcmp(const char *s1, const char *s2)
{
	printf("strcmp = %d\n", strcmp(s1, s2));
	printf("ft_strcmp = %d\n", ft_strcmp(s1, s2));
}

void test_write(const char *s1)
{
	printf("%ld\n", write(-1, s1, strlen(s1)));
	printf("errno = %d\n", errno);
	errno = 0;
	printf("errno = %d\n", errno);

	printf("%ld\n", ft_write(-1, s1, strlen(s1)));
	printf("errno = %d\n", errno);
}

int main()
{
	printf("----------------------------strlen\n");
	{
		test_strlen("coucou");
		test_strlen("");
	}

	printf("----------------------------strcpy\n");
	{
		test_strcpy("coucou");
		test_strcpy("");
		// test_strcpy(NULL);
	}

	printf("----------------------------strcmp\n");
	{
		test_strcmp("fcoucou", "ccoupou");
		test_strcmp("", "");
		test_strcmp("sd", "");
		test_strcmp("", "grh");
		// test_strcmp(NULL, "grh");
	}

	printf("----------------------------write\n");
	{
		test_write("fcoucou\n");
	}

	return (0);
}

