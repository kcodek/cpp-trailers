## Design Questions

https://crack-the-design.blogspot.com


## `Vehicle Parking System `
Idea here is to come up with low level classes and their interactions for a vehicle parking system.

Such a system is generally a huge building or a part of building or some open space with multiple Parking Slots to part a vehicle (car or bike). 
In case of buildings there could be multiple Parking Floors each containing multiple slots for cars and bikes. 

Let's consider an user journey in this system - 
user enters through his Car or Bike in Parking Area if there are available parking slots and a Parking Ticket is assigned to the user logging the entry time. There could be display screens available in each Parking Floor showing number of available parking in that floor and nearest available Parking Slot from the current location. If we consider a much advanced system where each Parking Slot has some sensors based on which it can determine the parked Vehicle the display part can be automated otherwise we can assume that a manual entry is done when a slot is taken. Similarly when a Vehicle is unparked that Parking Slot can be marked available and display changes accordingly.  On check out gate user submits the Parking Ticket and Parking Bill is generated. Let's come up with classes and their structure now:

1) Vehicle is the class containing the basic information and VehicleType which is an enum for type of vehicle like bike or car. It can generate a ParkingTicket on check-in
~~~cpp
enum ParkingSlotType {
        BIKE, CAR
};


class Vehicle
{
   string m_registrationNumber;     
   VehicleType m_type;
   ParkingTicket& m_parkingTicket;

public:
   ParkingTicket checkIn();//generate a parking ticket on check-in

};

/*
Vehicle {
    registrationNumber
    VehicleType type
    ParkingTicket parkingTicket

    ParkingTicket checkIn()

     VehicleType {
         BIKE, CAR
     }
}*/
~~~



2) ParkingSlot is the base class containing slot information like row, column, ParkingFloor, ParkingSlotType and park, unpark behaviors
~~~cpp
class ParkingSlot
{
    // string coordinates;//row,column
    int m_row;
    int m_column;
    
    ParkingFloor& m_parkingFloor;
    VehicleType m_type;
public:
    string park(Vehicle vehicle);
    void unpark();

};
/*
ParkingSlot {
    row
    column
    ParkingFloor parkingFloor
    ParkingSlotType type

    park(Vehicle vehicle)
    unpark()

    ParkingSlotType {
        BIKE, CAR
    }
}*/
~~~
3) ParkingFloor is a container class having a list of available and occupied ParkingSlots. It also displays number of available slots and nearest slot from a given location
~~~cpp
class ParkingFloor
{
    list<ParkingSlot> m_availableBikeParkingSlots;
    list<ParkingSlot> m_availableCarParkingSlots;
    list<ParkingSlot> m_occupiedBikeParkingSlots;
    list<ParkingSlot> m_occupiedCarParkingSlots;
    
public:
    int getNumberOfAvailableCarParkingSlots();
    int getNumberOfAvailableBikeParkingSlots();
    list<ParkingSlot> getNearestParkingSlots(int row=0, int column=0);
};

/*ParkingFloor {
    List<ParkingSlot> availableCarParkingSlots
    List<ParkingSlot> availableBikeParkingSlots
    List<ParkingSlot> occupiedCarParkingSlots
    List<ParkingSlot> occupiedCarParkingSlots

    getNumberOfAvailableCarParkingSlots()
    getNumberOfAvailableBikeParkingSlots()
    List<ParkingSlot> getNearestParkingSlots(row, column)
}*/
~~~

4) ParkingArea is a container class containing a list of ParkingFloors
~~~cpp
class ParkingArea {
    list<ParkingFloor> m_parkingFloors;
};
/*ParkingArea {
    List<ParkingFloor> parkingFloors
}*/
~~~

5) ParkingTicket class has the entered Vehicle details and check-in time. It also has a method to generate ParkingBill based on ParkingRateCard
~~~cpp

class ParkingTicket{
    Vehicle m_vehicle;
    time_t m_checkInTime;
    // current date/time based on current system
    //    time_t now = time(0);
    // convert now to string form
    //    char* dt = ctime(&now);

    //uint id ;
public:
    ParkingBill generateBill();

};
class ParkingBill {
    ParkingTicket m_parkingTicket;
    double m_amount;
};

