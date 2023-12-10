#include <stdio.h>

int main() {
    int n, time_quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burst_times[n];
    int remaining_times[n];
    int turnaround_times[n];
    int waiting_times[n];
    int completed = 0;
    int time = 0;

    for (int i = 0; i < n; i++) {
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &burst_times[i]);
        remaining_times[i] = burst_times[i];
        turnaround_times[i] = 0;
        waiting_times[i] = 0;
    }

    printf("Enter time quantum: ");
    scanf("%d", &time_quantum);

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (remaining_times[i] > 0) {
                if (remaining_times[i] <= time_quantum) {
                    time += remaining_times[i];
                    turnaround_times[i] = time;
                    waiting_times[i] = turnaround_times[i] - burst_times[i];
                    remaining_times[i] = 0;
                    completed++;
                } else {
                    time += time_quantum;
                    remaining_times[i] -= time_quantum;
                }
            }
        }
    }

    double total_waiting_time = 0.0;
    double total_turnaround_time = 0.0;

    printf("\nProcess\tBurst Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, burst_times[i], turnaround_times[i], waiting_times[i]);
        total_waiting_time += waiting_times[i];
        total_turnaround_time += turnaround_times[i];
    }

    double average_waiting_time = total_waiting_time / n;
    double average_turnaround_time = total_turnaround_time / n;

    printf("\nAverage Waiting Time: %.2f\n", average_waiting_time);
    printf("Average Turnaround Time: %.2f\n", average_turnaround_time);

    return 0;
}





