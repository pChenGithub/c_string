/*
 * char_ops.h - String processing interface.
 *
 * Copyright (C) 2016-2019, LomboTech Co.Ltd.
 * Author: lomboswer <lomboswer@lombotech.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "char_ops.h"

#define LOG_TAG "CHAR_OPS"
#include "log/log.h"

/**
 * is_digit_str - Determine whether a string is a number.
 * @str: IN, Pointer to the input string.
 *
 * Returns 1 if it's numbers, otherwise not 0.
 */
int is_digit_str(char *str)
{
	return (strspn(str, "0123456789") == strlen(str));
}

// 字符串的16进制转数值的16进制
// 需要自己控制输入与输出的长度，函数内部只判断输出是不是为0
int hexstrToHexchar(char *out, unsigned int len, const char *in)
{
    if (NULL==out|| 0==len || NULL==in)
        return -1;

    int tmp = 0;
    for (unsigned int i=0;i<len;i++) {
        tmp = in[2*i];
        if (tmp>='a')
            tmp -= ('a'-10);
        else if (tmp>='A')
            tmp -= ('A'-10);
        else
            tmp -= '0';

        out[i] = tmp*16;

        tmp = in[2*i+1];
        if (tmp>='a')
            tmp -= ('a'-10);
        else if (tmp>'A')
            tmp -= ('A'-10);
        else
            tmp -= '0';

        out[i] += tmp;
    }

    return 0;
}

// 这个函数未考虑溢出
long long hexStrTOll(const char *str)
{
    if (NULL==str)
        return -1;

    long long ret = 0;
    int len = strlen(str);

    for (int i=0;i<len;i++)
    {
        ret = ret<< 4;
        if ('0'<=str[i] && str[i]<='9')
            ret += (str[i]-'0');
        else if ('a'<=str[i] && str[i]<='f')
            ret += (str[i]-'a'+10);
        else if ('A'<=str[i] && str[i]<='F')
            ret += (str[i]-'A'+10);
        else
            return -1;
    }
    return ret;
}

// 16进制字符串小端存储
long long hexStrLittleTOll(const char *str)
{
    long long ret = 0;
    int i = 0;

    if (NULL==str)
        return -1;

    int len = strlen(str);
#if 0
    printf("长度 %d\n", len);
#endif
    for (i=len-2;i>=0;i-=2)
    {
        ret = ret << 4;
        if ('0'<=str[i] && str[i]<='9')
            ret += (str[i]-'0');
        else if ('a'<=str[i] && str[i]<='f')
            ret += (str[i]-'a'+10);
        else if ('A'<=str[i] && str[i]<='F')
            ret += (str[i]-'A'+10);
        else
            return -1;
#if 0
        printf("ret值 %lld\n", ret);
#endif

        ret = ret << 4;
        if ('0'<=str[i+1] && str[i+1]<='9')
            ret += (str[i+1]-'0');
        else if ('a'<=str[i+1] && str[i+1]<='f')
            ret += (str[i+1]-'a'+10);
        else if ('A'<=str[i+1] && str[i+1]<='F')
            ret += (str[i+1]-'A'+10);
        else
            return -1;
#if 0
        printf("ret值 %lld\n", ret);
#endif
    }
    return ret;
}

int hexstrLittleToDecstr(const char *str, char *out, int len)
{
    if (NULL==str || NULL==out || len<=0)
        return -1;
    snprintf(out, len, "%lld", hexStrLittleTOll(str));
    return 0;
}
