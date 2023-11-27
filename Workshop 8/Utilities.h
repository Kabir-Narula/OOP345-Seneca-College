

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H


#include "DataBase.h"
#include "Profile.h"

namespace sdds
{
	DataBase<Profile> excludeRaw(const DataBase<Profile>& allProfiles, const DataBase<Profile>& bannedProfiles); 
	DataBase<Profile> excludeSmart(const DataBase<Profile>& allProfiles, const DataBase<Profile>& bannedProfiles);
}

#endif	
