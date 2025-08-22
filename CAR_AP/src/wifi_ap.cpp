#include "wifi_ap.h"
#include "esp_camera.h"
#include "esp_http_server.h"
#include <string.h>
#include <stdlib.h>
#include "Arduino.h"

int speed = 255;
int noStop = 0;

enum state {fwd, rev, stp};
state actstate = stp;

// Aquí va todo el contenido de cmd_handler y status_handler que ya me enviaste
// Puedes copiarlo directamente aquí
