#include <list>
#include "packages/TripServiceSupport.h"
#include <algorithm>

UserSession *UserSession::oneUserSession=0;

std::list<Trip> TripService::GetTripsByUser( User *user )
{
    std::list<Trip> triplist ;
    User* loggedUser = UserSession::GetInstance()->GetLoggedUser();
    if ( loggedUser )
    {
        auto needle = std::find_if(begin(user->GetFriends()), end(user->GetFriends()), [&loggedUser](auto user) {
            if (user == *loggedUser)
                return true;
            return false;
        });
        if (needle != end(user->GetFriends()))
        {
            triplist = TripDAO::FindTripsByUser(user);
        }

        return triplist;
    }
    else
    {
        throw UserNotLoggedInException();
    }
}
