#include "NoteCollection.h"
#include "NoteModificationException.h"

#include <utility>

NoteCollection::NoteCollection(const std::string& name)
        : name(name),
          createDate(std::time(nullptr)),
          updateDate(createDate) {}


std::string NoteCollection::getName() const {
    return name;
}
Note NoteCollection::getNote(const std::string& note ){
    for(auto &n : notes){
        if(n.getTitle() == note)
            return n;
    }

    return Note("", ""); // TODO: bug da fix
}

std::time_t NoteCollection::getCreateDate() const {
    return createDate;
}

std::time_t NoteCollection::getUpdateDate() const {
    return updateDate;
}

std::list<Note> NoteCollection::getNotes() const {
    return notes;
}

size_t NoteCollection::getNumNotes() const {
    return notes.size();
}

void NoteCollection::attach(Observer *observer) {
    observers.push_back(observer);
}

void NoteCollection::detach(Observer *observer) {
    observers.erase(
            std::remove(
                    observers.begin(),
                    observers.end(),
                    observer
            ),
            observers.end()
    );
    updateDate = std::time(nullptr);
}

void NoteCollection::notify() {
    for (auto observer : observers) {
        observer->update(*this);
    }
}

void NoteCollection::setName(const std::string &newName) {
    name = newName;
    updateDate = std::time(nullptr);
}

void NoteCollection::addNote(const Note& note) {
    NoteCollection::notes.push_back(note);
    updateDate = std::time(nullptr);
    notify();
}

int NoteCollection::getIndexByTitle(const std::string& title) {
    int index = 0;
    for (auto it = notes.begin(); it != notes.end(); ++it, ++index) {
        if (it->getTitle() == title) {
            return index;
        }
    }

    return -1;
}

void NoteCollection::removeNote(const std::string& title) {
    int index = getIndexByTitle(title);
    if(index >= 0) {
        auto it = notes.begin();
        std::advance(it, index);
        if(it -> isLocked()) {
            throw NoteModificationException("this note is locked");
        }
        notes.erase(it);
        updateDate = std::time(nullptr);
        notify();
    } else {
        std::cerr << "Invalid index. Note not found." << std::endl;
    }
}

std::string NoteCollection::timeToString(std::time_t time) {
    char buffer[80];
    struct tm* timeinfo = std::localtime(&time);
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
    return {buffer};
}

void NoteCollection::printCollection() const {
    std::cout << "NoteCollection{" << std::endl;
    std::cout << "Collection name: " << name << std::endl;
    std::cout << "Collection created: " << timeToString(createDate) << std::endl;
    std::cout << "Collection updated: " << timeToString(updateDate) << std::endl;
    std::cout << "Collection notes: [" << std::endl;
    for (const auto& note : notes) {
        note.printNote();
    }
    std::cout << "]" << std::endl;
    std::cout << "}" << std::endl;
}
