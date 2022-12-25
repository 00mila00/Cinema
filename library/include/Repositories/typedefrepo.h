//
// Created by student on 14.06.2020.
//

#ifndef CINEMA_TYPEDEFREPO_H
#define CINEMA_TYPEDEFREPO_H

#include <iostream>
#include <memory>
#include "Repositories/RoomRepository.h"
#include "Repositories/ShowRepository.h"
#include "Repositories/MovieRepository.h"

typedef std::shared_ptr<MovieRepository> MovieRepoPtr;
typedef std::shared_ptr<ShowRepository> ShowRepoPtr;
typedef std::shared_ptr<RoomRepository> RoomRepoPtr;
#endif //CINEMA_TYPEDEFREPO_H
