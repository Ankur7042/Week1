#include <bits/stdc++.h>
using namespace std;


// Enum to represent user roles
enum class UserRole {
    ADMINISTRATOR,
    HOTEL_AGENT,
    NORMAL_USER
};

// User class
class User {
private:
    string userName;
    int userAge;
    char userGender;
    int userID;
    string userPassword;
    UserRole userRole;

public:
    // Parameterized constructor for User
    User(const string& userName, const string& userPassword, int userAge, char userGender, int userID, UserRole userRole)
        : userName(userName), userPassword(userPassword), userAge(userAge), userGender(userGender), userID(userID), userRole(userRole) {}

    // Getter and setter methods for the member variables
    const string& getUserName() const {
        return userName;
    }

    void setUserName(const string& name) {
        userName = name;
    }

    int getUserAge() const {
        return userAge;
    }

    void setUserAge(int age) {
        userAge = age;
    }

    char getUserGender() const {
        return userGender;
    }

    void setUserGender(char gender) {
        userGender = gender;
    }

    int getUserID() const {
        return userID;
    }

    void setUserID(int id) {
        userID = id;
    }

    const string& getUserPassword() const {
        return userPassword;
    }

    void setUserPassword(const string& password) {
        userPassword = password;
    }

    UserRole getUserRole() const {
        return userRole;
    }

    void setUserRole(UserRole role) {
        userRole = role;
    }
};


// Hotel class
class Hotel {
private:
    string name;
    string location;
    int numberOfRooms;
    vector<string> facilitiesProvided;
    bool approved;
    vector<string> feedbacks;
    double averageRating;

public:
    // Constructor
    Hotel(const string& name, const string& location, int numberOfRooms, const vector<string>& facilitiesProvided, double averageRating)
        : name(name), location(location), numberOfRooms(numberOfRooms), facilitiesProvided(facilitiesProvided), approved(false), averageRating(averageRating) {}

    // Setter for the number of rooms
    void setNumberOfRooms(int numRooms) {
        numberOfRooms = numRooms;
    }

    // Getter for the name of the hotel
    const string& getName() const {
        return name;
    }

    // Getter for the feedbacks
    const vector<string>& getFeedbacks() const {
        return feedbacks;
    }

    // Setter for the feedbacks
    void setFeedbacks(const vector<string>& feedbacks) {
        this->feedbacks = feedbacks;
    }

    // Getter for the average rating
    double getAverageRating() const {
        return averageRating;
    }

    // Setter for the average rating
    void setAverageRating(double rating) {
        averageRating = rating;
    }

    // Getter for the location of the hotel
    const string& getLocation() const {
        return location;
    }

    // Getter for the number of rooms
    int getNumberOfRooms() const {
        return numberOfRooms;
    }

    // Getter for the facilities provided
    const vector<string>& getFacilities() const {
        return facilitiesProvided;
    }

    // Setter for approval status
    void setApproved(bool isApproved) {
        approved = isApproved;
    }

    // Getter for approval status
    bool isApproved() const {
        return approved;
    }

    // Add feedback to the hotel
    void addFeedback(const string& feedback) {
        feedbacks.push_back(feedback);
    }
};

class HotelManagement {

    private:
    vector<User*> users;
    vector<Hotel*> hotels;
    vector<User*> agents;
public:
    // Constructor
    HotelManagement() {}

    // Getter for users
    vector<User*>& getUsers() {
        return users;
    }

    // Getter for hotels
    vector<Hotel*>& getHotels() {
        return hotels;
    }

    // Getter for agents
    vector<User*>& getAgents() {
        return agents;
    }

    // Register user
    void registerUser(User* user) {
        users.push_back(user);

        if (user->getUserRole() == UserRole::HOTEL_AGENT) {
            agents.push_back(user);
        }
    }

