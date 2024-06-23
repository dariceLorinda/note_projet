

#ifndef NOTE_PROJET_LAB_NOTE_COLLECTION_H
#define NOTE_PROJET_LAB_NOTE_COLLECTION_H

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "Subject.h"
#include "Note.h"

class NoteCollection : public Subject {
private:
    std::string name;
    std::vector<Note> notes;
    std::vector<Observer*> observers;
    std::time_t createDate{};
    std::time_t updateDate{};

    static std::string timeToString(std::time_t time);

public:
    explicit NoteCollection(std::string name);

    std::string getName() const;
    std::time_t getCreateDate() const;
    std::time_t getUpdateDate() const;

    std::vector<Note> getNotes() const;

    void attach(Observer *observer) override;

    void detach(Observer *observer) override;

    void notify() override;

    void setName(const std::string& newName);
    void addNote(const Note& note);
    void removeNote(size_t index);

    void getPrintNotes() const;
    void printCollection() const;

};


#endif //NOTE_PROJET_LAB_NOTE_COLLECTION_H
