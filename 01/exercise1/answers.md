# Exercise 1

### Study how to submit jobs in SLURM, how to check their state and how to cancel them.

Create a bash script with all options included instead of typing them out in the console table. Example:

```
#!/bin/bash

#SBATCH --job-name=job_name
#SBATCH --ntasks=number_of_tasks
#SBATCH --cpus-per-task=number_of_cpus_per_task
#SBATCH --mem-per-cpu=memory_per_cpu

./your_commands
```

### Prepare a submission script that starts an arbitrary executable, e.g. /bin/hostname

```
#!/bin/bash

# Execute job in the partition "lva" unless you have special requirements.
#SBATCH --partition=lva
# Name your job to be able to identify it later
#SBATCH --job-name test
# Redirect output stream to this file
#SBATCH --output=output.log
# Maximum number of tasks (=processes) to start in total
#SBATCH --ntasks=1
# Maximum number of tasks (=processes) to start per node
#SBATCH --ntasks-per-node=1
# Enforce exclusive node allocation, do not share with other jobs
#SBATCH --exclusive

/bin/hostname
```

### In your opionion, what are the 5 most important parameters available when submitting a job and why? What are possible settings of these parameters, and what effect do they have?

#### Job Settings

Easy to read job name and easier to find.

```
#SBATCH --job-name=name
```

#### Memory Allocation

To be safe that the job has the necessary resources.

```
#SBATCH --mem=size[K|M|G|T]
#SBATCH --mem-per-cpu=size[K|M|G|T]
```

#### Task/Nodes Settings

To be safe that the job has the necessary resources.

```
#SBATCH --ntasks=ntasks
#SBATCH --nodes=n[-m]
#SBATCH --ntasks-per-node=ntasks
#SBATCH --cpus-per-task=ncpus
```

#### Job Script Validation and Start Estimate

For testing and debugging job scripts before actual submission, preventing potential issues.

```
#SBATCH --test-only
```

#### Time

Prevents jobs from occupying resources for an excessive duration.

```
#SBATCH --time=time
```

### How do you run your program in parallel? What environment setup is required?

```
# Allocate one task on one node and six cpus for this task
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=6

# Allocate 12 Gigabytes for the whole node/task
#SBATCH --mem=12G
```