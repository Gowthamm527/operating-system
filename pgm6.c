#include <stdio.h>

int main() {
    int n, bt[20], at[20], pr[20], rt[20];
    int time = 0, count = 0, smallest;
    int end, total = 0, wt = 0, tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("AT BT PR for P%d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        rt[i] = bt[i];
    }

    pr[19] = 9999;

    while (count != n) {
        smallest = 19;
        for (int i = 0; i < n; i++)
            if (at[i] <= time && pr[i] < pr[smallest] && rt[i] > 0)
                smallest = i;

        rt[smallest]--;
        if (rt[smallest] == 0) {
            count++;
            end = time + 1;
            wt += end - at[smallest] - bt[smallest];
            tat += end - at[smallest];
        }
        time++;
    }

    printf("\nAverage Waiting Time = %.2f", wt * 1.0 / n);
    printf("\nAverage Turnaround Time = %.2f\n", tat * 1.0 / n);

    return 0;
}
