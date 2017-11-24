## embedded-log
[![Travis](https://img.shields.io/badge/release-1.0.0-blue.svg?style=plastic)](https://github.com/to9/embedded-log)
[![Travis](https://img.shields.io/travis/rust-lang/rust.svg?style=plastic)](https://github.com/to9/embedded-log)

## Description

是一个漂亮的可选彩色输出不级别别嵌入式日志库。

## View

* Simple:

<div align=left><img width="593" height="123" src="https://github.com/to9/embedded-log/blob/master/images/log1.png"/></div>

<div align=left><img width="592" height="218" src="https://github.com/to9/embedded-log/blob/master/images/log2.png"/></div>

## How is log used?
#### 1: Add three files to your project directory
- log_cfg.h
- log.h
- log.c

#### 2: Init log funtcion
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
## License

[![Crates.io](https://img.shields.io/packagist/l/doctrine/orm.svg?style=plastic)](https://github.com/to9/CodeStyle)<br>

Copyright (c) 2017-present, G.D.
