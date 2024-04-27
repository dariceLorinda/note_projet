//
// Created by darice lorinda dezo simo on 22/04/24.
//

#ifndef NOTE_PROJET_LAB_NOTE_H
#define NOTE_PROJET_LAB_NOTE_H

#include <string>
#include <ctime>
#include <mutex>

class Note {
private:
    std::string title; // titolo della mia note
    std::string content; // contenuto testuale delle note
    std::time_t createDate; // data di creazione delle note
    std::time_t updateDate; // data di aggiornamento delle note
    bool locked; // il locker delle note
    // std::mutex lockMutex; // Mutex for thread safety

public:
    Note(std::string  title, std::string  content);

    // Getters
    std::string getTitle() const;
    std::string getContent() const;
    std::time_t getCreateDate() const;
    std::time_t getUpdateDate() const;
    bool isLocked() const;

    // Setters
    void setTitle(const std::string& newTitle);
    void setContent(const std::string& newContent);
    void lock();
    void unlock();
};




#endif //NOTE_PROJET_LAB_NOTE_H
