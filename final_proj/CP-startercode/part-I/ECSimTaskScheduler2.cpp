//
//  ECSimTaskScheduler2.cpp
//  
//
//

#include <vector>
#include <iostream>
using namespace std;

#include "ECSimTaskScheduler2.h"
#include "ECSimTask.h"


//ECSimLWTFTaskScheduler
//longest waiting time first
//choose task that is waiting for the longest time

//ECSimPriorityScheduler
//schedule task with highest priorty
//this may mess up since we are coding on windows and not linux

//ECSimRoundRobinTaskScheduler
//schedule task that has been scheduled the least number of times
//count each time unit
