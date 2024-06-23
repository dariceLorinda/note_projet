//
// Created by darice lorinda dezo simo on 23/06/24.
//

#ifndef NOTE_PROJET_LAB_NOTEMODIFICATIONEXCEPTION_H
#define NOTE_PROJET_LAB_NOTEMODIFICATIONEXCEPTION_H


#include <stdexcept>

class NoteModificationException : public std::runtime_error {
public:
    NoteModificationException(const std::string& message) : std::runtime_error(message) {}
};


#endif //NOTE_PROJET_LAB_NOTEMODIFICATIONEXCEPTION_H
