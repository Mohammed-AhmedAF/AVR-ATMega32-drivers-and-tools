#!/bin/env bash

#This script is used to enable Internet connection via USB on the BeagleBone Black (BBB)

i=$@
if [[ $i = "host" || $i ]]
then
	echo "Executing host commands..."
	iptables --table nat --append POSTROUTING --out-interface wlp3s0 -j MASQUERADE
	iptables --append FORWARD --in-interface enx0479b787cf33 -j ACCEPT
elif [[ $i = "beagle" ]]
then
	echo "Executing Beaglebone Black commands"
	route add default gw 192.168.7.1
fi
