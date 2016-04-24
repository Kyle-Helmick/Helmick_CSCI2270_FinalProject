#ifndef PRINTING_H
#define PRINTING_H
#include <iostream>
#include <vector>

using namespace std;

struct menu_node;

struct menu_node_adj
{
    menu_node *m;
};

struct menu_node
{
    menu_node *parent;
    vector <menu_node> children;
};

class Printing
{
    public:
        Printing();
        void NewPage();
        void MainMenu();
        void ActionMenu();
        void FortifyMenu_B();
        void AttackMenu_1_B();
        void AttackMenu_2_B();
        void ResourcesMenu_1_B();
        void ResourcesMenu_2_B();
        void MenuEnd();
        void Title();
        virtual ~Printing();
    protected:
    private:
};

#endif // PRINTING_H
