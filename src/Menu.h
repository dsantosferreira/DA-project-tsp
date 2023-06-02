#ifndef PROJECT_TSP_MENU_H
#define PROJECT_TSP_MENU_H

#include <cstdlib>
#include <iostream>
#include <stack>
#include <limits>
#include "Scraper.h"

using namespace std;

class Menu {
public:
    Menu(vector<Graph*> Graphs);

private:
    stack<int> menuStack;
    int currentMenu;
    Graph* gh;
    vector<Graph*> graphs;
    string group;
    string graph;

    enum menus{
        main_menu = 1,
        specific_graphs = 2
    };

    void drawMainMenu();

    void drawSpecificGraphs();

    void drawMenu();

    void changeMenu(int newMenu);

    void back();

    void getOption(string &option);

    bool loadGraph(int group, string graph);
};


#endif //PROJECT_TSP_MENU_H