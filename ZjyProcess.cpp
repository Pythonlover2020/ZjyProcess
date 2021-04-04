#include "ZjyProcess.h"

ZjyProcess::ZjyProcess()
{
    this->startUpInfo = {0};
    this->processInfomation = {0};
    bSucess = false;
}

ProcessID ZjyProcess::start(char* lpApplicationName)
{
    bSucess = false;
    bSucess = CreateProcess(TEXT(lpApplicationName),NULL,NULL,NULL,FALSE,NULL,NULL,NULL,&this->startUpInfo,&this->processInfomation);
    if (bSucess)
    {
        return processInfomation.dwProcessId;
    }
    else
    {
        exit(1);
    }
}

void ZjyProcess::waitForFinished()
{
    if (bSucess)
    {
        WaitForSingleObject(processInfomation.hProcess,INFINITE);
        bSucess = false;
    }
}

void ZjyProcess::killProcess(ProcessID processID)
{
    char *command; // 指令
    sprintf(command,"taskkill /PID %d /T /F",processID);
    system(command);
    //WinExec(command,SW_HIDE);
}

void ZjyProcess::killProcess(char *name)
{
    char *command; // 指令
    sprintf(command,"taskkill /F /IM %s /T",name);
    system(command);
}