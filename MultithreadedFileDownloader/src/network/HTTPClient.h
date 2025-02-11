#ifndef HTTPCIENT_H
#define HTTPCIENT_H

#include <string>

class HTTPClient {
public:
    HTTPClient(const std::string& url);
    void downloadFile(const std::string& fileName, int startByte, int endByte);
private:
    std::string url;
};

#endif