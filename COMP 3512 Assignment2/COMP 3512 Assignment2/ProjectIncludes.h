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

// UI Base Class
#include "UIBase.h"

// UI Child Class
#include "UI_AddPatient.h"
#include "UI_GetPatient.h"
#include "UI_ChangeCategory.h"
#include "UI_Print.h"
#include "UI_Save.h"
#include "UI_Load.h"

void printPatient(Patient p);
bool CheckValidCategory(int cateNum);
bool CheckValidPIN(std::string pin);

#endif // !__ASN2_PROJECTINCLUDES_H__

