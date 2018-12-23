/**
 ****************************************************************************************
 *
 * @file vtcom.h
 *
 * @brief com port function
 *
 * Copyright (C) ViewTool 2018
 *
 * $Rev: 1.0$
 *
 * Change History:
 * 12/21/18: Initial release, working on capturing BLE data, see captured data in file: 2018.12.21-14.52.34.txt
 *
 ****************************************************************************************
 */

#ifndef VTCOM_H
#define VTCOM_H

//#define ENABLE_LINUX
//#define ENABLE_MAC    //
#define ENABLE_WINDOWS //

#ifdef ENABLE_WINDOWS
#include <windows.h>
#endif

#ifdef ENABLE_LINUX
#include <stdio.h>     
#include <stdlib.h>    
#include <unistd.h>   
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>      
#include <termios.h> 
#include <errno.h>    
#include <string.h>    
#endif

#ifdef ENABLE_MAC
#include <stdio.h>     
#include <stdlib.h>    
#include <unistd.h>   
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>     
#include <termios.h>
#include <errno.h>   
#include <string.h>   
#endif

#include <stdio.h>
#include <QString>
typedef unsigned int DLDRESULT;

#define MAKE_DRESULT(sev,fac,code) \
((DLDRESULT) (((unsigned long)(sev)<<31) | ((unsigned long)(fac)<<16) | ((unsigned long)(code))) )

#define MAKE_RET_RESULT(sev,fac,code) MAKE_DRESULT(sev, 4,        \
((fac << 6) | (code)))
//Error code
#define PR_GLO 0  /* General errors                             */
#define PR_USB 1  /* USB errors                             */
#define PR_I2C 2  /* I2C errors                             */
#define PR_MSC 3  /* Other errors                             */
#define PR_FIL 4  /* File errors     */
#define PR_COM 5  /* COM communication errors */

#define RET_OK           0
#define RET_FALSE        1

#define RET_GEN_BUFOVERFLOW          MAKE_RET_RESULT(1,PR_GLO,0)                  // 80040000
#define RET_GEN_TIMEOUT        MAKE_RET_RESULT(1,PR_GLO,1)                  // 80040001
#define RET_GEN_ERRPARAM        MAKE_RET_RESULT(1,PR_GLO,2)                  // 80040002
#define RET_USB_WRITEFAIL          MAKE_RET_RESULT(1,PR_USB,0)                  // 80040040
#define RET_USB_READFAIL          MAKE_RET_RESULT(1,PR_USB,1)                  // 80040041
#define RET_USB_CMDERROR          MAKE_RET_RESULT(1,PR_USB,2)                  // 80040042
#define RET_USB_CMD2ERROR          MAKE_RET_RESULT(1,PR_USB,3)                  // 80040043
#define RET_USB_READTIMEOUT	       MAKE_RET_RESULT(1,PR_USB,4)                  // 80040044
#define RET_USB_WRITETIMEOUT	       MAKE_RET_RESULT(1,PR_USB,5)                  // 80040045
#define RET_USB_READILL	       MAKE_RET_RESULT(1,PR_USB,6)                  // 80040046
#define RET_USB_WRITEILL	       MAKE_RET_RESULT(1,PR_USB,7)                  // 80040047
#define RET_USB_OPENFAIL    MAKE_RET_RESULT(1,PR_USB,8)                  // 80040048

#define RET_FIL_TOOLARGE          MAKE_RET_RESULT(1,PR_FIL,0)                  // 80040100
#define RET_FIL_READFAIL          MAKE_RET_RESULT(1,PR_FIL,1)                  // 80040101
#define RET_FIL_ERRLINE          MAKE_RET_RESULT(1,PR_FIL,2)                  // 80040102
#define RET_FIL_ERRSUM          MAKE_RET_RESULT(1,PR_FIL,3)                  // 80040103
#define RET_FIL_ERRTAIL          MAKE_RET_RESULT(1,PR_FIL,4)                  // 80040104
#define RET_FIL_ERRMEM          MAKE_RET_RESULT(1,PR_FIL,5)                  // 80040105
#define RET_FIL_VERIFY          MAKE_RET_RESULT(1,PR_FIL,6)                  // 80040106

