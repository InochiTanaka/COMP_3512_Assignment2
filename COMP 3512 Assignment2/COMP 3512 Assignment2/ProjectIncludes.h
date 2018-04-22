#pragma once
#ifndef __ASN2_PROJECTINCLUDES_H__
#define __ASN2_PROJECTINCLUDES_H__

// Libraries
#include <stdlib.h>
#include <cstring>

// STL
#include <vector>
#include <deque>

// IO
#include <stdio.h>
#include <iomanip>
#include <sstream>

// Time 
#include <ctime>
#include <time.h>

// file stream
#include<iostream>
#include<fstream>

// Project defines
#include "PriorityLevel.h"
#include "Patient.h"
#include "PriorityQueue.h"
#include "Triage.h"

#include "UIBase.h"
#include "UI_AddPatient.h"
#include "UI_GetPatient.h"
#include "UI_Print.h"
#include "UI_Save.h"

void printPatient(Patient p);



#endif // !__ASN2_PROJECTINCLUDES_H__

