/**
 * pic_pins.h
 * 
 * Defines the pins used for each peripheral as preprocessor constants.
 */

#pragma once

#define ADC_AN_PIN 30 // TFT LED PWM, Contrast, RD7

#define PWM_OUT1_PIN 33 // RB0
#define PWM_OUT2_PIN

#define UART_RX_PIN
#define UART_TX_PIN

#define SPI_SCK_PIN 34 // RB1
#define SPI_SDI_PIN
#define SPI_SDO_PIN 35 // RB2

#define TFT_CS_PIN 38 // RB5
#define TFT_DC_PIN 36 // RB3
#define TFT_nRST_PIN 37 // RB4
#define TFT_LED_PIN PWM_OUT1_PIN

#define I2C_SCL_PIN
#define I2C_SDA_PIN