package com.house;

import java.util.InputMismatchException;
import java.util.Scanner;

public class MainApp {

	HomeAutomation house = new HomeAutomation();
	Scanner sc = new Scanner(System.in);
	
	public static void main(String[] args) {
		
		
		MainApp app = new MainApp();
		
		app.HomeAutomation();
	
	}
	
	public void HomeAutomation()
	{
		int choice = 0;
		
		do {
			System.out.println("\nHOME AUTOMATION APP-->\n");
			System.out.println("1.Add New Room");
			System.out.println("2.Add New Device");
			System.out.println("3.Turn ON Device");
			System.out.println("4.Turn OFF Device");
			System.out.println("5.Check Current Status");
			System.out.println("6.Display All Devices");
			System.out.println("0.Want To Exit");
			
			System.out.print("Enter Your Choice : ");
			choice = sc.nextInt();
			
			switch(choice)
			{
				case 1 :
				{
						int input=-1;
					
						do {
							
							String roomName;
						
							System.out.println("\n@Add New Room==>");
							System.out.print("Enter Type Of Room : ");
							roomName = sc.next();
							
							Room newRoom = new Room(roomName);
						    house.addRoom(newRoom);
						    System.out.println("\nNew Room '" + roomName + "' added.\n");
						    
			
						    try {
								System.out.print("Press 0 For Exit --->");
								input = sc.nextInt();
							} 
						    catch (InputMismatchException e) 
						    {
								System.out.println("\nInput is wrong");
							}
						    sc.nextLine();
						}while(input!=0);
		
				}
				break;
				
				case 2 :
				{
					int roomIndex = 1;
					System.out.println("\nSelect Room To Add Device : \n");
					
					 for (Room room : house.rooms) {
	                        System.out.println(roomIndex + ". " + room.getRoomType());
	                        roomIndex++;
	                    }
					System.out.print("\nSelect The Room Number : ");
					int roomNum = sc.nextInt();
					sc.nextLine();
					
					if(roomNum >= 1 && roomNum <= house.rooms.size())
					{
					//	Room room = house.rooms.get(roomNum - 1);
						int newDevice;
						do {
							
								System.out.println("\nSelect Device You Want To Add\n");
								System.out.println("1.Electronic Device");
								System.out.println("2.Air Conditioner");
								System.out.println("3.Television");
								System.out.println("4.Showers");
								System.out.println("5.Lights");
								System.out.println("0.Back To Menu\n");
								
								System.out.print("Enter Your Choice : ");
								newDevice = sc.nextInt();
								
								if(newDevice >=1 && newDevice <=5)
								{
									System.out.print("Enter Device Name : ");
									String name = sc.next();
									
									System.out.print("Enter Device Type : ");
									String type = sc.next();
									
									System.out.print("Enter Device Id   : ");
									String id = sc.next();
									
									switch(newDevice)
									{
										
										case 1 :
										{
											ElectronicsDevice eDevice = new ElectronicsDevice(name,type,id);
											
											house.rooms.get(roomNum - 1).addDevice(eDevice);
							
											System.out.println(name+" Device added");
										}
										break;
										
										case 2 :
										{
											AirConditioners airConditioner = new AirConditioners(name,type,id);
											
											house.rooms.get(roomNum - 1).addDevice(airConditioner);
											
											System.out.println(name+" Device added");
										}
										break;
										
										case 3 :
										{
											Television telVision = new Television(name,type,id);
											
											house.rooms.get(roomNum - 1).addDevice(telVision);
											
											System.out.println(name+" Device added");
										}
										break;
										
										case 4 :
										{
											Showers shower = new Showers(name,type,id);
											
											house.rooms.get(roomNum - 1).addDevice(shower);
											
											System.out.println(name+" Device added");
										}
										break;
										
										case 5 :
										{
											Lights light = new Lights(name,type,id);
											
											house.rooms.get(roomNum - 1).addDevice(light);
											
											System.out.println(name+" Device added");
										}
										break;
										
									
									}
	
								}
								else if(newDevice==0)
								{
									System.out.println("\nBack to main menu <--\n");
								}
								else
								{
									System.out.println("\nRoom Number Is Wrong!!\n");
								}
						
						}while(newDevice!=0);
						
					}

				}
				break;
				
				case 3 :
				{
					System.out.println("\nSelect Room To Control Device : \n");
					int roomIndex = 1;
					
					 for (Room room : house.rooms) {
	                        System.out.println(roomIndex + ". " + room.getRoomType());
	                        roomIndex++;
	                    }
					 
					 System.out.println("Enter Room Type : ");
					 int roomNum = sc.nextInt();
					 sc.nextLine();
					 
				
					 if(roomNum >= 1 && roomNum <= house.rooms.size())
						{
							//Room room = house.rooms.get(roomNum - 1);
						 int deviceNum=-1;
						 
						 do {
							 	System.out.println("\nSelect Device To Turn ON ");
								System.out.println("1.Electronic Device");
								System.out.println("2.Air Conditioner");
								System.out.println("3.Television");
								System.out.println("4.Showers");
								System.out.println("5.Lights");
								System.out.println("0.Back To Menu\n");
								
								
								System.out.print("Enter Your choice : ");
								deviceNum = sc.nextInt();
								
							 
								if(deviceNum>=0 && deviceNum<=5)
								{
									
									
									switch(deviceNum)
									{
										
										default :
										{
											int flag=0;
											System.out.println();
											System.out.print("Enter Device Id : ");
											String deviceId = sc.next();
											
											for(int ctr=0;ctr<house.rooms.get(roomNum-1).devices.size();ctr++)
											{
											
												if(house.rooms.get(roomNum-1).devices.get(ctr).getDeviceId().equals(deviceId))
												{
													
													house.rooms.get(roomNum-1).devices.get(ctr).turnOn();
													flag++;
													break;
													
												}
											}
											if(flag==0)
											{
												System.out.println("\nDevice Not Found !\n");
											}
											
											
										}
										break;
										
										case 0 :
										{
											System.out.println("\nBack to main menu <--\n");
										}
										break;
								}
								
									
								}
								else
								{
									System.out.println("\nDevice Number is Wrong..\n");
								}
								
								
							 
						 }while(deviceNum!=0);
						 
						}
					 
					
				}
				break;
				
				case 4 :
				{
					System.out.println("\nSelect Room To Control Device : \n");
					int roomIndex = 1;
					
					 for (Room room : house.rooms) {
	                        System.out.println(roomIndex + ". " + room.getRoomType());
	                        roomIndex++;
	                    }
					 
					 System.out.println("Enter Room Type : ");
					 int roomNum = sc.nextInt();
					 sc.nextLine();
					 
				
					 if(roomNum >= 1 && roomNum <= house.rooms.size())
						{
							//Room room = house.rooms.get(roomNum - 1);
						 int deviceNum;
						 
						 do {
							 	System.out.println("Select Device To Turn OFF ");
								System.out.println("1.Electronic Device");
								System.out.println("2.Air Conditioner");
								System.out.println("3.Television");
								System.out.println("4.Showers");
								System.out.println("5.Lights");
								System.out.println("0.Back To Menu\n");
								
								System.out.print("Enter Your choice : ");
								deviceNum = sc.nextInt();
							 
								if(deviceNum>=0 && deviceNum<=5)
								{
									switch(deviceNum)
									{
										
										default :
										{
											int flag=0;
											System.out.println();
											System.out.print("Enter Device Id : ");
											String deviceId = sc.next();
											
											for(int ctr=0;ctr<house.rooms.get(roomNum-1).devices.size();ctr++)
											{
											
												if(house.rooms.get(roomNum-1).devices.get(ctr).getDeviceId().equals(deviceId))
												{
													
													house.rooms.get(roomNum-1).devices.get(ctr).turnOff();
													flag++;
													break;
													
												}
											}
											if(flag==0)
											{
												System.out.println("\nDevice Not Found !\n");
											}
											
											
										}
										break;
										
										case 0 :
										{
											System.out.println("\nBack to main menu <--\n");
										}
										break;
									}
									
								}
								else
								{
									System.out.println("\nDevice Number is Wrong..\n");
								}
							 
						 }while(deviceNum!=0);
						 
						}
			
				}
				break;
				
				case 5 :
				{
					house.displayStatus();
				}
				break;
				
				case 6 :
				{
					for(int ctr=0;ctr<house.rooms.size();ctr++)
					{
						System.out.println("\nRoom Name : "+house.rooms.get(ctr).roomType);
						
						for(int ctr2=0;ctr2<house.rooms.get(ctr).devices.size();ctr2++)
						{
							System.out.println("\nDevice Name : "+house.rooms.get(ctr).devices.get(ctr2).deviceName);
							System.out.println();
							
						}
					
	
					}
					
				}
				break;
				
				case 0 :
				{
					System.out.println("\nThank You!!");
				}
				break;
				
				default :
				{
					System.out.println("\nInvalid Choice!!\n");
				}
				break;
				
			}
		}while(choice!=0);


	}

}
