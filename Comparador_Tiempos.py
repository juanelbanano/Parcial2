import subprocess
import time

# Función para ejecutar un archivo Python
def run_python_file(file_path):
    start_time = time.time()
    subprocess.run(["python", file_path])
    end_time = time.time()
    execution_time = end_time - start_time
    return execution_time

# Función para ejecutar un archivo C
def run_c_file(file_path):
    start_time = time.time()
    subprocess.run(["gcc", file_path, "-o", "executable"])
    subprocess.run(["./executable"])
    end_time = time.time()
    execution_time = end_time - start_time
    return execution_time

# Solicitar rutas de los archivos
python_file_path = input("Ingrese la ruta del archivo Python: ")
c_file_path = input("Ingrese la ruta del archivo C: ")

# Ejecutar los archivos y medir los tiempos de ejecución
python_execution_time = run_python_file(python_file_path)
c_execution_time = run_c_file(c_file_path)

# Comparar los tiempos de ejecución
if python_execution_time < c_execution_time:
    print(f"El archivo Python ({python_file_path}) fue más rápido con un tiempo de ejecución de {python_execution_time:.6f} segundos, el de c tuvo {c_execution_time:.6f} segundos.")
else:
    print(f"El archivo C ({c_file_path}) fue más rápido con un tiempo de ejecución de {c_execution_time:.6f} segundos, el de python tuvo {python_execution_time:.6f} segundos.")