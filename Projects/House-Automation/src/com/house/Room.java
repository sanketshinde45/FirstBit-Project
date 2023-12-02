package com.house;

import java.util.ArrayList;

public class Room{

	String roomType;
	ArrayList<Device> devices;
	
	public Room() {
		// TODO Auto-generated constructor stub
	}

	public Room(String roomType) {
		this.roomType = roomType;
		this.devices = new ArrayList<>();
	}

	public String getRoomType() {
		return roomType;
	}

	public void setRoomType(String roomType) {
		this.roomType = roomType;
	}

	public ArrayList<Device> getDevice() {
		return devices;
	}

	public void addDevice(Device device) {
		devices.add(device);
	}
	
}


