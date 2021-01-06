#ifndef _LECTURE_H_
#define _LECTURE_H_
#include <iostream>

class Lecture{

    int courseID;
    int lectureID;
    int num_views;

    public:
    Lecture(int courseID=0, int lectureID=0,int time=0):courseID(courseID),lectureID(lectureID),num_views(time){}
    //increse number of views by 'to_add'
    void addViews(int to_add){
        num_views+=to_add;
    }
    //number of views getter
    int getViews() const{
        return num_views;
    }
    //courseID getter
    int getCourseID() const{
        return courseID;
    }
    //lectureID getter
    int getLectureID() const{
        return lectureID;
    }
    /*
    * Two Lectures are equal iff all their fields are the same
    */
    bool operator==(const Lecture& compare) const;
    /*
    * Two Lectures are different if they are not equal
    */
    bool operator!=(const Lecture& compare) const;
        
    /*
    * Lectures are ordered by:
    *  first- by number of views ( Biggest first)
    *  second- by CourseID (Smallest first)
    *  third - by LectureID (Smallest first)
    */
    bool operator>(const Lecture& compare) const;
    /*
    * Lectures are ordered by:
    *  first- by number of views ( Biggest first)
    *  second- by CourseID (Smallest first)
    *  third - by LectureID (Smallest first)
    */
    bool operator<(const Lecture& compare) const;
    bool operator>=(const Lecture& compare) const;
    bool operator<=(const Lecture& compare) const;

    friend std::ostream& operator<<(std::ostream& os,const Lecture& lecture);
};
std::ostream& operator<<(std::ostream& os,const Lecture& lecture){
    os<<"~~Printing Lecture~~"<<std::endl;    
    os<<"Course ID:" <<lecture.courseID<<std::endl;    
    os<<"Lecture ID:" <<lecture.courseID<<std::endl;    
    os<<"num_views :" <<lecture.num_views<<std::endl;    
    os<<"~~~~~~~~~~~~~~~~~~~~"<<std::endl;    
}

#endif