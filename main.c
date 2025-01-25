/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:51:49 by rpoder            #+#    #+#             */
/*   Updated: 2025/01/25 11:57:12 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

void test_strcpy(char *src)
{
	char	*dest = malloc(10);

	printf("strcpy = |%s|\n", strcpy(dest, src));
	memset(dest, '#', 10);
	printf("ft_strcpy = |%s|\n", ft_strcpy(dest, src));
	free(dest);
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
	// test 1: error showing errno
	printf("------------test 1\n");
	printf("%ld\n", write(-1, s1, strlen(s1)));
	printf("errno = %d\n", errno);
	errno = 0;
	printf("resetting errno = %d\n", errno);
	printf("%ld\n", ft_write(-1, s1, strlen(s1)));
	printf("errno = %d\n", errno);

	// test 2: working
	printf("------------test 2\n");
	printf("%ld\n", write(1, s1, strlen(s1)));
	printf("%ld\n", ft_write(1, s1, strlen(s1)));
}

void test_read()
{
	size_t	chars_to_read;
	char	*file_path;
	char	buf[250];
	int		fd;

	file_path = "./README.md";
	chars_to_read = 250;
	fd = open(file_path, O_RDONLY);
	memset(buf, 0, 250);

	printf("%zd\n", read(fd, buf, chars_to_read));
	buf[chars_to_read - 1] = '\0';
	printf("res = %s\n", buf);
	printf("errno = %d\n", errno);

	close(fd);
	fd = open(file_path, O_RDONLY);

	errno = 0;
	printf("errno = %d\n", errno);
	printf("%zd\n", ft_read(fd, buf, chars_to_read));
	printf("res = %s\n", buf);
	printf("errno = %d\n", errno);
	close(fd);
}

void test_strdup() {
	char *str;
	// test 1
	printf("------------test 1\n");
	str = strdup("hello42\0");
	printf("%p\n",str);
	printf("%s\n",str);
	free(str);
	str = ft_strdup("hello42");
	printf("%p\n",str);
	printf("%s\n",str);
	free(str);
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

	printf("----------------------------read\n");
	{
		test_read();
	}

		printf("----------------------------strdup\n");
	{
		test_strdup();
	}

	return (0);
}

