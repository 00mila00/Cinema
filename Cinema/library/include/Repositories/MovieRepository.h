//
// Created by student on 12.06.2020.
//

#ifndef LIBRARY_MOVIEREPOSITORY_H
#define LIBRARY_MOVIEREPOSITORY_H
#include <string>
#include <vector>
#include <memory>
#include <model/typedef.h>
#include "Repository.h"

class Movie;
class MovieManager;

class MovieRepository : Repository <Movie> {

    std::vector<MoviePtr> movies;
public:
    bool add(const MoviePtr& movie) override ;
    bool remove(const MoviePtr& movie) override ;
    std::string report() const override;
    unsigned int size() override;
    MoviePtr search(unsigned int id) override;
};


#endif //LIBRARY_ROOMREPOSITORY_H
