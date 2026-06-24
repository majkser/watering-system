#include <Arduino.h>
#include "SerialLogger.h"
#include "FileLogger.h"

// Tworzymy wskaźnik na nasz logger
SerialLogger *myLogger = nullptr;
fs::File logFile;

void setup()
{
    // 1. Inicjalizacja systemu plików LittleFS
    if (!LittleFS.begin(true))
    { // 'true' oznacza, że sformatuje pamięć, jeśli wystąpi błąd
        // Jeśli system plików padnie, musimy polegać na zwykłym Serialu,
        // bo logger jeszcze nie istnieje
        Serial.begin(115200);
        Serial.println("Blad inicjalizacji LittleFS!");
        return;
    }

    // 2. Otwieramy plik logów w trybie dopisywania ("a" - append)
    // Plik zostanie stworzony automatycznie, jeśli nie istnieje
    logFile = LittleFS.open("/app_logs.txt", "a");

    if (!logFile)
    {
        Serial.begin(115200);
        Serial.println("Nie udalo sie otworzyc pliku do zapisu!");
        return;
    }

    serialLogger.info("Gotowe! Zrzucam zawartosc plikow:");
    serialLogger.info("------------------------------");
    fileLogger.dump(Serial);
}

void loop()
{
    // Jeśli logger nie zainicjalizował się poprawnie, nic nie rób
    if (myLogger == nullptr)
        return;

    // Pobieramy czas w sekundach
    unsigned long sekundy = millis() / 1000;

    // Tworzymy komunikat tekstowy
    String czasKomunikat = "Czas od uruchomienia: " + String(sekundy) + " sekund.";

    // Co 5 sekund wrzucamy loga o różnym priorytecie, żeby przetestować filtry
    myLogger->info(czasKomunikat);

    // Przykładowe symulacje ostrzeżeń i błędów w innych odstępach czasu (opcjonalnie)
    if (sekundy % 15 == 0)
    {
        myLogger->warning("To jest automatyczny test ostrzeżenia co 15 sekund.");
    }
    if (sekundy % 30 == 0)
    {
        myLogger->error("To jest automatyczny test błędu co 30 sekund.");
    }

    // Czekamy dokładnie 5 sekund (5000 milisekund)
    delay(5000);
    fileLogger.info("Loop ping, czas: " + String(millis()) + "ms");
}