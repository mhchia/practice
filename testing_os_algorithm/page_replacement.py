#!/usr/bin/env python2
# -*- coding: utf-8 -*-

import random


def optimal(index, sequence, frames):
    '''
        Use future knowledge(pages in the future) to decide which page to be
        swapped out.
    '''

    dist_count = []
    for page in frames:
        try:
            dist = sequence[index+1:].index(page)
        except ValueError:
            dist = 2147483647
        dist_count.append(dist)
    max_dist = max(dist_count)

    return dist_count.index(max_dist)

def lru(index, sequence, frames):
    '''
    '''

    dist_count = []
    for page in frames:
        dist = sequence[:index][::-1].index(page)
        dist_count.append(dist)
    max_dist = max(dist_count)

    return dist_count.index(max_dist)


def fifo(index, sequence, frames):
    '''
        The basic First-In-First-Out algorithm.
    '''

    return 0

def run_simulation(sequence, num_frames, algorithm):

    num_page_faults = 0
    frames = []

    for i in xrange(len(sequence)):
        page = sequence[i]
        if page in frames:
            continue
        if len(frames) == num_frames:
            victim_index = algorithm(i, sequence, frames)
            frames.pop(victim_index)
        frames.append(page)
        num_page_faults += 1

    return num_page_faults, frames

def gen_random_sequence(num_frames, sequence_length):

    sequence = []
    for i in xrange(sequence_length):
        sequence.append(random.randint(0, 9))
    return sequence

def simulate_replacement(num_frames, sequence_length):

    sequence = gen_random_sequence(num_frames, sequence_length)
    print "sequence\t:\t" + ' '.join(map(str, sequence))
    functions = [fifo, lru, optimal]
    for func in functions:
        num_page_faults, frames = run_simulation(sequence, num_frames, func)
        print "%s\t:\t%d" % (func.__name__, num_page_faults)

if __name__ == '__main__':

    simulate_replacement(5, 40)
