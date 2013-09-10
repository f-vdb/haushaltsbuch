
#include<iostream>
#include<string>
#include<vector>
#include"showMainMenu.h"
#include"buildMenu.h"


void showMainMenu() {
    std::vector<std::string> points = { "Eingabe Geldausgaben",
                                        "Anzeigen aller Geldausgaben letzte Eingabe zuletzt",
                                        "Loesche letzte Eingabe (Geldausgaben)",
                                        "Loesche bestimmte Geldausgabe",
                                        "Anzeigen Geldausgaben Zeitraum",
                                        "Druckdatei erzeugen Zeitraum",
                                        "Oberkategorie verwalen",
                                        "Kategorien verwalen",
                                        "Speichern" };
    

    buildMenu(points, "Haushaltsbuch written by fvdb", 1, true, true); 
}
