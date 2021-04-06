#include<iostream>
#include"Demo.h"

using std::cout;
using std::cin;

int Books::successful=0;
int Books::failed = 0;
Books::Books(){
    cout << "enter size of collection:\n";
    cin >> l;
    lib = new struct inventory [l];

    for (int j = 0; j < l;j++)
    {

        cout<<"enter book_info:\n";
        cout<<"title:\n";
        getline(cin.ignore(),lib[j].title) ;
        cout<<"author:\n";
        getline(cin.ignore(),lib[j].author);
        cout<<"publisher:\n";
        getline(cin.ignore(),lib[j].publisher);
        cout<<"unit price:\n";
        cin>>lib[j].Price;
        cout<<"stock_value:\n";
        cin>>lib[j].stock_value;
        cout<<"stock_position\n";
        cin>>lib[j].stock_position;
        cout<<"\n";
    }
}

void Books::search(){
    string h, o;
    cout << "\n enter title:\n";
    getline(cin.ignore(), h);
    cout<< "author:\n";
getline(cin.ignore(), o);
    for (int y = 0; y < l;y++){
        if(h==lib[y].title && o==lib[y].author){
            cout << "book is available:\n";
            cout <<"Book Price:\n"<< lib[y].Price;
            int copies;
            cout << "\nenter copies required:\n";
            cin >> copies;
            if (copies<=lib[y].stock_position){
                cout << "your invoice: "
                     << copies *(lib[y].Price) << "\n";
                int decision;
                cout << "proceed with transaction?\n"
                << "enter 1 if yes and 2 if no:\n";
                cin >> decision;
                switch (decision)
                {
                case 1:

                    successful += 1;
                    lib[y].stock_position -=copies;
                    lib[y].stock_value = lib[y].stock_position *(lib[y].Price);
                    break;
                case 2:
                    cout << "okay transaction will be cancelled\n";
                    failed += 1;
                    break;

                default:
                    cout << "unrecognized input\n";
                    break;
                }

            }
            else{
                cout<<"required copies not in stock\n";
            }

        }
    }

}

void Books::price_update(){
    float e;
    string z;

    cout << "enter book you want price updated:\n";
    getline(cin.ignore(),z);
        for (int w = 0; w < l;w++){
            if(z==lib[w].title){
            cout << "enter new price:\n";
            cin >> e;
            lib[w].Price= e;
            cout << "new price is:" << lib[w].Price<<"\n";
            cout << "new stock value:"
                 << lib[w].stock_position * lib[w].Price<<"\n";
                }
            else{
                cout << "price cannot be updated since book doesn't exist\n";
                }
            }

}

void Books::manager(){
    cout << "Successful transactions:\t"
         << successful<<"\n";
    cout << "Failed:\t"
         << failed<<"\n";
    int entity;
    cout << "are you certain you want to update the price?\n"
        << "input 1 to proceed and 2 to cancel\n";
    cin >> entity;
      switch(entity){
    case 1:
        price_update();
        break;

    case 2:
     cout<<"okay no update will be done:\n";
     break;
    default:
        cout << "unrecognized input\n";
        break;
    }

}

Books::~Books(){
    delete[] lib;
}