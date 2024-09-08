The project represents a Clinic Management System.
Written in C Programming language.
At the beginning of the system it asks the user to choose 
between admin mode and user mode. 
In admin mode:
The system asks for password, the default password is 1234. The system allows 3 trails for the password 
entry, if the entered password was incorrect for 3 consecutive times, the system shall close. 
After login:
In admin mode, the system shall provide the following features: 
1. Add new patient's record: 
To add a new patient, the user shall admin shall enter these basic information: name, age, gender and provides an  ID. The ID shall be unique for the user. 
2. Edit patient's record:
By entering patient ID the system shall checks if the ID exists, the system shall allow the user to edit the 
patient information. If not, the system shall display incorrect ID message. 
3. Reserve a slot with the doctor:
By default there are 5 available slots, 2pm to 2:30pm, 2:30pm to 3pm, 3pm to 3:30pm, 4pm to 4:30pm 
and 4:30pm to 5pm. Upon opening of this window, the system shall display the available slots. The 
admin shall enter the patient ID and the desired slot. The reserved slot shall not appear again in the next 
patient reservation. 
4. Cancel reservation: 
The admin can cancel a reservation by entering the patient ID. This reservation shall be shown again in 
the available slots window. 
In user mode:
There is no password. The system allows the following features: 
1. View patient's record:
By entering the patient's ID, the system shall show the basic information for the patient. 
2. View today’s reservations:
In this view, the system shall print all reservations with the patient's ID attached to each reservation slot.
The program has a third mode for exiting.
