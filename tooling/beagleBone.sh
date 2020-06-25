#!/bin/env bash

#This script is used to enable Internet connection via USB on the BeagleBone Black (BBB)

i=$@
if [[ $# -eq 0 ]]
then
	echo "Usage: sudo ./beaglebone.sh host"
elif [[ $i = "host" || $i ]]
then
	echo "Executing host commands..."
	sysctl -w net.ipv4.ip_forward=1
	iptables --table nat --append POSTROUTING --out-interface wlp3s0 -j MASQUERADE
	iptables --append FORWARD --in-interface enp0s20f0u1 -j ACCEPT
elif [[ $i = "beagle" ]]
then
	echo "Executing Beaglebone Black commands"
	route add default gw 192.168.7.1
fi
