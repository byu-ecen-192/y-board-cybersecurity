#include "yboard.h"
#include "HTTPClient.h"
#include <WiFi.h>
#include <ArduinoJson.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

#include "screen.h"

uint8_t TEXT_SIZE = 1;

void screen_init()
{
  delay(1000);                               // Display needs time to initialize
  Yboard.display.begin(SSD1306_SWITCHCAPVCC, 0x3c); // Initialize display with I2C address: 0x3C
  Yboard.display.clearDisplay();
  Yboard.display.setTextColor(ON);
  Yboard.display.setRotation(ZERO_DEG); // Can be 0, 90, 180, or 270
  Yboard.display.setTextWrap(false);
  //display.dim(BRIGHTNESS_DAMPER);
  Yboard.display.display();
}

void screen_loop(String ip_address, String app_password, bool display_password)
{
  display_info(ip_address, app_password, display_password);
}

void display_text(String text)
{
  Yboard.display.clearDisplay(); // Clear the display

  draw_text(text, 0, 0); // Draw text

  Yboard.display.display(); // Display
}

void display_info(String ip_address, String app_password, bool display_password)
{
  Yboard.display.clearDisplay(); // Clear the display

  draw_text("IP Address", 0, 0); // Draw line for identifer
  draw_text(ip_address, 0, 16);  // Draw ip address
  // Draw password if display_password is true
  if (display_password == true)
  {
    draw_text("Password", 0, 32);   // Draw line for password
    draw_text(app_password, 0, 48); // Draw password
  }

  Yboard.display.display(); // Display
}

void draw_text(String text, int x, int y)
{
  Yboard.display.setCursor(x, y);
  Yboard.display.setTextSize(TEXT_SIZE);
  Yboard.display.print(text);
}
