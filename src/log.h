/*************************************************************************************
**                 _              _     _          _   _
**                | |            | |   | |        | | | |
**   ___ _ __ ___ | |__   ___  __| | __| | ___  __| | | | ___   __ _
**  / _ \ '_ ` _ \| '_ \ / _ \/ _` |/ _` |/ _ \/ _` | | |/ _ \ / _` |
** |  __/ | | | | | |_) |  __/ (_| | (_| |  __/ (_| | | | (_) | (_| |
**  \___|_| |_| |_|_.__/ \___|\__,_|\__,_|\___|\__,_| |_|\___/ \__, |
**                                                ______        __/ |
**                                               |______|      |___/
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

// software version number
#define LOG_VERSION "2.0.0"

// 定义日志等级
typedef enum LOG_LEVEL {
  LOG_LEVEL_CLOSE = 0,
  LOG_LEVEL_ASSERT,
  LOG_LEVEL_ERROR,
  LOG_LEVEL_WARNING,
  LOG_LEVEL_INFO,
  LOG_LEVEL_DEBUG,
  LOG_LEVEL_VERBOSE
} LogLevel;

extern unsigned char g_log_level;

// 定义打印函数和钩子函数
extern void (*log_hook)(const char *str);
extern void log_init(char *buff, unsigned int buff_len, void (*hook)(const char *));
extern void log_set_level(LogLevel level);

#ifndef LOG_DISABLE
extern void printk(const char *format, ...);
extern int printk_hex(unsigned char *buff, unsigned int count, const char *color);

// font color
#define LOG_COLOR_NORMAL "\x1B[0m"
#define LOG_COLOR_BLACK "\x1B[30m"
#define LOG_COLOR_RED "\x1B[31m"
#define LOG_COLOR_GREEN "\x1B[32m"
#define LOG_COLOR_YELLOW "\x1B[33m"
#define LOG_COLOR_BLUE "\x1B[34m"
#define LOG_COLOR_MAGENTA "\x1B[35m"
#define LOG_COLOR_CYAN "\x1B[36m"
#define LOG_COLOR_WHITE "\x1B[37m"
#define LOG_COLOR_LIGHT_BLACK "\x1B[90m"
#define LOG_COLOR_LIGHT_RED "\x1B[91m"
#define LOG_COLOR_LIGHT_GREEN "\x1B[92m"
#define LOG_COLOR_LIGHT_YELLOW "\x1B[93m"
#define LOG_COLOR_LIGHT_BLUE "\x1B[94m"
#define LOG_COLOR_LIGHT_MAGENTA "\x1B[95m"
#define LOG_COLOR_LIGHT_CYAN "\x1B[96m"
#define LOG_COLOR_LIGHT_WHITE "\x1B[97m"

// background color
#define LOG_COLOR_BACKGROUND_BLACK "\x1B[40m"
#define LOG_COLOR_BACKGROUND_RED "\x1B[41m"
#define LOG_COLOR_BACKGROUND_GREEN "\x1B[42m"
#define LOG_COLOR_BACKGROUND_YELLOW "\x1B[43m"
#define LOG_COLOR_BACKGROUND_BLUE "\x1B[44m"
#define LOG_COLOR_BACKGROUND_MAGENTA "\x1B[45m"
#define LOG_COLOR_BACKGROUND_CYAN "\x1B[46m"
#define LOG_COLOR_BACKGROUND_WHITE "\x1B[47m"
#define LOG_COLOR_BACKGROUND_LIGHT_BLACK "\x1B[100m"
#define LOG_COLOR_BACKGROUND_LIGHT_RED "\x1B[101m"
#define LOG_COLOR_BACKGROUND_LIGHT_GREEN "\x1B[102m"
#define LOG_COLOR_BACKGROUND_LIGHT_YELLOW "\x1B[103m"
#define LOG_COLOR_BACKGROUND_LIGHT_BLUE "\x1B[104m"
#define LOG_COLOR_BACKGROUND_LIGHT_MAGENTA "\x1B[105m"
#define LOG_COLOR_BACKGROUND_LIGHT_CYAN "\x1B[106m"
#define LOG_COLOR_BACKGROUND_LIGHT_WHITE "\x1B[107m"

// 日志标签名字
#ifdef LOG_TAGS_ENABLE
#define LOG_TAG_ASS "[ASS] "
#define LOG_TAG_ERR "[ERR] "
#define LOG_TAG_WRN "[WRN] "
#define LOG_TAG_INF "[INF] "
#define LOG_TAG_DBG "[DBG] "
#define LOG_TAG_VBS "[VBS] "
#else
#define LOG_TAG_ASS ""
#define LOG_TAG_ERR ""
#define LOG_TAG_WRN ""
#define LOG_TAG_INF ""
#define LOG_TAG_DBG ""
#define LOG_TAG_VBS ""
#endif

// 日志标签颜色
#ifndef LOG_ASS_COLOR
#define LOG_TAG_ASS_COLOR LOG_COLOR_LIGHT_MAGENTA
#else
#define LOG_TAG_ASS_COLOR LOG_ASS_COLOR
#endif

#ifndef LOG_ERR_COLOR
#define LOG_TAG_ERR_COLOR LOG_COLOR_LIGHT_RED
#else
#define LOG_TAG_ERR_COLOR LOG_ERR_COLOR
#endif

#ifndef LOG_WRN_COLOR
#define LOG_TAG_WRN_COLOR LOG_COLOR_LIGHT_YELLOW
#else
#define LOG_TAG_WRN_COLOR LOG_WRN_COLOR
#endif

#ifndef LOG_INF_COLOR
#define LOG_TAG_INF_COLOR LOG_COLOR_LIGHT_BLUE
#else
#define LOG_TAG_INF_COLOR LOG_INF_COLOR
#endif

#ifndef LOG_DBG_COLOR
#define LOG_TAG_DBG_COLOR LOG_COLOR_LIGHT_GREEN
#else
#define LOG_TAG_DBG_COLOR LOG_DBG_COLOR
#endif

#ifndef LOG_VBS_COLOR
#define LOG_TAG_VBS_COLOR LOG_COLOR_LIGHT_CYAN
#else
#define LOG_TAG_VBS_COLOR LOG_VBS_COLOR
#endif

#ifndef LOG_ASS_HEX_COLOR
#define LOG_TAG_ASS_HEX_COLOR LOG_COLOR_LIGHT_MAGENTA
#else
#define LOG_TAG_ASS_HEX_COLOR LOG_ASS_HEX_COLOR
#endif

#ifndef LOG_ERR_HEX_COLOR
#define LOG_TAG_ERR_HEX_COLOR LOG_COLOR_LIGHT_RED
#else
#define LOG_TAG_ERR_HEX_COLOR LOG_ERR_HEX_COLOR
#endif

#ifndef LOG_WRN_HEX_COLOR
#define LOG_TAG_WRN_HEX_COLOR LOG_COLOR_LIGHT_YELLOW
#else
#define LOG_TAG_WRN_HEX_COLOR LOG_WRN_HEX_COLOR
#endif

#ifndef LOG_INF_HEX_COLOR
#define LOG_TAG_INF_HEX_COLOR LOG_COLOR_LIGHT_BLUE
#else
#define LOG_TAG_INF_HEX_COLOR LOG_INF_HEX_COLOR
#endif

#ifndef LOG_DBG_HEX_COLOR
#define LOG_TAG_DBG_HEX_COLOR LOG_COLOR_LIGHT_GREEN
#else
#define LOG_TAG_DBG_HEX_COLOR LOG_DBG_HEX_COLOR
#endif

#ifndef LOG_VBS_HEX_COLOR
#define LOG_TAG_VBS_HEX_COLOR LOG_COLOR_LIGHT_CYAN
#else
#define LOG_TAG_VBS_HEX_COLOR LOG_VBS_HEX_COLOR
#endif

// line ending type
#ifndef LOG_NEWLINE_ENABLE
#define LOG_NEWLINE_CHAR ""
#else
#ifndef LOG_NEWLINE
#define LOG_NEWLINE_CHAR "\r\n"
#else
#define LOG_NEWLINE_CHAR LOG_NEWLINE
#endif
#endif

// file name
#ifndef LOG_FILE_FULL_PATH
#ifndef LOG_STRCHR_SYS
extern char *strrchr_1(char *string, int ch);
#define _STRCHR_ strrchr_1
#else
#define _STRCHR_ strrchr
#endif
#define LOG_FILE_NAME                                                        \
  (_STRCHR_((char *)__FILE__, '/')    ? _STRCHR_((char *)__FILE__, '/') + 1  \
   : _STRCHR_((char *)__FILE__, '\\') ? _STRCHR_((char *)__FILE__, '\\') + 1 \
                                      : (char *)__FILE__)
#else
#define LOG_FILE_NAME __FILE__
#endif

// log color
#ifdef LOG_COLOR_ENABLE
#define LOG_CALL_TPYE(tag, tag_color, format, ...) \
  printk("%s%s%s(%d): " format "%s" LOG_NEWLINE_CHAR, tag_color, tag, LOG_FILE_NAME, __LINE__, ##__VA_ARGS__, LOG_COLOR_NORMAL)

#define LOG_HEX_CALL_TPYE(data, len, tag_color) printk_hex(data, len, tag_color)
#else
#define LOG_CALL_TPYE(tag, tag_color, format, ...) \
  printk("%s%s%s(%d): " format "%s" LOG_NEWLINE_CHAR, "", tag, LOG_FILE_NAME, __LINE__, ##__VA_ARGS__, "")

#define LOG_HEX_CALL_TPYE(data, len, tag_color) printk_hex(data, len, NULL)
#endif

#endif  // LOG_DISABLE

// ASSERT
#if !defined(LOG_DISABLE)
#define LOG_ASS(format, ...)                                                \
  do {                                                                      \
    if (g_log_level >= LOG_LEVEL_ASSERT) {                                  \
      LOG_CALL_TPYE(LOG_TAG_ASS, LOG_TAG_ASS_COLOR, format, ##__VA_ARGS__); \
    }                                                                       \
  } while (0)

#define LOG_ASS_HEX(format, buff, len)                                 \
  do {                                                                 \
    if (g_log_level >= LOG_LEVEL_ASSERT) {                             \
      LOG_CALL_TPYE(LOG_TAG_ASS, LOG_TAG_ASS_HEX_COLOR, "%s", format); \
      LOG_HEX_CALL_TPYE(buff, len, LOG_TAG_ASS_HEX_COLOR);             \
    }                                                                  \
  } while (0)
#else
#define LOG_ASS(...)
#define LOG_ASS_HEX(...)
#endif

// ERROR
#if !defined(LOG_DISABLE)
#define LOG_ERR(format, ...)                                                \
  do {                                                                      \
    if (g_log_level >= LOG_LEVEL_ERROR) {                                   \
      LOG_CALL_TPYE(LOG_TAG_ERR, LOG_TAG_ERR_COLOR, format, ##__VA_ARGS__); \
    }                                                                       \
  } while (0)

#define LOG_ERR_HEX(format, buff, len)                                 \
  do {                                                                 \
    if (g_log_level >= LOG_LEVEL_ERROR) {                              \
      LOG_CALL_TPYE(LOG_TAG_ERR, LOG_TAG_ERR_HEX_COLOR, "%s", format); \
      LOG_HEX_CALL_TPYE(buff, len, LOG_TAG_ERR_HEX_COLOR);             \
    }                                                                  \
  } while (0)
#else
#define LOG_ERR(...)
#define LOG_ERR_HEX(...)
#endif

// WARNING
#if !defined(LOG_DISABLE)
#define LOG_WRN(format, ...)                                                \
  do {                                                                      \
    if (g_log_level >= LOG_LEVEL_WARNING) {                                 \
      LOG_CALL_TPYE(LOG_TAG_WRN, LOG_TAG_WRN_COLOR, format, ##__VA_ARGS__); \
    }                                                                       \
  } while (0)

#define LOG_WRN_HEX(format, buff, len)                                 \
  do {                                                                 \
    if (g_log_level >= LOG_LEVEL_WARNING) {                            \
      LOG_CALL_TPYE(LOG_TAG_WRN, LOG_TAG_WRN_HEX_COLOR, "%s", format); \
      LOG_HEX_CALL_TPYE(buff, len, LOG_TAG_WRN_HEX_COLOR);             \
    }                                                                  \
  } while (0)
#else
#define LOG_WRN(...)
#define LOG_WRN_HEX(...)
#endif

// INFO
#if !defined(LOG_DISABLE)
#define LOG_INF(format, ...)                                                \
  do {                                                                      \
    if (g_log_level >= LOG_LEVEL_INFO) {                                    \
      LOG_CALL_TPYE(LOG_TAG_INF, LOG_TAG_INF_COLOR, format, ##__VA_ARGS__); \
    }                                                                       \
  } while (0)

#define LOG_INF_HEX(format, buff, len)                                 \
  do {                                                                 \
    if (g_log_level >= LOG_LEVEL_INFO) {                               \
      LOG_CALL_TPYE(LOG_TAG_INF, LOG_TAG_INF_HEX_COLOR, "%s", format); \
      LOG_HEX_CALL_TPYE(buff, len, LOG_TAG_INF_HEX_COLOR);             \
    }                                                                  \
  } while (0)
#else
#define LOG_INF(...)
#define LOG_INF_HEX(...)
#endif

// DEBUG
#if !defined(LOG_DISABLE)
#define LOG_DBG(format, ...)                                                \
  do {                                                                      \
    if (g_log_level >= LOG_LEVEL_DEBUG) {                                   \
      LOG_CALL_TPYE(LOG_TAG_DBG, LOG_TAG_DBG_COLOR, format, ##__VA_ARGS__); \
    }                                                                       \
  } while (0)

#define LOG_DBG_HEX(format, buff, len)                                 \
  do {                                                                 \
    if (g_log_level >= LOG_LEVEL_DEBUG) {                              \
      LOG_CALL_TPYE(LOG_TAG_DBG, LOG_TAG_DBG_HEX_COLOR, "%s", format); \
      LOG_HEX_CALL_TPYE(buff, len, LOG_TAG_DBG_HEX_COLOR);             \
    }                                                                  \
  } while (0)
#else
#define LOG_DBG(...)
#define LOG_DBG_HEX(...)
#endif

// VERBOSE
#if !defined(LOG_DISABLE)
#define LOG_VBS(format, ...)                                                \
  do {                                                                      \
    if (g_log_level >= LOG_LEVEL_VERBOSE) {                                 \
      LOG_CALL_TPYE(LOG_TAG_VBS, LOG_TAG_VBS_COLOR, format, ##__VA_ARGS__); \
    }                                                                       \
  } while (0)

#define LOG_VBS_HEX(format, buff, len)                                 \
  do {                                                                 \
    if (g_log_level >= LOG_LEVEL_VERBOSE) {                            \
      LOG_CALL_TPYE(LOG_TAG_VBS, LOG_TAG_VBS_HEX_COLOR, "%s", format); \
      LOG_HEX_CALL_TPYE(buff, len, LOG_TAG_VBS_HEX_COLOR);             \
    }                                                                  \
  } while (0)
#else
#define LOG_VBS(...)
#define LOG_VBS_HEX(...)
#endif

#ifdef __cplusplus
}
#endif

#endif  // LOG_H
