#ifndef DNS_RESOLVER_H
#define DNS_RESOLVER_H

#include <string>
#include <cstdint>
#include <netinet/in.h> // For sockaddr_in

const int DNS_BUFFER_SIZE = 512;

class DNSResolver {
public:
    // Constructor: takes the domain name
    DNSResolver(const std::string& hostname);

    // Sends the DNS query to 8.8.8.8 (Google DNS)
    bool sendQuery();

    // Receives the response from DNS server
    bool receiveResponse();

    // Prints raw bytes of response (for now, just to verify)
    void printRawResponse() const;

private:
    std::string hostname;              // Hostname to resolve
    uint8_t buffer[DNS_BUFFER_SIZE];   // 512-byte buffer
    int sockfd;                        // UDP socket file descriptor
    sockaddr_in server_addr;           // Google DNS: 8.8.8.8:53

    void buildQuery();     // Builds DNS query header + question
    void setupSocket();    // Prepares UDP socket to talk to server
};

#endif // DNS_RESOLVER_H
