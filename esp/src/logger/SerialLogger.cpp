#include "SerialLogger.h"

// Wskaźnik statyczny, aby funkcja logująca ArduinoLog miała dostęp do pliku
static File _globalLogFile;

SerialLogger::SerialLogger(File logFile, int baudRate) 
    : _logFile(logFile), _baudRate(baudRate) {
    _globalLogFile = logFile; // Przypisujemy plik do zmiennej statycznej
}

// Funkcja, którą wywoła ArduinoLog przy każdym logowaniu
void SerialLogger::_logOutput(Print* output) {
    // 1. Wypisz na Serial
    Serial.print(output);
    
    // 2. Zapisz do pliku (jeśli plik jest poprawnie otwarty)
    if (_globalLogFile) {
        _globalLogFile.print(output);
        _globalLogFile.flush(); // Wymuszamy zapis na karcie/pamięci flash
    }
}

void SerialLogger::begin() {
    Serial.begin(_baudRate);
    delay(100);

    // Inicjalizacja ArduinoLog
    // LOG_LEVEL_VERBOSE oznacza, że przepuszczamy wszystkie logi
    // false wyłącza domyślne pokazywanie poziomu logowania przez ArduinoLog, 
    // bo i tak formatujesz to sam lub za pomocą prefixów.
    Log.begin(LOG_LEVEL_VERBOSE, &SerialLogger::_logOutput, false);
    
    // Opcjonalnie: możesz ustawić automatyczny prefix z czasem w milisekundach
    Log.setPrefix([](Print* _logOutput) {
        _logOutput->print("[" + String(millis()) + "ms] ");
    });
}

void SerialLogger::info(const String& message) {
    Log.notice("[INFO] %s\n", message.c_str());
}

void SerialLogger::warning(const String& message) {
    Log.warning("[WARN] %s\n", message.c_str());
}

void SerialLogger::error(const String& message) {
    Log.errors("[ERROR] %s\n", message.c_str());
}