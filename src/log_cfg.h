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

#ifndef LOG_CFG_H
#define LOG_CFG_H

// Disable log output
// #define LOG_DISABLE

// Enable full path display of file in output as long
#define LOG_FILE_FULL_PATH

// Enable newline and setting output newline sign
#define LOG_NEWLINE_ENABLE
#define LOG_NEWLINE "\r\n"

// Enable log color 
#define LOG_COLOR_ENABLE

// Enable log tags 
#define LOG_TAGS_ENABLE

// Customize log output colors according to log levels，use ANSI Escape Codes in a terminal.
// #define LOG_ASS_COLOR "\x1B[95m"
// #define LOG_ERR_COLOR "\x1B[91m"
// #define LOG_WRN_COLOR "\x1B[93m"
// #define LOG_INF_COLOR "\x1B[94m"
// #define LOG_DBG_COLOR "\x1B[92m"
// #define LOG_ASS_HEX_COLOR "\x1B[95m"
// #define LOG_ERR_HEX_COLOR "\x1B[91m"
// #define LOG_WRN_HEX_COLOR "\x1B[93m"
// #define LOG_INF_HEX_COLOR "\x1B[94m"
// #define LOG_DBG_HEX_COLOR "\x1B[92m"

#endif  // LOG_CFG_H
