

#include "Note.h"

#include <utility>
#include <iostream>

Note::Note(const std::string&  title, const std::string&  content)
    : title(title),
    content(content),
    createDate(std::time(nullptr)),
    updateDate(createDate),
    locked(false) {}

    // Copy constructor
Note::Note(const Note& other)
    : title(other.title),
    content(other.content),
    createDate(other.createDate),
    updateDate(other.updateDate),
    locked(other.locked) {}

// Copy assignment operator
Note& Note::operator=(const Note& other) {
    if (this == &other) {
        return *this; // Handle self-assignment
    }
    title = other.title;
    content = other.content;
    createDate = other.createDate;
    updateDate = other.updateDate;
    locked = other.locked;
    return *this;
}



std::string Note::getTitle() const {
    return title;
}

std::string Note::getContent() const {
    return content;
}

std::time_t Note::getCreateDate() const {
    return createDate;
}

std::time_t Note::getUpdateDate() const {
    return updateDate;
}

bool Note::isLocked() const {
    return locked;
}




void Note::setTitle(const std::string& newTitle) {
    if (!locked) {
        title = newTitle;
        updateDate = std::time(nullptr);
    }
}

void Note::setContent(const std::string& newContent) {
    if (!locked) {
        content = newContent;
        updateDate = std::time(nullptr);
    }
}


void Note::lock() {
    locked = true;
}

void Note::unlock() {
    locked = false;
}

void Note::printNote() const {
    std::cout << "Note{" << std::endl <<
    "\t" << "title: " << getTitle() << std::endl <<
    "\t" << "content: " << getContent() << std::endl <<
    "\t" << "create date: " << timeToString(getCreateDate()) << std::endl <<
    "\t" << "update date: " << timeToString(getUpdateDate()) << std::endl <<
    "}" << std::endl;
}

std::string Note::timeToString(std::time_t time) {
    char buffer[80];
    struct tm* timeinfo = std::localtime(&time);
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
    return {buffer};
}

