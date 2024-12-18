cmake_minimum_required(VERSION 3.27)
project(jobsearch)

set(CMAKE_CXX_STANDARD 17)

add_executable(jobsearch main.cpp
        User.cpp
        User.h
        Job.cpp
        Job.h
        Employer.cpp
        Employer.h
        Candidate.cpp
        Candidate.h
)
