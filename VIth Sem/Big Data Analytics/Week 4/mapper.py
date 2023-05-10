#!/usr/bin/python3
import sys

# input comes from STDIN (standard input)
for line in sys.stdin:
    # remove leading and trailing whitespace
    line = line.strip()

    # split the line into words
    words = line.split()

    # increase counters
    for word in words:
        # output the word as the key and 1 as the value
        print('%s\t%s' % (word, 1))
