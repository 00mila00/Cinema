//
// Created by student on 12.06.2020.
//

#include "Repositories/MovieManager.h"
MovieManager::MovieManager(): current_Movie(new MovieRepository){}

MovieManager::~MovieManager() {}

void MovieManager::delete_movie(MoviePtr &m ) {
current_Movie->remove(m);
m->Movie::~Movie();

}

void MovieManager::create_movie(MoviePtr &m ) {

current_Movie->add(m);

}

int MovieManager::get_nr_of_movies() const{

    return current_Movie->size();
}

MoviePtr MovieManager::find_movie(unsigned int id) {
    return current_Movie->search(id);
}



