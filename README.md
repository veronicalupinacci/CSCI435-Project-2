# Project 2: Producer-Consumer Problem

**Authors:** Miled Kalbourji, Veronica Lupinacci, Rebekah Watrous

## Description

This project implements a solution to the Producer-Consumer problem using pthreads in C. The system consists of one producer thread and three consumer threads. The producer generates integers and puts them into an array, while consumers consume these integers from the array.

The producer continuously generates a random number of integers (between 1 and 10) and places them into the array. Each consumer, on the other hand, consumes a random number of integers (between 1 and 3) from the array. After consuming an integer, the consumer marks the corresponding slot as consumed by placing -1. If there are still integers left in the array, the next consumer in line starts consuming.

To coordinate the activities of the producer and consumers, mutexes and conditional variables are used for synchronization. The producer signals the consumers when new integers are available, and consumers signal the producer when the array is empty.

## Usage

To compile the code, use the following command: gcc project2.c -lpthread, then run ./a.out  


## Project Background

This implementation was developed as a school project @Rhode Island College to demonstrate synchronization between threads using mutexes and conditional variables. The Producer-Consumer problem is a classic example used to illustrate the challenges of concurrent programming and how to solve them.

## Real-World Applications
The Producer-Consumer problem reflects scenarios encountered in various real-world systems where multiple producers generate data or tasks, and multiple consumers process them. Some common real-world applications include:

### Operating Systems

In an operating system, the Producer-Consumer problem manifests in several ways:

- **Disk I/O**: The disk scheduler acts as the producer, generating disk requests from various processes. Device drivers serve as consumers, processing these requests and interacting with the hardware to read from or write to the disk.
  
- **Network Communication**: In network communication, data packets produced by network interfaces or protocols need to be consumed by the appropriate processes or applications for processing. Network drivers and protocol handlers act as consumers to process incoming data packets.
  
### Web Servers

In a web server environment, the Producer-Consumer problem arises in handling incoming client requests:

- **HTTP Requests**: Multiple client requests (produced) arrive at the web server and are queued for processing. Worker threads or processes (consumers) then dequeue and process these requests to generate the appropriate HTTP responses.
  
- **Database Queries**: When handling database queries from web applications, the server may produce queries that need to be executed against the database. Worker threads consume these queries, execute them against the database, and return the results to the client.

### Message Queuing Systems

Message queuing systems are built around the concept of producers and consumers:

- **Publish-Subscribe Systems**: Publishers generate messages and enqueue them into topics or queues, while subscribers consume these messages to perform various tasks, such as data processing, notifications, or triggering actions.

- **Task Queues**: In task-based systems, producers enqueue tasks or jobs into queues, and worker processes or threads consume these tasks, execute them, and produce results.

### Parallel Computing

In parallel computing and distributed systems, the Producer-Consumer pattern is prevalent:

- **Parallel Task Execution**: In parallel computing environments, tasks or computations are produced and placed into a shared queue or distributed across nodes. Worker nodes or threads consume these tasks, execute them concurrently, and produce results.

- **Data Processing Pipelines**: Data processing pipelines involve multiple stages where data is produced, transformed, and consumed. Each stage may act as a producer and consumer, contributing to the overall processing of data.

Understanding and implementing solutions to the Producer-Consumer problem are fundamental skills for developing efficient and scalable concurrent systems in various domains.

