#include "SerialLogger.h"

// Wskaźnik statyczny na plik
static fs::File _globalLogFile;

SerialLogger::SerialLogger(fs::File logFile, int baudRate) 
    : _logFile(logFile), _baudRate(baudRate) {
    _globalLogFile = logFile; 
}

// Pusta funkcja wymagana, jeśli deklarujesz ją w klasie
void SerialLogger::_logOutput(Print* output) {
    // Pozostawiamy pustą, ponieważ logujemy bezpośrednio przez metody
}

void SerialLogger::begin() {
    Serial.begin(_baudRate);
    delay(100);

    // Rejestrujemy ArduinoLog na obiekt Serial
    Log.begin(LOG_LEVEL_VERBOSE, &Serial, false);
}

void SerialLogger::info(const String& message) {
    String formatted = "[" + String(millis()) + "ms] [INFO] " + message;
    
    Log.notice("%s\n", formatted.c_str());
    
    if (_globalLogFile) {
        _globalLogFile.println(formatted);
        _globalLogFile.flush();
    }
}

void SerialLogger::warning(const String& message) {
    String formatted = "[" + String(millis()) + "ms] [WARN] " + message;
    
    Log.warning("%s\n", formatted.c_str());
    
    if (_globalLogFile) {
        _globalLogFile.println(formatted);
        _globalLogFile.flush();
    }
}

void SerialLogger::error(const String& message) {
    String formatted = "[" + String(millis()) + "ms] [ERROR] " + message;
    
    // Poprawione z Log.errors na Log.error
    Log.error("%s\n", formatted.c_str());
    
    if (_globalLogFile) {
        _globalLogFile.println(formatted);
        _globalLogFile.flush();
    }
}