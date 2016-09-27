cmake_minimum_required(VERSION 3.3)
project(helloWorld)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp bilety/Ticket.cpp bilety/Ticket.h bilety/PlaneTicket.cpp bilety/PlaneTicket.h bilety/ShipTicket.cpp bilety/ShipTicket.h bilety/MixedTicket.cpp bilety/MixedTicket.h Database.h)
add_executable(helloWorld ${SOURCE_FILES})