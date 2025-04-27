#ifndef _tools_crashreporter_h
#define _tools_crashreporter_h

#include <string>

bool BeginCrashListener();
void EndCrashListener();

void ReportPreventionIncident(std::string category, std::string incident_str);

#endif