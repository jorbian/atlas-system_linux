#!/usr/bin/sh

PID=$1

if [ -z "$PID" ]; then
    echo "Usage: $0 <pid>"
    exit 1
fi

if (! kill -0 "$1" 2>/dev/null); then
    echo "ERROR: Process with PID $1 does not exist."
    exit 1
fi

kill -QUIT $PID
