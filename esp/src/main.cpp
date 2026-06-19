#include <Arduino.h>
#include "SerialLogger.h"
#include "FileLogger.h"

SerialLogger serialLogger;
FileLogger fileLogger;

void setup() {
    serialLogger.begin();

    if (!fileLogger.begin("/log.txt", 1000)) {  // limit 1000 bajtów żeby szybko przetestować rotację
        serialLogger.error("SPIFFS nie uruchomiony!");
        return;
    }

    serialLogger.info("Start — zapisuje logi do pliku...");

    // generuj logi żeby wywołać rotację
    for (int i = 0; i < 30; i++) {
        fileLogger.info("Wpis numer " + String(i));
        delay(50);
    }

    serialLogger.info("Gotowe! Zrzucam zawartosc plikow:");
    serialLogger.info("------------------------------");
    fileLogger.dump(Serial);
}

void loop() {
    delay(5000);
    fileLogger.info("Loop ping, czas: " + String(millis()) + "ms");
}