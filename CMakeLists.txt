cmake_minimum_required(VERSION 3.26)
project(note_projet_lab)

set(CMAKE_CXX_STANDARD 11)

add_executable(note_projet_lab main.cpp
        src/App.cpp
        src/Note.cpp
        src/NoteCollection.cpp
        src/NoteCollectionObserver.cpp
        src/NoteModificationException.h
)
