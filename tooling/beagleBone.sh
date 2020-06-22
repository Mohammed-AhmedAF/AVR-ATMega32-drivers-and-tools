#!/bin/env bash

#

iptables --table nat --append POSTROUTING --out-interface wlp3s0 -j MASQUERADE
iptables --append FORWARD --in-interface enx0479b787cf33 -j ACCEPT
