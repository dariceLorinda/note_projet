//
// Created by darice lorinda dezo simo on 22/04/24.
//

#include "Note.h"


#include <utility>
#include <iostream>


std::string Note::getTitle() const {
    return title;
}

Note::Note(std::string title, std::string content) {
    this->title = std::move(title);
    this->content = std::move(content);
    this->createDate = std::time(nullptr);
    this->updateDate = std::time(nullptr);
    this->locked = false;
}

// Getters

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

// Setters

void Note::setTitle(const std::string& newTitle) {
    if(!locked) {
        this->title = newTitle;
        updateDate = std::time(nullptr);
    }
}

void Note::setContent(const std::string &newContent) {
    if(!locked) {
        content = newContent;
        updateDate = std::time(nullptr);
    }
}

void Note::lock() {
    locked = true;
    updateDate = std::time(nullptr);
}

void Note::unlock() {
    locked = false;
    updateDate = std::time(nullptr);
}
