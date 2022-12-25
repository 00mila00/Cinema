//
// Created by student on 12.06.2020.
//

#include "Repositories/ShowManager.h"
#include <boost/date_time/special_defs.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time.hpp>

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;
using namespace std;
using namespace boost::posix_time;

ShowManager::ShowManager():current_show(new ShowRepository){}

ShowManager::~ShowManager() {}

void ShowManager::delete_show(const ShowPtr &s) {

    current_show->delete_archive_shows();
    current_show->remove(s);
    s->Show::~Show();
}


void ShowManager::get_daily_show(ptime &dat) {
    current_show->get_daily_shows(dat);

}

void ShowManager::create_show(const ShowPtr &s) {
    current_show->add(s);

}

unsigned int ShowManager::get_nr_of_shows() const{
    return current_show->size();
}

std::string ShowManager::get_all() const {
    return current_show->report();
}

ShowPtr ShowManager::find_show(unsigned int id) {
    return current_show->search(id);
}



