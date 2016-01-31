cmake_minimum_required(VERSION 3.3)
project(helloWorld)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp bilety/Bilet.cpp bilety/Bilet.h bilety/BiletPowietrzny.cpp bilety/BiletPowietrzny.h bilety/BiletMorski.cpp bilety/BiletMorski.h bilety/BiletMieszany.cpp bilety/BiletMieszany.h BazaDanych.h)
add_executable(helloWorld ${SOURCE_FILES})