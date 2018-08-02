#include <iostream>
#include <fstream>
#include <string>
#include <time.h>


class Time{
private:
    time_t nowtime;
    struct tm *pnow;
public:
    Time(){
        nowtime = time(NULL);
    }
    std::string now(){
        char buff[32];
        nowtime = time(NULL);
        pnow = localtime(&nowtime);
        sprintf(buff, "%04d-%02d-%02d %02d:%02d:%02d", pnow->tm_year + 1900, pnow->tm_mon + 1, pnow->tm_mday,
            pnow->tm_hour, pnow->tm_min, pnow->tm_sec);
        return std::string(buff);
    }
};


class ErrorHandler{
private:
    std::ofstream errLogFile;
    Time time;

public:
    static ErrorHandler &getInstance(){
        static ErrorHandler instance;
        return instance;   
    }
    ErrorHandler &operator<<(char* str){
        
        errLogFile << time.now() << "\t" << str << "\n";
    }
    ~ErrorHandler(){
        *this << "---END---";
        errLogFile.close();
    }
private:
    ErrorHandler(){
        errLogFile.open("error_output.log", std::ios_base::app);
        *this << "---START---";
    }
    ErrorHandler(const ErrorHandler &other){}
    ErrorHandler &operator=(const ErrorHandler &other){}
};

ErrorHandler &err = ErrorHandler::getInstance();
