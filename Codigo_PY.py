from collections import deque

MAX_PROCESSES = 10
MAX_QUEUES = 3

# Estructura de un proceso
class Process:
    def __init__(self, pid, burst_time, priority):
        self.pid = pid
        self.burst_time = burst_time
        self.priority = priority

# Cola de procesos
class Queue:
    def __init__(self):
        self.queue = deque()

    def is_empty(self):
        return len(self.queue) == 0

    def enqueue(self, process):
        self.queue.append(process)

    def dequeue(self):
        if self.is_empty():
            return None
        return self.queue.popleft()

# Función principal
def main():
    # Inicializar las colas
    queues = [Queue() for _ in range(MAX_QUEUES)]

    # Crear algunos procesos de prueba
    processes = [
        Process(1, 5, 0),
        Process(2, 3, 1),
        Process(3, 7, 0)
    ]

    # Añadir los procesos a las colas según su prioridad
    for process in processes:
        queues[process.priority].enqueue(process)

    # Simular la ejecución de procesos
    print("Ejecutando procesos:")
    while processes:
        for priority in range(MAX_QUEUES):
            if not queues[priority].is_empty():
                current_process = queues[priority].dequeue()
                print(f"Proceso {current_process.pid} en ejecución")
                # Aquí iría la lógica para ejecutar el proceso

                # Ajustar el tiempo de ráfaga del proceso
                current_process.burst_time -= 2
                if current_process.burst_time <= 0:
                    processes.remove(current_process)
                else:
                    queues[current_process.priority].enqueue(current_process)

if __name__ == "__main__":
    main()