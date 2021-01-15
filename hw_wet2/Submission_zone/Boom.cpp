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
    try
    {
        // consider changing this
        Course *to_remove = findValue(courseID);
        if (!to_remove)
        {
            return StatusType::FAILURE;
        }

        DynamicArray<Lecture> remove_lectures = to_remove->getLectureArray();
   
        for(int i = 0; i < remove_lectures.getSize(); i++){
            lectures.deleteNode(remove_lectures[i]);
        }

        courses.remove(*to_remove);

        return StatusType::SUCCESS;
    }
    catch (const std::bad_alloc &e)
    {
        return StatusType::ALLOCATION_ERROR;
    }
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
        if(!to_watch){
            //there is no such course
            return StatusType::FAILURE;
        }
        if(classID+1>to_watch->getLectureArray().getCounter()){
            return StatusType::INVALID_INPUT;
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
     try
     {
         Course *found_course = findValue(courseID);
         if (!found_course)
         {
             return StatusType::FAILURE;
         }
         if (classID + 1 > found_course->getLectureArray().getCounter())
         {
             return StatusType::INVALID_INPUT;
         }
         *timeViewed = found_course->getLectureArray()[classID].getViews();
         return StatusType::SUCCESS;
     }
     catch (const std::bad_alloc &e)
     {
         return StatusType::ALLOCATION_ERROR;
     }
}

StatusType Boom::GetIthWatchedClass(int i, int* courseID, int* classID){
    try
    {
        if (i > lectures.getNumNodes())
        {
            return StatusType::FAILURE;
        }
        // get the ith largest node
        Lecture selected = lectures.select(lectures.getNumNodes() - i + 1)->getValue();
        *courseID = selected.getCourseID();
        *classID = selected.getLectureID();
        return StatusType::SUCCESS;
    }
    catch (const std::bad_alloc &e)
    {
        return StatusType::ALLOCATION_ERROR;
    }
}

// consider changing
Course* Boom::findValue(int courseID){
    Course dummy(courseID);
    ListNode<Course>* found = courses.find(dummy);
    if(!found){
        return nullptr;
    }
    return found->getValue().get();
}