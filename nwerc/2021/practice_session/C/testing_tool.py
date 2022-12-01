#!/usr/bin/env python3
#
# Testing tool for the Coin problem
#
# Usage:
#
#   python3 testing_tool.py [-h] [-f inputfile] [-n N] [-q] program
#
# If neither the '-f' nor the '-n' parameter is specified, the sample is used.
# To run on a random test case with n = N, use parameter '-n N'.
# Otherwise, an input file is needed.
# The first line contains n, the number of coins.
# The second line contains the index of the odd coin, followed by
# either 'heavier' or 'lighter'. For example:
#
# 10
# 6 lighter
#
# If you have a Java solution that you would run using
# "java MyClass", you could invoke the testing tool with:
#
#   python3 testing_tool.py java MyClass
#
# If you have a Python solution that you would run using
# "python solution.py", you could invoke the testing tool with:
#
#   python3 testing_tool.py python solution.py
#
# If you have a C++ solution stored in a file called "sol.cpp",
# you must first compile using "g++ sol.cpp -o sol" and then
# invoke the testing tool with:
#  
#   python3 testing_tool.py ./sol
#
# If you want, for example, to test your solution on a random test case
# with the largest legal n and only print the number of guesses your
# submission used you can use:
#
#   python3 testing_tool.py -q -n -1 ./sol
#
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
import random
def write(p, line):
    assert p.poll() is None, 'Program terminated early'
    if not args.quiet: print('Write: {}'.format(line), flush=True)
    p.stdin.write('{}\n'.format(line))
    p.stdin.flush()

def read(p):
    assert p.poll() is None, 'Program terminated early'
    line = p.stdout.readline().strip()
    assert line != '', 'Read empty line or closed output pipe'
    if not args.quiet: print('Read: %s' % line, flush=True)
    return line

def wrong_answer(p, msg):
    # this kills the program.
    p.kill()
    print("Wrong answer:", msg)
    sys.exit(1)
    

parser = argparse.ArgumentParser(description='Testing tool for the Coin problem.')
parser.add_argument('-f', dest='inputfile', metavar='inputfile', default=None, type=argparse.FileType('r'),
                    help='Custom input file (defaults to sample 1).')
parser.add_argument('-n', dest='random', metavar='N', type=int,
                    help='Runs the submission on a random test case with N coins. This overwrites the -f flag.')
parser.add_argument('-q', action='store_true', dest='quiet', default=False,
                    help='Only print the number of moves required.')
parser.add_argument('program', nargs='+', help='Your solution')
args = parser.parse_args()
q = 0
if args.random is not None:
    n = args.random
    if n == -1: n = 2*10**5
    a = [0]*n
    a[random.randint(0, n - 1)] = 2*random.randint(0, 1) - 1
elif args.inputfile is not None:
    # Read the input file
    with args.inputfile as f:
        try:
            n = int(f.readline())
        except:
            assert False, "The first line of the input must contain a single integer."
        assert 3 <= n <= 2*10**5, "The integer n must be 3 <= n <= 2*10^5."
        b = list(f.readline().split())
        assert len(b) == 2, "The second line of the input must contain an integer and a string."
        try:
            b[0] = int(b[0])
        except:
            assert False, "The first part of the second line of the input must be an integer."
        assert 1 <= b[0] <= n, "The index must be on the range."
        assert b[1] == 'heavier' or b[1] == 'lighter', "The odd coin must be either 'heavier' or 'lighter'."
        assert f.readline() == '', 'Extra data at end of input file.'
        a = [0]*n
        if b[1] == 'lighter': a[b[0] - 1] = -1
        else: a[b[0] - 1] = 1
else:
    n = 10
    a = [0]*n
    a[random.randint(0, n - 1)] = 2*random.randint(0, 1) - 1

with subprocess.Popen(" ".join(args.program), shell=True, stdout=subprocess.PIPE, stdin=subprocess.PIPE, universal_newlines=True) as p:
    try:
        write(p, n)
        while True:
            line = read(p)
            if line == "": wrong_answer(p, "Command must contain at least one character.")
            if line[0] == '!': break;
            if line[0] != '?': wrong_answer(p, "Command must start with '?' or '!'.")
            try:
                x, y = map(int, line[2:].split())
            except:
                assert False, "The queries must contain two integers."
            if x == y: wrong_answer(p, "Queried indices must differ.")
            if x <= 0 or y <= 0 or x > n or y > n: wrong_answer(p, "Queried indices must be on range.")
            x -= 1
            y -= 1
            if a[x] == a[y]: write(p, "equal")
            elif a[x] < a[y]: write(p, "lighter")
            elif a[x] > a[y]: write(p, "heavier")
            q += 1
        try:
            x = int(line[2:])
        except:
            assert False, "The answer must be an integers."
        if x <= 0 or x > n: wrong_answer(p, "Answer must be on range.")
        if a[x - 1] == 0: wrong_answer(p, "Wrong coin guessed.")
    except:
        sys.stdout.flush()
        sys.stderr.flush()
        sys.exit(1)
    if not args.quiet: sys.stdout.write('Total number of guesses: {}\n'.format(q))
    else: sys.stdout.write('{}\n'.format(q))
    if not args.quiet: sys.stdout.write('exit code: {}\n'.format(p.wait()))
    sys.stdout.flush()

