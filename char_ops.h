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

#ifndef _CHAR_OPS_H
#define _CHAR_OPS_H
#include <string.h>

/**
 * is_digit_str - Determine whether a string is a number.
 * @str: IN, Pointer to the input string.
 *
 * Returns 0 if it's numbers, otherwise not 0.
 */
#ifdef __cplusplus
extern "C" {
#endif
int is_digit_str(char *str);
int hexstrToHexchar(char* out, unsigned int len, const char* in);
long long hexStrTOll(const char* str);
long long hexStrLittleTOll(const char* str);
int hexstrLittleToDecstr(const char* str, char* out, int len);
int llToHexstrBigend(long long num, char* hexstr, int len);
int llToHexstrLittle(long long num, char* hexstr, int len);
int strCopyC(char* buff, int len, const char* str);
#define STR_COPY(buff, len, str) ({ \
    int strlenght = strlen(str); \
    strlenght = strlenght<len?strlenght:len-1; \
    memcpy(buff, str, strlenght); \
    buff[strlenght] = 0; \
})

#ifdef __cplusplus
}
#endif

#endif  /* _CHAR_OPS_H */

