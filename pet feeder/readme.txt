Through this project we want to make human life a little bit more easier. This project works on human instruction. Whenever 

user will give a command through the webpage to the development board used in the project, the pet feeder will be able to 

provide food and water to the pet after detecting that the pet had arrived at that particular area. The pet will arrive at 

that area when a particular noise will be made through buzzer in prior with user’s command through webpage. 


WORKING OF THE PROJECT

    In the specific project, we set the feeder to start beeping when the microcontroller used in the project ,i.e., Arduino Uno
    
    receives signal through the webpage. The instruction is given by the user through the webpage. The internet connection is 
    
    provided to the project through Arduino Uno which is attached to the Ethernet shield. The Ethernet shield is connected to 
    
    the laptop through LAN(Local Area Network) wire. The pet will receive instruction as soon as the buzzer beeps on the 
    
    command of the user.  Once the comes closer to the device, the ultrasonic sensor measures the distance of the pet from 
    
    the sensor and when the pet comes at the suitable distance both servo motors are triggered ,i.e., one for food and the 
    
    other one for water.


Hardware Components used:

1. Arduino Uno
2. Ultrasonic Sensor
3. Servo motors
4. Ethernet Shield
5. L293D
6. 7805







Welcome to the DHCP Server for Windows

What is a DHCP Server?
----------------------

A DHCP Server is a protocol server for TCP/IP networks that
supplies IP addresses to other computers. DHCP Server for Windows
also supports TFTP, DNS and HTTP protocol which makes a nice 
package for easy and simple to install networks e.g. for
remote boot and other purposes.

DHCP server runs on all Win32 capable Windows operating
systems starting from Windows 95 to Windows 7.


Installation
------------

The DHCP Server is a portable application and runs from anywhere
on your computer. Extract the content of the zip file wherever you like,
e.g. D:\dhcpsrv

You now find the following files in there:

D:\dhcpsrv
 |
 |--- dhcpsrv.exe               // the DHCP Server program
 |--- dhcpwiz.exe               // Configuration program
 |--- readme.txt                // this file
 |--- wwwroot                   // Directory with basic web files
 |      |--- dhcpstyle.xsl
 |      |--- dhcppkgstyle.xsl
 |      |--- favicon.ico
 |      |--- index.html
 |      |--- RJ45_5.jpg
 |      |--- RJ45_52.jpg
 .      .


Configuration with dhcpwiz.exe
------------------------------

In order to get the software running I'm suggesting to start dhcpwiz.exe
first. The dhcpwiz.exe program is a wizard style configuration program for
the DHCP server. It will guide you in 5 easy steps through the basic
configuration of the software. If you are an advanced user just updating from
an earlier version then plesae go straight to the Web site 
http://www.dhcpserver.de/ and learn whats new in this version.


1. Welcome to the DHCP configuration wizard.
There is not much more to do than to hit the next button.

2. Network interface cards.
The DHCP configuration wizard lists all currently identified network
interfaces on your computer. It is necessary to select one. This is
going to be the interface that will be used by DHCP server. It is a good
idea to choose a network interface that by itself is not getting it's
IP address from a DHCP server. This would probably cause conflicts.
Hit next after interface has been selected.

3. Supported Protocols.
Now you can select which TCP/IP protocols should be activated.
I'm suggesting to enable HTTP (Web Server) and hit next.

4. Configuring DHCP for interface.
In this step you define the pool of IP addresses. A client will get an
IP addresses assigned out of this pool. The default values should be good
and lead you to the next step after hitting the next button.

5. Writing the INI file.
The final result of the DHCP configuration wizard is an INI file. This file
will contain all the configuration options. The filename and path shown here
should point to d:\dhcpsrv\dhcpsrv.ini, depending on where you've exctracted
the zip file. It is important that the INI file is placed into the same folder
as dhcpsrv.exe resides. If that is all ok, then hit the "Write INI file" and
the the next button to start the final step of the configuration.

6. DHCP configuration completed.
The windows firewall is a great thing to have. But it can be a pain also to 
get communication server programs working. That is the reason why the wizard 
gives you at this stage the option to add the dhcp server program to the 
exception list of the windows firewall. Please hit the configure button and 
wait for the status to change from "Not configured" to "configured". If you 
are not running the DHCP configuration wizard with administrator privileges, 
then you need to do that after you have elevated your rights accordingly by 
hitting the "Admin..." button.

It is now time to start the DHCP server program. The DHCP server can run as 
a service or as an application. If you want to run it as a service then you 
can install and start the service here also. Again, non-administrators can 
do that only after elevation (the "Admin..." button). The status needs to 
change from "Not installed" to "Running". If you decide not to install DHCP 
server as a service but wants to run DHCP server as an application, then you 
can tick the "Run DHCP server immediatly" check box and click finish. 



Running dhcpsrv.exe 
-------------------

Once the INI file has been created by the DHCP configuration wizard, it is now
time to start the actual DHCP server program. Start the dhcpsrv.exe. 

If you are running Windows NT or Windows 2000/XP/VISTA/7 then the DHCP server will ask show
a dialog box. On all older operating systems (Windows 98, etc..) the DHCP server will 
go straight into the tray as a tray icon application.
The dialog allows you again to operate the service and the firewall.



Check if DHCP server works as expected
--------------------------------------

Once the DHCP configuration has been performed and DHCP server is started, you probably
want to know whether it actually works. If you have activated the HTTP support as part
of step3 during the DHCP configuration wizard, then you can use your internet browser to 
open the DHCP status web site:   http://127.0.0.1/dhcpstatus.xml
This should show the configured and operating connections and also all currently 
active clients. I assume there aren't any yet.

Once a DHCP client is assigned an IP address it will show up after reloading the page.


Please visit my web site regularily to check for updates and any further reading.
If you have any questions or recommendations:
E-Mail me: Uwe.Ruttkamp@gmx.net
or visit my WEB page: http://www.dhcpserver.de/
