//
// Created by student on 12.06.2020.
//

#ifndef LIBRARY_SHOWREPOSITORY_H
#define LIBRARY_SHOWREPOSITORY_H
#include <string>
#include <vector>
#include <memory>
#include "Repository.h"
#include "model/typedef.h"
class Show;
class ShowManager;
typedef std::shared_ptr<Show> ShowPtr;
class ShowRepository : Repository <Show> {

    std::vector<ShowPtr> shows;
public:
    bool add(const ShowPtr& show) override ;
    bool remove(const ShowPtr& show) override ;
    std::string report() const override;
    unsigned int size() override;
    void delete_archive_shows();
    ShowPtr search(unsigned int id) override;

    std::string get_daily_shows(boost::posix_time::ptime &dat);

};


#endif //LIBRARY_ROOMREPOSITORY_H