    // List hotels based on criteria
    vector<Hotel*> listHotels(const string& criteria) {
        vector<Hotel*> filteredHotels;
        for (Hotel* hotel : hotels) {
            if (hotel->getLocation() == criteria || find(hotel->getFacilities().begin(), hotel->getFacilities().end(), criteria) != hotel->getFacilities().end()) {
                filteredHotels.push_back(hotel);
            }
        }
        return filteredHotels;
    }

    // Approve hotel details
    void approveHotelDetails(Hotel* hotel) {
        hotel->setApproved(true);
    }

    // Display hotel details
    void displayHotelDetails() {
        cout << "The list of the Hotels available : \n";
        for (Hotel* hotel : hotels) {
            cout << "*********************************************\n";
            cout << "Hotel Name: " << hotel->getName() << "\n";
            cout << "Location: " << hotel->getLocation() << "\n";
            cout << "Number of Rooms available: " << hotel->getNumberOfRooms() << "\n";
            cout << "Facilities Provided: ";
            for (const auto& facility : hotel->getFacilities()) {
                cout << facility << " ";
            }
            cout << "\n";
            cout << "Approved: " << (hotel->isApproved() ? "Yes" : "No") << "\n";
            cout << "Average Rating: " << hotel->getAverageRating() << "\n";
            cout << "**************************************************\n";
        }
    }
};



// Administrator class, derived from User
class Administrator : public User {
public:
    // Constructor
    Administrator(const string& userName, const string& userPassword, int userAge, char userGender, int userID)
        : User(userName, userPassword, userAge, userGender, userID, UserRole::ADMINISTRATOR) {}

    // Approve hotel details
    void approveHotelDetails(Hotel* hotel) {
        hotel->setApproved(true);
        cout << "Hotel details approved successfully!" << endl;
    }

    // Delete user and hotel details
    void deleteDetails(User* user, Hotel* hotel, HotelManagement* hotelManagement) {
        if (user->getUserRole() == UserRole::NORMAL_USER) {
            auto it = find(hotelManagement->getUsers().begin(), hotelManagement->getUsers().end(), user);
            if (it != hotelManagement->getUsers().end()) {
                hotelManagement->getUsers().erase(it);
            }
        } else if (user->getUserRole() == UserRole::HOTEL_AGENT) {
            auto it = find(hotelManagement->getAgents().begin(), hotelManagement->getAgents().end(), user);
            if (it != hotelManagement->getAgents().end()) {
                hotelManagement->getAgents().erase(it);
            }
        }

        if (hotel != nullptr) {
            auto it =find(hotelManagement->getHotels().begin(), hotelManagement->getHotels().end(), hotel);
            if (it != hotelManagement->getHotels().end()) {
                hotelManagement->getHotels().erase(it);
            }
        }
    }

    // Display reservation status
    void displayReservationStatus(Hotel* hotel) {
        cout << "Reservation Status for " << hotel->getName() << ":\n";
        cout << "Number of Available Rooms: " << hotel->getNumberOfRooms() << endl;
        cout << "------------------------------------------------------" << endl;
    }
};


// HotelManagement class

class NormalUser : public User {
private:
    string password;

public:
    // Constructor
    NormalUser(const string& userName, const string& userPassword, int userAge, char userGender, int userID)
        : User(userName, userPassword, userAge, userGender, userID, UserRole::NORMAL_USER), password(userPassword) {}

    // Book hotel room
    void bookHotelRoom(Hotel* hotel, HotelManagement* hotelManagement) {
        if (hotel->isApproved() && hotel->getNumberOfRooms() > 0) {
            hotel->setNumberOfRooms(hotel->getNumberOfRooms() - 1);
            cout << "Room Booked successfully\n";
        } else {
            cout << "Booking failed either the hotel is not approved or no rooms available\n";
        }
    }

    // Modify self details
    void modifySelfDetails() {
        cout << "Enter new password: ";
        cin >> password;
    }

    // Provide feedback to the hotel
    void provideFeedback(Hotel* hotel) {
        cout << "Enter your feedback and rating for " << hotel->getName() << ":\n";
        string feedback;
        getline(cin >> ws, feedback); // Read the entire line, including spaces
        hotel->addFeedback(feedback);
        cout << "Feedback submitted successfully!\n";
    }
};


