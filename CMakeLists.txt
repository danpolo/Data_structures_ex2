
project(Data_structures_ex2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Data_structures_ex2
        wet2util.h
        worldcup23a2.cpp
        worldcup23a2.h Uptrees.cpp Uptrees.h SkipListTeams.cpp SkipListTeams.h NodeUpTree.h)
