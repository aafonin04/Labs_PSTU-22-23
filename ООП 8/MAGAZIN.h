#pragma once
#include "PRINT.h"

class MAGAZIN :
    public PRINT
{
protected:
    int pages;
public:
    MAGAZIN();
    MAGAZIN(string, string, int);
    MAGAZIN(const MAGAZIN&);
    ~MAGAZIN();
    void Show();
    void Input();
    int get_pages();
    void set_pages(int);
    MAGAZIN& operator=(const MAGAZIN&);
};

