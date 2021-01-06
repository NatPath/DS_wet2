#include "library2.h"
#include "Boom.h"

void *Init(){
    Boom *DS = new Boom();
    return (void*)DS;
}

void Quit(void** DS){

    delete (Boom*)*DS;
    *DS=nullptr;
}

StatusType AddCourse(void *DS,int courseID){
    if(!DS || courseID<=0 ){
        return StatusType::INVALID_INPUT;
    }
    BoomDS* converted = static_cast<BoomDS*>(DS);
    return converted->AddCourse(courseID,numOfClasses);
}

StatusType RemoveCourse(void *DS, int courseID){
    if(!DS || courseID<=0){
        return StatusType::INVALID_INPUT;
    }
    BoomDS* converted = static_cast<BoomDS*>(DS);
    return converted->RemoveCourse(courseID);
}

StatusType AddClass(void* DS, int courseID, int* classID){
    if(!DS || courseID<=0){
        return StatusType::INVALID_INPUT;
    }
    BoomDS* converted = static_cast<BoomDS*>(DS);
    return converted->RemoveCourse(courseID);
}


StatusType WatchClass(void *DS, int courseID, int classID, int time){
    if(!DS || courseID<=0 || classID<0 || time<=0){
        return StatusType::INVALID_INPUT;
    }
    BoomDS* converted = static_cast<BoomDS*>(DS);
    return converted->WatchClass(courseID, classID, time);
}

StatusType TimeViewed(void *DS, int courseID, int classID, int *timeViewed){
    if(!DS || courseID<=0 || classID<0){
        return StatusType::INVALID_INPUT;
    }
    BoomDS* converted = static_cast<BoomDS*>(DS);
    return converted->TimeViewed(courseID, classID, timeViewed);
}

tatusType GetIthWatchedClass(void* DS, int i, int* courseID, int* classID){
    if(!DS || i<=0){
         return StatusType::INVALID_INPUT;
    }
    BoomDS* converted = static_cast<BoomDS*>(DS);
    return converted->TimeViewed(courseID, classID, timeViewed);
}