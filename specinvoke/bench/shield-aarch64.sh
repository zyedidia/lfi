#!/bin/bash

# Consider changing the fixed clock frequency based on your machine, and make
# sure you lock benchmarking to the particular core you want to measure (e.g.,
# a P-core).

set -ex

# set cpu freq on CPU 2
sudo cpufreq-set -c 2 -g performance
sudo cpufreq-set -c 2 --min 2200MHz --max 2200MHz
# set cpu shield on CPU 2
sudo cset shield -c 2 -k on
sudo cset shield -e sudo -- -u "$USER" env "PATH=$PATH" bash

# You are in a subshell now, run your benchmark here

# Ctrl+D to close the current subshell
# Reset cpu frequency on CPU 2 by copying policy from cpu 0
POLICYINFO=($(cpufreq-info -c 0 -p))
echo "${POLICYINFO[0]}" "${POLICYINFO[1]}" "${POLICYINFO[2]}"
sudo cpufreq-set -c 2 -g ${POLICYINFO[2]}
sudo cpufreq-set -c 2 --min ${POLICYINFO[0]} --max ${POLICYINFO[1]}
