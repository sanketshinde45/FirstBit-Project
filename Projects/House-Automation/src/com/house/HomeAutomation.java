package com.house;

import java.util.ArrayList;

public class HomeAutomation {

	ArrayList<Room> rooms;
	
	public HomeAutomation() 
	{	
		this.rooms = new ArrayList<>();
	}
	
	public void addRoom(Room room )
	{
		rooms.add(room);
	}
	
	public void displayStatus() {
        for (Room room : rooms) {
            System.out.println("\nRoom: " + room.getRoomType());
            ArrayList<Device> devices = room.getDevice();
            for (Device device : devices) {
                System.out.println("- Device: " + device.getDeviceName());
                System.out.println("  Status: " + (device.isOn() ? "ON" : "OFF"));
                System.out.println("  Total Time In State (ms): " + device.getTotalTimeInState());  
                System.out.println("  Last State Change Time: " + device.getLastStateTime());
            }
        }
    }

	
}
