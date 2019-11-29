#ifndef TRIP_SERVICE_SUPPORT
#define TRIP_SERVICE_SUPPORT

#include <list>
#include <stdexcept>

class UserNotLoggedInException : public virtual std::runtime_error {
public:
    UserNotLoggedInException() : std::runtime_error("User not logged in") {}
};

class Trip
{
    // TODO: implement me
};

class User
{
public:
    // constructor
    User( int _id ):id(_id) {} ;

    std::list<User> GetFriends() { return friends; }
    std::list<Trip> Trips() { return trips; }

    // Add a friend
    void AddFriend( User user ) { friends.push_back( user ); }
    // Add a friend
    void AddTrip( Trip trip ) { friends.push_back( trip ); }

    bool operator==( User& other ) { return (other.id==id); }
private:
    int id;
    std::list<Trip> trips;
    std::list<User> friends;
};


class UserSession
{
public:
    static UserSession* GetInstance()
    {
        if ( !oneUserSession ) { oneUserSession = new UserSession(); }
        return oneUserSession;
    }

    bool IsUserLoggedIn( User user )
    {
        // TODO: implement me
        return false;
    }
    User* GetLoggedUser()
    {
        // TODO: implement me
        return nullptr;
    }

private:
    static UserSession *oneUserSession;
    // private constructor
    UserSession() {};
};

class TripDAO
{
public:
    static std::list<Trip> FindTripsByUser(User *user)
    {
        // TODO: implement me
        return {};
    }
};

#endif //TRIP_SERVICE_SUPPORT
