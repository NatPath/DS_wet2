#include "Boom.h"


StatusType Boom::AddCourse(int courseID){
    try{
        Course to_insert(courseID);
        if(!courses.insert(to_insert)){
            return StatusType::FAILURE;
        
        }
        return StatusType::SUCCESS;
        
    }
    catch(const std::bad_alloc &e){
        return StatusType::ALLOCATION_ERROR;
    }
}

StatusType Boom::RemoveCourse(int courseID){

    // consider changing this
    Course *to_remove = findValue(courseID);
    if(!to_remove){
        return StatusType::FAILURE;
    }
    courses.remove(*to_remove);
    return StatusType::SUCCESS;

}

StatusType Boom::AddClass(int courseID, int* classID){
    try{
        Course *to_add = findValue(courseID);
        if(!to_add){
            return StatusType::FAILURE;
        }
        *classID = to_add->getLectureArray().getCounter();
        to_add->getLectureArray().push(Lecture(courseID,to_add->getLectureArray().getCounter()));
        return StatusType::SUCCESS;
    }
    catch(const std::bad_alloc &e){
        return StatusType::ALLOCATION_ERROR;
    }
 }


 StatusType Boom::WatchClass(int courseID, int classID, int time){
    try{
       
        Course *to_watch = findValue(courseID);
        if(classID+1>to_watch->getLectureArray().getCounter()){
            return StatusType::INVALID_INPUT;
        }
        if(!to_watch){
            return StatusType::FAILURE;
        }

        int old_time = to_watch->getLectureArray()[classID].getViews();
        Lecture found_class(courseID,classID,old_time);
        lectures.deleteNode(found_class);
        // update time both in the parent course and in the lecture tree
        found_class.addViews(time);
        to_watch->getLectureArray()[classID].addViews(time);
        lectures.insertNode(found_class,found_class);
        
        return StatusType::SUCCESS;
    }
    catch(const std::bad_alloc &e){
        return StatusType::ALLOCATION_ERROR;
    }
 }

 StatusType Boom::TimeViewed(int courseID, int classID, int* timeViewed){
    Course *found_course = findValue(courseID);
    if(classID+1>found_course->getLectureArray().getCounter()){
            return StatusType::INVALID_INPUT;
    }
    if(!found_course){
        return StatusType::FAILURE;
    }
    *timeViewed = found_course->getLectureArray()[classID].getViews();
    return StatusType::SUCCESS;

}

StatusType Boom::GetIthWatchedClass(int i, int* courseID, int* classID){
    
    if(i>lectures.getNumNodes()){
        return StatusType::FAILURE;
    }
    // get the ith largest node
    Lecture selected = lectures.select(lectures.getNumNodes()-i+1)->getValue();
    *courseID = selected.getCourseID();
    *classID = selected.getLectureID();
    return StatusType::SUCCESS;
}

// consider changing
Course* Boom::findValue(int courseID){
    Course dummy(courseID);
    return courses.find(dummy)->getValue().get();
}