#ifndef PRINTING_H
#define PRINTING_H
#include <iostream>


using namespace std;

class Printing
{
    public:
        Printing();
        void TextPrint(string message);
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
