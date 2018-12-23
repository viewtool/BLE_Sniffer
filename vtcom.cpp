/**
 ****************************************************************************************
 *
 * @file vtcom.cpp
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


#define VTCOM_API __declspec(dllexport)
#include "vtcom.h"
#ifndef ENABLE_WINDOWS
#include <QDebug>
#endif

extern int com_port_open_success;

vtcom::vtcom()
{
}

vtcom::~vtcom()
{
}

#ifdef ENABLE_WINDOWS
HRESULT vtcom::Open(unsigned int nPort, unsigned int nBandRate, unsigned int nByteSize, unsigned int nParity, unsigned int nStopBit,
                    unsigned int nReadTimeout, unsigned int nWriteTimeout)
{
    return NULL;
}

//timeout
void vtcom::Close()
{
}

HRESULT vtcom::Read(unsigned char *pbyBuffer, unsigned int *nNByte)
{
    return NULL;
}

HRESULT vtcom::Write(const unsigned char *pbyBuffer, unsigned int nNByte)
{
    return NULL;
}
#endif

#ifdef ENABLE_LINUX
int vtcom::Open(unsigned int nPort, unsigned int nBaudRate, unsigned int nByteSize, unsigned int nParity,
                 unsigned int nStopBit, unsigned int nTimeout, unsigned int nMin)
{
    return NULL;
}

void vtcom::Close()
{
}

void vtcom::SetTrace(bool bTrace)
{
}

int vtcom::Read(unsigned char *pbyBuffer, unsigned int *nNByte)
{
    return NULL;
}

int vtcom::Write(unsigned char *pbyBuffer, unsigned int nNByte)
{
    return NULL;
}
#endif

#ifdef ENABLE_MAC
int vtcom::Open(QString nPort, unsigned int nBaudRate, unsigned int nByteSize, unsigned int nParity,
                 unsigned int nStopBit, unsigned int nTimeout, unsigned int nMin)
{
    return NULL;
}

void vtcom::Close()
{
}

void vtcom::SetTrace(bool bTrace)
{
}

int vtcom::Read(unsigned char *pbyBuffer, unsigned int * nNByte)
{
    return NULL;
}


int vtcom::Write(unsigned char *pbyBuffer, unsigned int nNByte)
{
    return NULL;
}
#endif
