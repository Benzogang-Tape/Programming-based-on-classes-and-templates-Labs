
set(FIND_PLANET_PATHS "/mnt/d/BMSTU/Study/Course 1/Semester 2/Programming Basics/Labs/Lab 2/Libraries")

find_path(PLANET_INCLUDE_DIR Planet.hpp
        PATH_SUFFIXES Planet
        PATHS ${FIND_PLANET_PATHS})

# TODO: Link precompiled libraries here. Precompiled libraries are located at the path "/mnt/d/BMSTU/Study/Course 1/Semester 2/Programming Basics/Labs/Libraries/Lab2"