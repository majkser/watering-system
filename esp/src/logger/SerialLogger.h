#pragma once
#include "ILogger.h"
#include <ArduinoLog.h>
#include <FS.h>

class SerialLogger : public ILogger {
public:
    // Kluczowe jest użycie fs::File tutaj
    SerialLogger(fs::File logFile, int baudRate = 115200);
    
    void begin();
    void info(const String& message) override;
    void warning(const String& message) override;
    void error(const String& message) override;

private:
    int _baudRate;
    fs::File _logFile;
    
    static void _logOutput(Print* output);
};