#!/bin/bash
make
SERVER=`ps aux | grep " ./server" | head -n 1 | awk -F ' ' '{print $2}'`


STARTTIME=$(date +%s.%3N)

./client $SERVER $1

ENDTIME=$(date +%s.%3N)
ELAPSED=$(echo "scale=3; $ENDTIME - $STARTTIME" | bc)
echo "It takes $ELAPSED seconds to send this message"