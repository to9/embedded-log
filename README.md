## embedded-log
[![Travis](https://img.shields.io/badge/release-1.0.0-blue.svg?style=plastic)](https://github.com/to9/embedded-log)
[![Travis](https://img.shields.io/travis/rust-lang/rust.svg?style=plastic)](https://github.com/to9/embedded-log)

## Description

embedded-log 是一个小巧漂亮的嵌入式日志库。具有彩色输出，也可指定通过uart或usb输出到pc上。使用c语言编写，可用于C51、arm等设备上。

## View
- Log serial output:

<div align=left><img width="593" height="123" src="https://github.com/to9/embedded-log/blob/master/images/log1.png"/></div>

<div align=left><img width="592" height="218" src="https://github.com/to9/embedded-log/blob/master/images/log2.png"/></div>

## How is log used?
#### 1: Add three files to your project directory
- log_cfg.h
- log.h
- log.c

#### 2: Init log funtcion
- Output to the serial port
```c
char g_log_buff[512];

void MID_LOG_Put(const char *str)
{
	HAL_UART_Send((UINT_8 *)str, strlen(str));
}

void MID_LOG_Init(void)
{
	HAL_UART_Init();
	log_init(g_log_buff, sizeof(g_log_buff), MID_LOG_Put);
}
```
- Output to the USB/Screen/flash
```c
void MID_LOG_Put(const char *str)
{
	HID_USB_WriteData((UINT_8 *)str, strlen(str));
}

void MID_LOG_Put(const char *str)
{
	MID_TFT_DisInfo_n((UINT_8 *)str, strlen(str), 0, 0);
}

void MID_LOG_Put(const char *str)
{
	MID_FlashWrite(0x8000, (UINT_8 *)str, strlen(str));
}
```
#### 3: Used function
```c
  LOG_WRN("The file system is not initialized.");
  LOG_INF("init file system ok.");
  LOG_ERR("recv data error!");
  LOG_ASS(g_test_count > 101);

  LOG_INF("get data from queue.");
  u16DataLen = (u16DataLen > 1024) ? 1024 : u16DataLen;
  LOG_DBG("Msg recv length: %d", u16DataLen);
  LOG_DBG_HEX("BT Msg:", g_BtMsgBufCom, u16DataLen);
```
## Advanced used
- log_cfg.h file configuration instructions

```c
#define LOG_ENABLE			//关闭日志功能
#define LOG_CONFIG_LEVEL 4		//设置日志等级
#define LOG_CONFIG_COLOR		//是否开启彩色输出, 默认开启
#define LOG_CONFIG_TAGS			//是否输出日志类型标签, 默认输出
#define LOG_CONFIG_NEWLINE		//是否使用换行符"\n"
```
## PC Tool
- SecurtCRT
- AccessPort
- MobaXtern

## License

[![Crates.io](https://img.shields.io/packagist/l/doctrine/orm.svg?style=plastic)](https://github.com/to9/CodeStyle)<br>

Copyright (c) 2017-present, G.D.
