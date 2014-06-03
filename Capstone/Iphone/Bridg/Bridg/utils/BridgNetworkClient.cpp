//
//  BridgNetworkClient.cpp
//  Bridg
//
//  Created by Ahmed Jafri on 6/2/14.
//  Copyright (c) 2014 lol. All rights reserved.
//

#include "BridgNetworkClient.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void BridgNetworkClient::resetForNewSong()
{
    sendCommand(BridgCommands::NEW_SONG_UPLOAD);
}

void BridgNetworkClient::finishedWithSong()
{
    sendCommand(BridgCommands::UPLOAD_DONE);
}

void BridgNetworkClient::skipSong()
{
    sendCommand(BridgCommands::SKIP);
}

void BridgNetworkClient::sendCommand(BridgCommands command)
{
    char tempBuffer[1];
    
    BridgData data = BridgData();
    data.length = sizeof(char);
    data.dataType = BridgDataType::COMMAND;
    data.data = (char*)tempBuffer;
    tempBuffer[0] = (char)command;
    
    sendDataToServer(data);
}

void BridgNetworkClient::sendMusicData(int length, unsigned char * inData)
{
    BridgData data = BridgData();
    data.length = length;
    data.dataType = BridgDataType::MP3_ENCODED_DATA;
    data.data = (char*)inData;
    
    sendDataToServer(data);
}

void BridgNetworkClient::sendDataToServer(BridgData inData)
{
    int sockfd, portno;
    long n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    
    uint32_t headerLength = inData.length + HEADER_LENGTH + TYPE_LENGTH;
    char dataBuffer[headerLength];
    
    serialize(dataBuffer, inData);
    
    portno = PORT_NUMBER;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sockfd < 0)
    {
        fprintf(stderr,"ERROR, cannot open socket. \n");
        return;
    }
    
    server = gethostbyname(SERVER_ADDRESS);
    
    if (server == NULL)
    {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    
    bzero((char *) &serv_addr, sizeof(serv_addr));
    
    serv_addr.sin_family = AF_INET;
    
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    
    serv_addr.sin_port = htons(portno);
    
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
    {
        fprintf(stderr,"ERROR, connection refused. \n");
        return;
    }
    
    n = write(sockfd, &headerLength, sizeof(uint32_t) );
    
    n = write(sockfd, dataBuffer , headerLength );
    
    if (n < 0)
    {
        fprintf(stderr,"ERROR, can't write to socket. \n");
        return;
    }
    
    close(sockfd);
}

int BridgNetworkClient::serialize(char * dataBuffer, BridgData dataToSerialize)
{
    memcpy(dataBuffer,                                      &dataToSerialize.dataType,      sizeof(char));
    
    uint32_t b0,b1,b2,b3, flippedInt;
    
    b0 = (dataToSerialize.length & 0x000000ff) << 24u;
    b1 = (dataToSerialize.length & 0x0000ff00) << 8u;
    b2 = (dataToSerialize.length & 0x00ff0000) >> 8u;
    b3 = (dataToSerialize.length & 0xff000000) >> 24u;
    
    flippedInt = b0 | b1 | b2 | b3;
    
    memcpy(&dataBuffer[TYPE_LENGTH],                        &flippedInt,                  sizeof(uint32_t));
    memcpy(&dataBuffer[sizeof(uint32_t) + TYPE_LENGTH],     dataToSerialize.data,         dataToSerialize.length);
    for(int i = 0; i < 10; i ++)
        printf("0x%x ",dataBuffer[i]);
    
    printf("\n");
    return 0;
}