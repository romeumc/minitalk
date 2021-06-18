#!/bin/bash
make
SERVER=`ps aux | grep " ./server" | head -n 1 | awk -F ' ' '{print $2}'`


STARTTIME=$(date +%s.%3N)
./client $SERVER "SMALL MESSAGE (100 characteres): 0123456789 0123456789 0123456789 0123456789 0123456789 0123456789 0"
PARTIALTIME=$(date +%s.%3N)
ELAPSED=$(echo "scale=3; $PARTIALTIME - $STARTTIME" | bc)
echo "It takes $ELAPSED seconds to send 100 characters"

./client $SERVER "┊┊┊┊╭━━╮╭━━╮┊╭━┓"
./client $SERVER "┈╭━━┫▔╲┣╯━━┻╮┃╭┛♫"
./client $SERVER "╭┫┈┈┃┈┈▏┊▋┊▋┃┃┃"
./client $SERVER "┃┃┈┈┃┈╱╭╰╯╰╯╰┫┣━╮"
./client $SERVER "╯┃┈┈╰━━╯╰━━━┳┫┣╮┃"
./client $SERVER "┈┃╭┳╭━┫╭┳╭━━╯┃┃┃┃"
./client $SERVER "┈┃┃┃┃┈┃┃┃┃┈╭╮┃╰╯┃"
./client $SERVER "┈┗┛┗┛┈┗┛┗┛╭╮┈╰━━╯"


./client $SERVER "║█║█║║█║█║█║║█║█║║█║█║█║"
./client $SERVER "║█║█║║█║█║█║║█║█║║█║█║█║"
./client $SERVER "║║║║║║║║║║║║║║║║║║║║║║║║"
./client $SERVER "╚╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╝"
./client $SERVER "♬ piano"

./client $SERVER "LARGE MESSAGE (1000 characters): aaaaaaaaaabbbbbbbbbbccccccccccaaaaaaaaaabbbbbbbbbbccccccccccaaaaaaaaaabbbbbbbbbbccccccccccaaaaaaaaaabbbbbbbbbbccccccccccaaaaaaaaaabbbbbbbbbbccccccccccaaaaaaaaaabbbbbbbbbbccccccccccaaaaaaaaaabbbbbbbbbbccccccccccaaaaaaaaaabbbbbbbbbbccccccccccaaaaaaaaaabbbbbbbbbbccccccccccaaaaaaaaaabbbbbbbbbbccccccccccaaaaaaaaaabbbbbbbbbbccccccccccaaaaaaaaaabbbbbbbbbbccccccccccaaaaaaaaaabbbbbbbbbbccccccccccaaaaaaaaaabbbbbbbbbbccccccccccaaaaaaaaaabbbbbbbbbbccccccccccaaaaaaaaaabbbbbbbbbbccccccccccaaaaaaaaaabbbbbbbbbbccccccccccaaaaaaaaaabbbbbbbbbbccccccccccaaaaaaaaaabbbbbbbbbbccccccccccaaaaaaaaaabbbbbbbbbbccccccccccaaaaaaaaaabbbbbbbbbbccccccccccaaaaaaaaaabbbbbbbbbbccccccccccaaaaaaaaaabbbbbbbbbbccccccccccaaaaaaaaaabbbbbbbbbbccccccccccaaaaaaaaaabbbbbbbbbbccccccccccaaaaaaaaaabbbbbbbbbbccccccccccaaaaaaaaaabbbbbbbbbbccccccccccaaaaaaaaaabbbbbbbbbbccccccccccaaaaaaaaaabbbbbbbbbbccccccccccaaaaaaaaaabbbbbbbbbbccccccccccaaaaaaaaaabbbbbbbbbbccccccccccaaaaaaaaaabbbbbbbbbbccccccccccaaaaaaa"

ENDTIME=$(date +%s.%3N)
ELAPSED=$(echo "scale=3; $ENDTIME - $STARTTIME" | bc)
echo "It takes $ELAPSED seconds to complete this task..."