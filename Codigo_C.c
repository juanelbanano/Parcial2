#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10
#define MAX_QUEUES 3

// Estructura de un proceso
typedef struct {
    int id;
    int burst_time;
    int priority;
} Process;

// Cola de procesos
typedef struct {
    Process *queue[MAX_PROCESSES];
    int front, rear;
} Queue;

// Inicializar una cola
void initializeQueue(Queue *q) {
    q->front = q->rear = -1;
}

// Verificar si la cola está vacía
int isEmpty(Queue *q) {
    return (q->front == -1);
}

// Añadir un proceso a la cola
void enqueue(Queue *q, Process *process) {
    if (q->rear == MAX_PROCESSES - 1) {
        printf("La cola está llena\n");
        exit(EXIT_FAILURE);
    }

    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->queue[q->rear] = process;
}

// Eliminar un proceso de la cola
Process *dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("La cola está vacía\n");
        exit(EXIT_FAILURE);
    }

    Process *process = q->queue[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return process;
}

// Función principal
int main() {
    // Inicializar las colas
    Queue queues[MAX_QUEUES];
    for (int i = 0; i < MAX_QUEUES; i++)
        initializeQueue(&queues[i]);

    // Crear algunos procesos de prueba
    Process *process1 = malloc(sizeof(Process));
    process1->id = 1;
    process1->burst_time = 5;
    process1->priority = 0;
    Process *process2 = malloc(sizeof(Process));
    process2->id = 2;
    process2->burst_time = 3;
    process2->priority = 1;
    Process *process3 = malloc(sizeof(Process));
    process3->id = 3;
    process3->burst_time = 7;
    process3->priority = 0;

    // Añadir los procesos a las colas según su prioridad
    enqueue(&queues[process1->priority], process1);
    enqueue(&queues[process2->priority], process2);
    enqueue(&queues[process3->priority], process3);

    // Simular la ejecución de procesos
    printf("Ejecutando procesos:\n");
    while (!isEmpty(&queues[0]) || !isEmpty(&queues[1]) || !isEmpty(&queues[2])) {
        for (int i = 0; i < MAX_QUEUES; i++) {
            if (!isEmpty(&queues[i])) {
                Process *current_process = dequeue(&queues[i]);
                printf("Proceso %d en ejecución\n", current_process->id);
                // Aquí iría la lógica para ejecutar el proceso

                // Ajustar la prioridad del proceso (ejemplo)
                if (current_process->burst_time > 2) {
                    current_process->priority++;
                    if (current_process->priority >= MAX_QUEUES)
                        current_process->priority = MAX_QUEUES - 1;
                    enqueue(&queues[current_process->priority], current_process);
                }
            }
        }
    }

    // Liberar memoria
    free(process1);
    free(process2);
    free(process3);

    return 0;
}