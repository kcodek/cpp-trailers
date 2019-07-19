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

enum VehicleType{
    bike, 
    car
};

class ParkingTicket;

class Vehicle
{
   string m_registrationNumber;     
   VehicleType m_type;
   ParkingTicket& m_parkingTicket;

public:
   ParkingTicket checkIn();//generate a parking ticket on check-in

};

class ParkingFloor;


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


class ParkingArea {
    list<ParkingFloor> m_parkingFloors;
};

class ParkingBill;

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
    map<VehicleType,float> m_vehicleTypeToRateMap;
};

class ParkingManager {
    ParkingArea m_parkingArea;
    list<Vehicle> m_checkedInVehicles;
public:
    bool isParkingAvailable();
    ParkingTicket checkInVehicle(Vehicle vehicle);
    ParkingBill generateBill(ParkingTicket parkingTicket);
};
