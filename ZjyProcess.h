#ifndef ZJYPROCESS_H
#define ZJYPROCESS_H

#include "ZjyExport.h"
#include <cstdio>
#include <cstdlib>

#ifndef __LP64__
#define ProcessID unsigned long ///< 进程ID的数据类型
#else
#define ProcessID unsigned int ///< 进程ID的数据类型
#endif

/**
 *@file ZjyProcess.h
 *@author 朱江宇@开源者bilibili
 *@date 2021-4-3
 *@brief ZjyProcess进程类
 *@note 该类用于Windows下创建进程
 *@todo 增加Linux下创建进程的支持，修复killProcess函数的BUG
 *@version 1.3
 *@bug killProcess函数有莫名其妙的BUG，不建议使用
 */
class ZJY_EXPORT ZjyProcess
{
    public:
        ZjyProcess();

        /**
         *@brief 启动进程
         *@param lpApplicationName 要启动的应用程序
         *@return 返回进程ID
         *@note 如果创建失败会直接终止程序
         */
        ProcessID start(char* lpApplicationName);

        /**
         *@brief 等待进程结束
         *@note 当进程创建失败或没有创建进程时不会执行
         */
        void waitForFinished();

        /**
         *@brief 杀死指定进程
         *@param processID 要杀死的进程的ID
         */
        void killProcess(ProcessID processID);

        /**
         *@brief 杀死指定进程
         *@param name 文件的名字（路径+文件名+拓展名）
         *@note 该函数会杀死指定文件创建的进程
         */
        void killProcess(char *name);

    protected:

    private:
        STARTUPINFO startUpInfo; ///< 启动信息
        PROCESS_INFORMATION processInfomation; ///< 进程信息
        BOOL bSucess; ///< 是否成功创建进程
};

#endif // ZJYPROCESS_H
