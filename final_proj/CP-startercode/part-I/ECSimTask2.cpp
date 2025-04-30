//
//  ECSimTask2.cpp
//  
//
//

#include "ECSimTask2.h"

#include <string>
#include <vector>
//ECMultiIntervalsTask
//taks consists of multiple intervals
//AddInterval(int a, int b) that add an interval a,b to it 
//otherwise behaves same as single soft interval
ECMultiIntervalsTask::ECMultiIntervalsTask(const std::string &tid) 
    : ECSimTask(tid), a(0), b(0)
{
}

void ECMultiIntervalsTask::AddInterval(int a, int b){
    //adds an interval to the vector
    softTask.push_back(pair<int, int>(a,b));
}

bool ECMultiIntervalsTask::IsReadyToRun(int tick) const{
    //similar approach to SoftIntervalTask except we need to iterate through
    for(auto i: softTask){
        if(tick >= i.first && tick <= i.second){
            return true;
        }
    }
    return false;
}

bool ECMultiIntervalsTask::IsFinished(int tick) const{
    for(auto i: softTask){
        if(tick  <= i.second){
            return false;
        }
    }
    return true; 
}




//ECHardIntervalTask
//different from ECSoftIntervalTask
//it must start at the time it requested
//otherwise it behaves the same as soft interval
using namespace std;
ECHardIntervalTask::ECHardIntervalTask(const string &tid, int tmStartIn, int tmEndIn) 
    : ECSimTask(tid), tmStart(tmStartIn), tmEnd(tmEndIn), failedToStart(false)
{
    if(tmStart > tmEnd){
        failedToStart = true;
    }
}

bool ECHardIntervalTask::IsReadyToRun(int tick) const{
    //needs a hard indicator to start 
    if(!failedToStart && tick >= tmStart && tick <= tmEnd){
        return true;
    }
    return false;

}

bool ECHardIntervalTask::IsFinished(int tick) const{
    if(!failedToStart && tick > tmEnd){
        return true;
    }
    return false;
}

void ECHardIntervalTask::Run(int tick, int duration){
    //run from start duration to end duration
    //return == leaving/no longer running
    if(failedToStart){
        return; 
    }

    if(!startedOnTime){
        if(tick == tmStart){
            //started on time
            startedOnTime = true;
        }else{
            //failed to start
            failedToStart = true;
            return;
        }
    }

    //call base case
    ECSimTask::Run(tick, duration);
}

void ECHardIntervalTask::Wait(int tick, int duration){
    //if there is a pause in the running time

    //doesn't start no waiting
    if(failedToStart){
        return;
    }

    if(startedOnTime){
        //call base case
        ECSimTask::Wait(tick, duration);
    }

    if(tick == tmStart && !startedOnTime){
        failedToStart = true;
        return;
    }

    //if haven't approached start then we want to wait until we do
    if(tick < tmStart){
        ECSimTask::Wait(tick, duration);

    }
    else if (tick >= tmStart && !startedOnTime){
        //uh oh
        failedToStart = true;
        return; 
    }

}

//ECConsecutiveTask
//Must run in a sonsecutive interbal
//once interupted it will finish
using namespace std;
ECConsecutiveIntervalTask::ECConsecutiveIntervalTask(const string &tid, int tmStartIn, int tmEndIn) : ECSimTask(tid), tmStart(tmStartIn), tmEnd(tmEndIn)
{
}

bool ECConsecutiveIntervalTask::IsReadyToRun(int tick) const{
}

bool ECConsecutiveIntervalTask::IsFinished(int tick) const{
}

void ECConsecutiveIntervalTask::Run(int tick, int duration){
}

void ECConsecutiveIntervalTask::Wait(int tick, int duration){
}




//ECPerodicTask
//Recurring Task 
//Requests to run periodically of fixed length
//then idle for a fixed time
using namespace std;
ECPeriodicTask::ECPeriodicTask(const string &tid, int tmStart, int runLen, int sleepLen) : ECSimTask(tid), tmStart(tmStart), runLen(runLen), sleepLen(sleepLen)
{
}


bool ECPeriodicTask::IsReadyToRun(int tick) const{
}

bool ECPeriodicTask::IsFinished(int tick) const{
}

void ECPeriodicTask::Run(int tick, int duration){
}

void ECPeriodicTask::Wait(int tick, int duration){
}



