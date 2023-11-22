## embedded-log
[![Travis](https://img.shields.io/badge/release-2.0.0-blue.svg?style=plastic)](https://github.com/to9/embedded-log/releases)
[![Travis](https://img.shields.io/badge/build-passing-brightgreen.svg?style=plastic)](https://github.com/to9/embedded-log/releases)
[![Crates.io](https://img.shields.io/packagist/l/doctrine/orm.svg?style=plastic)](https://github.com/to9/embedded-log/blob/master/LICENSE)

```
                 _              _     _          _   _             
                | |            | |   | |        | | | |            
   ___ _ __ ___ | |__   ___  __| | __| | ___  __| | | | ___   __ _ 
  / _ \ '_ ` _ \| '_ \ / _ \/ _` |/ _` |/ _ \/ _` | | |/ _ \ / _` |
 |  __/ | | | | | |_) |  __/ (_| | (_| |  __/ (_| | | | (_) | (_| |
  \___|_| |_| |_|_.__/ \___|\__,_|\__,_|\___|\__,_| |_|\___/ \__, |
                                                ______        __/ |
                                               |______|      |___/ 
```
## Description

**`embedded-log`**  is a small and beautiful embedded log library. With color output, log information can be specified to be output to serial port, screen, FLASH, or output to PC through USB. Written in C language, can be used on devices such as C51 and arm.

## View
- Log serial output:

<div align=left><img width="593" height="123" src="https://github.com/to9/embedded-log/blob/master/images/log1.png"/></div>

<div align=left><img width="592" height="218" src="https://github.com/to9/embedded-log/blob/master/images/log2.png"/></div>

## How is embedded-log used?
#### 1: Add three files to your project
- `log_cfg.h`, `log.h`, `log.c`

#### 2: Init log funtcion

You need to define an output buffer (such as 512 bytes). use **`log_init`** Initialize init and pass in the callback function, call the function as the final output of the data, which can be output to the serial port, USB, screen, internal flash, and any other place you want to output.

```c
char g_log_buff[512];
log_init(g_log_buff, sizeof(g_log_buff), MID_LOG_Put);
```

- Dynamic setting of log level， default verbose

  > LOG_LEVEL_CLOS  
  > LOG_LEVEL_ASSERT  
  > LOG_LEVEL_ERROR    
  > LOG_LEVEL_WARNING    
  > LOG_LEVEL_INFO  
  > LOG_LEVEL_DEBUG    
  > LOG_LEVEL_VERBOSE   
  
```c
log_set_level(LOG_LEVEL_ERROR);
```

- Output to the serial port
```c
void MID_LOG_Put(const char *str) {
	HAL_UART_Send((UINT_8 *)str, strlen(str));
}
```
- Output to the usb/screen/flash
```c
void MID_LOG_Put(const char *str) {
	HID_USB_WriteData((UINT_8 *)str, strlen(str));
}

void MID_LOG_Put(const char *str) {
	MID_TFT_DisInfo_n((UINT_8 *)str, strlen(str), 0, 0);
}

void MID_LOG_Put(const char *str) {
	MID_FlashWrite(0x8000, (UINT_8 *)str, strlen(str));
}
```
#### 3: Used function
```c
  LOG_WRN("The file system is not initialized.");
  LOG_INF("init file system ok.");
  LOG_ERR("recv data error!");
  LOG_ASS("assert message");
  LOG_VBS("verbose message");

  LOG_INF("get data from queue.");
  u16DataLen = (u16DataLen > 1024) ? 1024 : u16DataLen;
  LOG_DBG("Msg recv length: %d", u16DataLen);
  LOG_DBG_HEX("BT Msg:", g_BtMsgBufCom, u16DataLen);
  LOG_ASS_HEX("BT Msg:", g_BtMsgBufCom, u16DataLen);
  LOG_ERR_HEX("BT Msg:", g_BtMsgBufCom, u16DataLen);
  LOG_WRN_HEX("BT Msg:", g_BtMsgBufCom, u16DataLen);
  LOG_DBG_HEX("BT Msg:", g_BtMsgBufCom, u16DataLen);
  LOG_INF_HEX("BT Msg:", g_BtMsgBufCom, u16DataLen);
  LOG_ASS_HEX("BT Msg:", g_BtMsgBufCom, u16DataLen);  
```
## Advanced used

Modifying configuration files can provide more features such as custom colors, style wrapping, and more.

- log_cfg.h
```c
#define LOG_DISABLE			// 关闭日志功能
#define LOG_COLOR_ENABLE		// 是否开启彩色输出, 默认开启
#define LOG_TAGS_ENABLE			// 是否输出日志类型标签, 默认输出
#define LOG_NEWLINE_ENABLE		// 是否使用换行符"\r\n"
#define LOG_NEWLINE "\r\n"              // 配置输出换行符
```

- Customize log output colors
```c
#define LOG_ASS_COLOR "\x1B[95m"
#define LOG_ERR_COLOR "\x1B[91m"
#define LOG_WRN_COLOR "\x1B[93m"
#define LOG_INF_COLOR "\x1B[94m"
#define LOG_DBG_COLOR "\x1B[92m"
#define LOG_ASS_HEX_COLOR "\x1B[95m"
#define LOG_ERR_HEX_COLOR "\x1B[91m"
#define LOG_WRN_HEX_COLOR "\x1B[93m"
#define LOG_INF_HEX_COLOR "\x1B[94m"
#define LOG_DBG_HEX_COLOR "\x1B[92m"
```

## PC Tool
- **SecurtCRT**
  
  📢: 不支持彩色日志输出，`LOG_COLOR_ENABLE` 应该被关闭
- **AccessPort** 
  
  📢: 不支持彩色日志输出，`LOG_COLOR_ENABLE` 应该被关闭。
- **MobaXtern**
  
  支持彩色日志输出。
## License

Copyright (c) 2017-present, G.D.
