
#ifndef WEB_H
#define WEB_H

#include "esp_http_server.h"

typedef struct {
    httpd_req_t *req;
    size_t len;
} jpg_chunking_t;

extern httpd_handle_t stream_httpd;
extern httpd_handle_t camera_httpd;

esp_err_t index_handler(httpd_req_t *req);
esp_err_t capture_handler(httpd_req_t *req);
esp_err_t stream_handler(httpd_req_t *req);
void startCameraServer();

#endif

