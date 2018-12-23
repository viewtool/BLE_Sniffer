#ifndef COMMON_H
#define COMMON_H

#define CONSOLE_MODE    1
#define CONSOLE_HEX_MODE  1
#define APP_NO_THREAD   0
#define RESPONSE_DATA_THROUGHT_UART    1


extern int ota_flag;


extern void printf_mac_addr(unsigned char *addr);
extern void printf_hex_data(unsigned char *d, int size);


#endif // COMMON_H
