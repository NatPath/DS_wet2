#include "Course.h"

Course::Course(int courseID):courseID(courseID),lecture_arr(5){}


int Course::get_id() const{
    return courseID;
}


int Course::getNumOfClasses(){
    return lecture_arr.getCounter();

}

DynamicArray<Lecture>& Course::getLectureArray(){
    return lecture_arr;
}


Lecture& Course::getLecture(int classID){
    return lecture_arr[classID];
}


