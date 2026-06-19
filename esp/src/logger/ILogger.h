#pragma once
#include <Arduino.h>

class ILogger {
public:
    virtual void info(const String& message) = 0;
    virtual void warning(const String& message) = 0;
    virtual void error(const String& message) = 0;
    virtual ~ILogger() = default;
};