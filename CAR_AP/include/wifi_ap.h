
#ifndef WIFI_AP_H
#define WIFI_AP_H

#include "esp_http_server.h"

extern int speed;
extern int noStop;

esp_err_t cmd_handler(httpd_req_t *req);
esp_err_t status_handler(httpd_req_t *req);

#endif
