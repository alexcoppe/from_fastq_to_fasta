# from_fastq_to_fasta
### :pill: A software for converting FASTQ files to FASTA ones

### Compiling the software

Download the software from [github](https://github.com/alexcoppe/from_fastq_to_fasta), enter the directory containg from_fastq_to_fasta.c and compile it with:

```
make
```

### Getting the FASTA file

The following command outputs the results to the standard output (STDOUT)
```
from_fastq_to_fasta reads.fastq
```

For redirectoring the output to a file:
```
from_fastq_to_fasta reads.fastq > reads.fasta
```