// HotelAgent class, derived from User
class HotelAgent : public User {
public:
    // Constructor
    HotelAgent(const string& userName, const string& userPassword, int userAge, char userGender, int userID)
        : User(userName, userPassword, userAge, userGender, userID, UserRole::HOTEL_AGENT) {}

    // Add or update hotel details
    void addOrUpdateHotelDetails(Hotel* hotel, HotelManagement* hotelManagement) {
        auto it = std::find(hotelManagement->getHotels().begin(), hotelManagement->getHotels().end(), hotel);
        if (it == hotelManagement->getHotels().end()) {
            hotelManagement->getHotels().push_back(hotel);
        }
    }
};



// Function to get integer input with validation
int getIntegerInput() {
    int input;
    while (true) {
        cout << "Enter a number: ";
        if (cin >> input && input>=0) {
            // Input is an integer
            break;
        } else {
            // Invalid input, clear the buffer
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
        }
    }
    return input;
}



int main() {
   
        // Create the object of HotelManagement
        HotelManagement hotelManagement;

        // Create objects of Administrator, HotelAgent, and NormalUser
        Administrator admin("admin", "adminpass", 45, 'M', 321);
        HotelAgent agent("agent1", "agentpass", 24, 'F', 653);
        NormalUser normalUser("user1", "userpass", 34, 'M', 78);

        // Register admin, agent, and normalUser
        hotelManagement.registerUser(&admin);
        hotelManagement.registerUser(&agent);
        hotelManagement.registerUser(&normalUser);

        // Create hotels
        Hotel hotel1("Raddison Blue", "Mumbai", 50, {"Wifi", "Parking", "Bruch", "Dinner", "Mumbai", "Spa"}, 4.0);
        Hotel hotel2("Hyatt Regency", "Delhi", 2, {"Suite", "Hall", "Late Night Dinner", "Wisky Bar", "Delhi"}, 3.8);
        Hotel hotel3("The Palm Court", "Ludhiana", 34, {"Swimming Pool", "Gym", "Suite", "open Roof Top", "Ludhiana"}, 3.6);

        // Agent adds or updates hotel details
        agent.addOrUpdateHotelDetails(&hotel1, &hotelManagement);
        agent.addOrUpdateHotelDetails(&hotel2, &hotelManagement);
        agent.addOrUpdateHotelDetails(&hotel3, &hotelManagement);

        // Approve hotel details
        hotelManagement.approveHotelDetails(&hotel1);
        hotelManagement.approveHotelDetails(&hotel3);

        // Display all hotel details
        hotelManagement.displayHotelDetails();

        // Ask for search criteria
        cout << "Please type the facilities you need, e.g., [Gym, Swimming Pool, Wifi, Parking, Suite, Hall, Delhi, Mumbai, Ludhiana]: ";
        string searchCriteria;
        cin >> ws; // consume any leading whitespaces
        getline(cin, searchCriteria);

        // List hotels based on search criteria
        vector<Hotel*> resultHotels = hotelManagement.listHotels(searchCriteria);

        // Display filtered hotel details
        hotelManagement.displayHotelDetails();

        // If there are available hotels according to the search criteria
        if (!resultHotels.empty()) {
            cout << "Please select the hotel from the available list:\n";
            for (int i = 0; i < resultHotels.size(); i++) {
                cout << i + 1 << ". " << resultHotels[i]->getName() << endl;
            }

            cout << "Please enter the number corresponding to the hotel: ";
            int selection = getIntegerInput();

            if (selection >= 1 && selection <= resultHotels.size()) {
                normalUser.bookHotelRoom(resultHotels[selection - 1], &hotelManagement);
            } else {
                cout << "Invalid selection.\n";
            }
        } else {
            cout << "No hotels found matching the criteria.\n";
        }
        return 0;
    } 

    
