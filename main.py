import pandas as pd
import matplotlib.pyplot as plt

# Carregar o CSV
data = pd.read_csv('metricas.csv')

# Filtrar os dados por algoritmo (exemplo: Bubble Sort)
bubble_sort_data = data[data['Algorithm'] == 'Bubble Sort']

# Plotar gráfico de barras comparando comparações e movimentos para diferentes tamanhos de array
plt.figure(figsize=(10, 6))
plt.bar(bubble_sort_data['Array Size'], bubble_sort_data['Comparisons'], label='Comparisons')
plt.bar(bubble_sort_data['Array Size'], bubble_sort_data['Movements'], label='Movements')
plt.xlabel('Array Size')
plt.ylabel('Count')
plt.title('Bubble Sort - Comparisons vs Movements for Different Array Sizes')
plt.legend()
plt.show()