//
// Created by student on 12.06.2020.
//

#include "Repositories/ShowRepository.h"

#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <memory>
#include <boost/date_time/special_defs.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time.hpp>

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;
using namespace std;
using namespace boost::posix_time;

using namespace std;
bool ShowRepository::add(const ShowPtr &show) {
    if (show==nullptr)
        __throw_logic_error("Seans nie moze byc nullptr");
    for(int i=0; i<shows.size(); i++) {
        if (show == shows[i])
            __throw_logic_error("Ten seans juz istnieje w repozytorium");
        if (show->get_show_id()==shows[i]->get_show_id())
            __throw_logic_error("Seans o tym ID juz istnieje w repozytorium");
        else if(show->get_room() == shows[i]->get_room() && show->get_date() >= shows[i]->get_date() && show->get_date()<=shows[i]->get_end()){
            __throw_logic_error("Film sie pokrywa z innym");
        }
    }
    shows.push_back(show);
    return true;
}

bool ShowRepository::remove(const ShowPtr &show) {
    for (int i = 0; i < shows.size(); i++) {
        if (shows[i] == show)
            shows[i] = nullptr;
        shows.erase(shows.begin() + i);
        return true;
    }
    __throw_logic_error("Nie moge usunac seansu, ktory nie istnieje");
}

unsigned int ShowRepository::size() {
    return shows.size();
}

std::string ShowRepository::report() const {
    ostringstream sout;
    for(int i = 0 ; i<shows.size(); i++){
        if(shows[i]->get_date()>=second_clock::local_time())
        sout<<shows[i]->get_show_info();
    }
    return sout.str();
}


void ShowRepository::delete_archive_shows() {
    for (int i = 0; i < size(); i++) {
        if (shows[i]->get_date() < second_clock::local_time()) {
            shows[i] = nullptr;
            shows.erase(shows.begin() + i);
        }
    }
}

string ShowRepository::get_daily_shows(ptime &dat) {
    ostringstream sout;
    for(int i=0; i<size(); i++){

        if(shows[i]->get_date().date() == dat.date() ){
            sout<<shows[i]->get_show_info()<<endl;
        }
    }
    return sout.str();
}

ShowPtr ShowRepository::search(unsigned int id) {
    for(int i = 0; i<size(); i++){
        if(id == shows[i]->get_show_id())
            return shows[i];
    }
    __throw_logic_error("Nie znaleziono seansu o takim ID");
}


