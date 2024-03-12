#!/bin/bash

# Execute job in the partition "lva" unless you have special requirements.
#SBATCH --partition=lva
# Name your job to be able to identify it later
#SBATCH --job-name PP-01-02-Fast
# Redirect output stream to this file
#SBATCH --output=fast.output.log

OMP_NUM_THREADS=1
time ../files/fast

OMP_NUM_THREADS=12
time ../files/fast