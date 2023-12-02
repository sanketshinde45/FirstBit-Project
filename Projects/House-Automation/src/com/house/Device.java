package com.house;

import java.util.Date;

public class Device implements ControlDevice{

	String deviceName;
	String deviceType;
	String deviceId;
	boolean isOn;
	long totalTimeInState;
    Date lastStateTime;

	public Device() {
		
	}

	public Device(String name,String type,String id) {
		super();
		this.deviceName = name;
		this.deviceType = type;
		this.deviceId = id;
		this.isOn = false;
		this.totalTimeInState = 0;
		this.lastStateTime = new Date();
	}

	public String getType() {
		return deviceType;
	}

	public void setType(String type) {
		this.deviceType = type;
	}

	public String getDeviceName() {
		return deviceName;
	}

	public void setDeviceName(String deviceName) {
		this.deviceName = deviceName;
	}

	public String getDeviceType() {
		return deviceType;
	}

	public void setDeviceType(String deviceType) {
		this.deviceType = deviceType;
	}

	public String getDeviceId() {
		return deviceId;
	}

	public void setDeviceId(String deviceId) {
		this.deviceId = deviceId;
	}

	public boolean isOn() {
		return isOn;
	}

	public void setOn(boolean isOn) {
		this.isOn = isOn;
	}

	public void setTotalTimeInState(long totalTimeInState) {
		this.totalTimeInState = totalTimeInState;
	}
	
	public long getTotalTimeInState() {
		
		long currentTime = System.currentTimeMillis();
		
		if(isOn)
		{
			return totalTimeInState + (currentTime - lastStateTime.getTime()); 
		}
		else
		{
			return totalTimeInState;
		}

	}

	public void setLastStateTime(Date lastStateTime) {
		this.lastStateTime = lastStateTime;
	}

	public Date getLastStateTime() {
		
		return lastStateTime;
	}
	
	@Override
	public void turnOn() {
		
		if(!isOn)
		{
			isOn = true;
			
			long currentTime = System.currentTimeMillis();
			
            this.totalTimeInState += (currentTime - lastStateTime.getTime());
            this.lastStateTime = new Date(currentTime);
            System.out.println(this.deviceName + " is turned ON");
		}
		else
		{
			System.out.println(this.deviceName + " is already ON");
		}
	
	}

	@Override
	public void turnOff() {
      
		if(isOn)
		{
			isOn = false;
			
			long currentTime = System.currentTimeMillis();
			
            this.totalTimeInState += (currentTime - lastStateTime.getTime());
            this.lastStateTime = new Date(currentTime);
            System.out.println(this.deviceName + " is turned OFF");
			
		}
		else
		{
			System.out.println(this.deviceName + " is already OFF");
		}
		
	}
	
}
