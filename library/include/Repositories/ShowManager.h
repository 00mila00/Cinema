//
// Created by student on 12.06.2020.
//

#ifndef LIBRARY_SHOWMANAGER_H
#define LIBRARY_SHOWMANAGER_H


#include <string>
#include <vector>
#include <memory>
#include "Repository.h"
#include "Repositories/typedefrepo.h"
#include "Repositories/typedefrepo.h"
class ShowManager {
    ShowRepoPtr current_show;
public:
    ShowManager();
    virtual ~ShowManager();
    void create_show(const ShowPtr &s);
    void delete_show(const ShowPtr &s);
    void get_daily_show(pt::ptime &date);
    unsigned int get_nr_of_shows() const;
    std::string get_all() const;
    ShowPtr find_show(unsigned int);

};


#endif //LIBRARY_SHOWMANAGER_H
