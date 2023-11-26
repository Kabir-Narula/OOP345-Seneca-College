//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
//==============================================
// I did all the code by myself and only copied the code given by professor
// provided to complete my workshops and assignments.

#include <memory>
#include <utility>
#include "DataBase.h"
#include "Profile.h"
#include "Utilities.h"

using namespace std;

namespace sdds
{

    DataBase<Profile> excludeRaw(const DataBase<Profile> &allProfiles, const DataBase<Profile> &bannedProfiles)
    {
        DataBase<Profile> res;
        bool same = false;

        for (size_t i = 0; i < allProfiles.size(); i++)
        {
            same = false;

            for (size_t m = 0; m < bannedProfiles.size() && !same; m++)
            {
                if (allProfiles[i].m_age == bannedProfiles[m].m_age && allProfiles[i].m_name.first_name == bannedProfiles[m].m_name.first_name && allProfiles[i].m_name.last_name == bannedProfiles[m].m_name.last_name)
                {
                    same = true;
                }
            }
            // if is not same
            if (!same)
            {

                Profile *t_profile = new Profile(allProfiles[i].m_name, allProfiles[i].m_address, allProfiles[i].m_age);
                try
                {

                    t_profile->validateAddress();
                }
                catch (...)
                {
                    delete t_profile;
                    throw;
                }

                res += t_profile;

                delete t_profile;
            }
        }
        return res;
    }

    DataBase<Profile> excludeSmart(const DataBase<Profile> &allProfiles, const DataBase<Profile> &bannedProfiles)
    {
        DataBase<Profile> res;
        bool same = false;

        for (size_t i = 0; i < allProfiles.size(); i++)
        {
            same = false;

            for (size_t m = 0; m < bannedProfiles.size() && !same; m++)
            {
                if (allProfiles[i].m_age == bannedProfiles[m].m_age && allProfiles[i].m_name.first_name == bannedProfiles[m].m_name.first_name && allProfiles[i].m_name.last_name == bannedProfiles[m].m_name.last_name)
                {
                    same = true;
                }
            }
            // if is not same
            if (!same)
            {
                shared_ptr<Profile> prof(new Profile(allProfiles[i].m_name, allProfiles[i].m_address, allProfiles[i].m_age));

                prof->validateAddress();

                res += prof;
            }
        }
        return res;
    }
}