class ParkingRateCard {
    map<VehicleType,float> vehicleTypeToRateMap;
};

/*ParkingTicket {
    Vehicle vehicle
     checkInTime

     ParkingBill generateBill()
}

ParkingBill {
    ParkingTicket parkingTicket
    amount
}

ParkingRateCard {
    vehicleTypeToRateMap
}*/
~~~
6) ParkingManager is the main interface class to which API layer can talk to. It contains reference of ParkingArea through which parking availability can be checked. It has methods to check-in a Vehicle and generate ParkingBill. It also maintains a list of checked-in vehicles
~~~cpp

class ParkingManager {
    ParkingArea m_parkingArea;
    list<Vehicle> m_checkedInVehicles;
public:
    bool isParkingAvailable();
    ParkingTicket checkInVehicle(Vehicle vehicle);
    ParkingBill generateBill(ParkingTicket parkingTicket);
};
/*
ParkingManager {
    ParkingArea parkingArea
    List<Vehicle> checkedInVehicles

    boolean isParkingAvailable()
    ParkingTicket checkInVehicle(Vehicle vehicle)
    ParkingBill generateBill(ParkingTicket parkingTicket)
}*/
~~~


## `Restaurant Reservation System `

Restaurant Reservation System is again a very common Low Level Design problem where we are expected to showcase classes and their interactions to make reservation in a restaurant.

Let's list down the requirements first:

An user(operator or end user) can see list of restaurants for a given query like city, location, max occupancy etc
For a selected restaurant an user can check availability of table(s) on a given date/time passing criteria such as number of seats, pool side, etc
User can book selected table(s) in a restaurant for a certain date/time 

We can assume that such a system is managing reservations of a chain of Restaurants each located in different places(or cities). Each Restaurant contains a list of Tables. Tables will have their own set of attributes like number of seats, floor, location in floor and other attributes like pool side, open roof, etc. A Restaurant can respond to query looking for Tables with certain criteria like number of seats, pool side, etc. Each Restaurant needs to have DayCalendar for a given date which contains the availability map of Tables for a particular time slot. DayCalendar in a simplistic approach can maintain a boolean array for each hour of day with entry being true or false based on that hour is available or not. With this approach we need to have 24 slots for the day, but if needed be it can further go down to 30 or 15 mins of time slot. Keeping these points in mind we can come up with below set of classes:

1) Table is a class to represent a table within a restaurant which contains attributes like id, number of seats, it's location, floor, etc

Table {
 id
 numberOfSeats
 location
 floor
}

2) Restaurant class contains list of Tables and other attributes like name, address, etc. It has a method to list Tables given a query criteria

Restaurant {
 id
 name
 address
 List<Table> tables
 workingTimingsList
 
 List<Table> search(query)
}

3) RestaurantManager is a class to manager Restaurant admin apis like add/remove restaurant, search restaurant/tables for a given query

RestaurantManager {
        addRestaurant(Restaurant restaurant)
        removeRestaurant(Restaurant restaurant)
 List<Restaurant> searchRestaurants(query)
 List<Table> searchTables(restaurantId, query)
}

4) DayCalendar maintains availability map of hours of a day. It has methods to book or free a given time slot

DayCalendar {
 date
 boolean []hourAvailability
 
 book(startTime, endTime)
 free(startTime, endTime)
}

5) RestaurantDayCalendar maintains a map of a Table and it's DayCalendar for a given date. It has create method which creates the map of Table and DayCalendar marking all hours free at initialization. It also has methods to check availability and book a table for a given time slot.

RestaurantDayCalendar {
 date
 Map<Table, DayCalendar> tableAvailabilityMap
 
 create(List<Table> tableList, date)
 isTableAvailable(table, startTime, endTime)
 bookTable(table, startTime, endTime)
}

6) RestaurantCalendar of a Restaurant maintains a map of date and RestaurantCalendar. It has create method to create RestaurantCalendar for a given date. It also has methods to check availability and book table of that Restaurant for a given time slot  

RestaurantCalendar {
 restaurantId
 Map\<date, RestaurantCalendar\> dateCalendarMap
 
 create(restaurnatId, date)
 isTableAvailable(table, date, startTime, endTime)
 bookTable(table, date, startTime, endTime)
}