#define RET_COM_OPENFAIL          MAKE_RET_RESULT(1,PR_COM,0)
#define RET_COM_WRITEFAIL          MAKE_RET_RESULT(1,PR_COM,1)
#define RET_COM_READFAIL          MAKE_RET_RESULT(1,PR_COM,2)
#define RET_COM_SETFAIL          MAKE_RET_RESULT(1,PR_COM,3)
#define RET_COM_ACCESS_DENIED    MAKE_RET_RESULT(1,PR_COM,4)

#define RET_I2C_READERROR1          MAKE_RET_RESULT(1,PR_I2C,0)
#define RET_I2C_WRITEERROR1          MAKE_RET_RESULT(1,PR_I2C,1)

#define RET_I2C_READERROR2          MAKE_RET_RESULT(1,PR_I2C,2)
#define RET_I2C_WRITEERROR2          MAKE_RET_RESULT(1,PR_I2C,3)

#define RET_I2C_READERROR3          MAKE_RET_RESULT(1,PR_I2C,4)
#define RET_I2C_WRITEERROR3          MAKE_RET_RESULT(1,PR_I2C,5)

class  vtcom
{
public:
    vtcom();
    ~vtcom();
#ifdef ENABLE_WINDOWS
        HRESULT Open(unsigned int nPort,unsigned int  nBandRate,unsigned int  nByteSize,unsigned int  nParity,unsigned int  nStopBit,unsigned int  nReadTimeout,unsigned int  nWriteTimeout);
	void Close();
        HRESULT Read(unsigned char *pbyBuffer, unsigned int *nNByte);
        HRESULT Write(const unsigned char *pbyBuffer, unsigned int  nNbyte);
#endif

#ifdef ENABLE_LINUX
        int Open(unsigned int nPort, unsigned int nBaudRate, unsigned int nByteSize, unsigned int nParity, unsigned int nStopBit, unsigned int m_nTimeout, unsigned int m_nMin);
        void Close();
        void SetTrace(bool bTrace);
        int Read(unsigned char *pbyBuffer, unsigned int *nNByte);
        int Write(unsigned char *pbyBuffer, unsigned int nNByte);
#endif

#ifdef ENABLE_MAC
        int Open(QString nPort, unsigned int nBaudRate, unsigned int nByteSize, unsigned int nParity, unsigned int nStopBit, unsigned int m_nTimeout, unsigned int m_nMin);
        void Close();
        void SetTrace(bool bTrace);
        int Read(unsigned char *pbyBuffer, unsigned int *nNByte);
        int Write(unsigned char *pbyBuffer, unsigned int nNByte);
#endif


protected:
#ifdef ENABLE_WINDOWS
	HANDLE m_hFile;
	BOOL m_bOpen;
	BOOL m_bTrace;

	UINT m_nPort;
	UINT m_nBandRate;
	UINT m_nByteSize;
	UINT m_nParity;
	UINT m_nStopBit;
	UINT m_nReadTimeout;
	UINT m_nWriteTimeout;
#endif

#ifdef ENABLE_LINUX
        int fd;
        bool m_bOpen;
        bool m_bTrace;

        unsigned int m_nPort;
        unsigned int m_nBaudRate;
        unsigned int m_nByteSize;
        unsigned int m_nParity;
        unsigned int m_nStopBit;
        unsigned int m_nTimeout;
        unsigned int m_nMin;
#endif

#ifdef ENABLE_MAC
        int fd;
        bool m_bOpen;
        bool m_bTrace;

        unsigned int m_nPort;
        unsigned int m_nBaudRate;
        unsigned int m_nByteSize;
        unsigned int m_nParity;
        unsigned int m_nStopBit;
        unsigned int m_nTimeout;
        unsigned int m_nMin;
#endif


};

#endif // VTCOM_H
