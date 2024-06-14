#include <stdio.h>

#define MAX_JOBS 100

void jobSequencing(char id[], int deadline[], int profit[], int n) {
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (deadline[i] > maxDeadline) {
            maxDeadline = deadline[i];
        }
    }

    char result[maxDeadline];
    int i, j, totalProfit = 0;

    for (i = 0; i < maxDeadline; i++) {
        result[i] = '\0';
    }

    for (i = 0; i < n; i++) {
        for (j = deadline[i] - 1; j >= 0; j--) {
            if (result[j] == '\0') {
                result[j] = id[i];
                totalProfit += profit[i];
                break;
            }
        }
    }

    printf("Scheduled Jobs: ");
    for (i = 0; i < maxDeadline; i++) {
        if (result[i]!= '\0') {
            printf("%c ", result[i]);
        }
    }
    printf("\nTotal Profit: %d\n", totalProfit);
}

void SortJobs(char id[], int deadline[], int profit[], int n) {
    for (int step = 0; step < n - 1; ++step) {
        for (int i = 0; i < n - step - 1; ++i) {
            if (profit[i] < profit[i + 1]) {
                char tempId = id[i];
                id[i] = id[i + 1];
                id[i + 1] = tempId;

                int tempDeadline = deadline[i];
                deadline[i] = deadline[i + 1];
                deadline[i + 1] = tempDeadline;

                int tempProfit = profit[i];
                profit[i] = profit[i + 1];
                profit[i + 1] = tempProfit;
            }
        }
    }
}

int main() {
    char id[MAX_JOBS];
    int deadline[MAX_JOBS];
    int profit[MAX_JOBS];
    int n;

    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    printf("Enter job details (ID, Deadline, Profit):\n");
    for (int i = 0; i < n; i++) {
        printf("Job %d: ", i + 1);
        scanf(" %c %d %d", &id[i], &deadline[i], &profit[i]);
    }


    SortJobs(id, deadline, profit, n);

    jobSequencing(id, deadline, profit, n);

    return 0;
}
