#pragma once
#include "ILogger.h"

class SerialLogger : public ILogger {
public:
    SerialLogger(int baudRate = 115200);
    void begin();
    void info(const String& message) override;
    void warning(const String& message) override;
    void error(const String& message) override;

private:
    int _baudRate;
    String _format(const String& level, const String& message);
};