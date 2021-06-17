#!/bin/bash
make
SERVER=`ps aux | grep " ./server" | head -n 1 | awk -F ' ' '{print $2}'`

./client $SERVER "0123456789 0123456789 0123456789 0123456789 0123456789 0123456789 0123456789 0123456789 0123456789 0123456789"
./client $SERVER "romeu\n"
./client $SERVER "rita\n"