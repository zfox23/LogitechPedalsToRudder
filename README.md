Given a properly-wired Arduino Leonardo and Logitech G27 pedals, this Ardunio sketch allows your standalone G27 pedals to act as a rudder control via USB. I like to use my pedals as my Flight Simulator and Elite Dangerous rudders.

# What You'll Need
- [Logitech G27](https://support.logi.com/hc/en-us/articles/360024641254) pedals
    - This might work with other Logitech racing wheel pedals, but I only own the G27.
- An Arduino Leonardo
    - ~$20 on [Amazon](https://amzn.to/2YgF9xw)
- A Micro USB cable to go from the Arduino to your PC
    - Find one lying around your house, or grab some for ~$10 on [Amazon](https://amzn.to/3g3dupO)
- A DB9 female connector
    - If you're lucky, find one at a local electronics store, or buy more than you need for ~$8 on [Amazon](https://amzn.to/2FC23ZH)
- A soldering iron and some solder
    - Maybe you already own this gear from previous hobby projects. If not, here's a $23 [soldering kit](https://amzn.to/323UKkT) and some $9 [solder](https://amzn.to/317ujvk) on Amazon.
- Some male-to-male jumper wires
    - These are probably cheaper to buy locally or find in your hobby drawer, but here's [some $6 jumper wires on Amazon](https://amzn.to/31661Ca).
- The [Arduino IDE](https://www.arduino.cc/en/main/software)
    - Free!
- A copy of the [Arduino Joystick Library in ZIP format](https://github.com/MHeironimus/ArduinoJoystickLibrary/archive/master.zip) on your hard drive.
    - Free!

## Total Project Cost
If you need to buy _everything_ from above, this project will cost you around **$76 plus the cost of the G27 pedals**.

# Wiring the DB9 Connector to the Arduino
Look at the rear of your DB9 female connector:
- The row of 5 pins is the "top"; pin 1 is the top-left pin.
- The row of 4 pins is the "bottom"; pin 9 is the bottom-right pin.
- DB9 pinout ASCII art:
    ```
    _________________________
    \   1   2   3   4   5   /
     \    6   7   8   9    /
      \___________________/  
    ```

We'll use this information below.

Use your soldering iron, solder, and jumper wires to wire the following DB9 pins to the corresponding Arduino Leonardo pins:
- Pin 1 -> `GND`
- Pin 2 -> `A2`
- Pin 3 -> `A1`
- Pin 4 -> `A0`
- Pin 5 _no connection_
- Pin 6 -> `5V`
- Pin 7 _no connection_
- Pin 8 _no connection_
- Pin 9 -> `5V`
    - If there's only one `5V` pin on your Arduino, it's okay to solder one jumper wire to another, then plug the resulting exposed wire into `5V`. It won't be pretty, but it'll work!

# Plug It In
1. Plug your G27 pedals into your DB9 connector (the DB9 connector is wired to your Arduino).
2. Plug your Arduino into your computer via Micro USB.

# The Software
After you've plugged it all in and wired it all up, make sure you've downloaded and installed the free [Arduino IDE](https://www.arduino.cc/en/main/software).

1. Open the Arduino IDE.
2. Click `File -> Open`.
3. Open `LogitechPedalsToArduino.ino` from this repository.
4. Click `Sketch -> Include Library -> Add .ZIP Library...`.
5. Navigate to and open the [Arduino Joystick Library .ZIP file]((https://github.com/MHeironimus/ArduinoJoystickLibrary/archive/master.zip)).
6. Click `Tools -> Board: * -> Arduino Leonardo`.
7. Click `Sketch -> Upload` or press the Upload button in the IDE toolbar.
8. Wait for the programming to finish.
9. You can now close the Arduino IDE.

Now your clutch pedal and your accelerator pedal are working to create the Rudder axis on a virtual joystick!

# Calibrate the Pedal Axes
Importantly - you must now calibrate the "controller" from within Windows:
1. Click Start.
2. Search for "controllers" and press enter.
3. Click the `Arduino Leonardo` controller, then click `Properties`.
4. Click the `Settings` tab, then click `Calibrate...`.
5. Follow the instructions to calibrate the rudder axis.

# Done!
You're all set! Now you can bind an input in your favorite flight games to your new rudder axis. Enjoy!