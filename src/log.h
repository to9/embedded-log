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

#ifndef LOG_H
#define LOG_H

#include "log_cfg.h"

#ifdef __cplusplus
extern "C" {
#endif

#define LOG_VERSION "1.0.0"


#define LOG_LEVEL_ASSERT 		0
#define LOG_LEVEL_ERROR 		1
#define LOG_LEVEL_WARNING 		2
#define LOG_LEVEL_INFO 			3
#define LOG_LEVEL_DEBUG 		4

#if !defined(LOG_CONFIG_LEVEL)
#define LOG_LEVEL LOG_LEVEL_DEBUG
#else
#define LOG_LEVEL LOG_CONFIG_LEVEL
#endif


#if defined(LOG_ENABLE)
extern int printk(const char *format, ...);
extern void (*log_hook)(const char *str);
extern void log_init(char *buff, unsigned int buff_len, void (*hook)(const char *));
extern int printk_hex(unsigned char *buff, unsigned int count);

#define LOG_COLOR_NONE    		""
#define LOG_COLOR_OFF     		"\x1B[0m"
#define LOG_COLOR_RED     		"\x1B[0;31m"
#define LOG_COLOR_LIGHT_RED     "\x1B[1;31m"
#define LOG_COLOR_GREEB     	"\x1B[0;32m"
#define LOG_COLOR_LIGHT_GREEN   "\x1B[1;32m"
#define LOG_COLOR_YELLOW  		"\x1B[0;33m"
#define LOG_COLOR_LIGHT_YELLOW  "\x1B[1;33m"
#define LOG_COLOR_BLUE  		"\x1B[0;34m"
#define LOG_COLOR_LIGHT_BLUE  	"\x1B[1;34m"
#define LOG_COLOR_MAGENTA  		"\x1B[0;35m"
#define LOG_COLOR_LIGHT_MAGENTA	"\x1B[1;35m"
#define LOG_COLOR_CYAN  		"\x1B[0;36m"
#define LOG_COLOR_LIGHT_CYAN	"\x1B[1;36m"

#if defined(LOG_CONFIG_TAGS)
#define LOG_TAG_ASS				"[ASS] "
#define LOG_TAG_ERR 			"[ERR] "
#define LOG_TAG_WRN 			"[WRN] "
#define LOG_TAG_INF 			"[INF] "
#define LOG_TAG_DBG 			"[DBG] "
#else
#define LOG_TAG_ASS 			""
#define LOG_TAG_ERR 			""
#define LOG_TAG_WRN 			""
#define LOG_TAG_INF 			""
#define LOG_TAG_DBG 			""
#endif


#if !defined(LOG_CONFIG_ASS_COLOR)
#define LOG_TAG_ASS_COLOR			LOG_COLOR_LIGHT_MAGENTA
#else
#define LOG_TAG_ASS_COLOR			LOG_CONFIG_ASS_COLOR
#endif

#if !defined(LOG_CONFIG_ERR_COLOR)
#define LOG_TAG_ERR_COLOR			LOG_COLOR_LIGHT_RED
#else
#define LOG_TAG_ERR_COLOR			LOG_CONFIG_ERR_COLOR
#endif

#if !defined(LOG_CONFIG_WRN_COLOR)
#define LOG_TAG_WRN_COLOR			LOG_COLOR_LIGHT_YELLOW
#else
#define LOG_TAG_WRN_COLOR			LOG_CONFIG_WRN_COLOR
#endif

#if !defined(LOG_CONFIG_INF_COLOR)
#define LOG_TAG_INF_COLOR			LOG_COLOR_LIGHT_BLUE
#else
#define LOG_TAG_INF_COLOR			LOG_CONFIG_INF_COLOR
#endif

#if !defined(LOG_CONFIG_DBG_COLOR)
#define LOG_TAG_DBG_COLOR			LOG_COLOR_LIGHT_GREEN//LOG_COLOR_NONE
#else
#define LOG_TAG_DBG_COLOR			LOG_COLOR_LIGHT_GREEN
#endif



#if !defined(LOG_CONFIG_NEWLINE)
#define LOG_NEWLINE ""
#else
#define LOG_NEWLINE "\n"
#endif

#if defined(LOG_CONFIG_COLOR)
#define LOG_CALL_TPYE(tag, tag_color, format, ...)	\
	printk("%s%s%s(%d): " format "%s" LOG_NEWLINE,	\
	       tag_color, tag, __FILE__, __LINE__, ##__VA_ARGS__, LOG_COLOR_OFF)

#define LOG_CALL_TPYE0(color) printk("%s" color)
#else
#define LOG_CALL_TPYE(tag, tag_color, format, ...)	\
	printk("%s%s%s(%d): " format "%s" LOG_NEWLINE,	\
	       LOG_COLOR_NONE, tag, __FILE__, __LINE__, ##__VA_ARGS__, LOG_COLOR_NONE)

#define LOG_CALL_TPYE0(color) { ; }
#endif


#define LOG_COLOR0(color) LOG_CALL_TPYE0(color)
#define LOG_COLOR(tag, tag_color, format, ...) LOG_CALL_TPYE(tag, tag_color, format, ##__VA_ARGS__)

#if (LOG_LEVEL >= LOG_LEVEL_ASSERT)
#define LOG_ASS(EX) \
	if(!(EX)) \
	{ \
		LOG_COLOR(LOG_TAG_ASS, LOG_TAG_ASS_COLOR, "assert: '" #EX "' failed"); \
	}
#endif

#if (LOG_LEVEL >= LOG_LEVEL_ERROR)
#define LOG_ERR(format, ...) LOG_COLOR(LOG_TAG_ERR, LOG_TAG_ERR_COLOR, format, ##__VA_ARGS__)
#endif

#if (LOG_LEVEL >= LOG_LEVEL_WARNING)
#define LOG_WRN(format, ...) LOG_COLOR(LOG_TAG_WRN,	LOG_TAG_WRN_COLOR, format, ##__VA_ARGS__)
#endif

#if (LOG_LEVEL >= LOG_LEVEL_INFO)
#define LOG_INF(format, ...) LOG_COLOR(LOG_TAG_INF,	LOG_TAG_INF_COLOR, format, ##__VA_ARGS__)
#endif

#if (LOG_LEVEL >= LOG_LEVEL_DEBUG)
#define LOG_DBG(format, ...) LOG_COLOR(LOG_TAG_DBG,	LOG_TAG_DBG_COLOR, format, ##__VA_ARGS__)

#define LOG_DBG_HEX(format, buff, len) { \
		LOG_COLOR(LOG_TAG_DBG, LOG_TAG_DBG_COLOR, "%s", format); \
		LOG_COLOR0(LOG_TAG_DBG_COLOR); \
		printk_hex(buff, len); \
		LOG_COLOR0(LOG_COLOR_OFF); \
	}
#endif

#else
#define printk(...) { ; }
#define log_init(...) { ; }
#endif


#if !defined(LOG_ASS)
#define LOG_ASS(format, ...) { ; }
#endif

#if !defined(LOG_ERR)
#define LOG_ERR(format, ...) { ; }
#endif

#if !defined(LOG_WRN)
#define LOG_WRN(format, ...) { ; }
#endif

#if !defined(LOG_INF)
#define LOG_INF(format, ...) { ; }
#endif

#if !defined(LOG_DBG)
#define LOG_DBG(format, ...) { ; }
#define LOG_DBG_HEX(format, buff, len) { ; }
#endif


#ifdef __cplusplus
}
#endif

#endif//LOG_H

