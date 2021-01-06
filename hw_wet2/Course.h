#ifndef _COURSE_H_
#define _COURSE_H_

#include <exception>
#include "DynamicArray.h"
#include "Lecture.h"
class Course{
    
    int courseID;
    DynamicArray<Lecture> lecture_arr;
    


    public:
        Course(int courseID);
        Course(Course& copy) = default;
        Course& operator=(Course& copy) = default;

        /*
        * returns reference to the lecture dynamic array
        */
        DynamicArray<Lecture>&  getLectureArray();

        /*
        * returns reference to specific lecture by id
        */
        Lecture& getLecture(int classID);
    
        /*
        * returns course ID
        */
        int get_id() const;
        /*
        * returns number of classes
        */
        int getNumOfClasses();


        ~Course();


};

#endif