7) RestaurantBookingManager is the class used by admin apis to check availability and make reservation of a table in a restaurant for a give time slot 

RestaurantBookingManager {
 isAvailable(restaurant, table, date, startTime, endTime)
 makeReservation(restaurant, table, date, startTime, endTime)
}


`Chat Box `


A chat box (like WhatsApp) is a system which can be used for private or group conversation(s). Ignoring the user registration part we can think of below requirements:

User can send friend request to another user
User can accept or reject friend request
User can start conversation with a friend
A group can be created which has a list of users
Group members can send message to the group
Considering these requirements let's list down classes and their responsibilities:

1) User class in addition to attributes like userId and basic information, contains behaviors such as  send/receive friend request, group creation, start conversation and send message.

User {
    userId
    ..........
    ..........
    List<User> friends
    List<Group> groups
    List<Conversation> conversations
   
    sendFriendRequest(User anotherUser)
    respondToFriendRequest(User anotherUser)

    startConversation(User anotherUser)

    createGroup(Group group)
    addMemberToGroup(Group group)
    leaveGroup(Group group)
    sendMessage(Conversation conversation, Message message)
} 

2) Group class contains a list of users and other group related information and methods to add or remove user

Group {
    groupId
    ............
    ............
    List<User> members

    addMember(User user)
    removeMember(User user)
}

3) Message class is the container for a message being sent to either private or group conversation. It can contain image, video or other rich text documents

Message {
    messageId
    content
    .........
    .........
}

4) Conversation is a base class which has a list of messages and users

Conversation {
    conversationId
    List<User> participants
    List<Message> messages

    addParticipant(User user)
    removeParticipant(User user)
    addMessage(Message message)
}

5) PrivateConversation which extends Conversation will just have two participants

PrivateConversation extends Conversation {
    PrivateConversation(User user1, User user2)
} 

6) GroupConversation also extends Conversation and will have list of participants

GroupConversation extends Conversation {
    GroupConversation(List<User> users)
}

7) ChatManager is the class which orchestrates all the interactions of API layer
ChatManager {
    sendFriendRequest(User user1, User user2)
    startPrivateConversation(User user1, User user2)        
    createGroup(User user, Group group)
    addGroupMember(User user, Group group, User anotherUser)
    removeGroupMember(User user, Group group, User anotherUser)
    sendMessage(User user, Conversation conversation, Message message)
}


`Movie Booking System `

A Movie Booking System is something like BookMyShow which is a centralized system to book movie tickets in a theater of your choice. Consider below scenarios:

Day 1 of BookMyShow when the system is launched with no theater registered to it, so first step is to register a Theater which has a list of Screens and each Screen has a list of Tickets of different Classes.
Once a Theater is registered there might be a need to add or remove a Screen
Very rare but there might be cases where we need to modify seat layouts of a given Screen of a Theater 
Once Theaters are registered we need to think of below use cases for booking of a movie ticket:
A Movie needs to be created and movies can be searched based on certain criteria 
For theaters running the movie Shows are created containing show time and PriceMap for each class of tickets
User can select available seat(s) from a show and book movie Ticket(s) by making Payment using some online payment mechanism 
Keeping above requirements in mind we can start listing the classes and their behavior 

1) Seat class contains row, column information for it's location in a screen and also a SeatClass which can an enum 
~~~cpp
enum SeatClass{
   normal,
   recliner
};

class Seat{
    int m_row;
    int m_column;
    SeatClass m_class;
};
/*
Seat {
    row, column
    SeatClass class
}*/

~~~

2) Screen class will have a name and list of Seats. It's behavior includes methods to add or remove Seat(s)
~~~cpp
class Screen {
    string m_name;
    list<Seat> m_seats;
public:    
    void addSeats(list<Seat> seats);
    void removeSeats(list<Seat> seats);
    void addSeat(Seat seat);
    void removeSeat(Seat seat);
};

/*Screen {
    name
    List<Seat> seats
    
    addSeats(List<Seat> seats)
    removeSeats(List<Seat> seats)
    addSeat(Seat seat)
    removeSeat(Seat seat)
}*/
~~~ 

