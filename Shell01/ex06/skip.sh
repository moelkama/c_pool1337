#!/bin/sh
ls -l | awk 'Nr % 2 == 1'
