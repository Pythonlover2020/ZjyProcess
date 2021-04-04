#ifndef ZJYEXPORT_H_INCLUDED
#define ZJYEXPORT_H_INCLUDED

#include <windows.h>

#ifdef BUILD_DLL
    #define ZJY_EXPORT __declspec(dllexport)
#else
    #define ZJY_EXPORT __declspec(dllimport)
#endif


#endif // ZJYEXPORT_H_INCLUDED
