cmake_minimum_required(VERSION 3.4)
project(Library)

set(SOURCE_FILES
        include/model/Show.h
        src/model/Show.cpp
        include/model/Movie.h
        src/model/Movie.cpp
        include/model/Room.h
        src/model/Room.cpp
        include/model/Ticket.h
        src/model/Ticket.cpp
        include/model/Single.h
        src/model/Single.cpp
        include/model/Multiple.h
        src/model/Multiple.cpp
        include/model/CashRegister.h
        src/model/CashRegister.cpp
        include/model/typedef.h
        include/Repositories/Repository.h
        include/Repositories/RoomRepository.h
        include/Repositories/MovieRepository.h
        include/Repositories/ShowRepository.h
        src/Repositories/RoomRepository.cpp
        src/Repositories/ShowRepository.cpp
        src/Repositories/MovieRepository.cpp
        src/Repositories/RoomManager.cpp include/Repositories/RoomManager.h
        src/Repositories/ShowManager.cpp include/Repositories/ShowManager.h
        src/Repositories/MovieManager.cpp include/Repositories/MovieManager.h
        test/MovieTest.cpp test/CashRegisterTest.cpp
        test/RoomRepoTest.cpp test/MovieRepoTest.cpp
        test/ShowRepoTest.cpp test/MovieManagerTest.cpp
        test/RoomManagerTest.cpp test/ShowManagerTest.cpp test/RoomTest.cpp)
add_library(Library ${SOURCE_FILES})

target_include_directories(Library PUBLIC include)
enable_testing()
find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_FILES
        test/ShowTest.cpp
        test/master.cpp
        test/TicketTest.cpp test/MovieTest.cpp
        test/CashRegisterTest.cpp test/RoomRepoTest.cpp
        test/MovieRepoTest.cpp test/ShowRepoTest.cpp
        test/MovieManagerTest.cpp test/RoomManagerTest.cpp
        test/ShowManagerTest.cpp test/RoomTest.cpp)
add_executable (LibraryTest ${SOURCE_TEST_FILES})
#dołącz bibliotekę z testowanymi klasami oraz bibliotekę boost.test do programu testów
target_link_libraries (LibraryTest
        Library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

add_test(LibraryTest1 LibraryTest
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})