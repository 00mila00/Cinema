//
// Created by student on 12.06.2020.
//

#include "Repositories/MovieRepository.h"
#include <sstream>
#include <string>
#include <iostream>
#include "model/typedef.h"
using namespace std;
bool MovieRepository::add(const MoviePtr &movie) {
    if (movie==nullptr)
        __throw_logic_error("Film nie moze byc nullptr");
    for(const auto & i : movies) {
        if (movie == i)
            __throw_logic_error("Ten film juz istnieje w repozytorium");
        else if(movie->get_movie_Id() == i->get_movie_Id())
            __throw_logic_error("Film o takim ID juz istnieje w repozytorium");

    }
    movies.push_back(movie);
    return true;
}

bool MovieRepository::remove(const MoviePtr &movie) {
for(int i = 0; i < movies.size(); i++){
    if(movies[i] == movie){
        movies[i] = nullptr;
        movies.erase(movies.begin()+i);
        return true;
    }
    }
        __throw_logic_error("Nie mozna usunac filmu, ktory nie istnieje");
}

std::string MovieRepository::report() const {
    ostringstream sout;
    for(const auto & movie : movies){
        sout<<movie->get_movie_information()<<endl;
    }
    return sout.str();
}

unsigned int MovieRepository::size() {
    return movies.size();
}

MoviePtr MovieRepository::search(unsigned int id) {
    for(int i = 0; i<size(); i++){
        if(id == movies[i]->get_movie_Id())
            return movies[i];
    }
    __throw_logic_error("Nie znaleziono filmu o takim ID") ;
}

