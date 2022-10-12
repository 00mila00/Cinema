//
// Created by student on 11.06.2020.
//

#ifndef LIBRARY_TYPEDEF_H
#define LIBRARY_TYPEDEF_H

#include <iostream>
#include <memory>
#include "Room.h"
#include "Movie.h"
#include "Ticket.h"
#include "Multiple.h"
#include "Single.h"
#include "Show.h"
//#include "Repositories/RoomRepository.h"
//#include "Repositories/ShowRepository.h"
//#include "Repositories/MovieRepository.h"

typedef std::shared_ptr<Room> RoomPtr;
typedef std::shared_ptr<Movie> MoviePtr;
typedef std::shared_ptr<Single> SinglePtr;
typedef std::shared_ptr<Multiple> MultiplePtr;
typedef std::shared_ptr<Ticket> TicketPtr;
typedef std::shared_ptr<Show> ShowPtr;
//typedef std::shared_ptr<MovieRepository>  MovieRepoPtr;
//typedef std::shared_ptr<ShowRepository>  ShowRepoPtr;
//typedef std::shared_ptr<RoomRepository>  RoomRepoPtr;




#endif //LIBRARY_TYPEDEF_H
