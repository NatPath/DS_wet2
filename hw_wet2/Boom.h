#ifndef _BOOM_H_
#define _BOOM_H_
#include "Course.h"
#include "Lecture.h"
#include "Avl.h"
#include "HashTable.h"
#include "library2.h"

class Boom{

    HashTable<Course> courses;
    AVL_Tree<Lecture,Lecture> lectures;


    public:
        Boom() = default;
        StatusType AddCourse(int courseID);
        StatusType RemoveCourse(int courseID);
        StatusType AddClass(int courseID, int* classID);
        StatusType WatchClass(int courseID, int classID, int time);
        StatusType TimeViewed(int courseID, int classID, int* timeViewed);
        StatusType GetIthWatchedClass(int i, int* courseID, int* classID);
        ~Boom() = default;

};



#endif