3) Theater class will have a name, list of Screens and Location. It will have methods to add or remove Screen(s)

~~~cpp

class Theater {
    string m_name;
    Location& m_location;
    list<Screen> m_screens;
public:
    void addScreens(list<Screen> screens);
    void removeScreens(list<Screen> screens);
    void addScreen(Screen screen);
    void removeScreen(Screen screen);
};
/*
Theater {
    name
    Location location
    List<Screen> screens

    addScreens(List<Screen> screens)
    removeScreens(List<Screen> screens)
    addScreen(Screen screen)
    removeScreen(Screen screen)
}
*/
~~~
4) TheaterManager class will be used by admin users to add/remove theater or screen
~~~cpp

class TheaterManager
{
  public:
    void addTheater(Theater theater);
    void removeTheater(Theater theater);
    void addScreen(Theater theater, Screen screen);
    void removeScreen(Theater theater, Screen screen);
};
/*
TheaterManager {
    addTheater(Theater theater)
    removeTheater(Theater theater)
    addScreen(Theater theater, Screen screen)
    removeScreen(Theater theater, Screen screen)
}

*/
~~~
5) Movie class contains a number of attributes in addition to name like trailer video, artists information and much more.
~~~cpp
class Movie{
    string m_name;
    // trailer, release date, actors & technicians 
};
/* Movie {
    name,
    ........
    ........
}*/
~~~

6) MovieManager class contains methods like add/remove/search movie
~~~cpp
class MovieManager {
public:
    void addMovie(Movie movie);
    void removeMovie(Movie movie);
    list<Movie> searchMovies(string searchQuery);
};

/*MovieManager {
    addMovie(Movie movie)
    removeMovie(Movie movie)
    List<Movie> searchMovies(searchQuery)
}*/
~~~

7) Ticket class contains seat(s), screen, theater information, movie, price and show timing

~~~cpp
class Ticket {
    list<Seat> m_seats;
    Screen screen;
    Theater m_theater;
    Movie m_movie;
    double m_price;
    time_t m_showTime;
};
/*
Ticket {
    List<Seat> seats
    Screen screen
    Theater theater
    Movie movie
    price
    showTime
}*/
~~~

8) PriceMap is a map of SeatClass and it's price

~~~cpp
class PriceMap {
    map<SeatClass,double> m_seatClassToPriceMap;
public:
    void addPriceForASeatClass(SeatClass seatclass, int price);
};

/*PriceMap {
    seatClassToPriceMap
    
    addPriceForASeatClass(SeatClass, price)
}*/
~~~

9) Show class will have a Screen, Movie, show time, PriceMap and a map of seats availability. It can calculate final price of selected seats and can generate Ticket(s)

~~~cpp
class Show {
    Screen m_screen;
    Movie m_movie;
    time_t m_showTime;
    PriceMap m_priceMap;
    // seatAvailabilityMap;
    
public:    
    double calculatePrice(list<Seat> seats);
    list<Ticket> bookTickets(list<Seat> seats);
};
/*
Show {
    Screen screen
    Movie movie
    showTime
    PriceMap priceMap
    seatAvailabilityMap
    
    double calculatePrice(List<Seat> seats)
    List<Ticket> bookTickets(List<Seat> seats)
}*/
~~~

10) Payment class will take care of booking amount payment
~~~cpp
class Payment{};
Payment {
    ..........
}
~~~

11) ShowManager class will have methods like create Show, find Shows and other methods for ticket booking

~~~cpp
class ShowManager
{

public:
    void  createShow(Show show);
    list<Show> findShows(Movie movie);
    double calculatePrice(Screen screen, list<Seat> seats);
    void makePayment(double amount);
    list<Ticket> generateTickets(Screen screen, list<Seat> seats) ;
}; 
/*
ShowManager {
    createShow(Show show)
    List<Show> findShows(Movie movie)
    double calculatePrice(Screen screen, List<Seat> seats)
    makePayment(amount)
    List<Ticket> generateTickets(Screen screen, List<Seat> seats) 
} */
~~~

All manager classes from the above list can be use to expose APIs of the system.