#include <stdio.h>

// Process structure
typedef struct {
    int process_id;
    int burst_time;
    int arrival_time;
} Process;

// First-Come, First-Served (FCFS) Scheduling Algorithm
void fcfs(Process processes[], int n) {
    int completion_time[n];
    int turnaround_time[n];
    int waiting_time[n];

    // Calculate completion time for each process
    completion_time[0] = processes[0].burst_time;
    for (int i = 1; i < n; i++) {
        completion_time[i] = completion_time[i - 1] + processes[i].burst_time;
    }

    // Calculate turnaround time and waiting time for each process
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = completion_time[i] - processes[i].arrival_time;
        waiting_time[i] = turnaround_time[i] - processes[i].burst_time;
    }

    // Print results
    printf("FCFS Scheduling Algorithm:\n");
    printf("Process\tBurst Time\tArrival Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].burst_time,
               processes[i].arrival_time, completion_time[i], turnaround_time[i], waiting_time[i]);
    }
    printf("\n");
}

// Shortest Job First (SJF) Scheduling Algorithm
void sjf(Process processes[], int n) {
    int completion_time[n];
    int turnaround_time[n];
    int waiting_time[n];

    // Sort processes based on burst time (shortest to longest)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burst_time > processes[j + 1].burst_time) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    // Calculate completion time for each process
    completion_time[0] = processes[0].burst_time;
    for (int i = 1; i < n; i++) {
        completion_time[i] = completion_time[i - 1] + processes[i].burst_time;
    }

    // Calculate turnaround time and waiting time for each process
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = completion_time[i] - processes[i].arrival_time;
        waiting_time[i] = turnaround_time[i] - processes[i].burst_time;
    }

    // Print results
    printf("Shortest Job First (SJF) Scheduling Algorithm:\n");
    printf("Process\tBurst Time\tArrival Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].burst_time,
               processes[i].arrival_time, completion_time[i], turnaround
