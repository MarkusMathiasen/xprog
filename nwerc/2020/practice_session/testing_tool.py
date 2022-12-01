#!/usr/bin/env python3
#
# Testing tool for the Cheating problem
#
# Usage:
#
#   python3 testing_tool.py [-f input_file] <program>
#
# If the -f parameter is not specified, sample 1 is used. Otherwise,
# an input file is needed. The file should only contain 4 lowercase
# letters. For example:
#
# icpc

# You can compile and run your solution as follows.
# - You may have to replace 'python3' by just 'python'.
# - On Windows, you may have to to replace '/' by '\'.

# C++:
#   g++ solution.cpp
#   python3 testing_tool.py ./a.out

# Java
#   javac solution.java
#   python3 testing_tool.py java solution

# Python3
#   python3 testing_tool.py python3 ./solution.py

# The tool is provided as-is, and you should feel free to make
# whatever alterations or augmentations you like to it.
#
# The tool attempts to detect and report common errors, but it
# is not guaranteed that a program that passes the testing tool
# will be accepted.
#

import argparse
import subprocess
import sys
import traceback
import string


def write(p, line):
    assert p.poll() is None, 'Program terminated early'
    print('Write: {}'.format(line), flush=True)
    p.stdin.write('{}\n'.format(line))
    p.stdin.flush()


def read(p):
    assert p.poll() is None, 'Program terminated early'
    line = p.stdout.readline().strip()
    assert line != '', 'Read empty line or closed output pipe. Make sure that your program started successfully.'
    print('Read: %s' % line, flush=True)
    return line


parser = argparse.ArgumentParser(description='Testing tool for the Cheating problem')
parser.add_argument('-f', dest='inputfile', metavar='inputfile', default=None, type=argparse.FileType('r'),
                    help='Custom input file (defaults to sample 1)')
parser.add_argument('program', nargs='+', help='Your solution')

args = parser.parse_args()
guesses = 0

if args.inputfile is not None:
    # Read the input file
    with args.inputfile as f:
        password = f.readline().strip()
        assert len(password) == 4, 'Password must have 4 letters'
        assert set(password) <= set(string.ascii_lowercase), 'Password must only contain lowercase letters'
        assert f.readline() == '', 'Extra data at end of input file'
else:
    password = 'icpc'

with subprocess.Popen(" ".join(args.program), shell=True, stdout=subprocess.PIPE, stdin=subprocess.PIPE,
                          universal_newlines=True) as p:
    try:
        while True:
            guess = read(p).strip()
            guesses += 1

            assert len(guess) == 4, 'Guess must have 4 letters'
            assert set(guess) <= set(string.ascii_lowercase), 'Guess must only contain lowercase letters'

            correct = 0
            counted = [False]*4
            for i in range(4):
                if guess[i] == password[i]:
                    correct += 1
                    counted[i] = True
            if correct == 4:
                write(p, 'correct')
                assert p.stdout.readline() == '', 'Printed extra data after finding password'
                assert p.wait() == 0, 'Did not exit cleanly after finishing'
                break

            wrong_position = 0
            for i in range(4):
                if guess[i] != password[i]:
                    for j in range(4):
                        if not counted[j] and guess[i] == password[j]:
                            wrong_position += 1
                            counted[j] = True
                            break

            write(p, '%d %d' % (correct, wrong_position))

            if guesses == 50:
                sys.stdout.write('Program used too many guesses\n')
                p.kill()
                break
    except:
        traceback.print_exc()
    finally:
        sys.stdout.flush()
        sys.stderr.flush()
        sys.stdout.write('Guessed {} times, exit code: {}\n'.format(guesses, p.wait()))
        sys.stdout.flush()
