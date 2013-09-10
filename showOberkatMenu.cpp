
#include<iostream>
#include<string>
#include<vector>
#include"showOberkatMenu.h"
#include"buildMenu.h"


void showOberkatMenu() {
    std::vector<std::string> points = { "hinzufuegen", "loeschen"};

    buildMenu(points, "", 1, false, true); 
}
