//class definition
#ifndef DEMO_H
#define DEMO_H
#include<string>
#include<iostream>

using  std::cout;
using  std::cin;
using std::string;

class Books{
    struct inventory
    {
        string title, author, publisher;
        float Price,stock_value;
        int stock_position;
    };
    int l;
    static int successful;
    static int failed ;
    struct inventory *lib;
    void price_update();

public:
    Books();
    void manager();
    void search();
    ~Books();
};

#endif