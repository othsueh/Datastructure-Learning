#include "./lib/base.h"
typedef struct {
    int duration;
    int earliestStart;
    int latestStart;
    int *dependencies;
    int dependencyCount;
} Task;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

void calculateEarliestStartTimes(Task *tasks, int n) {
    int changed, i, j, depTask;
    do {
        changed = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < tasks[i].dependencyCount; j++) {
                depTask = tasks[i].dependencies[j];
                if (tasks[depTask].earliestStart + tasks[depTask].duration > tasks[i].earliestStart) {
                    tasks[i].earliestStart = tasks[depTask].earliestStart + tasks[depTask].duration;
                    changed = 1;
                }
            }
        }
    } while (changed);
}

void calculateLatestStartTimes(Task *tasks, int n, int totalTime) {
    for (int i = 0; i < n; i++) {
        tasks[i].latestStart = totalTime - tasks[i].duration;
    }

    int changed, i, j, depTask;
    do {
        changed = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < tasks[i].dependencyCount; j++) {
                depTask = tasks[i].dependencies[j];
                if (tasks[depTask].latestStart > tasks[i].latestStart - tasks[depTask].duration) {
                    tasks[depTask].latestStart = tasks[i].latestStart - tasks[depTask].duration;
                    changed = 1;
                }
            }
        }
    } while (changed);
}

void findCriticalTasks(Task *tasks, int n) {
    for (int i = 0; i < n; i++) {
        if (tasks[i].earliestStart == tasks[i].latestStart) {
            printf("%d ", i + 1);
        }
    }
    printf("\n");
}

int main() {
    int n, k;
    scanf("%d", &n);

    Task *tasks = (Task *)malloc(n * sizeof(Task));
    for(int i = 0; i < n; i++) {
        scanf("%d", &tasks[i].duration);
        tasks[i].dependencies = (int *)malloc(n * sizeof(int));
        tasks[i].dependencyCount = 0;
        tasks[i].earliestStart = 0;
    }

    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        tasks[b-1].dependencies[tasks[b-1].dependencyCount++] = a-1;
    }

    calculateEarliestStartTimes(tasks, n);

    int totalTime = 0;
    for(int i = 0; i < n; i++) {
        totalTime = max(totalTime, tasks[i].earliestStart + tasks[i].duration);
    }

    calculateLatestStartTimes(tasks, n, totalTime);

    printf("%d\n", totalTime);
    for(int i = 0; i < n; i++) {
        printf("%d ", tasks[i].latestStart);
    }
    printf("\n");

    findCriticalTasks(tasks, n);

    for(int i = 0; i < n; i++) {
        free(tasks[i].dependencies);
    }
    free(tasks);

    return 0;
}

