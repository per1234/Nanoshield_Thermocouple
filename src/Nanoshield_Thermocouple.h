/**
 * @file Nanoshield_Thermovouple.h
 * This is the library to access the Thermocouple Nanoshield
 * 
 * Copyright (c) 2013 Circuitar
 * This software is released under the MIT license. See the attached LICENSE file for details.
 */

#ifndef NANOSHIELD_THERMOCOUPLE_h
#define NANOSHIELD_THERMOCOUPLE_h

#ifdef ARDUPI
  #include "arduPi.h"
#else
  #include "Arduino.h"
  #include <SPI.h>
#endif

class Nanoshield_Thermocouple {
  public:
    /**
     * @brief Constructor.
     * 
     * Creates an object to access one Termopar Nanoshield.
     */
    Nanoshield_Thermocouple();

    /**
     * @brief Initializes the module.
     * 
     * Initializes SPI and CS pin.
     * 
     * @param cs Chip select pin to access Termopar Nanoshield.
     */
    void begin(uint8_t cs = 8);

    /**
     * @brief Reads internal and external temperatures.
     * 
     * @see getInternal()
     * @see getExternal()
     * @see hasError()
     */
    void read();

    /**
     * @brief Gets the last internal temperature read.
     * 
     * @return The last internal temperature read.
     * @see read()
     */
    double getInternal();

    /**
     * @brief Gets the last external temperature read.
     * 
     * @return The last external temperature read.
     * @see read()
     */
    double getExternal();

    /**
     * @brief Checks if is shorted to VCC.
     * 
     * The sensor is connected to VCC.
     * 
     * @return True if shorted to VCC. False otherwise.
     */
    bool isShortedToVcc();

    /**
     * @brief Checks if is shorted to GND.
     * 
     * The sensor is connected to GND.
     * 
     * @return True if shorted to GND. False otherwise.
     */
    bool isShortedToGnd();

    /**
     * @brief Checks if open circuit.
     * 
     * The sensor circuit is open.
     * 
     * @return True if open circuit. False otherwise.
     */
    bool isOpen();

    /**
     * @brief Checks if there are errors.
     * 
     * @return True if any of shorted to VCC, shorted to GND or open circuit
     *         errors occurred. False if no errors.
     * @see isShortedToVcc()
     * @see isShortedToGnd()
     * @see isOpen()
     */
    bool hasError();

  protected:
    uint8_t csPin;
    double intTemp;
    double extTemp;
    bool shortToVcc;
    bool shortToGnd;
    bool openCircuit;
};

#endif