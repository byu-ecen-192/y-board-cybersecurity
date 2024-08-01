#ifndef CYBER_H
#define CYBER_H

void cyber_init();
void cyber_loop();
void cyber_credentials_init();
void cyber_wifi_init();
void cyber_color_init();
void getCredentials();
void pollForCommands();
void confirmCommandExecuted(String command);

#endif
