cmake_minimum_required(VERSION 3.26)
project(note_projet_lab)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)

set(SOURCE_FILES
        src/utils.h
        src/Note.cpp
        src/Note.h
        src/NoteCollection.cpp
        src/NoteCollection.h
        src/NoteCollectionObserver.cpp
        src/NoteCollectionObserver.h
        src/NoteModificationException.h
        src/Observer.h
        src/Subject.h
        src/App.cpp
        src/App.h
)
add_executable(note_projet_lab main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(note_projet_lab core)
