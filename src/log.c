/*************************************************************************************
** 
** Copyright (c) 2017 G.D gaodongzi@126.com
** Contact: https://github.com/to9
** 
** This file is part of the log library.
**
** MIT License
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to deal
** in the Software without restriction, including without limitation the rights
** to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
** copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
** 
** The above copyright notice and this permission notice shall be included in all
** copies or substantial portions of the Software.
** 
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
** OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
** SOFTWARE.
** 
** 
*************************************************************************************/

#include "log.h"

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#if defined(LOG_ENABLE)

char *log_buffer = ((void *)0);
unsigned int log_buffer_len = 0;
void log_hook_default(const char *str)
{
	(void)(str);
}

void (*log_hook)(const char *str) = log_hook_default;
void log_init(char *buff, unsigned int buff_len, void (*hook)(const char *))
{
	log_hook = hook;
	log_buffer = buff;
	log_buffer_len = buff_len;
}

int printk(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	(void)vsnprintf(log_buffer, log_buffer_len, format, ap);
	va_end(ap);
	log_hook(log_buffer);

	return 0;
}

int printk_hex(unsigned char *buff, unsigned int count)
{
	static const char hex[] = "0123456789abcdef";
	unsigned int i, j;
	char str[16];
	char str_val[75];
	unsigned int index = 0;
	unsigned int str_index = 0;
	unsigned int cnt;

	if(count % 16)
	{
		cnt = count / 16 + 1;
	}
	else
	{
		cnt = count / 16;
	}

	for(i = 0; i < cnt; i++)
	{
		index = 0;
		str_index = 0;
		str_val[index++] = hex[(i & 0xf000) >> 12];
		str_val[index++] = hex[(i & 0xf00) >> 8];
		str_val[index++] = hex[(i & 0xf0) >> 4];
		str_val[index++] = hex[i & 0xf];
		str_val[index++] = ' ';
		str_val[index++] = ' ';

		for(j = 0; j < 16; j++)
		{
			if(j + (i << 4) < count)
			{
				str_val[index++] = hex[(buff[j + (i << 4)] & 0xf0) >> 4];
				str_val[index++] = hex[buff[j + (i << 4)] & 0xf];
				str_val[index++] = ' ';
				if((buff[j] >= 0x20) && (buff[j] <= 0x7e))
				{
					str[str_index++] = buff[j];
				}
				else
				{
					str[str_index++] = '.';
				}
			}
			else
			{
				str_val[index++] = ' ';
				str_val[index++] = ' ';
				str_val[index++] = ' ';
				str[str_index++] = ' ';
			}
		}
		str_val[index++] = ' ';
		str_val[index++] = ' ';
		memcpy(&str_val[index], str, str_index);
		index += str_index;
		str_val[index++] = '\n';
		str_val[index++] = '\0';
		log_hook(str_val);
	}
	return 0;
}

#endif

