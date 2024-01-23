#include <stdio.h>

#define MAX_PROCESSES 100
#define TIME_SLICE 1
#define PRIORITY_DECREMENT 3

typedef struct
{
    int ID;
    int PRIORITY;
    int CPUTIME;
    int ALLTIME;
    int STATE;
} PCB;

void initializeProcesses(PCB processes[])
{
    int i;

    for (i = 0; i < MAX_PROCESSES; i++)
    {
        processes[i].ID = i;
        processes[i].PRIORITY = (i % 2 == 0) ? 10 + i : 20 - i;
        processes[i].CPUTIME = 1;
        processes[i].ALLTIME = 5 + i;
        processes[i].STATE = 1;
    }
}

/*
void initializeProcesses(PCB processes[])
{
    int i;

    for (i = 0; i < MAX_PROCESSES; i++)
    {
        processes[i].ID = i;
        processes[i].PRIORITY = (i == 4) ? 0 : (i % 2 == 0) ? 30 + i
                                                            : 38 - i;
        processes[i].CPUTIME = 0;
        processes[i].ALLTIME = (i == 4) ? 4 : 3 + i;
        processes[i].STATE = 1;
    }
}
*/

void printProcesses(PCB processes[], int currentProcess, int readyQueue[])
{
    int i;

    printf("锟斤拷前锟斤拷锟斤拷锟叫的斤拷锟教ｏ拷");

    if (currentProcess == -1)
    {
        printf("锟斤拷\n");
    }
    else
    {
        printf("%d\n", currentProcess);
    }

    printf("锟斤拷前锟斤拷锟斤拷锟斤拷锟叫ｏ拷");

    for (i = 0; i < MAX_PROCESSES; i++)
    {
        if (readyQueue[i] != -1)
        {
            printf("%d ", readyQueue[i]);
        }
    }

    printf("\n");
}

float calculateAverageTurnaroundTime(PCB processes[])
{
    int i;
    float totalTurnaroundTime = 0;

    for (i = 0; i < MAX_PROCESSES; i++)
    {
        int turnaroundTime = processes[i].CPUTIME;
        totalTurnaroundTime += turnaroundTime;
    }

    return totalTurnaroundTime / MAX_PROCESSES;
}

int main()
{
    PCB processes[MAX_PROCESSES];
    int readyQueue[MAX_PROCESSES];
    int currentProcess = -1;
    int i, j;
    float averageTurnaroundTime;

    initializeProcesses(processes);

    for (i = 0; i < MAX_PROCESSES; i++)
    {
        readyQueue[i] = i;
    }

    printf("锟斤拷始锟斤拷锟斤拷状态锟斤拷\n");
    printProcesses(processes, currentProcess, readyQueue);

    while (1)
    {
        int highestPriority = -1;

        // 锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟饺硷拷锟斤拷锟�
        for (i = 0; i < MAX_PROCESSES; i++)
        {
            if (readyQueue[i] != -1 && processes[readyQueue[i]].ALLTIME > 0)
            {
                if (highestPriority == -1 || processes[readyQueue[i]].PRIORITY > processes[highestPriority].PRIORITY)
                {
                    highestPriority = readyQueue[i];
                }
            }
        }

        if (highestPriority == -1)
        {
            break; // 锟斤拷锟斤拷锟窖斤拷锟斤拷
        }

        currentProcess = highestPriority;
        processes[currentProcess].CPUTIME += TIME_SLICE;
        processes[currentProcess].ALLTIME -= TIME_SLICE;
        processes[currentProcess].PRIORITY -= PRIORITY_DECREMENT;

        if (processes[currentProcess].ALLTIME <= 0)
        {
            processes[currentProcess].STATE = 0; // 锟斤拷锟斤拷锟斤拷锟�
        }

        // 锟斤拷锟铰讹拷锟斤拷
        for (i = 0; i < MAX_PROCESSES; i++)
        {
            if (readyQueue[i] == currentProcess)
            {
                readyQueue[i] = -1;
            }
        }

        // 锟狡讹拷锟斤拷锟斤拷山锟斤拷痰锟斤拷锟轿�
        for (i = 0; i < MAX_PROCESSES; i++)
        {
            if (processes[i].STATE == 0)
            {
                for (j = 0; j < MAX_PROCESSES; j++)
                {
                    if (readyQueue[j] == -1)
                    {
                        readyQueue[j] = i;
                        break;
                    }
                }
            }
        }

        printProcesses(processes, currentProcess, readyQueue);
    }

    averageTurnaroundTime = calculateAverageTurnaroundTime(processes);
    printf("锟斤拷锟斤拷锟姐法平锟斤拷锟斤拷转时锟戒：%.2f\n", averageTurnaroundTime);

    return 0;
}