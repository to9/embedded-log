#include "log.h"

char g_log_buff[512];

void MID_LOG_Put(const char *str) {
	printf("%s", str);
}

int main(int argc, char const* argv[]) {
    uint8_t buff[32] = "123456778abcdef2222";
    uint32_t sensors = 0u;
	
    log_init(g_log_buff, sizeof(g_log_buff), MID_LOG_Put);
  
    printf("111111111111111111\r\n");
    LOG_VBS("verbose message");
    printf("111111111111111111\r\n");
    LOG_VBS_HEX("verbose message hex", buff, 32);
    printf("111111111111111111\r\n");
    LOG_INF("info message");
    printf("111111111111111111\r\n");
    LOG_INF_HEX("info message hex\r\n", buff, 32);
    LOG_DBG("debug message");
    LOG_DBG_HEX("debug message hex", buff, 32);
    LOG_WRN("warning message");
    LOG_WRN_HEX("warning message hex", buff, 32);
    LOG_ERR("error message");
    LOG_ERR_HEX("error message hex", buff, 32);    
    LOG_ASS(sensors == 1);
    LOG_ASS_MSG(sensors == 1, "assert message: %s, len: %d", buff, sizeof(buff));
    LOG_ASS_HEX(sensors == 1, "assert message hex", buff, 32);
    log_set_level(LOG_LEVEL_WARNING);
    LOG_VBS("verbose message");
    LOG_VBS_HEX("verbose message hex", buff, 32);
    LOG_INF("info message");
    LOG_INF_HEX("info message hex", buff, 32);
    LOG_DBG("debug message");
    LOG_DBG_HEX("debug message hex", buff, 32);
    LOG_WRN("warning message");
    LOG_WRN_HEX("warning message hex", buff, 32);
    LOG_ERR("error message");
    LOG_ERR_HEX("error message hex", buff, 32);
    LOG_ASS(sensors == 1);
    LOG_ASS_MSG(sensors == 1, "assert message: %s, len: %d", buff, sizeof(buff));
    LOG_ASS_HEX(sensors == 1, "assert message hex", buff, 32);
    log_set_level(LOG_LEVEL_ERROR);
    LOG_VBS("verbose message");
    LOG_VBS_HEX("verbose message hex", buff, 32);
    LOG_INF("info message");
    LOG_INF_HEX("info message hex", buff, 32);
    LOG_DBG("debug message");
    LOG_DBG_HEX("debug message hex", buff, 32);
    LOG_WRN("warning message");
    LOG_WRN_HEX("warning message hex", buff, 32);
    LOG_ERR("error message");
    LOG_ERR_HEX("error message hex", buff, 32);
    LOG_ASS(sensors == 1);
    LOG_ASS_MSG(sensors == 1, "assert message: %s, len: %d", buff, sizeof(buff));
    LOG_ASS_HEX(sensors == 1, "assert message hex", buff, 32);
    printf("111111111111111111\r\n");
    return 0;
}
