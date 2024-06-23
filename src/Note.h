

#ifndef NOTE_PROJET_LAB_NOTE_H
#define NOTE_PROJET_LAB_NOTE_H

#include <string>
#include <ctime>
#include <mutex>
/**
 * Class Note
 * */
class Note {
private:
    std::string title;
    std::string content;
    std::time_t createDate{};
    std::time_t updateDate{};
    bool locked{};

    static std::string timeToString(std::time_t time) ;


public:
    Note(const std::string&  title, const std::string&  content);
    Note(const Note& note);

    Note& operator=(const Note& other);

    std::string getTitle() const;
    std::string getContent() const;
    std::time_t getCreateDate() const;
    std::time_t getUpdateDate() const;
    bool isLocked() const;

    void setTitle(const std::string& newTitle);
    void setContent(const std::string& newContent);
    void lock();
    void unlock();

    void printNote() const;



    };


#endif //NOTE_PROJET_LAB_NOTE_H
