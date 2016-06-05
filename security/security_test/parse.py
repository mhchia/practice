#!/usr/bin/env python2
# -*- coding: utf-8

import argparse
import os
import subprocess
import sys

import xml.etree.ElementTree as ET


evtxdump_path = "python-evtx/scripts/evtxdump.py"

def evtxdump_exist():

    return os.path.isfile(evtxdump_path)

def evtx_to_xml(evtx_file):

    if not evtxdump_exist():
        print "evtxdump.py doesn't exist!"
        sys.exit(1)
    with open('temp.xml', 'w') as f:
        if subprocess.call(['python', evtxdump_path, evtx_file], stdout=f):
            print "Error occurs when convert evtx to xml format"
            sys.exit(1)

def parse_xml(event_id):

    with open('temp.xml', 'rt') as f:
        tree = ET.parse(f)

    flag = False
    for node in tree.findall('.//*'):
        if node.tag.find("EventID") != -1 and int(node.text) == event_id:
            flag = True
        if flag and node.tag.find("EventRecordID") != -1:
            print node.text
            flag = False

def main():

    parser = argparse.ArgumentParser(
        description="Process evtx file and get corresponding " +
                    "EventRecordID of certain event id"
    )
    parser.add_argument('evtx_filename', type=str)
    parser.add_argument('event_id', type=int)
    args = parser.parse_args()

    evtx_to_xml(args.evtx_filename)
    parse_xml(args.event_id)

if __name__ == '__main__':

    main()
