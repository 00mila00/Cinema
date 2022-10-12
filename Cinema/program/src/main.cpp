//
// Created by student on 13.06.2020.
//

#include "model/Show.h"
#include "model/Room.h"
#include "model/Movie.h"
#include "model/typedef.h"
#include "model/CashRegister.h"
#include "model/Single.h"
#include "model/Multiple.h"
#include "model/Ticket.h"
#include "Repositories/ShowRepository.h"
#include "Repositories/ShowManager.h"
#include <iostream>

using namespace std;
using namespace boost::posix_time;
void rootsection();

int it=100;
RoomPtr room(new Room(1,3,true,30,30));
RoomPtr room2(new Room(2,3,false,40,30));
time_duration td(2,0,0);
MoviePtr movie (new Movie(3,"Harry Potter i kamien filozoficzny",td));
MoviePtr movie2 (new Movie(3,"Harry Potter i komnata tajemnic",td));

ShowPtr show1 (new Show(1,movie,room,pt::ptime(gr::date(2020,6,20),pt::hours(10)+pt::minutes(0))));
ShowPtr show2 (new Show(2,movie,room2,pt::ptime(gr::date(2020,6,21),pt::hours(15)+pt::minutes(0))));
ShowPtr show3 (new Show(3,movie,room2,pt::ptime(gr::date(2020,6,22),pt::hours(15)+pt::minutes(0))));
ShowPtr show4 (new Show(4,movie,room,pt::ptime(gr::date(2020,6,23),pt::hours(15)+pt::minutes(0))));

CashRegister * cash1 =new CashRegister(show1);
CashRegister * cash2 =new CashRegister(show2);
CashRegister * cash3 =new CashRegister(show3);
CashRegister * cash4 =new CashRegister(show4);
CashRegister * cas = nullptr;
vector<CashRegister *> CASH;
ShowManager man;

unsigned int id;
int wybor1=1;
int wybor2=1;
int ilosc;
bool rodz;
bool znizka;
SinglePtr sing (new Single(it,0,0));
MultiplePtr multi (new Multiple(it,0,3));
int x;
int y;

int main()
{
    CASH.push_back(cash1);
    CASH.push_back(cash2);
    CASH.push_back(cash3);
    CASH.push_back(cash4);
    man.create_show(show1);
    man.create_show(show2);
    man.create_show(show3);
    man.create_show(show4);
while(wybor1>0) {
    //clear
    cout<<endl;
    cout<<"Witaj!"<<endl;
    cout<<"Podaj 1 jezeli jestes zwyklym uzytkownikiem. (domyslne)"<<endl;
    cout<<"Podaj magiczna liczbe jesli jestes root."<<endl;
    cout<<"Kazda inna liczba wyjdzie z programu."<<endl;
    cout<<"Twoj wybor: ";
    cin>>wybor1;
    switch(wybor1)
    {
        case(1): {
            cout << man.get_all();
            cout << "Podaj id show Z którym chcesz wykonać operacje: ";
            cin >> id;
            if (id == 0 || id > CASH.size()) {
                cout << "Podales bledne ID.";
                break;
            }

            for (int i = 0; i < CASH.size(); i++) {
                if (id == CASH[i]->get_show()->get_show_id()) {
                    cas = CASH[i];
                }
            }

            while (wybor2 > 0) {
                cout << endl;
                cout << "Podaj co chcesz zrobić." << endl;
                cout << "1.Kup bilet jednoosobowy" << endl;
                cout << "2.Kup bilet grupowy" << endl;
                cout << "3.Zwrot biletu" << endl;
                cout << "0.Wroc do wyboru seansu" << endl;
                cout << "Twoj wybor: ";
                cin >> wybor2;
                cout << endl;
                switch (wybor2) {
                    case (1):
                        cout << "Czy posiadasz karte rodzinki? (0 oznacza nie): ";
                        cin >> rodz;
                        cout << "Czy posiadasz znizke? (0 oznacza nie): ";
                        cin >> znizka;
                        sing->set_family_card(rodz);
                        sing->set_discount(znizka);
                        sing->calc_price();
                        cas->add(sing);
                        cout << "Podaj miejsce na którym chcesz siedzieć (najpierw rzad potem kolumne): ";
                        cin >> x;
                        cin >> y;
                        while (!(cas->get_show()->take_place(x, y, it))) {
                            cout << "Miejsce jest zajete!! Wybierz inne: ";
                            cin >> x;
                            cin >> y;
                        }
                        cas->final_price(cas->get_ticket(it));
                        cout << "Do zaplaty:" << cas->get_ticket(it)->get_price();
                        break;
                    case (2):
                        cout << "Czy posiadacie karte rodzinki? (0 oznacza nie): ";
                        cin >> rodz;
                        cout << "Podaj ilosc osob w grupie: ";
                        cin >> ilosc;
                        multi->set_family_card(rodz);
                        multi->set_amount(ilosc);
                        multi->calc_price();
                        cas->add(multi);
                        for (int i = 0; i < ilosc; i++) {
                            cout << "Podaj miejsce " << i + 1 << ". osoby (najpierw rzad potem kolumne): ";
                            cin >> x;
                            cin >> y;
                            while (!(cas->get_show()->take_place(x, y, it))) {
                                cout << "Miejsce jest zajete!! Wybierz inne: ";
                                cin >> x;
                                cin >> y;
                            }
                        }
                        cas->final_price(cas->get_ticket(it));
                        cout << "Do zaplaty:" << cas->get_ticket(it)->get_price();
                        break;
                    case (3):
                        cout << "Podaj numer id blietu do zwrotu: ";
                        cin >> id;
                        cas->return_ticket(id);
                        break;
                    default:
                        break;
                }
            }
            break;
        }
        case (6):
            ////ROOOT SECTION////
            break;
        default:
            return 0;
    }
}

    return 0;
}
void rootsection()
{

}