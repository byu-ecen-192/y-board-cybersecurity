#include "HTTPClient.h"
#include <WiFi.h>
#include <ArduinoJson.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

#include "screen.h"

Adafruit_SSD1306 display(128, 32); // Create display
uint8_t TEXT_SIZE = 1;

void screen_init()
{
  delay(1000);                               // Display needs time to initialize
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c); // Initialize display with I2C address: 0x3C
  display.clearDisplay();
  display.setTextColor(ON);
  display.setRotation(ZERO_DEG); // Can be 0, 90, 180, or 270
  display.setTextWrap(false);
  //display.dim(BRIGHTNESS_DAMPER);
  display.display();
}

void screen_loop(String ip_address, String app_password, bool display_password)
{
  display_info(ip_address, app_password, display_password);
}

void display_text(String text)
{
  display.clearDisplay(); // Clear the display

  draw_text(text, 0, 0); // Draw text

  display.display(); // Display
}

void display_info(String ip_address, String app_password, bool display_password)
{
  display.clearDisplay(); // Clear the display

  draw_text("IP Address", 0, 0); // Draw line for identifer
  draw_text(ip_address, 0, 16);  // Draw ip address
  // Draw password if display_password is true
  if (display_password == true)
  {
    draw_text("Password", 0, 32);   // Draw line for password
    draw_text(app_password, 0, 48); // Draw password
  }

  display.display(); // Display
}

void draw_text(String text, int x, int y)
{
  display.setCursor(x, y);
  display.setTextSize(TEXT_SIZE);
  display.print(text);
}
