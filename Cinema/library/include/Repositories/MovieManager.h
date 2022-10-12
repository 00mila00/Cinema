//
// Created by student on 12.06.2020.
//

#ifndef LIBRARY_MOVIEMANAGER_H
#define LIBRARY_MOVIEMANAGER_H

#include <string>
#include <vector>
#include <memory>
#include "Repository.h"
#include "Repositories/typedefrepo.h"
class MovieManager {
    MovieRepoPtr current_Movie;
public:
    MovieManager();
    virtual ~MovieManager();
    void create_movie(MoviePtr &m );
    void delete_movie(MoviePtr&);
    int get_nr_of_movies() const;
    MoviePtr find_movie (unsigned int);



};


#endif //LIBRARY_MOVIEMANAGER_H
