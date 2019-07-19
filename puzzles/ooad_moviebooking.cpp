// `Vehicle Parking System `

#ifndef IOSTREAM
#define IOSTREAM
#include<iostream>
#endif

#ifndef LIST
#define LIST
#include<list>
#endif

#ifndef MAP
#define MAP
#include <map>
#endif

#ifndef STRING  
#define STRING
#include<string>
#endif

#ifndef CTIME
#define CTIME
#include <ctime>
#endif


using std::endl;
using std::cout;
using std::string;
using std::list;
using std::map;


enum SeatClass{
   normal,
   recliner
};

class Seat{
    int m_row;
    int m_column;
    SeatClass m_class;
};


class Screen {
    string m_name;
    list<Seat> m_seats;
public:    
    void addSeats(list<Seat> seats);
    void removeSeats(list<Seat> seats);
    void addSeat(Seat seat);
    void removeSeat(Seat seat);
}; 

class Location{};
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

class TheaterManager
{
  public:
    void addTheater(Theater theater);
    void removeTheater(Theater theater);
    void addScreen(Theater theater, Screen screen);
    void removeScreen(Theater theater, Screen screen);
};

class Movie{
    string m_name;
    // trailer, release date, actors & technicians 
};


class MovieManager {
public:
    void addMovie(Movie movie);
    void removeMovie(Movie movie);
    list<Movie> searchMovies(string searchQuery);
};


class Ticket {
    list<Seat> m_seats;
    Screen screen;
    Theater m_theater;
    Movie m_movie;
    double m_price;
    time_t m_showTime;
};


class PriceMap {
    map<SeatClass,double> m_seatClassToPriceMap;
public:
    void addPriceForASeatClass(SeatClass seatclass, int price);
};



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

class Payment{};

class ShowManager
{

public:
    void  createShow(Show show);
    list<Show> findShows(Movie movie);
    double calculatePrice(Screen screen, list<Seat> seats);
    void makePayment(double amount);
    list<Ticket> generateTickets(Screen screen, list<Seat> seats) ;
}; 
